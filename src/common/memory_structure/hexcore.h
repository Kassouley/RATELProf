#ifndef HEXCORE_H
#define HEXCORE_H

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <pthread.h>
#include <limits.h>
#include <stdio.h>
#include <stddef.h>
#include <sys/mman.h>


/* Supported allocation sizes */
static const size_t hexcore_size_classes[] = {
    16u, 32u, 64u, 128u, 256u, 512u, 1024u, 2048u
};

#define HEXCORE_NUM_CLASSES (sizeof(hexcore_size_classes) / sizeof(hexcore_size_classes[0]))

#define HEXCORE_MIN_EXPONENT (sizeof(size_t) * CHAR_BIT - __builtin_clzl(hexcore_size_classes[0]) - 1)

#define HEXCORE_MIN_CLASS_SIZE 16u
#define HEXCORE_MAX_CLASS_SIZE 2048u

#define HEXCORE_PAGE_SIZE 4096

#define HEXCORE_PAGE_ALLOC_NUMBER 64

#define HEXCORE_BATCH_SIZE 128
#define HEXCORE_NUMBER_BATCH_PUSHED 4
#define HEXCORE_PUSH_THRESHOLD 4096
#define HEXCORE_TOTAL_PUSHED_SIZE (HEXCORE_BATCH_SIZE * HEXCORE_NUMBER_BATCH_PUSHED)

typedef uint8_t hexcore_cls_t;

typedef struct {
    hexcore_cls_t cls;
} hexcore_header;

#define HEXCORE_ALIGNMENT _Alignof(max_align_t)

#define HEXCORE_HEADER_SIZE (((sizeof(hexcore_header) + HEXCORE_ALIGNMENT - 1) / HEXCORE_ALIGNMENT) * HEXCORE_ALIGNMENT)

typedef struct hexcore_mmap_page_s
{
    struct hexcore_mmap_page_s* next;
    void* mmap_ptr;
} hexcore_mmap_page_t;


typedef struct hexcore_free_node
{
    struct hexcore_free_node *next;
    struct hexcore_free_node *batch_tail;
} hexcore_free_node;


typedef struct
{
    hexcore_free_node *head;
    size_t count;
    pthread_mutex_t mutex;
} hexcore_global_pool;


typedef struct
{
    hexcore_free_node *head;
    size_t counts;
    void* page;
    size_t page_offset;
} hexcore_thread_cache;


typedef struct
{
    hexcore_global_pool global_pools[HEXCORE_NUM_CLASSES];
    hexcore_mmap_page_t* mmap_pages;
    void* free_pages;
    size_t available_pages_number;
    pthread_mutex_t mutex;
} hexcore_allocator_t;


static hexcore_allocator_t hexcore_allocator = { 0 };
static __thread hexcore_thread_cache hexcore_cache[HEXCORE_NUM_CLASSES] = { 0 };

/*
 * Return class index.
 *
 * Examples:
 *     16   -> 0
 *     32   -> 1
 *     64   -> 2
 *     128  -> 3
 */
static inline hexcore_cls_t hexcore_size_to_class_index(size_t size)
{
    if (size <= HEXCORE_MIN_CLASS_SIZE) {
        return 0;
    }

    // ceil(log2(size)) - log2(MIN_CLASS_SIZE)
    unsigned bits = (unsigned)(sizeof(size_t) * 8);

    unsigned log2 = bits - (unsigned)__builtin_clzl(size - 1);

    unsigned min_log2 = (unsigned)__builtin_ctzl(HEXCORE_MIN_CLASS_SIZE);

    return log2 - min_log2;
}


static inline void hexcore_fetch_nodes_from_global(hexcore_thread_cache* cache, hexcore_cls_t cls)
{
    hexcore_global_pool* global_pool = &hexcore_allocator.global_pools[cls];
    cache->head = NULL;
    cache->counts = 0;
    pthread_mutex_lock(&global_pool->mutex);
    if (global_pool->count < HEXCORE_BATCH_SIZE) {
        pthread_mutex_unlock(&global_pool->mutex);
        return;
    }

    cache->head = global_pool->head;
    
    // global_pool->head->batch_tail is the last node of this batch.
    hexcore_free_node* batch_tail = global_pool->head->batch_tail;

    global_pool->head = batch_tail->next;
    batch_tail->next = NULL;

    global_pool->count -= HEXCORE_BATCH_SIZE;
    cache->counts = HEXCORE_BATCH_SIZE;

    pthread_mutex_unlock(&global_pool->mutex);
}

static inline void hexcore_push_nodes_to_global(hexcore_thread_cache* cache, hexcore_cls_t cls)
{
    if (cache->counts < HEXCORE_PUSH_THRESHOLD) {
        return;
    }
    hexcore_global_pool* global_pool = &hexcore_allocator.global_pools[cls];

    hexcore_free_node* new_global_head = cache->head;
    hexcore_free_node* batch_head = cache->head;
    hexcore_free_node* batch_tail = NULL;

    for (size_t j = 0; j < HEXCORE_NUMBER_BATCH_PUSHED; j++) {
        batch_tail = batch_head;

        // Find the last node of the batch.
        for (size_t i = 1; i < HEXCORE_BATCH_SIZE; i++) {
            batch_tail = batch_tail->next;
        }

        batch_head->batch_tail = batch_tail;
        batch_head = batch_tail->next;
    }

    // Advance cache head past the batch.
    cache->head = batch_head;

    pthread_mutex_lock(&global_pool->mutex);

    // Add the batch to the global pool.
    batch_tail->next = global_pool->head;
    global_pool->head = new_global_head;
    global_pool->count += HEXCORE_TOTAL_PUSHED_SIZE;

    pthread_mutex_unlock(&global_pool->mutex);

    cache->counts -= HEXCORE_TOTAL_PUSHED_SIZE;
}

static inline void hexcore_alloc_new_pages() {
    // using mmap to allocate a new page of memory
    void* new_pages = mmap(NULL, HEXCORE_PAGE_SIZE * HEXCORE_PAGE_ALLOC_NUMBER, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (new_pages == MAP_FAILED) {
        perror("mmap failed");
        exit(EXIT_FAILURE);
    }
    hexcore_allocator.free_pages = new_pages;
    hexcore_allocator.available_pages_number = HEXCORE_PAGE_ALLOC_NUMBER;
}

static inline void* hexcore_get_free_page() {
    pthread_mutex_lock(&hexcore_allocator.mutex);
    if (hexcore_allocator.available_pages_number == 0) {
        hexcore_alloc_new_pages();
    }
    void* page = hexcore_allocator.free_pages;
    hexcore_allocator.free_pages = (void*)((uint8_t*)page + HEXCORE_PAGE_SIZE);
    hexcore_allocator.available_pages_number--;
    pthread_mutex_unlock(&hexcore_allocator.mutex);
    return page;
}

static inline void hexcore_fetch_page_from_global(hexcore_thread_cache* cache, hexcore_cls_t cls)
{
    cache->page = hexcore_get_free_page();
    cache->page_offset = 0;
}


/*
 * Recover the size class from an allocated pointer.
 */
static inline hexcore_cls_t hexcore_ptr_to_cls(void *payload)
{
    const uint8_t *block = (const uint8_t *)payload - HEXCORE_HEADER_SIZE;

    const hexcore_header *header = (const hexcore_header *)block;

    return header->cls;
}


/*
 * Recover the original block address from an allocated pointer.
 *
 * The free-list node occupies the beginning of the block.
 */
static inline hexcore_free_node *hexcore_ptr_to_node(void *ptr)
{
    return (hexcore_free_node *)((uint8_t *)ptr - HEXCORE_HEADER_SIZE);
}


/*
 * Store the size class and return the aligned payload.
 */
static inline void *hexcore_add_cls_to_payload(void *block, hexcore_cls_t cls)
{
    hexcore_header *header = (hexcore_header *)block;

    header->cls = cls;

    return (uint8_t *)block + HEXCORE_HEADER_SIZE;
}

static inline void* hexcore_get_block_from_page(hexcore_thread_cache* cache, hexcore_cls_t cls)
{
    uint8_t* block = (uint8_t*)cache->page + cache->page_offset;
    cache->page_offset += hexcore_size_classes[cls];
    return hexcore_add_cls_to_payload(block, cls);
}

static inline bool hexcore_cache_is_empty(hexcore_thread_cache* cache)
{
    return cache->counts == 0;
}

static inline void* hexcore_get_node_from_cache(hexcore_thread_cache* cache, hexcore_cls_t cls)
{
    hexcore_free_node* node = cache->head;
    cache->head = node->next;
    cache->counts--;
    return hexcore_add_cls_to_payload(node, cls);
}

static inline void *hexcore_alloc(size_t size)
{
    size += HEXCORE_HEADER_SIZE;

    hexcore_cls_t cls = hexcore_size_to_class_index(size);

    if (cls >= HEXCORE_NUM_CLASSES) return NULL;

    hexcore_thread_cache *cache = &hexcore_cache[cls];

    /* Fast path: allocate from the current page. */
    if (cache->page != NULL && cache->page_offset <= HEXCORE_PAGE_SIZE - hexcore_size_classes[cls]) {
        return hexcore_get_block_from_page(cache, cls);
    }

    /* Reuse locally cached blocks. */
    if (!hexcore_cache_is_empty(cache)) {
        return hexcore_get_node_from_cache(cache, cls);
    }

    /* Refill the local cache from the global pool. */
    hexcore_fetch_nodes_from_global(cache, cls);

    if (!hexcore_cache_is_empty(cache)) {
        return hexcore_get_node_from_cache(cache, cls);
    }

    /* No cached blocks available: obtain a new page. */
    hexcore_fetch_page_from_global(cache, cls);

    return hexcore_get_block_from_page(cache, cls);
}

static inline void hexcore_free(void* ptr)
{
    hexcore_cls_t cls = hexcore_ptr_to_cls(ptr);
    if (cls >= HEXCORE_NUM_CLASSES) {
        return;
    }

    hexcore_thread_cache* cache = &hexcore_cache[cls];

    hexcore_free_node* node = hexcore_ptr_to_node(ptr);

    node->next = cache->head;
    cache->head = node;
    cache->counts++;

    if (cache->counts >= HEXCORE_PUSH_THRESHOLD) {
        hexcore_push_nodes_to_global(cache, cls);
    }
}

static inline void hexcore_allocator_init()
{
    pthread_mutex_init(&hexcore_allocator.mutex, NULL);
    for (size_t i = 0; i < HEXCORE_NUM_CLASSES; ++i) {
        pthread_mutex_init(&hexcore_allocator.global_pools[i].mutex, NULL);
        hexcore_allocator.global_pools[i].head = NULL;
        hexcore_allocator.global_pools[i].count = 0;
    }
}

static inline void hexcore_allocator_destroy()
{
    pthread_mutex_destroy(&hexcore_allocator.mutex);
    for (size_t i = 0; i < HEXCORE_NUM_CLASSES; ++i) {
        pthread_mutex_destroy(&hexcore_allocator.global_pools[i].mutex);
    }
    // Free all mmap pages
    hexcore_mmap_page_t* page = hexcore_allocator.mmap_pages;
    while (page) {
        munmap(page->mmap_ptr, HEXCORE_PAGE_SIZE * HEXCORE_PAGE_ALLOC_NUMBER);
        hexcore_mmap_page_t* next_page = page->next;
        free(page);
        page = next_page;
    }
}


#endif // HEXCORE_H
#ifndef CHT_H
#define CHT_H

#include <stdatomic.h>
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct cht_node {
    uint64_t key;
    void *value;
    struct cht_node *next;
} cht_node_t;

typedef struct {
    _Atomic(cht_node_t *) head;
} cht_bucket_t;

typedef struct {
    size_t bucket_count;
    size_t count;
    cht_bucket_t *buckets;
} cht_t;

static inline uint64_t hash_key(uint64_t x)
{
    x ^= x >> 30;
    x *= UINT64_C(0xbf58476d1ce4e5b9);
    x ^= x >> 27;
    x *= UINT64_C(0x94d049bb133111eb);
    x ^= x >> 31;

    return x;
}

static inline cht_t *cht_create(size_t size)
{
    if (size == 0)
        return NULL;

    // Size must be a power of two to avoid modulo so we automatically adjust it
    if ((size & (size - 1)) != 0) {
        size = 1ULL << (64 - __builtin_clzll(size - 1));
    }

    cht_t *table = (cht_t*)calloc(1, sizeof(*table));
    if (table == NULL)
        return NULL;

    table->buckets = (cht_bucket_t*)calloc(size, sizeof(cht_bucket_t));

    if (table->buckets == NULL) {
        free(table);
        return NULL;
    }

    table->bucket_count = size;

    for (size_t i = 0; i < size; i++)
        atomic_init(&table->buckets[i].head, NULL);

    return table;
}

static inline int cht_set(cht_t *table, uint64_t key, void *value)
{
    if (table == NULL)
        return 1;

    size_t index = hash_key(key) & (table->bucket_count - 1);
    cht_bucket_t *bucket = &table->buckets[index];

    cht_node_t *candidate = NULL;

    for (;;) {
        cht_node_t *head = atomic_load_explicit(&bucket->head, memory_order_acquire);
     
        /* Allocate a private node. */
        if (candidate == NULL) {
            candidate = (cht_node_t*)malloc(sizeof(cht_node_t));

            if (candidate == NULL)
                return 2;

            candidate->key = key;
            candidate->value = value;
        }

        candidate->next = head;

        cht_node_t *expected = head;

        if (atomic_compare_exchange_weak_explicit(
                &bucket->head,
                &expected,
                candidate,
                memory_order_release,
                memory_order_acquire)) {
            table->count++;
            return 0;
        }

        /*
         * Another thread modified the bucket.
         * Retry and check for duplicate keys.
         */
    }
    return 3; /* Should never reach here */
}


static inline void* cht_get(cht_t *table, uint64_t key)
{
    if (table == NULL)
        return NULL;

    size_t index = hash_key(key) & (table->bucket_count - 1);
    cht_bucket_t *bucket = &table->buckets[index];

    cht_node_t *node = atomic_load_explicit(&bucket->head, memory_order_acquire);

    while (node != NULL) {
        if (node->key == key) {
            return node->value;
        }

        node = node->next;
    }

    return NULL;
}


static inline void cht_destroy(cht_t *table, void (*free_value)(void*))
{
    if (table == NULL)
        return;

    for (size_t i = 0; i < table->bucket_count; i++) {
        cht_node_t *node = atomic_load_explicit(&table->buckets[i].head, memory_order_relaxed);

        while (node != NULL) {
            cht_node_t *next = node->next;
            if (free_value) free_value(node->value);
            free(node);
            node = next;
        }
    }

    free(table->buckets);
    free(table);
}

static inline size_t cht_count(cht_t *table)
{
    if (table == NULL)
        return 0;

    return table->count;
}

static inline void cht_for_each(cht_t *table, void (*callback)(uint64_t key, void* value, void* uargs), void* uargs)
{
    if (table == NULL || callback == NULL)
        return;

    for (size_t i = 0; i < table->bucket_count; i++) {
        cht_node_t *node = atomic_load_explicit(&table->buckets[i].head, memory_order_relaxed);

        while (node != NULL) {
            callback(node->key, node->value, uargs);
            node = node->next;
        }
    }
}

#endif // CHT_H
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef enum {
    HT_STRING_KEY,
    HT_UINT64_KEY,
} ht_key_mode_t;

typedef union {
    uint64_t u64key;
    const char* strkey;
} ht_key_t;

typedef struct ht_node_s {
    ht_key_t key;
    uint64_t value;
    struct ht_node_s *next;
} ht_node_t;

typedef struct hash_table_s {
    size_t size;
    ht_node_t **buckets;
    ht_key_mode_t mode;
} hash_table_t;


static inline uint64_t u64key_hash(ht_key_t key) {
    uint64_t x = key.u64key;

    x = (~x) + (x << 21); // x = (x << 21) - x - 1;
    x = x ^ (x >> 24);
    x = (x + (x << 3)) + (x << 8); // x * 265
    x = x ^ (x >> 14);
    x = (x + (x << 2)) + (x << 4); // x * 21
    x = x ^ (x >> 28);
    x = x + (x << 31);

    return x;
}

static inline bool u64key_equal(ht_key_t a, ht_key_t b) {
    return a.u64key == b.u64key;
}

static inline uint64_t strkey_hash(ht_key_t key) {
    uint64_t hash = 0x811C9DC5;
    const uint32_t prime = 0x01000193;

    const char* s = key.strkey;
    while (*s) {
        hash ^= (uint8_t)(*s++);
        hash *= prime;
    }

    return hash;
}

static inline bool strkey_equal(ht_key_t a, ht_key_t b) {
    return strcmp(a.strkey, b.strkey) == 0;
}

static bool key_hash(ht_key_mode_t mode, ht_key_t key) {
    if (mode == HT_STRING_KEY) return strkey_hash(key);
    else return u64key_hash(key);
}

static bool key_equal(ht_key_mode_t mode, ht_key_t a, ht_key_t b) {
    if (mode == HT_STRING_KEY) return strkey_equal(a, b);
    else return u64key_equal(a, b);
}

static inline hash_table_t *ht_create(size_t size, ht_key_mode_t mode) {
    hash_table_t *ht = (hash_table_t*) calloc(1, sizeof(hash_table_t));
    if (!ht) return NULL;
    ht->mode = mode;
    ht->size = size;
    ht->buckets = (ht_node_t**) calloc(size, sizeof(ht_node_t*));
    if (!ht->buckets) {
        free(ht);
        return NULL;
    }

    return ht;
}

static inline void ht_destroy(hash_table_t *ht) {
    if (!ht) return;

    for (size_t i = 0; i < ht->size; i++) {
        ht_node_t *node = ht->buckets[i];
        while (node) {
            ht_node_t *tmp = node->next;
            free(node);
            node = tmp;
        }
    }
    free(ht->buckets);
    free(ht);
}

static inline int ht_insert(hash_table_t *ht, ht_key_t key, uint64_t value) {
    if (!ht) return 1;

    uint64_t hash = key_hash(ht->mode, key);
    size_t idx = hash % ht->size;

    for (ht_node_t *n = ht->buckets[idx]; n; n = n->next) {
        if (key_equal(ht->mode, n->key, key)) {
            n->value = value; // overwrite
            return 0;
        }
    }

    ht_node_t *newnode = (ht_node_t*) malloc(sizeof(ht_node_t));
    if (!newnode) return 1;

    newnode->key = key;
    newnode->value = value;
    newnode->next = ht->buckets[idx];
    ht->buckets[idx] = newnode;

    return 0;
}

static inline uint64_t ht_get(hash_table_t *ht, ht_key_t key) {
    if (!ht) return (uint64_t)-1;

    uint64_t hash = key_hash(ht->mode, key);
    size_t idx = hash % ht->size;

    for (ht_node_t *n = ht->buckets[idx]; n; n = n->next) {
        if (key_equal(ht->mode, n->key, key)) {
            return n->value;
        }
    }
    return (uint64_t)-1;
}

static inline int ht_remove(hash_table_t *ht, ht_key_t key) {
    if (!ht) return 1;

    uint64_t hash = key_hash(ht->mode, key);
    size_t idx = hash % ht->size;

    ht_node_t *prev = NULL;
    ht_node_t *n = ht->buckets[idx];

    while (n) {
        if (key_equal(ht->mode, n->key, key)) {
            if (prev) prev->next = n->next;
            else ht->buckets[idx] = n->next;
            free(n);
            return 0;
        }
        prev = n;
        n = n->next;
    }

    return 1;
}

static inline int ht_get_or_insert(hash_table_t *ht, ht_key_t key, uint64_t *out_value, bool *was_inserted) {
    if (!ht) return -1;

    uint64_t hash = key_hash(ht->mode, key);
    size_t idx = hash % ht->size;

    for (ht_node_t *n = ht->buckets[idx]; n; n = n->next) {
        if (key_equal(ht->mode, n->key, key)) {
            *out_value = n->value;
            *was_inserted = false;
            return 1;
        }
    }

    ht_node_t *newnode = (ht_node_t*) malloc(sizeof(ht_node_t));
    if (!newnode) return -1;

    newnode->key = key;
    newnode->value = *out_value;
    newnode->next = ht->buckets[idx];
    ht->buckets[idx] = newnode;

    *was_inserted = true;
    return 1;
}
#ifndef U64_KEY_HASH_TABLE_H
#define U64_KEY_HASH_TABLE_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

/* =========================
   Key / Value Structures
   ========================= */
#ifndef HT_VALUE_TYPE
#define HT_VALUE_TYPE uint64_t
#endif

#ifndef HT_DEFAULT_VALUE
#define HT_DEFAULT_VALUE (HT_VALUE_TYPE)(-1)
#endif

typedef uint64_t ht_key_t;
typedef HT_VALUE_TYPE ht_value_t;

/* =========================
   Hash + Compare
   ========================= */

static inline uint64_t key_hash(ht_key_t key) {
    uint64_t x = key;

    x = (~x) + (x << 21); // x = (x << 21) - x - 1;
    x = x ^ (x >> 24);
    x = (x + (x << 3)) + (x << 8); // x * 265
    x = x ^ (x >> 14);
    x = (x + (x << 2)) + (x << 4); // x * 21
    x = x ^ (x >> 28);
    x = x + (x << 31);

    return x;
}

static inline bool key_equal(ht_key_t a, ht_key_t b) {
    return a == b;
}


/* =========================
   Hash Table API
   ========================= */
   
typedef struct ht_node_t {
    ht_key_t key;
    ht_value_t value;
    struct ht_node_t *next;
} ht_node_t;

typedef struct {
    size_t size;
    size_t count;
    ht_node_t **buckets;
} hash_table_t;

static inline hash_table_t* ht_create(size_t size) {
    hash_table_t *ht = (hash_table_t*) malloc(sizeof(hash_table_t));
    if (!ht || size == 0) return NULL;

    // Size must be a power of two to avoid modulo so we automatically adjust it
    if ((size & (size - 1)) != 0) {
        size = 1ULL << (64 - __builtin_clzll(size - 1));
    }

    ht->size = size;
    ht->count = 0;
    ht->buckets = (ht_node_t**) calloc(size, sizeof(ht_node_t*));
    if (!ht->buckets) {
        free(ht);
        return NULL;
    }
    return ht;
}

static inline bool ht_destroy(hash_table_t *ht) {
    if (!ht) return true;

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
    return false;
}

static inline bool ht_insert(hash_table_t *ht, ht_key_t key, ht_value_t value) {
    if (!ht) return true;

    uint64_t hash = key_hash(key);
    size_t idx = hash & (ht->size - 1);

    for (ht_node_t *n = ht->buckets[idx]; n; n = n->next) {
        if (key_equal(n->key, key)) {
            n->value = value; // overwrite
            return false;
        }
    }
    
    ht_node_t *newnode = (ht_node_t*) malloc(sizeof(ht_node_t));
    if (!newnode) return true;

    newnode->key = key;
    newnode->value = value;
    newnode->next = ht->buckets[idx];
    ht->buckets[idx] = newnode;
    ht->count++;
    return false;
}

static inline ht_value_t ht_get(hash_table_t *ht, ht_key_t key) {
    if (!ht) return HT_DEFAULT_VALUE;

    uint64_t hash = key_hash(key);
    size_t idx = hash & (ht->size - 1);

    for (ht_node_t *n = ht->buckets[idx]; n; n = n->next) {
        if (key_equal(n->key, key)) {
            return n->value;
        }
    }
    return HT_DEFAULT_VALUE;
}


static inline bool ht_remove(hash_table_t *ht, ht_key_t key) {
    if (!ht) return true;

    uint64_t hash = key_hash(key);
    size_t idx = hash & (ht->size - 1);

    ht_node_t *prev = NULL;
    ht_node_t *n = ht->buckets[idx];

    while (n) {
        if (key_equal(n->key, key)) {
            if (prev) prev->next = n->next;
            else ht->buckets[idx] = n->next;
            free(n);
            ht->count--;
            return false;
        }
        prev = n;
        n = n->next;
    }

    return true;
}

static inline bool ht_for_each(
    hash_table_t *ht,
    bool (*callback)(ht_key_t, ht_value_t, void*),
    void *userdata
) {
    if (!ht || !callback) return true;

    for (size_t i = 0; i < ht->size; i++) {
        ht_node_t *node = ht->buckets[i];
        while (node) {
            // If callback returns false, stop iterating
            if (!callback(node->key, node->value, userdata))
                return false;
            node = node->next;
        }
    }
    return false;
}

static inline size_t ht_count(hash_table_t *ht) {
    return ht ? ht->count : 0;
}


#endif // U64_KEY_HASH_TABLE_H
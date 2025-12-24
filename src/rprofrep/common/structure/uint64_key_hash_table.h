#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct ht_node_s {
    uint64_t key;
    uint64_t value;
    struct ht_node_s *next;
} ht_node_t;

typedef struct hash_table_s {
    size_t size;
    ht_node_t **buckets;
} hash_table_t;


static inline uint64_t key_hash(uint64_t key) {
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

static inline bool key_equal(uint64_t a, uint64_t b) {
    return a == b;
}

static inline hash_table_t *ht_create(size_t size) {
    hash_table_t *ht = (hash_table_t*) calloc(1, sizeof(hash_table_t));
    if (!ht) return NULL;

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

static inline int ht_insert(hash_table_t *ht, uint64_t key, uint64_t value) {
    if (!ht) return 1;

    uint64_t hash = key_hash(key);
    size_t idx = hash % ht->size;

    for (ht_node_t *n = ht->buckets[idx]; n; n = n->next) {
        if (key_equal(n->key, key)) {
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

static inline uint64_t ht_get(hash_table_t *ht, uint64_t key) {
    if (!ht) return (uint64_t) -1;

    uint64_t hash = key_hash(key);
    size_t idx = hash % ht->size;

    for (ht_node_t *n = ht->buckets[idx]; n; n = n->next) {
        if (key_equal(n->key, key)) {
            return n->value;
        }
    }
    return (uint64_t) -1;
}

static inline int ht_remove(hash_table_t *ht, uint64_t key) {
    if (!ht) return 1;

    uint64_t hash = key_hash(key);
    size_t idx = hash % ht->size;

    ht_node_t *prev = NULL;
    ht_node_t *n = ht->buckets[idx];

    while (n) {
        if (key_equal(n->key, key)) {
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

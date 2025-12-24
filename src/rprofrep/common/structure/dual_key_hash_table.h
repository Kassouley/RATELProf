#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    uint64_t k1;
    uint64_t k2;
} ht_dual_key_t;

typedef struct ht_node_s {
    ht_dual_key_t key;
    void *value;
    struct ht_node_s *next;
} ht_node_t;

typedef struct hash_table_s {
    size_t size;
    size_t count;
    ht_node_t **buckets;
} hash_table_t;


static inline uint64_t key_hash(ht_dual_key_t key) {
    uint64_t x = ((uint64_t)(uint32_t)key.k1 << 32) | (uint32_t)key.k2;
    x ^= x >> 33;
    x *= 0xff51afd7ed558ccdULL;
    x ^= x >> 33;
    x *= 0xc4ceb9fe1a85ec53ULL;
    x ^= x >> 33;
    return x;
}

static inline bool key_equal(ht_dual_key_t a, ht_dual_key_t b) {
    return (a.k1 == b.k1) && (a.k2 == b.k2);
}

static inline hash_table_t *ht_create(size_t size) {
    hash_table_t *ht = (hash_table_t*) calloc(1, sizeof(hash_table_t));
    if (!ht) return NULL;

    ht->size = size;
    ht->count = 0;
    ht->buckets = (ht_node_t**) calloc(size, sizeof(ht_node_t*));
    if (!ht->buckets) {
        free(ht);
        return NULL;
    }

    return ht;
}

static inline void ht_destroy(hash_table_t *ht, void (*free_value)(void*)) {
    if (!ht) return;

    for (size_t i = 0; i < ht->size; i++) {
        ht_node_t *node = ht->buckets[i];
        while (node) {
            ht_node_t *tmp = node->next;
            if (free_value) free_value(node->value);
            free(node);
            node = tmp;
        }
    }
    free(ht->buckets);
    free(ht);
}

static inline int ht_insert(hash_table_t *ht, ht_dual_key_t key, void *value) {
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
    ht->count++;
    return 0;
}

static inline void *ht_get(hash_table_t *ht, ht_dual_key_t key) {
    if (!ht) return NULL;

    uint64_t hash = key_hash(key);
    size_t idx = hash % ht->size;

    for (ht_node_t *n = ht->buckets[idx]; n; n = n->next) {
        if (key_equal(n->key, key)) {
            return n->value;
        }
    }
    return NULL;
}


static inline int ht_remove(hash_table_t *ht, ht_dual_key_t key, void (*free_value)(void*)) {
    if (!ht) return 1;

    uint64_t hash = key_hash(key);
    size_t idx = hash % ht->size;

    ht_node_t *prev = NULL;
    ht_node_t *n = ht->buckets[idx];

    while (n) {
        if (key_equal(n->key, key)) {
            if (prev) prev->next = n->next;
            else ht->buckets[idx] = n->next;

            if (free_value) free_value(n->value);
            free(n);
            ht->count--;
            return 0;
        }
        prev = n;
        n = n->next;
    }

    return 1;
}

// Iterate over all entries in the hash table.
// callback signature:
//    bool callback(ht_dual_key_t key, void *value, void *userdata)
// Return false from the callback to stop iteration early.
static inline void ht_foreach(
    hash_table_t *ht,
    bool (*callback)(ht_dual_key_t, void*, void*),
    void *userdata
) {
    if (!ht || !callback) return;

    for (size_t i = 0; i < ht->size; i++) {
        ht_node_t *node = ht->buckets[i];
        while (node) {
            // If callback returns false, stop iterating
            if (!callback(node->key, node->value, userdata))
                return;
            node = node->next;
        }
    }
}

static inline size_t ht_count(hash_table_t *ht) {
    return ht ? ht->count : 0;
}



static inline uint64_t *ht_unique_k1(hash_table_t *ht, size_t *out_count) {
    if (!ht || !out_count) return NULL;

    size_t capacity = 32;
    size_t count = 0;
    uint64_t *k1_list = (uint64_t *)malloc(capacity * sizeof(uint64_t));
    if (!k1_list) return NULL;

    for (size_t i = 0; i < ht->size; i++) {
        ht_node_t *node = ht->buckets[i];
        while (node) {
            // Check if k1 already exists in the list
            bool exists = false;
            for (size_t j = 0; j < count; j++) {
                if (k1_list[j] == node->key.k1) {
                    exists = true;
                    break;
                }
            }

            if (!exists) {
                if (count >= capacity) {
                    capacity *= 2;
                    uint64_t *tmp = (uint64_t *)realloc(k1_list, capacity * sizeof(uint64_t));
                    if (!tmp) {
                        free(k1_list);
                        return NULL;
                    }
                    k1_list = tmp;
                }
                k1_list[count++] = node->key.k1;
            }

            node = node->next;
        }
    }

    *out_count = count;
    return k1_list;
}

// Returns both values and k2 arrays. Caller must free both arrays.
// out_count will contain the number of items returned.
static inline int ht_values_by_k1(
    hash_table_t *ht,
    uint64_t k1,
    void ***out_values,
    uint64_t **out_k2,
    size_t *out_count
) {
    if (!ht || !out_values || !out_k2 || !out_count) return 1;

    size_t capacity = 32;
    size_t count = 0;
    void **values = (void **)malloc(capacity * sizeof(void *));
    if (!values) return 1;
    uint64_t *k2_list = (uint64_t *)malloc(capacity * sizeof(uint64_t));
    if (!k2_list) { 
        free(values);
        return 1;
    };

    for (size_t i = 0; i < ht->size; i++) {
        ht_node_t *node = ht->buckets[i];
        while (node) {
            if (node->key.k1 == k1) {
                if (count >= capacity) {
                    capacity *= 2;
                    void **tmp_values = (void **)realloc(values, capacity * sizeof(void *));
                    uint64_t *tmp_k2 = (uint64_t *)realloc(k2_list, capacity * sizeof(uint64_t));
                    if (!tmp_values || !tmp_k2) {
                        return 1;
                    }
                    values = tmp_values;
                    k2_list = tmp_k2;
                }

                values[count] = node->value;
                k2_list[count] = node->key.k2;
                count++;
            }
            node = node->next;
        }
    }

    *out_values = values;
    *out_k2 = k2_list;
    *out_count = count;
    return 0; // success
}
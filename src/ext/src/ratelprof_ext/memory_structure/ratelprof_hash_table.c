#include <pthread.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <ratelprof.h>
#include "ratelprof_ext/memory_structure/ratelprof_hash_table.h"
#include "ratelprof_ext/ratelprof_ext_status.h"

static inline size_t ratelprof_round_up_power_of_two(size_t size)
{
    if (size == 0) {
        return 1;
    }

    size_t power = 1;
    while (power < size) {
        if (power > (SIZE_MAX >> 1)) {
            return 0;
        }
        power <<= 1;
    }
    return power;
}

// Create a new hash table
ratelprof_status_t ratelprof_hashtable_init(ratelprof_hash_table_t *table, 
                                            size_t size) 
{
    size_t rounded_size = ratelprof_round_up_power_of_two(size);
    if (rounded_size == 0) {
        return RATELPROF_STATUS_MALLOC_FAILED;
    }
    table->size = rounded_size;
    table->buckets = (ratelprof_hash_entry_t **)malloc(sizeof(ratelprof_hash_entry_t *) * rounded_size);
    if (table->buckets == NULL) {
        return RATELPROF_STATUS_MALLOC_FAILED;
    }
    for (size_t i = 0; i < rounded_size; i++) {
        table->buckets[i] = NULL;
    }
    pthread_mutex_init(&table->mutex, NULL);
    table->count = 0;
    return RATELPROF_STATUS_SUCCESS;
}

// Hash function to map a key to an index. The size is guaranteed to be a power
// of two, so this uses a bitmask instead of modulo for faster hashing.
size_t ratelprof_hash(uint64_t key, size_t size) 
{
    return (size_t)(key & (size - 1));
}

// Insert a key-value pair into the hash table
ratelprof_status_t ratelprof_insert_hash(ratelprof_hash_table_t *table, 
                                         uint64_t key, 
                                         void* value) 
{
    if (!table) return RATELPROF_STATUS_INVALID_PTR;
    if (!table->buckets) return RATELPROF_STATUS_TABLE_IS_NULL;


    size_t index = ratelprof_hash(key, table->size);
    ratelprof_hash_entry_t *new_entry = (ratelprof_hash_entry_t *)malloc(sizeof(ratelprof_hash_entry_t));
    if (new_entry == NULL) {
        return RATELPROF_STATUS_MALLOC_FAILED;
    }

    table->count++;
    new_entry->key = key;
    new_entry->value = value;
    new_entry->next = NULL;

    pthread_mutex_lock(&table->mutex);
    if (table->buckets[index] == NULL) {
        table->buckets[index] = new_entry;
    } else {
        new_entry->next = table->buckets[index];
        table->buckets[index] = new_entry;
    }
    pthread_mutex_unlock(&table->mutex);
    return RATELPROF_STATUS_SUCCESS;
}

// Find a value by its key in the hash table
ratelprof_status_t ratelprof_find_hash(ratelprof_hash_table_t *table, 
                                       uint64_t key, 
                                       void** value) 
{
    if (!table) return RATELPROF_STATUS_INVALID_PTR;
    if (!table->buckets) return RATELPROF_STATUS_TABLE_IS_NULL;


    size_t index = ratelprof_hash(key, table->size);

    pthread_mutex_lock(&table->mutex);
    ratelprof_hash_entry_t *entry = table->buckets[index];
    while (entry != NULL) {
        if (entry->key == key) {
            *value = entry->value;
            pthread_mutex_unlock(&table->mutex);
            return RATELPROF_STATUS_SUCCESS;
        }
        entry = entry->next;
    }
    pthread_mutex_unlock(&table->mutex);
    return RATELPROF_STATUS_KEY_NOT_FOUND;
}

// Delete a key-value pair from the hash table
ratelprof_status_t ratelprof_delete_hash(ratelprof_hash_table_t *table, 
                                         uint64_t key) 
{
    if (!table) return RATELPROF_STATUS_INVALID_PTR;
    if (!table->buckets) return RATELPROF_STATUS_TABLE_IS_NULL;

    size_t index = ratelprof_hash(key, table->size);
    
    pthread_mutex_lock(&table->mutex);

    ratelprof_hash_entry_t *entry = table->buckets[index];
    ratelprof_hash_entry_t *prev = NULL;
    while (entry != NULL && entry->key != key) {
        prev = entry;
        entry = entry->next;
    }
    if (entry == NULL) {
        pthread_mutex_unlock(&table->mutex);
        return RATELPROF_STATUS_KEY_NOT_FOUND;
    }
    if (prev == NULL) {
        table->buckets[index] = entry->next;
    } else {
        prev->next = entry->next;
    }
    free(entry->value);
    entry->value = NULL;
    free(entry);
    entry = NULL;
    table->count--;
    pthread_mutex_unlock(&table->mutex);
    return RATELPROF_STATUS_SUCCESS;
}

// Free the hash table
ratelprof_status_t ratelprof_hashtable_free(ratelprof_hash_table_t *table, void (*free_value)(void*)) 
{
    if (!table) return RATELPROF_STATUS_INVALID_PTR;
    if (!table->buckets) return RATELPROF_STATUS_TABLE_IS_NULL;

    pthread_mutex_lock(&table->mutex);

    for (size_t i = 0; i < table->size; i++) {
        ratelprof_hash_entry_t *entry = table->buckets[i];
        while (entry != NULL) {
            ratelprof_hash_entry_t *temp = entry;
            entry = entry->next;
            if (free_value) {
                free_value(temp->value);
            }
            free(temp);
        }
    }
    free(table->buckets);
    table->buckets = NULL;
    table->size = 0;
    table->count = 0;

    pthread_mutex_unlock(&table->mutex);
    pthread_mutex_destroy(&table->mutex);

    return RATELPROF_STATUS_SUCCESS;
}

ratelprof_status_t ratelprof_hash_table_for_each(ratelprof_hash_table_t *table, void (*callback)(uint64_t, void*, void*), void *user_data) {
    if (!table) return RATELPROF_STATUS_INVALID_PTR;
    if (!table->buckets) return RATELPROF_STATUS_TABLE_IS_NULL;

    pthread_mutex_lock(&table->mutex);

    for (size_t i = 0; i < table->size; i++) {
        ratelprof_hash_entry_t *entry = table->buckets[i];
        while (entry != NULL) {
            callback(entry->key, entry->value, user_data);
            entry = entry->next;
        }
    }

    pthread_mutex_unlock(&table->mutex);
    return RATELPROF_STATUS_SUCCESS;
}
#include <ratelprof.h>
#include "ratelprof_ext/memory_structure/ratelprof_hash_table.h"
#include "ratelprof_ext/ratelprof_ext_status.h"

// Create a new hash table
ratelprof_status_t ratelprof_hashtable_init(ratelprof_hash_table_t *table, 
                                            size_t size) 
{
    table->size = size;
    table->buckets = (ratelprof_hash_entry_t **)malloc(sizeof(ratelprof_hash_entry_t *) * size);
    if (table->buckets == NULL) {
        return RATELPROF_STATUS_MALLOC_FAILED;
    }
    for (size_t i = 0; i < size; i++) {
        table->buckets[i] = NULL;
    }
    return RATELPROF_STATUS_SUCCESS;
}

// Hash function to map a key to an index
unsigned int ratelprof_hash(uint64_t key, size_t size) 
{
    return key % size;
}

// Insert a key-value pair into the hash table
ratelprof_status_t ratelprof_insert_hash(ratelprof_hash_table_t *table, 
                                         uint64_t key, 
                                         void* value) 
{
    if (table->buckets == NULL)
        return RATELPROF_STATUS_TABLE_IS_NULL;
    size_t index = ratelprof_hash(key, table->size);
    
    ratelprof_hash_entry_t *new_entry = (ratelprof_hash_entry_t *)malloc(sizeof(ratelprof_hash_entry_t));
    if (new_entry == NULL) return RATELPROF_STATUS_MALLOC_FAILED;

    new_entry->key = key;
    new_entry->value = value;
    new_entry->next = NULL;

    if (table->buckets[index] == NULL) {
        table->buckets[index] = new_entry;
    } else {
        new_entry->next = table->buckets[index];
        table->buckets[index] = new_entry;
    }
    return RATELPROF_STATUS_SUCCESS;
}

// Find a value by its key in the hash table
ratelprof_status_t ratelprof_find_hash(ratelprof_hash_table_t *table, 
                                       uint64_t key, 
                                       void** value) 
{
    if (table->buckets == NULL) return RATELPROF_STATUS_TABLE_IS_NULL;

    size_t index = ratelprof_hash(key, table->size);
    ratelprof_hash_entry_t *entry = table->buckets[index];
    while (entry != NULL) {
        if (entry->key == key) {
            *value = entry->value;
            return RATELPROF_STATUS_SUCCESS;
        }
        entry = entry->next;
    }
    return RATELPROF_STATUS_KEY_NOT_FOUND;
}

// Delete a key-value pair from the hash table
ratelprof_status_t ratelprof_delete_hash(ratelprof_hash_table_t *table, 
                                         uint64_t key) 
{
    if (table->buckets == NULL) {
        return RATELPROF_STATUS_TABLE_IS_NULL;
    }
    size_t index = ratelprof_hash(key, table->size);
    ratelprof_hash_entry_t *entry = table->buckets[index];
    ratelprof_hash_entry_t *prev = NULL;
    while (entry != NULL && entry->key != key) {
        prev = entry;
        entry = entry->next;
    }
    if (entry == NULL) {
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
    return RATELPROF_STATUS_SUCCESS;
}

// Free the hash table
ratelprof_status_t ratelprof_hashtable_free(ratelprof_hash_table_t *table) 
{
    if (!table) return RATELPROF_STATUS_INVALID_PTR;
    if (!table->buckets) return RATELPROF_STATUS_TABLE_IS_NULL;
    for (size_t i = 0; i < table->size; i++) {
        ratelprof_hash_entry_t *entry = table->buckets[i];
        while (entry != NULL) {
            ratelprof_hash_entry_t *temp = entry;
            entry = entry->next;
            free(temp->value);
            free(temp);
        }
    }
    free(table->buckets);
    table->buckets = NULL;
    return RATELPROF_STATUS_SUCCESS;
}

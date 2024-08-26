#include "ratelprof.h"
#include "ratelprof_ext.h"
#include "ratelprof_hash_table.h"

// Create a new hash table
ratelprof_status_t ratelprof_hashtable_init(ratelprof_hash_table_t *table, 
                                            size_t size) 
{
    table->size = size;
    table->buckets = (ratelprof_hash_entry_t **)malloc(sizeof(ratelprof_hash_entry_t *) * size);
    if (table->buckets == NULL) {
        return RATELPROF_STATUS_MALLOC_FAILED;
    }
    table->buckets[0] = NULL;
    // for (size_t i = 1; i < size; i++) {
    //     table->buckets[i] = NULL;
    // }
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
    unsigned int index = ratelprof_hash(key, table->size);
    ratelprof_hash_entry_t *new_entry = NULL;
    if (table->buckets[index] == NULL) {
        new_entry = (ratelprof_hash_entry_t *)malloc(sizeof(ratelprof_hash_entry_t));
        new_entry->key = key;
        new_entry->value = value;
        new_entry->next = NULL;
        table->buckets[index] = new_entry;
    } else {
        return RATELPROF_STATUS_HASH_TABLE_COLLISION;
    }
    return RATELPROF_STATUS_SUCCESS;
}

// Find a value by its key in the hash table
ratelprof_status_t ratelprof_find_hash(ratelprof_hash_table_t *table, 
                                       uint64_t key, 
                                       void** value) 
{
    if (table->buckets == NULL) {
        return RATELPROF_STATUS_TABLE_IS_NULL;
    }
    unsigned int index = ratelprof_hash(key, table->size);
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
    unsigned int index = ratelprof_hash(key, table->size);
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
    free(entry);
    entry->value = NULL;
    entry = NULL;
    return RATELPROF_STATUS_SUCCESS;
}

// Free the hash table
ratelprof_status_t ratelprof_hashtable_free(ratelprof_hash_table_t *table) 
{
    if (table->buckets == NULL) {
        return RATELPROF_STATUS_TABLE_IS_NULL;
    }
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
    free(table);
    table->buckets = NULL;
    table = NULL;
    return RATELPROF_STATUS_SUCCESS;
}

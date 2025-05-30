#ifndef RATELPROF_HASH_TABLE_H
#define RATELPROF_HASH_TABLE_H

#include <stdint.h>
#include <stdlib.h>
#include <ratelprof.h>

/**
 * Structure to represent an entry in the hash table.
 * This structure holds a key-value pair and a pointer to the next entry.
 */
typedef struct ratelprof_hash_entry_s {
    /** The key for the hash entry. */
    uint64_t key;
    /** The value associated with the key. */
    void* value;        
    /** Pointer to the next entry. */                
    struct ratelprof_hash_entry_s *next; 
} ratelprof_hash_entry_t;

/**
 * Structure to represent the hash table.
 * This structure holds an array of pointers to hash entries (buckets)
 * and the size of the hash table (number of bucket).
 */
typedef struct ratelprof_hash_table_s {
    /** Array of pointers to hash entries (buckets). */
    ratelprof_hash_entry_t **buckets; 
    /** The size of the hash table (number of buckets). */
    size_t size;
} ratelprof_hash_table_t;

/**
 * The function `ratelprof_hashtable_init` initializes a hash table with a specified size by allocating
 * memory for the buckets.
 * 
 * @param table The `table` parameter is a pointer to a `ratelprof_hash_table_t` structure, which
 * likely contains information about a hash table such as its size and buckets.
 * @param size The `size` parameter in the `ratelprof_hashtable_init` function represents the number of
 * buckets in the hash table that is being initialized. It determines the initial size of the hash
 * table's array of buckets where key-value pairs will be stored.
 * 
 * @return The function `ratelprof_hashtable_init` is returning a value of type `ratelprof_status_t`. In
 * this specific case, it will return `RATELPROF_STATUS_SUCCESS` if the initialization is successful,
 * and `RATELPROF_STATUS_MALLOC_FAILED` if the memory allocation using `malloc` fails.
 */
ratelprof_status_t 
ratelprof_hashtable_init(ratelprof_hash_table_t *table, 
                         size_t size);



/**
 * The function `ratelprof_hash` calculates the hash value of a given key
 * 
 * @param key The `key` parameter is a 64-bit unsigned integer used as input for the hash function.
 * @param size Size is the size of the hash table or the number of buckets in the hash table. It is
 * used to determine the index where the key should be stored in the hash table.
 * 
 * @return The `ratelprof_hash` function is returning the result of the key modulo size operation,
 * which is the remainder when key is divided by size.
 */
unsigned int 
ratelprof_hash(uint64_t key, 
               size_t size);



/**
 * The function ratelprof_insert_hash inserts a key-value pair into a hash table, handling collisions
 * by returning an error status.
 * 
 * @param table The `table` parameter is a pointer to a hash table structure (`ratelprof_hash_table_t`)
 * where you want to insert a new key-value pair.
 * @param key The `key` parameter in the `ratelprof_insert_hash` function is used as the key for the
 * hash entry that you want to insert into the hash table. It is typically a unique identifier that
 * helps in indexing and retrieving the associated value in the hash table.
 * @param value The `value` parameter in the `ratelprof_insert_hash` function represents the data that
 * you want to store in the hash table corresponding to the given `key`. It can be any pointer to data
 * that you want to associate with the key in the hash table.
 * 
 * @return The function `ratelprof_insert_hash` is returning a value of type `ratelprof_status_t`. In
 * this specific case, it will return `RATELPROF_STATUS_SUCCESS` if the insertion is successful,
 * `RATELPROF_STATUS_TABLE_IS_NULL` if the table is not init, and RATELPROF_STATUS_HASH_TABLE_COLLISION
 * if there is a hash collision.
 */
ratelprof_status_t 
ratelprof_insert_hash(ratelprof_hash_table_t *table, 
                      uint64_t key, 
                      void* value);



/**
 * The function ratelprof_find_hash searches for a key in a hash table and returns the corresponding
 * value if found.
 * 
 * @param table The `table` parameter is a pointer to a hash table structure (`ratelprof_hash_table_t`)
 * that contains information about the hash table, such as the array of buckets and the size of the
 * table.
 * @param key The `key` parameter in the `ratelprof_find_hash` function is the value that you want to
 * search for in the hash table. It is used to determine the index where the corresponding entry might
 * be located in the hash table.
 * @param value The `value` parameter in the `ratelprof_find_hash` function is a pointer to a pointer
 * (`void**`). This parameter is used to store the value associated with the key that is being searched
 * for in the hash table.
 * 
 * @return The function `ratelprof_find_hash` returns a `ratelprof_status_t` enum value. It can return
 * one of the following values:
 * - `RATELPROF_STATUS_TABLE_IS_NULL` if the hash table's buckets are NULL.
 * - `RATELPROF_STATUS_SUCCESS` if the key is found in the hash table, and the corresponding value is
 * assigned to the `value`.
 */
ratelprof_status_t 
ratelprof_find_hash(ratelprof_hash_table_t *table, 
                    uint64_t key, 
                    void** value);



/**
 * The function ratelprof_delete_hash deletes a key from a hash table.
 * 
 * @param table The `table` parameter is a pointer to a hash table structure (`ratelprof_hash_table_t`)
 * that contains information about the hash table, such as the array of buckets and its size.
 * @param key The `key` parameter in the `ratelprof_delete_hash` function is the unique identifier used
 * to locate and delete a specific entry in the hash table. It is the value that is hashed to determine
 * the index in the hash table where the entry is stored.
 * 
 * @return The function `ratelprof_delete_hash` returns a `ratelprof_status_t` enum value. The possible
 * return values are:
 * - `RATELPROF_STATUS_TABLE_IS_NULL` if the input hash table is NULL
 * - `RATELPROF_STATUS_KEY_NOT_FOUND` if the specified key is not found in the hash table
 * - `RATELPROF_STATUS_SUCCESS` if the success deleting
 */                                
ratelprof_status_t 
ratelprof_delete_hash(ratelprof_hash_table_t *table, 
                      uint64_t key);



/**
 * The function ratelprof_hashtable_free frees memory allocated for a hash table and its entries.
 * 
 * @param table The function `ratelprof_hashtable_free` takes a pointer to a hash table
 * `ratelprof_hash_table_t` as a parameter. This hash table contains an array of buckets where each
 * bucket may have one or more hash entries (`ratelprof_hash_entry_t`). The function iterates over
 * 
 * @return The function `ratelprof_hashtable_free` returns a `ratelprof_status_t` enum value. If the
 * table's buckets are NULL, it returns `RATELPROF_STATUS_TABLE_IS_NULL`. Otherwise, after freeing all
 * the entries in the hash table and then freeing the buckets and the table itself, it returns
 * `RATELPROF_STATUS_SUCCESS`.
 */
ratelprof_status_t 
ratelprof_hashtable_free(ratelprof_hash_table_t *table);

#endif // RATELPROF_HASH_TABLE_H

#ifndef RPROFREP_TREE_H
#define RPROFREP_TREE_H

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>


typedef union rprofrep_tree_child_u {
    struct rprofrep_tree_node_s ** node;
    uint64_t leaf_value;
} rprofrep_tree_child_t;


typedef struct rprofrep_tree_node_s {
    uint64_t value;
    uint64_t capacity;
    uint64_t nchild;
    rprofrep_tree_child_t childs;
} rprofrep_tree_node_t;

typedef bool (*rprofrep_tree_callback_t)(rprofrep_tree_node_t* node, void* user_arg);

rprofrep_tree_node_t* rprofrep_tree_create_node(uint64_t value, uint64_t capacity);

void rprofrep_tree_add_node(rprofrep_tree_node_t* tree, rprofrep_tree_node_t* node);

void rprofrep_tree_free_node(rprofrep_tree_node_t* node);

void rprofrep_tree_free_tree(rprofrep_tree_node_t* tree);

rprofrep_tree_node_t* rprofrep_tree_find_node(rprofrep_tree_node_t* tree, uint64_t value);

void rprofrep_tree_set_leaf_value(rprofrep_tree_node_t* node, uint64_t value);

uint64_t rprofrep_tree_get_leaf_value(rprofrep_tree_node_t* node);

bool rprofrep_tree_for_each_child(rprofrep_tree_node_t* tree, rprofrep_tree_callback_t callback, void* user_arg);

bool rprofrep_tree_for_each_leaf(rprofrep_tree_node_t* tree, rprofrep_tree_callback_t callback, void* user_arg);

size_t rprofrep_tree_count_leaves(rprofrep_tree_node_t* tree);


#endif // RPROFREP_TREE_H
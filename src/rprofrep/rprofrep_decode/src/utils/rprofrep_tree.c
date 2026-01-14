#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "rprofrep_log.h"
#include "utils/rprofrep_tree.h"

rprofrep_tree_node_t* rprofrep_tree_create_node(uint64_t value, uint64_t capacity)
{
    rprofrep_tree_node_t* t = (rprofrep_tree_node_t*) malloc(sizeof(rprofrep_tree_node_t));
    if (!t) return NULL;

    t->value = value;
    t->capacity = capacity;
    t->nchild = 0;

    if (capacity > 0) {
        t->childs.node = calloc(capacity, sizeof(rprofrep_tree_node_t*));
        if (t->childs.node == NULL) return NULL;
    }
    return t;
}

void rprofrep_tree_add_node(rprofrep_tree_node_t* tree, rprofrep_tree_node_t* node)
{
    if (tree->capacity > tree->nchild) {
        tree->childs.node[tree->nchild++] = node;
    }
}

void rprofrep_tree_free_tree(rprofrep_tree_node_t* tree)
{
    if (!tree) return;

    if (tree->capacity > 0 && tree->childs.node) {
        for (uint64_t i = 0; i < tree->nchild; i++) {
            rprofrep_tree_free_tree(tree->childs.node[i]);
        }
        free(tree->childs.node);
    }
    free(tree);
}

void rprofrep_tree_free_node(rprofrep_tree_node_t* node)
{
    if (!node) return;

    if (node->capacity > 0 && node->childs.node) {
        free(node->childs.node);
    }
    free(node);
}



void rprofrep_tree_set_leaf_value(rprofrep_tree_node_t* node, uint64_t value)
{
    if (node && node->capacity == 0) {
        node->childs.leaf_value = value;
    } else {
        rprofrep_log(RPROFREP_LOG_WARN, "Trying to set a leaf value but a node is already setted.\n");
    }
}


uint64_t rprofrep_tree_get_leaf_value(rprofrep_tree_node_t* node)
{
    if (node && node->capacity == 0) {
        return node->childs.leaf_value;
    }
    return (uint64_t)-1;
}


rprofrep_tree_node_t* rprofrep_tree_find_node(rprofrep_tree_node_t* tree, uint64_t value)
{
    if (!tree) return NULL;

    for (uint64_t i = 0; i < tree->nchild; i++) {
        rprofrep_tree_node_t* node = tree->childs.node[i];
        if (node->value == value) return node;
    }
    return NULL;
}


bool rprofrep_tree_for_each_child(rprofrep_tree_node_t* tree, rprofrep_tree_callback_t callback, void* user_arg)
{
    if (!tree || !callback) return false;
    for (uint64_t i = 0; i < tree->nchild; i++) {
        rprofrep_tree_node_t* node = tree->childs.node[i];
        if (callback(node, user_arg) == false) return false;
    }
    return true;
}

bool rprofrep_tree_for_each_leaf(rprofrep_tree_node_t* tree, rprofrep_tree_callback_t callback, void* user_arg)
{
    if (!tree || !callback) return false;

    if (tree->capacity == 0) {
        if (callback(tree, user_arg) == false) return false;
    } else {
        for (uint64_t i = 0; i < tree->nchild; i++) {
            rprofrep_tree_node_t* node = tree->childs.node[i];
            if (rprofrep_tree_for_each_leaf(node, callback, user_arg) == false) return false;
        }
    }
    return true;
}


bool __count_leaves(rprofrep_tree_node_t* node, void* user_arg) {
    size_t* count_ptr = (size_t*)user_arg;
    (*count_ptr)++;
    return true;
}


size_t rprofrep_tree_count_leaves(rprofrep_tree_node_t* tree) {
    size_t count = 0;
    rprofrep_tree_for_each_leaf(tree, __count_leaves, &count);
    return count;
}

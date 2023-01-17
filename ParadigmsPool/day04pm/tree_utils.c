/*
** EPITECH PROJECT, 2023
** day04pm
** File description:
** $DESCRIPTION
*/

#include <stdlib.h>
#include <stddef.h>
#include "tree.h"

bool tree_is_empty(tree_t tree)
{
    return tree == NULL;
}

static void tree_list_dump(list_t list, dump_func_t dump_func)
{
    while (list != NULL) {
        dump_func(list->value);
        list = list->next;
    }
}

void tree_node_dump(tree_node_t *tree_node, dump_func_t dump_func)
{
    if (tree_node == NULL)
        return;
    dump_func(tree_node->data);
    tree_list_dump(tree_node->children, dump_func);
}

bool init_tree(tree_t *tree_ptr, void *data)
{
    tree_node_t *tree = malloc(sizeof(tree_node_t));

    if (tree == NULL)
        return (false);
    tree->children = NULL;
    tree->parent = NULL;
    tree->data = data;
    *tree_ptr = tree;
    return (true);
}

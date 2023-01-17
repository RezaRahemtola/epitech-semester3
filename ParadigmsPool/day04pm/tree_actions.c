/*
** EPITECH PROJECT, 2023
** day04pm
** File description:
** $DESCRIPTION
*/

#include <stddef.h>
#include "tree.h"

tree_node_t *tree_add_child(tree_node_t *tree_node, void *data)
{
    tree_node_t *new = NULL;

    if (tree_node == NULL)
        return (NULL);
    init_tree(&new, data);
    new->parent = tree_node;
    list_add_elem_at_back(&(tree_node->children), new);
    return (new);
}

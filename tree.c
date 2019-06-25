#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

tree* tree_create_node(float mul, char var) {
    tree* retval = (tree*) malloc(sizeof(tree));
    retval->variable = var;
    retval->multiplier = mul;
    return retval;
}

void tree_add_node(tree **root, float mul, char var) {
    if (*root == NULL) {
        tree* to_add = tree_create_node(mul, var);
        *root = to_add;
    } else if (var == '_') {
        tree_add_node(&((*root)->left), mul, var);
    } else {
        tree_add_node(&((*root)->left), mul, '_');
        tree_add_node(&((*root)->right), 1.0, var);
    }
}

void tree_print(tree *root, int level)
{ // печать древа
    for (int i = 0; i < level; i++)
    {
        printf(" ");
    }
    if (root == NULL)
    {
        printf("NULL \n");
        return;
    }
    else if(root->variable != '_')
    {
        printf("* \n%f %c \n", root->multiplier, root->variable);
    }
    else {
        printf("* \n%f \n", root->multiplier);
    }
    tree_print(root->left, level + 1);
    tree_print(root->right, level + 1);
}

float tree_simplify(tree **root) {
    float temp;
    if ((*root)->left != NULL) {
        temp = (*root)->multiplier * tree_simplify(&((*root)->left));
        (*root)->multiplier = 1;
        return temp;
    } else {
        temp = (*root)->multiplier;
        (*root)->multiplier = 1;
        return temp;
    }
}

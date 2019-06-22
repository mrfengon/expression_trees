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

void tree_print (tree *root) {
    if (root == NULL) {
        return;
    }
    else {
        if (root->multiplier != 1.0) {
            printf("%f * ", root->multiplier);
        }
        if (root->variable != '_') {
            printf("%c * ", root->variable);
        }
    }
    tree_print(root->left);
    tree_print(root->right);
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

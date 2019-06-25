#ifndef TREE_H
#define TREE_H

typedef struct tree
{
    float multiplier;
    char variable;
    struct tree *left;
    struct tree *right;
    struct tree *parent;
} tree;

tree* tree_create_node(float mul, char var);
void tree_add_node(tree** root, float mul, char var);
void tree_print(tree* root, int level);
float tree_simplify(tree** root);

#endif
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

#endif
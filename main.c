#include <stdio.h>
#include "tree.h"

int main(int argc, char const *argv[])
{
    int temp = 1;
    float root_mul;
    char root_var;
    tree *root = NULL;
    while (temp != 5)
    {
        printf("\n1 - add multiplier, 2 - print tree, 3 - simplify tree, 5 - exit\n\n");
        scanf("%d", &temp);
        if (temp == 1)
        {
            printf("\nenter expression ('_' for no variable): ");
            scanf("%f %c", &root_mul, &root_var);
            tree_add_node(&root, root_mul, root_var);
        }
        else if (temp == 2)
        {
            tree_print(root, 0);
        }
        else if (temp == 3)
        {
            root->multiplier = tree_simplify(&root);
        }
        else
        {
            return 0;
        }
    }
}

#include <stdlib.h>
#include <stdio.h>

struct Node
{
    struct Node* left;
    struct Node* right;
    int data;

};

void printTree(Node* node)
{
    printf("%d", node->data);

    if(node->left != NULL)
    {
        printTree(node->left);
    }
    if (node->right != NULL)
    {
        printTree(node ->right);
    }
    
}

int Addleft()

typedef struct Node Node;

int main()
{
    Node root;
    int len;
    int * inorder;
    int* preorder;
    scanf("%d", &len);

    inorder = (int*)calloc(len, sizeof(int));
    preorder = (int*)calloc(len, sizeof(int));

    for (int i = 0; i < len; i++)
    {
        scanf("%d", inorder + i);
    }
    for (int i = 0; i < len; i++)
    {
        scanf("%d", preorder + i);
    }
        

}

#include <stdio.h>

// Binary Tree -- Tree with atmost 2 childrens...

typedef struct {
    int data;
    struct Node *left;
    struct Node *right; 
}Node;

Node *create_node(int data){
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL; 
    new_node->right = NULL; 
    return new_node;                
};

void display_tree_inorder(Node *root){
    if(root == NULL){
        return;
    }
    else
    {
        display_tree_inorder(root->left);
        printf("%d",root->data);
        display_tree_inorder(root->right);       
    }
};

void main(){
    Node *root = create_node(1);

    root->left = create_node(2);
    root->right = create_node(3);   

    display_tree_inorder(root);
};


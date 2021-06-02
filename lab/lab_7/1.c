#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct Node{

    int data;
    struct Node *right, *left;
}Node;

Node *construcBST(int preorder_array[], int key, int min, int max, int array_size, int *idx){

    if (*idx > array_size){
        return NULL;
    }

    Node *root = NULL;

    if (key > min && key < max){

        root = (Node *)malloc(sizeof(Node));
        root->data = key;
        root->right = root->left = NULL;
        *idx = *idx+1;

        if (*idx < array_size){

            root->left = construcBST(preorder_array, preorder_array[*idx], min, key, array_size, idx);
            root->right = construcBST(preorder_array, preorder_array[*idx], key, max, array_size, idx);
        }
    }
    return root;
}

void inOrder(Node *root){
    
    if(root->left != NULL){

        inOrder(root->left);
    }

    printf("%d ", root->data);

    if(root->right != NULL){

        inOrder(root->right);
    }
}

void main(){

    int preorder_array[100], size, idx = 0;

    printf("Enter the size of the traversal array: ");
    scanf("%d", &size);
    printf("Enter the array: ");

    for (int i = 0; i<size; i++){

        scanf("%d", &preorder_array[i]);
    }
    Node *root = construcBST(preorder_array, preorder_array[idx], INT_MIN, INT_MAX, size, &idx);
    inOrder(root);
}
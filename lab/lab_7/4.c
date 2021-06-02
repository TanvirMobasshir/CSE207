#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

    int data;
    struct Node *left, *right;
} Node;

void inOrder(Node *root, int array[], int *c_idx){
    
    if(root->left != NULL){

        inOrder(root->left, array, c_idx);
    }

    array[*c_idx] = root->data;
    (*c_idx)++;

    if(root->right != NULL){

        inOrder(root->right, array, c_idx);
    }
}

Node *createBT(int array[], int idx, int size){

    Node *root = NULL;

    if (idx < size){

        Node *temp = (Node *)malloc(sizeof(Node));
        temp->data = array[idx];
        temp->left = temp->right = NULL;
        root = temp;

        root->left = createBT(array, (2*idx)+1, size);
        root->right = createBT(array, (2*idx)+2, size);
    }
    return root;
}

int check_BST(int array[], int size){

    int data = array[0];

    for (int i = 1; i < size; i++){

        if (data > array[i]){
            return 0;
        }
        else{
            data = array[i];
        }
    }
    return 1;
}

void main(){

    int size, idx = 0, c_idx = 0, result;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int array[size], check_array[size];

    printf("Enter the array: ");
    for (int i = 0; i<size; i++){

        scanf("%d", &array[i]);
    }

    Node *root = createBT(array, idx, size);
    inOrder(root, check_array, &c_idx);

    result = check_BST(check_array, size);

    if (result){
        printf("True\n");
    }
    else{
        printf("False\n");
    }
}
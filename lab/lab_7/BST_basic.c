#include<stdio.h>
#include<stdlib.h>

struct Node{

    int data;
    struct Node *right, *left;
};

void create(struct Node **root, int data){

    struct Node *temp = *root, *node;

    node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->right = NULL;
    node->left = NULL;

    if (*root == NULL){
        
        *root = node;
        printf("created root\n");
        return;
    }
    while (temp != NULL){

        if (data > temp->data){

            if (temp->right == NULL){
                
                temp->right = node;
                printf("created bigger value\n");
                return;
            }
            else {
                temp = temp->right;
            }

        }
        else if (data < temp->data){

            if (temp->left == NULL){

                temp->left = node;
                printf("created smaller value\n");
                return;
            }
            else {
                temp = temp->left;
            }
        }
        else if (data == temp->data){

            printf("can't add data\n");
            return;
        }
    }
}

void search(struct Node **root, int data){

    struct Node *temp = *root;

    if (*root == NULL){
        
        printf("Binary search tree is empty!!\n");
        return;
    }
    while (temp != NULL){

        if (data == temp->data){

            printf("found your data\n");
            return;
        }

        else if (data > temp->data){

            if (temp->right == NULL){
                
                printf("data doesn't exist in this binary search tree\n");
                return;
            }
            else {
                temp = temp->right;
            }

        }
        else if (data < temp->data){

            if (temp->left == NULL){

                printf("data doesn't exist in this binary search tree\n");
                return;
            }
            else {
                temp = temp->left;
            }
        }
    }
}

void delete(struct Node **root, int data){

    struct Node *temp = *root;

    if (*root == NULL){
        
        printf("Binary search tree is empty!!\n");
        return;
    }
    while (temp != NULL){

        if (data > temp->data){

            if (temp->right == NULL){
                
                printf("data doesn't exist in this binary search tree\n");
                return;
            }
            else {

                if (data == (temp->right)->data){

                    temp->right = NULL;
                    printf("data deleted\n");
                    return;
                }
                temp = temp->right;
            }

        }
        else if (data < temp->data){

            if (temp->left == NULL){

                printf("data doesn't exist in this binary search tree\n");
                return;
            }
            else {

                 if (data == (temp->left)->data){

                    temp->left = NULL;
                    printf("data deleted\n");
                    return;
                }
                temp = temp->left;
            }
        }
    }
}

void preOrder(struct Node *root){

    printf("%d ", root->data);

    if(root->left != NULL){

        preOrder(root->left);
    }
    if(root->right != NULL){

        preOrder(root->right);
    }
}

void postOrder(struct Node *root){
    
    if(root->left != NULL){

        postOrder(root->left);
    }
    if(root->right != NULL){

        postOrder(root->right);
    }
    printf("%d ", root->data);
}

void inOrder(struct Node *root){
    
    if(root->left != NULL){

        inOrder(root->left);
    }

    printf("%d ", root->data);

    if(root->right != NULL){

        inOrder(root->right);
    }
}

void main(){

    struct Node *root = NULL;
    create(&root, 8);
    create(&root, 10);
    create(&root, 15);
    create(&root, 3);
    create(&root, 6);
    create(&root, 20);
    create(&root, 1);
    create(&root, 5);
    create(&root, 9);
    create(&root, 13);
    printf("\n");
    printf("pre-order: ");
    preOrder(root);
    printf("\npost-order: ");
    postOrder(root);
    printf("\nin-order: ");
    inOrder(root);
    printf("\n\n");
}
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;

void create(struct Node **root, int data){

    struct Node *temp = *root, *node;

    node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->right = NULL;
    node->left = NULL;

    if (*root == NULL){
        
        *root = node;
        return;
    }
    while (temp != NULL){

        if (data > temp->data){

            if (temp->right == NULL){
                
                temp->right = node;
                return;
            }
            else {
                temp = temp->right;
            }

        }
        else if (data < temp->data){

            if (temp->left == NULL){

                temp->left = node;
                return;
            }
            else {
                temp = temp->left;
            }
        }
        else if (data == temp->data){

            return;
        }
    }
}

void largest_element(Node *root, int k){
    
    static int i = 0;

    if (root == NULL || i > k) {
        return;
    }

    largest_element(root->right, k);

    i = i + 1;

    if (i == k) {
        printf("Element: %d\n", root->data);
        return;
    }

    largest_element(root->left, k);

}

void main() {

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

    int k;

    printf("K: ");
    scanf("%d", &k);

    largest_element(root, k);
}
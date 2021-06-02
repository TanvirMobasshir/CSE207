#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

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

void inOrder(Node *root){
    
    if(root->left != NULL){

        inOrder(root->left);
    }

    printf("%d ", root->data);

    if(root->right != NULL){

        inOrder(root->right);
    }
}

int height(Node *node) {
    if (node != NULL) {
        int x = height(node->left);
        int y = height(node->right);

        if (x > y) {
            return x + 1;
        } else {
            return y + 1;
        }
    }

    return -1;
}

Node *pre(Node *node) {
    while (node != NULL && node->right) {
        node = node->right;
    }

    return node;
}

Node *succ(Node *node) {
    while (node != NULL && node->left) {
        node = node->left;
    }

    return node;
}

Node *r_del(Node **node, int key) {

    Node *temp;

    if ((*node) == NULL) {
        return NULL;
    }

    if (!(*node)->left && !(*node)->right) {
        free((*node));
        return NULL;
    }

    if (key > (*node)->data) {
        (*node)->right = r_del(&(*node)->right, key);

    } else if (key < (*node)->data) {
        (*node)->left = r_del(&(*node)->left, key);

    } else {
        if (height((*node)->left) > height((*node)->right)) {
            temp = pre((*node)->left);
            (*node)->data = temp->data;
            (*node)->left = r_del(&(*node)->left, temp->data);
        } else {
            temp = succ((*node)->right);
            (*node)->data = temp->data;
            (*node)->right = r_del(&(*node)->right, temp->data);
        }
    }

    return (*node);
}

void internal_delete(Node **node, int root_value) {

    if ((*node)) {

        if (((*node)->left || (*node)->right) && (*node)->data != root_value) {
            r_del(&(*node), (*node)->data);
        }

        internal_delete(&(*node)->left, root_value);

        internal_delete(&(*node)->right, root_value);
    }

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

    printf("Before deleting internal nodes: ");
    inOrder(root);
    printf("\nAfter deleting internal nodes: ");
    internal_delete(&root, root->data);
    inOrder(root);
    printf("\n");
}

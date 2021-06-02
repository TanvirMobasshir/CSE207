#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

    int data, height;
    struct Node *right, *left;
} Node;

int tree_height(Node *node) {

    int l_height, r_height;

    if (node != NULL && node->left != NULL){

        l_height = node->left->height;
    }
    else{

        l_height = 0;
    }

    if (node != NULL && node->right != NULL){

        r_height = node->right->height;
    }
    else{

        r_height = 0;
    }

    if (l_height > r_height) {

        return l_height + 1;
    }
    else{
        
        return r_height + 1;
    }
}

int balanceFactor(Node *node) {

    int l_height, r_height;

    if (node != NULL && node->left != NULL){

        l_height = node->left->height;
    }
    else{

        l_height = 0;
    }

    if (node != NULL && node->right != NULL){

        r_height = node->right->height;
    }
    else{

        r_height = 0;
    }

    return l_height - r_height;
}

Node *left_left_rotation(Node *node) {

    Node *lnode = node->left;
    Node *lnode_right = lnode->right;

    lnode->right = node;
    node->left = lnode_right;

    node->height = tree_height(node);
    lnode->height = tree_height(lnode);

    return lnode;
}

Node *right_right_rotation(Node *node) {

    Node *rnode = node->right;
    Node *rnode_left = rnode->left;

    rnode->left = node;
    node->right = rnode_left;

    node->height = tree_height(node);
    rnode->height = tree_height(rnode);

    return rnode;
}

Node *left_right_rotation(Node *node) {

    Node *lnode = node->left;
    Node *lnode_right = lnode->right;

    lnode->right = lnode_right->left;
    node->left = lnode_right->right;

    lnode_right->right = node;
    lnode_right->left = lnode;

    lnode->height = tree_height(lnode);
    node->height = tree_height(node);
    lnode_right->height = tree_height(lnode_right);

    return lnode_right;
}

Node *right_left_rotation(Node *node) {

    Node *rnode = node->right;
    Node *rnode_left = rnode->left;

    rnode->left = rnode_left->right;
    node->right = rnode_left->left;

    rnode_left->right = rnode;
    rnode_left->left = node;

    rnode->height = tree_height(rnode);
    node->height = tree_height(node);
    rnode_left->height = tree_height(rnode_left);

    return rnode_left;
}

Node *push(Node *node, int value) {

    Node *new_node;

    if (node == NULL) {

        new_node = (Node *) malloc(sizeof(Node));
        new_node->data = value;
        new_node->height = 1;
        new_node->left = new_node->right = NULL;
        return new_node;
    }

    if (value > node->data) {

        node->right = push(node->right, value);
    } 
    else if (value < node->data) {

        node->left = push(node->left, value);
    }

    node->height = tree_height(node);

    if (balanceFactor(node) == 2 && balanceFactor(node->left) == 1) {

        return left_left_rotation(node);
    } 
    else if (balanceFactor(node) == 2 && balanceFactor(node->left) == -1) {

        return left_right_rotation(node);
    } 
    else if (balanceFactor(node) == -2 && balanceFactor(node->right) == -1) {

        return right_right_rotation(node);
    } 
    else if (balanceFactor(node) == -2 && balanceFactor(node->right) == 1) {

        return right_left_rotation(node);
    }
    return node;
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

int main() {

    Node *root = NULL;

    int n, node_data;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter data(s) of the node(s): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &node_data);
        root = push(root, node_data);
    }

    inOrder(root);
    printf("\n");

    return 0;
}
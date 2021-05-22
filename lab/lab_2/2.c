#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node * create_node(int node_number, struct Node *first_node, int *data_list){

    struct Node *prev_node, *node;

    first_node->data = data_list[0];
    first_node->next = NULL;
    prev_node = first_node;

    for (int i = 1; i < node_number; i++){
    
        node = (struct Node *)malloc(sizeof(struct Node));
        node->data = data_list[i];
        node->next = NULL;
        prev_node->next = node;
        prev_node = node;
    }

    return node;
}

void display_node(struct Node *first_node){

    int i = 1;
    while (first_node != NULL){

        printf(" data %d: %d\n", i, first_node->data);
        first_node = first_node->next;
        i++;
    }
}

void display_node_reverse(struct Node *first_node){

    if (first_node == NULL)
        return;

    display_node_reverse(first_node->next);
    printf(" data: %d\n", first_node->data);
}

void main(){

    int node_number, *data_list;

    printf("Input the number of nodes: ");
    scanf("%d", &node_number);

    for (int i = 0; i < node_number; i++){
        
        printf(" Input data for node %d: ", i+1);
        scanf("%d", data_list+i);
    }

    struct Node *first_node = (struct Node *)malloc(sizeof(struct Node)), *last_node;
    last_node = create_node(node_number, first_node, data_list);

    printf("\n");
    printf("\nData entered in the list:\n");
    display_node(first_node);
    printf("\nThe list in reverse: \n");
    display_node_reverse(first_node);
    printf("\n");
}
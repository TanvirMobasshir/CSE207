#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void create_node(int node_number, struct Node *first_node, int *data_list){

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
}

void display_node(struct Node *first_node){

    int i = 1;
    printf("\nData entered in the list:\n");
    while (first_node != NULL){

        printf(" data %d: %d\n", i, first_node->data);
        first_node = first_node->next;
        i++;
    }
}

void main(){

    int node_number, *data_list = (int *)malloc(sizeof(int));

    printf("Input the number of Nodes: ");
    scanf("%d", &node_number);
    printf("\n");
    
    for (int i = 0; i < node_number; i++){
        printf(" Input data for node %d: ", i + 1);
        scanf("%d", data_list + i);
    }

    struct Node *first_node = (struct Node *)malloc(sizeof(struct Node));

    create_node(node_number, first_node, data_list);
    display_node(first_node);
    printf("\n");
}

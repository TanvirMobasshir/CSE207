#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void create_node(int node_number, struct Node *first_node, int *data_list){

    struct Node *node, *current_node = first_node;

    for (int i = 1; i < node_number; i++){
    
        node = (struct Node *)malloc(sizeof(struct Node));
        node->data = *(data_list+i);
        node->next = NULL;

        current_node->next = node;
        current_node = node;
    }
}

void display(struct Node *first_node){

    while(first_node != NULL){

        printf(" Data = %d\n", first_node->data);
        first_node = first_node->next;
    }
}

int count(struct Node *first_node){

    int count = 0;
    while(first_node != NULL){

        count++;
        first_node = first_node->next;
    }
    return count;
}

void main(){
    
    int node_number, *data_list = (int *)malloc(sizeof(int));

    printf("Input the number of nodes: ");
    scanf("%d", &node_number);

    for (int i = 0; i < node_number; i++){
    
        printf(" Input data for node %d: ", i+1);
        scanf("%d", data_list+i);
    }

    struct Node *first_node = (struct Node *)malloc(sizeof(struct Node));

    first_node->data = *(data_list);
    first_node->next = NULL;
    create_node(node_number, first_node, data_list);
    printf("\nData entered in the list are :\n");
    display(first_node);
    printf(" Total number of nodes = %d\n", count(first_node));
}
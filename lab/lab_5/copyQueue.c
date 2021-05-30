#include<stdio.h>
#include<stdlib.h>

struct Node{

    int data;
    struct Node *next;
};

void enqueue(struct Node **front, struct Node **rear, int data){

    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;

    if (*front == NULL){

        *front = node;
        *rear = node;
    }
    else {

        (*rear)->next = node;
        *rear = node;
    }
}

void display(struct Node *head){

    if (head == NULL){

        printf("The queue is empty.\n\n");
        return;
    }

    while (head != NULL){
    
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void copyQueue(struct Node *head){

    struct Node *cfront = NULL, *crear = NULL;

    while (head != NULL){

        enqueue(&cfront, &crear, head->data);
        head = head->next;
    }
    printf("Q2: ");
    display(cfront);
}

void main(){

    struct Node *front = NULL, *rear = NULL;

    int data_size, data;
    printf("Enter the Number of elements: ");
    scanf("%d", &data_size);

    for (int i = 0; i < data_size; i++){
    
        scanf("%d", &data);
        enqueue(&front, &rear, data);
    }
    printf("Q1: ");
    display(front);
    copyQueue(front);
}
#include<stdio.h>
#include<stdlib.h>

struct Node{

    int data;
    struct Node *next;
};

void insertion(struct Node **head, int data){

    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = *head;
    *head = node;
}

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

void copyStackToQueue(struct Node *stackHead, struct Node **front, struct Node **rear){

    while (stackHead != NULL){

        enqueue(front, rear, stackHead->data);
        stackHead = stackHead->next;
    }
}

void display(struct Node *head){

    if (head == NULL){

        printf("The list is empty.\n\n");
        return;
    }

    while (head != NULL){
    
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void main(){

    struct Node *front = NULL, *rear = NULL, *head = NULL;

    int data_size, data;
    printf("Enter the Number of elements: ");
    scanf("%d", &data_size);

    printf("S: ");
    for (int i = 0; i < data_size; i++){
    
        scanf("%d", &data);
        insertion(&head, data);
    }
    
    copyStackToQueue(head, &front, &rear);
    printf("Q: ");
    display(front);
}
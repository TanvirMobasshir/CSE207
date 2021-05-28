#include<stdio.h>
#include<stdlib.h>

struct Node{

    int data;
    struct Node *next;
};

void enqueue(struct Node **front, struct Node **rear){

    int data;
    printf("Input a data: ");
    scanf("%d", &data);

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
    printf("\n");
}

void dequeue(struct Node **front){

    if (*front == NULL){

        printf("There is no data in the queue!!\n\n");
        return;
    }
    else {
        *front = (*front)->next;
    }
}

void display(struct Node *head){

    if (head == NULL){

        printf("The queue is empty.\n\n");
        return;
    }

    while (head != NULL){
    
        printf("data: %d\n", head->data);
        head = head->next;
    }
    printf("\n");
}

void main(){

    struct Node *front = NULL, *rear = NULL;

    int a;

a:
    printf("choose something:\n");
    printf("\t1. insert data\n\t2. print queue\n\t3. dequeue\n\t4. terminate\n");
    scanf("%d", &a);

    switch (a)
    {
    case 1:
        enqueue(&front, &rear);
        goto a;
        scanf("%d", &a);
    
    case 3:
        dequeue(&front);
        goto a;
        scanf("%d", &a);

    case 2:
        display(front);
        goto a;
        scanf("%d", &a);

    case 4:
        return;

    default:
        printf("\nwrong option, choose again\n");
        printf("\n");
        goto a;
    }
}
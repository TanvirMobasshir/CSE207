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

int dequeue(struct Node **front){

    int result = 0;

    if (*front == NULL){

        printf("There is no data in the queue!!\n\n");
    }
    else {
        result = (*front)->data;
        *front = (*front)->next;
    }
    return result;
}

void deleteNegative(struct Node **front, struct Node **rear){

    int data_size = 1, temp;
    int *datalist = (int *)malloc(data_size * sizeof(int));

    while ((*front) != NULL){

        if ((*front)->data >= 0){

            *(datalist + (data_size-1)) = dequeue(front);
            data_size++;
            datalist = (int *)realloc(datalist, data_size * sizeof(int));
        }
        else {

            temp = dequeue(front);
        }
    }
 
    for (int i = 0; i < data_size-1; i++){

        enqueue(front, rear, *(datalist+i));
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

    struct Node *front = NULL, *rear = NULL;

    int data_size, data;
    printf("Enter the Number of elements: ");
    scanf("%d", &data_size);

    printf("Q: ");
    for (int i = 0; i < data_size; i++){
    
        scanf("%d", &data);
        enqueue(&front, &rear, data);
    }

    deleteNegative(&front, &rear);
    printf("Q: ");
    display(front);  
}
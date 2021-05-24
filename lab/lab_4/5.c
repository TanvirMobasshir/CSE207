#include<stdio.h>
#include<stdlib.h>

struct Node{

    int data;
    struct Node *next;
};

void insertion(struct Node **head, int a){

    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = a;
    node->next = *head;
    *head = node;
}

void binary_convert(struct Node **head, int decimal){

    while (decimal != 0){
        
        insertion(head, decimal%2);
        decimal = decimal/2;
    }   
}

void display(struct Node *first){

    printf("Binary: ");
    while (first != NULL)
    {
        printf("%d", first->data);
        first = first->next;
    } 
    printf("\n\n");
}

void main(){

    int decimal;
    printf("Enter the decimal number: ");
    scanf("%d", &decimal);

    struct Node *head = NULL;
    binary_convert(&head, decimal);
    display(head);
}
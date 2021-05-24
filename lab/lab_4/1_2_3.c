#include<stdio.h>
#include<stdlib.h>

struct Node{

    int data;
    struct Node *next;
};

void insertion(struct Node **head){

    int a;
    printf("\ninput data: ");
    scanf("%d", &a);

    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = a;
    node->next = *head;
    *head = node;
}

void deletion(struct Node **head){

    if (*head == NULL)
    {
        printf("\nThe list is empty!!\n");
        return;
    }
    

    struct Node *temp = *head;

    *head = temp->next;
    free(temp);
}

void display(struct Node *first){

    if (first == NULL){

        printf("\nThe list is empty!!\n");
        return;
    }

    printf("\n");
    while (first != NULL)
    {
        printf("data: %d\n", first->data);
        first = first->next;
    } 
    printf("\n");
}

int main(){

    struct Node *head = NULL;
    int a;

a:
    printf("choose something:\n");
    printf("\t1. insert data/push stack\n\t2. print stack\n\t3. pop\n\t4. terminate\n");
    scanf("%d", &a);

    switch (a)
    {
    case 1:
        insertion(&head);
        printf("\n");
        goto a;
        scanf("%d", &a);
    
    case 3:
        deletion(&head);
        printf("\n");
        goto a;
        scanf("%d", &a);

    case 2:
        display(head);
        goto a;
        scanf("%d", &a);

    case 4:
        return 0;

    default:
        printf("\nwrong option, choose again\n");
        printf("\n");
        goto a;
    }
}

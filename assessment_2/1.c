#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{

    char data;
    int data_indx;
    int data_count;
    struct Node *next;
};

void insertion(struct Node **head, char a, int data_indx, int lcount){

    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = a;
    node->data_indx = data_indx;
    node->data_count = lcount;
    node->next = *head;
    *head = node;
}

int get_index(struct Node *head, int count){

    while (head != NULL){

        if (head->data_count == count){
            
            return head->data_indx;
        }
        head = head->next;
    }
}

void parentheses_check(struct Node **head, char *str, int index){

    int data_indx = 0;
    int lcount = 0;

    for (int i = 0; *(str+i) != '\0'; i++){

        if (*(str + i) == ']'){

            lcount++;
            insertion(head, *(str + i), data_indx, lcount);
        }
        data_indx++;
    }

    int count = 0;

    for (int i = 0; i <= index; i++){

        if (*(str + i) == '['){
        
            count++;
        }
    }

    printf("%d\n", get_index(*head, count));
}

void main(){

    struct Node *head = NULL;

    char *str = (char *)malloc(100 * sizeof(char));
    int index;
    printf("string = ");
    scanf("%s", str);
    printf("index = ");
    scanf("%d", &index);
    parentheses_check(&head, str, index);
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{

    char data;
    struct Node *next;
};

void insertion(struct Node **head, char a){

    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = a;
    node->next = *head;
    *head = node;
}

int deletion(struct Node **head){

    if (*head == NULL){

        return -1;
    }
    
    struct Node *temp = *head;
    *head = temp->next;
    free(temp);
    return 1;
}

int isNodeNull(struct Node *head){

    if (head == NULL){

        return 0;
    } 
    else {
        return 1;
    }
}

void parentheses_check(char *str){

    struct Node *head = NULL;

    for (int i = 0; *(str+i) != '\0'; i++){

        if (*(str + i) == '('){

            insertion(&head, *(str + i));
        }
        else if (*(str + i) == ')'){
            
            if (isNodeNull(head) == 0){

                printf("Closing parantheses not matched\n\n");
                break;
            }
            else{

                deletion(&head);
            }
        }
    }
    
    if (isNodeNull(head) == 1){

        printf("Openning parantheses not end\n\n");
    };
}

int main(){

    char *str = (char *)malloc(100 * sizeof(char));
    printf("Enter the string: ");
    scanf("%s", str);
    parentheses_check(str);
}
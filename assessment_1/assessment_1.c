#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void add_begining(struct Node **head){

    int new_data;
    printf("Input data at the begining: ");
    scanf("%d", &new_data);

    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
  
    node->data  = new_data;
    node->next = *head;
    *head = node;
}

void add_end(struct Node **head){

    int new_data;
    printf("Input data at the end: ");
    scanf("%d", &new_data);
    
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    struct Node *last = *head;
    
    node->data  = new_data;
    node->next = NULL;

    if (*head == NULL){
       *head = node;
       return;
    }

    while (last->next != NULL){
        last = last->next;
    }
  
    last->next = node;
}

void add_middle(struct Node *head){

    if (head == NULL)
    {
      printf("List is empty. Insert some value first.\n");
      return;
    }

    int key, new_data;
    printf("Input data: ");
    scanf("%d", &new_data);
    printf("Enter the previous data of the inseted data: ");
    scanf("%d", &key);
  
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    struct Node *temp = head, *prev;

    node->data = new_data;
    node->next = NULL;

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL){

        if (temp->data == key){

            node->next = temp->next;
            temp->next = node;
        }
    }    
    else{
        printf("Data doesn't exist on the List.\n");
    }
}

void delete_begining(struct Node **head){

    if (*head == NULL){
        printf("List is empty, Insert some value first.\n");
        return;
    }

    struct Node *temp = *head;
    
    *head = temp->next;
    free(temp);
}

void delete_middle(struct Node **head){

    if (*head == NULL){
        printf("List is empty, Insert some value first.\n");
        return;
    }

    int key;
    printf("Enter the data you want to delete: ");
    scanf("%d", &key);

    struct Node *temp = *head, *prev;
 
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }
 
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
 
    if (temp == NULL){

        printf("Value doesn't exist in the list\n");
    }
    else{
        prev->next = temp->next;
        free(temp);
    }
}

void delete_end(struct Node *head){

    if (head == NULL){
        printf("List is empty, Insert some value first.\n");
        return;
    }
    else if(head->next == NULL){
        free(head);
    }

    struct Node *temp;
    temp = head;

    while (temp->next->next !=NULL){

        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

void display_node(struct Node *first_node){

    if (first_node == NULL){

        printf("List is empty, insert some value first.\n\n");
    }

    else{
        
        int i = 1;
        printf("\nData entered in the list:\n");
        while (first_node != NULL){

            printf(" data %d: %d\n", i, first_node->data);
            first_node = first_node->next;
            i++;
        }
    }
}

void search(struct Node *head){

    if (head == NULL){
        printf("List is empty, Insert some value first.\n");
        return;
    }

    int count = 1, search_data;
    struct Node *temp, *prev;
    temp = head;

    printf("Input the data you want to search: ");
    scanf("%d", &search_data);

    while (temp != NULL && temp->data != search_data) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (temp != NULL){
    
        if (temp->data == search_data){
        
            printf("The position of your data in the linked list is: %d\n", count);
        } 
    }
    else{
        printf("Data doesn't exist\n");
        return;
    }
    
    

}

int main(){

    struct Node *head = NULL;
    char *str1 = "\nPlease insert your option:\n\n\t"
                    "1.Insert Node at the beginning\n\t"
                    "2.Insert Node at the end\n\t"
                    "3.Insert Node at the Middle\n\t"
                    "4.Delete Node from beginning\n\t"
                    "5.Delete Node from End\n\t"
                    "6.Delete Node from Middle\n\t"
                    "7.Display the List\n\t"
                    "8.Find a Value From the List\n\t"
                    "9.Exit your code\n";
                
    puts(str1);

    int user_choice;
    scanf("%d", &user_choice);

    while (user_choice > 0 || user_choice < 10){
    
        if (user_choice == 1){

            add_begining(&head);
            puts(str1);
            scanf("%d", &user_choice);
        }

        else if (user_choice == 2){

            add_end(&head);
            puts(str1);
            scanf("%d", &user_choice);
        }

        else if (user_choice == 3){

            add_middle(head);
            puts(str1);
            scanf("%d", &user_choice);
        }

        else if (user_choice == 4){

            delete_begining(&head);
            puts(str1);
            scanf("%d", &user_choice);
        }

        else if (user_choice == 5){

            delete_end(head);
            puts(str1);
            scanf("%d", &user_choice);
        }

        else if (user_choice == 6){

            delete_middle(&head);
            puts(str1);
            scanf("%d", &user_choice);
        }

        else if (user_choice == 7){

            display_node(head);
            puts(str1);
            scanf("%d", &user_choice);
        }

        else if (user_choice == 8){

            search(head);
            puts(str1);
            scanf("%d", &user_choice);
        }

        else if (user_choice == 9){

            printf("program terminated\n");
            break;
        }

        else{
            printf("You input is wrong, please choice between 1-9\n");
            scanf("%d", &user_choice);
        }
    }

}

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void create(int *array, int n, struct Node *first_node) {
    struct Node *node, *current_node;
    first_node->data = array[0];
    first_node->next = NULL;
    current_node = first_node;

    for (int i = 1; i < n; i++) {
        node = (struct Node *) malloc(sizeof(struct Node));
        node->data = array[i];
        node->next = NULL;
        current_node->next = node;
        current_node = node;
    }
}


void display(struct Node *node) {
    printf("Data entered in the list : \n");

    while (node != NULL) {
        printf("Data = %d\n", node->data);
        node = node->next;
    }
}

int main() {
    int n;

    printf("Input the number of nodes : ");
    scanf("%d", &n);

    int *array = (int *) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        printf("Input data for node %d : ", i + 1);
        scanf("%d", array + i);
    }

    struct Node *first_node;
    first_node = (struct Node *) malloc(sizeof(struct Node));

    create(array, n, first_node);

    display(first_node);

    return 0;
}

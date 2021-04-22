#include<stdio.h>

int search(int n, int *data, int search_element){
    for (int i = 0; i < n; i++){

        if (data[i] == search_element){
            return i;
        }
    }
}

void main(){

    int n, *data, search_element;

    printf("How manydata do you want to input: ");
    scanf("%d", &n);

    printf("Input the data: ");

    for (int i = 0; i < n; i++){

        scanf("%d", (data+i));
    }

    printf("What element do you want to search: ");
    scanf("%d", &search_element);
    printf("Your element is found in position %d\n\n", search(n, data, search_element));
}
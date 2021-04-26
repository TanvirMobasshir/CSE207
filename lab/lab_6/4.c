#include<stdio.h>

void swap(int *x, int *y){

    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void bubble_sort(int n, int *data){

    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){       
            if (*(data+j) < *(data+i)){
                swap(data+i, data+j);
            }
        }
    }
}

void main(){

    int n, *data;
    printf("How many data do you want to input: ");
    scanf("%d", &n);

    printf("Input the data: ");

    for (int i = 0; i < n; i++){

        scanf("%d", (data+i));
    }

    bubble_sort(n, data);

    printf("Sorted List: ");
    for (int i = 0; i < n; i++){

        printf("%d ", *(data+i));
    }
    printf("\n");

}
#include<stdio.h>

void swap(int *x, int *y){

    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void selection_sort(int n, int *data){
    
    int min_indx;
    for (int i = 0; i < n; i++){
        min_indx = i;
        for (int j = i; j < n; j++){       
            if (data[j] < data[min_indx]){
                min_indx = j;
            }
        }
        swap(data+min_indx, data+i);
    }
}

void main(){

    int n, *data;
    printf("How manydata do you want to input: ");
    scanf("%d", &n);

    printf("Input the data: ");

    for (int i = 0; i < n; i++){

        scanf("%d", (data+i));
    }

    selection_sort(n, data);

    printf("Sorted List: ");
    for (int i = 0; i < n; i++){

        printf("%d ", data[i]);
    }
    printf("\n");

}
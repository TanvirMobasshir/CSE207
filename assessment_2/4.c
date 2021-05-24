#include<stdio.h>

void swap(int *x, int *y){

    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void selection_sort(int n, int *data){
    
    int max_indx;
    for (int i = 0; i < n; i++){
        max_indx = i;
        for (int j = i; j < n; j++){       
            if (*(data+j) > *(data+max_indx)){
                max_indx = j;
            }
        }
        swap(data+max_indx, data+i);
    }
}

void main(){

    int n, *data;
    printf("Enter total input: ");
    scanf("%d", &n);

    printf("Enter the numbers: ");

    for (int i = 0; i < n; i++){

        scanf("%d", (data+i));
    }

    selection_sort(n, data);

    printf("Descending orders are: ");
    for (int i = 0; i < n; i++){

        printf("%d", *(data+i));
        
        if (i != n-1){
            printf(", ");
        }
    }
    printf("\n");
}
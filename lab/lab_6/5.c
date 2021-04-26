#include<stdio.h>

void insertion_sort(int n, int *data)
{
    int key, j;
    for (int i = 1; i < n; i++) {
        key = *(data+i);
        j = i - 1;
 
        while (j >= 0 && *(data+j) > key) {
            *(data+j+1) = *(data+j);
            j = j - 1;
        }
        *(data+j+1) = key;
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

    insertion_sort(n, data);

    printf("Sorted list in reverse order: ");
    for (int i = n-1; i >= 0; i--){

        printf("%d ", data[i]);
    }
    printf("\n");

}
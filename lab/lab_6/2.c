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
            if (data[j] < data[i]){
                swap(&data[i], &data[j]);
            }
        }
    }
}

int binary_search(int n, int *data, int search_element){
    int start = 0, end = n-1;
    int index;

    while (end>=start){
    
        index = (end-start)/2 + start;

        if (data[index] == search_element){
            return index;
        }
        else if (data[index] < search_element){
            start = index + 1;
        }
        else if (data[index] > search_element){
            end = index - 1;
        }
        else{
            return 0;
        }
    }
}

void main(){

    int n, *data, search_element;
    printf("How many data do you want to input: ");
    scanf("%d", &n);

    printf("Input the data: ");

    for (int i = 0; i < n; i++){

        scanf("%d", (data+i));
    }

    printf("What element do you want to search: ");
    scanf("%d", &search_element);
    
    bubble_sort(n, data);
    int result = binary_search(n, data, search_element);

    if (result != 0){
        printf("Your element is found in positin %d", result);
    }
    else{
        printf("No such element!!");
    }
    

    printf("\n\n");

}
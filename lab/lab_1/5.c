#include<stdio.h>

int sum_array(int *a, int n){

    int i = 0, sum = 0;

    while (i<n){

        sum = sum + *a;
        i++;
        a++;
    }
    
    return sum;

}

void main(){

    printf("Input the number of elements to store in array (max 10): ");

    int n, i = 0;;
    scanf("%d", &n);

    printf("\nInput %d number of elements in the array: \n", n);
    int a[n];

    while (i<n){
    
        printf("element %d: ", i+1);
        scanf("%d", &a[i]);
        i++;
    }

    printf("\nThe sum of the array is: %d\n\n\n", sum_array(a, n));
    
}
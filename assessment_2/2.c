#include<stdio.h>
#include<stdlib.h>

void main(){

    int n;
    
    printf("Total number of values: ");
    scanf("%d", &n);

    int *dataset = (int *)malloc(n * sizeof(int));
    int *queue = (int *)malloc(n * sizeof(int));
}
#include<stdio.h>

int max(int *x, int *y)
{
    if(*x>*y){
        return *x;
    }
    else if(*y>*x){
        return *y;
    }
}

void main()
{    
    int first_number, second_number;

    printf("Input the first number: ");
    scanf("%d", &first_number);

    printf("Input the second number: ");
    scanf("%d", &second_number);

    printf("%d is the maximum number\n\n", max(&first_number, &second_number));

}


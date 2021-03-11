#include<stdio.h>

int add(int *x, int *y)
{
    return *x + *y;
}

void main()
{
    int first_number, second_number;

    printf("Input the first number: ");
    scanf("%d", &first_number);

    printf("Input the second number: ");
    scanf("%d", &second_number);

    printf("The sum of the entered numbers is: %d\n\n", add(&first_number, &second_number));

}


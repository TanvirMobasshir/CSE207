#include<stdio.h>

void swap_elements(int *x, int *y, int *z)
{
    int temp;

    temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;

}
void main()
{
    int first_element, second_element, third_elemnent;

    printf("Input the value of first element: ");
    scanf("%d", &first_element);

    printf("Input the value of second element: ");
    scanf("%d", &second_element);

    printf("Input the value of third element: ");
    scanf("%d", &third_elemnent);
    
    printf("\nThe value before swapping are:\n");
    printf("element 1: %d\n", first_element);
    printf("element 2: %d\n", second_element);
    printf("element 3: %d\n", third_elemnent);
    
    swap_elements(&first_element, &second_element, &third_elemnent);
    
    printf("\nThe value after swapping are:\n");
    printf("element 1: %d\n", first_element);
    printf("element 2: %d\n", second_element);
    printf("element 3: %d\n\n", third_elemnent);

}

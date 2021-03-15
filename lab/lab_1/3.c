#include<stdio.h>

void check_letter(char *a){

    int v_count = 0, c_count = 0;

    while (*a != '\0'){
    
        if(*a == 'a' || *a == 'e' || *a == 'i' || *a == 'o' || *a == 'u' || 
           *a == 'A' || *a == 'E' || *a == 'I' || *a == 'O' || *a == 'U'){
            v_count++;
        }
        else{
            c_count++;
        }
        a++;
    }

    printf("Number of vowels: %d\n", v_count);
    printf("Number of consonants: %d\n\n\n", c_count);
    
}

void main(){

    char a[200];

    printf("Input a string: ");
    scanf("%s", a);

    check_letter(a);
}
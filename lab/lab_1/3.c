#include<stdio.h>

void check_letter(char *p){

    int c_count = 0, v_count = 0;

    while (*p != '\0'){

        if (*p == 'a' || *p == 'e' || *p == 'i' || *p == 'o' || *p == 'u' || 
        *p == 'A' || *p == 'E' || *p == 'I' || *p == 'O' || *p == 'U'){
             v_count++;
         }
         else{
             c_count++;
         }
         p++;

    }
    
    printf("\nNumber of vowels: %d\n", v_count);
    printf("Number of consonants: %d\n\n\n", c_count);

}


void main(){

    char a[200];

    printf("Enter a String: ");
    scanf("%s", a);

    check_letter(a);

}
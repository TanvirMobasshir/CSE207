#include<stdio.h>

int prime(int a, int b){

    if(b == 1){
        return 1;
    }
    else if(a%b == 0){
        return 0;
    }
    return prime(a, b-1);
}

void main(){

    int result1 = prime(58, 58-1);
    int result2 = prime(47, 47-1);
    
    if (result1 == 0){
        printf("58 is not prime number\n");
    }
    else{
        printf("58 is prime number\n");
    }

     if (result2 == 0){
        printf("47 is not prime number\n");
    }
    else{
        printf("47 is prime number\n");
    }
}
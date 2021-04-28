#include<stdio.h>

int factorial(int a){

    if(a == 1){
        return a;
    }
    return a * factorial(a-1);
}

void main(){

    printf("%d\n", factorial(5));
}
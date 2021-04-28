#include<stdio.h>

int product(int a, int b){
    if(b == 0){
        return 0;
    }
    return a + product(a, b-1);
}

void main(){

    printf("%d\n", product(100,4));
}
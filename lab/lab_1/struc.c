#include<stdio.h>
#include<math.h>

struct Point{
    float x, y;
};

float distance(struct Point A, struct Point B){
    return sqrt(pow((A.x - B.x), 2) + pow((A.y - B.y), 2));
}

void main(){
    struct Point point1, point2;

    printf("Input point A: ");
    scanf("%f %f", &point1.x, &point1.y);
    printf("Input point B: ");
    scanf("%f %f", &point2.x, &point2.y);

    printf("Distance is: %f\n\n", distance(point1, point2));
    
}
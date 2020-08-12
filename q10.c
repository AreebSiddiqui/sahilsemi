#include<stdio.h> 

float distance_covered(float u, float v, float d) {
    float distance = (u*v*d)/((v*v) - (u*u));
        return distance;
}

int take_input () {
    float u,v,d; 

    printf("Enter velocity of Tom:");
    scanf("%f",&u);

    printf("Enter velocity of Jerry:");
    scanf("%f",&v);
    
    printf("Distance between Tom and Jerry:");
    scanf("%f",&d);


    float result = distance_covered(u,v,d);
    printf("\nThe distance covered by Jerry will be: [ %f m ]\n", result);

}

int main() {
    take_input();
}

#include<stdio.h> 
#include <stdbool.h>
float time_covered (float u, float v, float d) {
    float time = (v*d)/((v*v) - (u*u));
        return time;
}

float distance_covered(float u, float v, float d) {
    float distance = u * time_covered(u,v,d);
        return distance;
}

int take_input () {
    float u,v,d;
    bool cal = true; 
    //Exception: 
    //v will be always greater than u.
    //speed of Jerry will always be greater than Tom.
    //If Jerry wants to catch Tom.
    
   do
    {
    printf("\nEnter velocity of Tom:");
    scanf("%f",&u);

    printf("Enter velocity of Jerry:");
    scanf("%f",&v);
    if (v<u) {
        printf("\n\nExcpetion:\n");
        printf("- Jerry can never catch Tom, as Tom is running with higher velocity.\n- Jerry should always run faster than Tom in order to catch him.");
        printf("\n\n--- Program-restarted ---\n");
        cal = false;
    }
    
    else{ 
    printf("Distance between Tom and Jerry:");
    scanf("%f",&d);
    

    float time = time_covered(u,v,d);
    float distance = distance_covered(u,v,d);
    
    printf("\nThe time taken by Jerry will be: [ %f s ]\n", time);
    printf("\nThe distance covered by Jerry will be: [ %f m ]\n", distance);
    cal = true;

    }
    } 
    while (!cal); 
    
}

int main() {
    take_input();
}

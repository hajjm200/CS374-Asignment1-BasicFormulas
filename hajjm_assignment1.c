#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

int main(){
  int n, i = 0;
    float R, ha, hb;
    float lateral, top, bottom, total_surface, volume;
    float sum_surface = 0.0, sum_volume = 0.0;

  do {
        printf("How many spherical segments you want to evaluate [2-10]? ");
        scanf("%d", &n);
    } while (n < 2 || n > 10);

  while (i<n){
    //obtain data for first segment
    printf("Obtaining data for spherical segment number %d\n", i + 1);
// what is radius
            printf("What is the radius of the sphere (R)? ");
        scanf("%f", &R);
//What is the Ha
                printf("What is the height of the top area of the spherical segment (ha)? ");
        scanf("%f", &ha);
//What is the Hb
        printf("What is the height of the bottom area of the spherical segment (hb)? ");
        scanf("%f", &hb);
        // print out the entered data 
         printf("Entered data: R = %.2f ha = %.2f hb = %.2f.\n", R, ha, hb);

        if (R <= 0 || ha <= 0 || hb <= 0 || ha > R || hb > R || hb > ha) {
            printf("Invalid Input.\n");
            continue;  // Ask for the same segment again
        }

        
  }
}

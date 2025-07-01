#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

int main() {
    int n, i = 0;
    float R, ha, hb;
    float top, bottom, lateral, total_surface, volume;
    float sum_surface = 0.0, sum_volume = 0.0;

    // Ask how many spherical segments to evaluate
    do {
        printf("How many spherical segments you want to evaluate [2-10]? ");
        scanf("%d", &n);
    } while (n < 2 || n > 10);

    // Loop through each spherical segment
    while (i < n) {
        printf("Obtaining data for spherical segment number %d\n", i + 1);

        // Input radius
        printf("What is the radius of the sphere (R)? ");
        scanf("%f", &R);

        // Input ha
        printf("What is the height of the top area of the spherical segment (ha)? ");
        scanf("%f", &ha);

        // Input hb
        printf("What is the height of the bottom area of the spherical segment (hb)? ");
        scanf("%f", &hb);

        // Validation
       if (R <= 0 || ha <= 0 || hb <= 0 || ha > R || hb > R || hb >= ha) {
    printf("Entered data: R = %.2f ha = %.2f hb = %.2f\n", R, ha, hb);
    printf("Invalid Input.\n");
    continue;  
}

        // Correct calculations using assignment formulas
        float h = ha - hb;
        float a = sqrt(R * R - ha * ha);
        float b = sqrt(R * R - hb * hb);

        top = PI * a * a;
        bottom = PI * b * b;
        lateral = 2 * PI * R * h;
        total_surface = top + bottom + lateral;

        volume = (PI / 6) * h * (3 * a * a + 3 * b * b + h * h);

        // Output result for current segment
        printf("Entered data: R = %.2f ha = %.2f hb = %.2f\n", R, ha, hb);
        printf("Total Surface Area = %.2f Volume = %.2f.\n", total_surface, volume);

        // Accumulate totals
        sum_surface += total_surface;
        sum_volume += volume;

        i++;  // Proceed to next segment
    }

    // Final average report
    printf("Total average results:\n");
    printf("Average Surface Area = %.2f Average Volume = %.2f\n", sum_surface / n, sum_volume / n);

    return 0;
}

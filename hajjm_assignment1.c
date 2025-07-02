#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

    // Ask how many spherical segments to evaluate
int get_number_of_segments() {
    int n;
    do {
        printf("How many spherical segments you want to evaluate [2-10]?\n");
        scanf("%d", &n);
    } while (n < 2 || n > 10);
    return n;
}

float get_radius(int n) {
    float R;
    printf("Obtaining data for spherical segment number %d\n", n);
    printf("What is the radius of the sphere (R)?\n");
    scanf("%f", &R);
    return R;
}

float get_ha() {
    float ha;
    printf("What is the height of the top area of the spherical segment (ha)?\n");
    scanf("%f", &ha);
    return ha;
}

float get_hb() {
    float hb;
    printf("What is the height of the bottom area of the spherical segment (hb)?\n");
    scanf("%f", &hb);
    return hb;
}

int validate_inputs(float R, float ha, float hb) {
    printf("Entered data: R = %.2f ha = %.2f hb = %.2f\n", R, ha, hb);
    if (R <= 0 || ha <= 0 || hb <= 0 || ha > R || hb > R || hb >= ha) {
        printf("Invalid Input.\n");
        return 0;  // invalid
    }
    return 1;  // valid
}

float calculate_h(float ha, float hb) {
    return ha - hb;
}

float calculate_a(float R, float ha) {
    return sqrt(R * R - ha * ha);
}

float calculate_b(float R, float hb) {
    return sqrt(R * R - hb * hb);
}

float calculate_top_surface(float a) {
    return PI * a * a;
}

float calculate_bottom_surface(float b) {
    return PI * b * b;
}

float calculate_lateral_surface(float R, float h) {
    return 2 * PI * R * h;
}

float calculate_total_surface(float top, float bottom, float lateral) {
    return top + bottom + lateral;
}

float calculate_volume(float h, float a, float b) {
    return (PI / 6) * h * (3 * a * a + 3 * b * b + h * h);
}

void print_segment_results(float R, float ha, float hb, float total_surface, float volume) {
    printf("Entered data: R = %.2f ha = %.2f hb = %.2f\n", R, ha, hb);
    printf("Total Surface Area = %.2f Volume = %.2f.\n", total_surface, volume);
}

void print_final_averages(float sum_surface, float sum_volume, int n) {
    printf("Total average results:\n");
    printf("Average Surface Area = %.2f Average Volume = %.2f\n", sum_surface / n, sum_volume / n);
}


int main() {
    int n = get_number_of_segments();
    int i = 0;
    float R, ha, hb;
    //float top, bottom, lateral, total_surface, volume;
    float sum_surface = 0.0, sum_volume = 0.0;

    

    // Loop through each spherical segment
    while (i < n) {
        float R = get_radius(i + 1);
        float ha = get_ha();
        float hb = get_hb();


        //Validate, if not invalid then continue
         if (!validate_inputs(R, ha, hb)) {
            continue;  // reprompt same segment if invalid
        }

        float h = calculate_h(ha, hb);
        float a = calculate_a(R, ha);
        float b = calculate_b(R, hb);

       float top = calculate_top_surface(a);
       float bottom = calculate_bottom_surface(b);
       float lateral = calculate_lateral_surface(R, h);
       float total_surface = calculate_total_surface(top, bottom, lateral);
       float volume = calculate_volume(h, a, b);

       print_segment_results(R, ha, hb, total_surface, volume);

        // Accumulate totals
        sum_surface += total_surface;
        sum_volume += volume;

        i++;  // Proceed to next segment
    }

    // Final average report
        print_final_averages(sum_surface, sum_volume, n);

    return 0;
}

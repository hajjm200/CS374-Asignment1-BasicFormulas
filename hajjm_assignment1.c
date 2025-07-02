#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

    // Function: get_number_of_segments()
    // Prompts the user for the number of spherical segments (2-10) and returns it.
int get_number_of_segments() {
    int n;
    do {
        printf("How many spherical segments you want to evaluate [2-10]?\n");
        scanf("%d", &n);
    } while (n < 2 || n > 10);
    return n;
}

    // Function: get_radius(int n)
    // Prompts the user for the radius R of the sphere for a given segment.
float get_radius(int n) {
    float R;
    printf("Obtaining data for spherical segment number %d\n", n);
    printf("What is the radius of the sphere (R)?\n");
    scanf("%f", &R);
    return R;
}

    // Function: get_ha()
    // Prompts the user for the height ha of the top area of the spherical segment.
float get_ha() {
    float ha;
    printf("What is the height of the top area of the spherical segment (ha)?\n");
    scanf("%f", &ha);
    return ha;
}

    // Function: get_hb()
    // Prompts the user for the height hb of the bottom area of the spherical segment.
float get_hb() {
    float hb;
    printf("What is the height of the bottom area of the spherical segment (hb)?\n");
    scanf("%f", &hb);
    return hb;
}

    // Function: validate_input(float R, float ha, float hb)
    // Validates the input values R, ha, and hb; returns 1 (valid) or 0 (invalid).
int validate_inputs(float R, float ha, float hb) {
    printf("Entered data: R = %.2f ha = %.2f hb = %.2f\n", R, ha, hb);
    if (R <= 0 || ha <= 0 || hb <= 0 || ha > R || hb > R || hb >= ha) {
        printf("Invalid Input.\n");
        return 0;  // invalid
    }
    return 1;  // valid
}

    // Function: calculate(float ha, float hb)
    // Calculates the vertical height (h) of the spherical segment from ha and hb.
float calculate_h(float ha, float hb) {
    return ha - hb;
}

    // Function: calculate_a(float R, float ha)
    // Calculates the radius of the top circular area (a) using R and ha.
float calculate_a(float R, float ha) {
    return sqrt(R * R - ha * ha);
}

    // Function: calculate_b(float R, float hb)
    // Calculates the radius of the bottom circular area (b) using R and hb.
float calculate_b(float R, float hb) {
    return sqrt(R * R - hb * hb);
}

    // Function: calculate_top_surface(float a)
    // Calculates the surface area of the top circle (π * a * a).
float calculate_top_surface(float a) {
    return PI * a * a;
}

    // Function: calculate_bottom_surface(float b)
    // Calculates the surface area of the bottom circle (π * b * b).
float calculate_bottom_surface(float b) {
    return PI * b * b;
}

    // Function: calculate_lateral_surface(float R, float h)
    // Calculates the lateral surface area (2 * π * R * h).
float calculate_lateral_surface(float R, float h) {
    return 2 * PI * R * h;
}

    // Function: calculate_total_surface(float top, float bottom, float lateral)
    // Calculates the lateral surface area (2 * π * R * h).
float calculate_total_surface(float top, float bottom, float lateral) {
    return top + bottom + lateral;
}

    // Function: calculate_volume(float h, float a, float b)
    // Calculates the volume of the spherical segment.
float calculate_volume(float h, float a, float b) {
    return (PI / 6) * h * (3 * a * a + 3 * b * b + h * h);
}

    // Function: print_segment_results(float R, float ha, float hb, float total_surface, float volume)
    // Prints the results of a single spherical segment's calculations.
void print_segment_results(float R, float ha, float hb, float total_surface, float volume) {
    printf("Entered data: R = %.2f ha = %.2f hb = %.2f\n", R, ha, hb);
    printf("Total Surface Area = %.2f Volume = %.2f.\n", total_surface, volume);
}

    // Function: print_final_averages(float sum_surface, float sum_volume, int n)
    // Prints the final average surface area and volume over all segments.

void print_final_averages(float sum_surface, float sum_volume, int n) {
    printf("Total average results:\n");
    printf("Average Surface Area = %.2f Average Volume = %.2f\n", sum_surface / n, sum_volume / n);
}


int main() {
    int n = get_number_of_segments();
    int i = 0;
    float R, ha, hb;
    float sum_surface = 0.0, sum_volume = 0.0;

    // Loop through each spherical segment
    while (i < n) {
        float R = get_radius(i + 1);
        float ha = get_ha();
        float hb = get_hb();


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

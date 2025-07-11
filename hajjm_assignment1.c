#include <stdio.h>
#include <math.h>

#define PI 3.14159265359


/* Prompts the user for the number of spherical segments (2-10) and returns it.
* Parameters: None
* Returns: the number n of segments 
*/
int get_number_of_segments() {
    int n;
    do {
        printf("How many spherical segments you want to evaluate [2-10]?\n");
        scanf("%d", &n);
    } while (n < 2 || n > 10);
    return n;
}

/*
 * Prompts the user to enter the radius of a spherical segment.
 * First prints a message indicating which segment’s radius is being obtained, then reads and returns the radius entered by the user
 * Parameters: The index number of the spherical segment.
 * Returns: The radius R entered by the user.
 */
float get_radius() {
    float R;
    printf("What is the radius of the sphere (R)?\n");
    scanf("%f", &R);
    return R;
}

/*
 * Prompts the user to enter the height of the top area (ha) of the spherical segment.
 * Prints a message asking for the height, then reads and returns the height entered by the user.
 * Parameters: NA
 * Returns: The height ha entered by the user.
 */
float get_ha() {
    float ha;
    printf("What is the height of the top area of the spherical segment (ha)?\n");
    scanf("%f", &ha);
    return ha;
}

   /*
 * Prompts the user to enter the height of the bottom area (hb) of the spherical segment.
 * Prints a message asking for the height, then reads and returns the height entered by the user.
 * Parameters: NA
 * Returns: The height hb entered by the user.
 */
float get_hb() {
    float hb;
    printf("What is the height of the bottom area of the spherical segment (hb)?\n");
    scanf("%f", &hb);
    return hb;
}

/*
 * Validates the input values R, ha, and hb for a spherical segment.
 * Checks that all values are positive, ha and hb do not exceed R, and that hb is less than ha. Prints "Invalid Input." if any
 * condition fails.
 * Parameters:
 *   R: The radius of the sphere.
 *   ha: The height of the top area.
 *   hb: The height of the bottom area.
 * Returns: 1 (True) if the inputs are valid, 0 (False) if the inputs are invalid.
 */
int validate_inputs(float R, float ha, float hb) {
    if (R <= 0 || ha <= 0 || hb <= 0 || ha > R || hb > R || hb >= ha) {
        printf("Invalid Input.\n");
        return 0;  // invalid, return False
    }
    return 1;  // valid, return True
}

/*
 * Calculates the vertical height (h).
 * Parameters:
 *   ha: The height of the top area .
 *   hb: The height of the bottom area.
 * Returns: The vertical height h = (ha - hb).
 */
float calculate_h(float ha, float hb) {
    return ha - hb;
}

/*
 * Calculates the radius of the top circular area.
 * Parameters:
 *   R: The radius of the sphere.
 *   ha:The height of the top area.
 * Returns: The radius a of the top circular area.
 */
float calculate_a(float R, float ha) {
    return sqrt(R * R - ha * ha);
}

/*
 * Calculates the radius of the bottom circular area.
 *   R: The radius of the sphere.
 *   hb: The height of the bottom area.
 * Returns: The radius b of the bottom circular area.
 */
float calculate_b(float R, float hb) {
    return sqrt(R * R - hb * hb);
}

/*
 * Calculates the surface area of the top circular area.
 * Parameters: The radius a of the top circular area.
 * Returns: The surface area.
 */
float calculate_top_surface(float a) {
    return PI * a * a;
}

/*
 * Calculates the surface area of the bottom circular area.
 * Parameters: The radius b of the bottom circular area.
 * Returns:  The surface area.
 */
float calculate_bottom_surface(float b) {
    return PI * b * b;
}

/*
 * Calculates the lateral surface area.
 * Parameters:
 *   R: The radius of the sphere.
 *   h: The vertical height.
 * Returns: The lateral surface area.
 */
float calculate_lateral_surface(float R, float h) {
    return 2 * PI * R * h;
}

/*
 * Calculates the total surface area, adding the top, bottom, and lateral surface areas.
 * Parameters:
 *   top: The surface area of the top.
 *   bottom: The surface area of the bottome.
 *   lateral: The lateral surface area.
 * Returns: The sum of the areas.
 */
float calculate_total_surface(float top, float bottom, float lateral) {
    return top + bottom + lateral;
}
/*
 * Calculates the volume of the spherical segment.
 * Parameters:
 *   h: The vertical height.
 *   a: The radius of the top circular area.
 *   b: The radius of the bottom circular area.
 * Returns: The volume of the segment.
 */
float calculate_volume(float h, float a, float b) {
    return (PI / 6) * h * (3 * a * a + 3 * b * b + h * h);
}

/*
 * Prints the calculated results of a spherical segment, including the total surface area and volume.
 * Parameters:
 *   R: The radius of the sphere.
 *   ha: The height of the top area.
 *   hb: The height of the bottom area.
 *   total_surface: The total surface area.
 *   volume: The volume of the segment.
 * Returns: NA
 */
void print_segment_results(float R, float ha, float hb, float total_surface, float volume) {
    printf("Total Surface Area = %.2f Volume = %.2f.\n", total_surface, volume);
}

/*
 * Prints the averages of the surface area and volume across all segments.
 * Parameters:
 *   sum_surface: The sum of surface areas.
 *   sum_volume:  The sum of volumes.
 *   n: The number of segments.
 * Returns: NA
 */
void print_final_averages(float sum_surface, float sum_volume, int n) {
    printf("Total average results:\n");
    printf("Average Surface Area = %.2f Average Volume = %.2f\n", sum_surface / n, sum_volume / n);
}


int main() {
    int n = get_number_of_segments();
    int i = 0;
    float sum_surface = 0.0, sum_volume = 0.0;

    // Loop through each spherical segment
    while (i < n) {
        //Get the required parameters
        printf("Obtaining data for spherical segment number %d\n", i+1);
        float R = get_radius();
        float ha = get_ha();
        float hb = get_hb();

        //print what we got and end loop if valid values
        printf("Entered data: R = %.2f ha = %.2f hb = %.2f\n", R, ha, hb);
         if (!validate_inputs(R, ha, hb)) {
            continue;  // skip to end of loop and reprompt same segment if invalid
        }

        //Calaculate dimensions needed for areas and volume
        float h = calculate_h(ha, hb);
        float a = calculate_a(R, ha);
        float b = calculate_b(R, hb);

        //Calculate areas and volume
       float top = calculate_top_surface(a);
       float bottom = calculate_bottom_surface(b);
       float lateral = calculate_lateral_surface(R, h);
       float total_surface = calculate_total_surface(top, bottom, lateral);
       float volume = calculate_volume(h, a, b);

       //print computed results
       print_segment_results(R, ha, hb, total_surface, volume);

        // Accumulate totals
        sum_surface += total_surface;
        sum_volume += volume;

        i++;  // Proceed to next segment
    }

    // Compute and print averages
        print_final_averages(sum_surface, sum_volume, n);

    return 0;
}

/*
 * tube.c
 *
 * Thom Nijdam
 */
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159265359
#define RADIAL (PI / 180)
#define TIMES 180

float tmp, y_start, x_start, x_end, outside_radius_brace;

int main(void)
{
    float const rad = RADIAL;
    float pi, A, r1, r2, Alpha, Alpha_hlp1, Alpha_hlp2, Alpha_hlp3;
    float outside_diameter_leg, outside_diameter_brace, wall_thickness_brace, angle, outside_radius_leg, inside_radius_brace, x_axis[TIMES], y_axis[TIMES], units;
    int i;
    char unit;

    printf("\nEnter the following values:\n\n");
    printf("Dimensions Metric or Imperial [M/I]?: ");
    scanf("%s", &unit);
    printf("Outside diameter Leg\t\t: ");
    scanf("%f", &outside_diameter_leg);
    printf("Outside diameter Brace\t\t: ");
    scanf("%f", &outside_diameter_brace);
    printf("Wallthickness Brace\t\t: ");
    scanf("%f", &wall_thickness_brace);
    printf("Angle between Leg and Brace\t: ");
    scanf("%f", &angle);

    if (angle > 90)
        angle = 180 - angle;
    if (toupper(unit) == 'I')
    {
        units = 25.4;
    }
    else
    {
        units = 1.0;
    }

    /*
     * Calculate the x-axis
     */
    outside_radius_leg   = (outside_diameter_leg   / 2.0);
    inside_radius_brace  = (outside_diameter_brace - (2.0 * wall_thickness_brace)) / 2.0;
    outside_radius_brace = (outside_diameter_brace / 2.0);
    angle = angle * rad;
    r1 = powf(inside_radius_brace, 2.0f);
    r2 = powf(outside_radius_leg, 2.0f);
    // Debug info
    // printf("outside_radius_leg: %7.2lf, inside_radius_brace: %7.2lf, outside_radius_brace: %7.2lf, angle in rad: %lf\n", outside_radius_leg,
    //       inside_radius_brace, outside_radius_brace, angle);
    for (i = 0; i <= 180; i += 10)
    {
        Alpha = i * 1.0f;
        Alpha = Alpha * rad;
        Alpha_hlp1 = sinf(Alpha);
        Alpha_hlp3 = cosf(Alpha);
        Alpha_hlp2 = powf(Alpha_hlp1, 2.0f);
        A = 1.0f - sqrtf(1.0f - ((r1 / r2) * Alpha_hlp2));
        x_axis[i] = ((outside_radius_leg / sinf(angle)) * A) + ((inside_radius_brace / tanf(angle)) * (1.0f - Alpha_hlp3));
        y_axis[i] = fabsf(outside_radius_brace * Alpha_hlp3);
        printf("x[%3i] = %8.3f, y[%3i] = %8.3f\n", i, x_axis[i], i, y_axis[i]);
    }
    system("pause");
}

/*
 * tube.c
 *
 * Thom Nijdam
 */
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# define PI 3.14159265359
# define RADIAAL (PI / 180)
# define TIMES 180


float  tmp, y_start, x_start, x_end, brace1;

int main(void)
{
    double const rad = RADIAAL;
    double pi, A, r1, r2, Alpha, Alpha_hlp1, Alpha_hlp2, Alpha_hlp3;
    float  od_leg, od_brace, wt_brace, angle, RadiusLeg, Rbrace, Ordinate[TIMES], y[TIMES], c_pixel;
    int    i;

    printf("\nEnter the following values:\n\n");
    printf("Outside diameter Leg\t\t: "); scanf("%f", &od_leg);
    printf("Outside diameter Brace\t\t: "); scanf("%f", &od_brace);
    printf("Wallthickness Brace\t\t: "); scanf("%f", &wt_brace);
    printf("Angle between Leg and Brace\t: "); scanf("%f", &angle);

    if (angle > 90) angle = 180 - angle;

    /*
     * Calculate the ordinate
     */
    RadiusLeg = (od_leg / 2.0);
    Rbrace    = (od_brace - (2.0 * wt_brace)) / 2.0;
    brace1    = (od_brace / 2.0);
    angle     = angle * rad;
    r1        = pow(Rbrace, 2);
    r2        = pow(RadiusLeg,2);
    // Debug info
    printf("Radiusleg: %f, Rbrace: %f, brace1: %f, angle in rad: %f\n", RadiusLeg, Rbrace, brace1, angle);
    for (i = 0; i <= 180; i += 10)
    {
        Alpha = i * 1.0;
        Alpha = Alpha * rad;
        Alpha_hlp1 = sin(Alpha);
        Alpha_hlp3 = cos(Alpha);
        Alpha_hlp2 = pow(Alpha_hlp1, 2);
        A = 1 - (sqrt(1 - ((r1 / r2) * Alpha_hlp2)));
        Ordinate[i] = ((RadiusLeg/sin(angle)) * A) + ((Rbrace/tan(angle)) * (1 - Alpha_hlp3));
        y[i] = fabs(brace1 * Alpha_hlp3);
        printf("x[%i]\t= %f\t, y[%i]=\t %f\n", i, Ordinate[i], i, y[i]);
    }
    system("pause");
}

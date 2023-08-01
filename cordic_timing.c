#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int z_table[11] = {1608, 949, 501, 254, 127, 63, 31, 15, 7, 3, 1};

void cordic_V_fixed_point(int *x, int *y, int *z); /* defined elsewhere*/

void main(void)
{
    int x_i_init, y_i_init, z_i_init; /* initial values*/
    int x_i, y_i, z_i;                /* integer (fixed-point) variables*/

    // points
    // (0.5, 0.5), (0.87, 0.34), (-0.2, 0.45), (-0.7, 0.1)
    double x[4] = {0.5, 0.87, -0.2, -0.7};
    double y[4] = {0.5, 0.34, 0.45, 0.1};

    for (int i = 0; i < 4; ++i)
    {
        x_i = (int)(x[i] * (1 << 11) + 0.5);
        y_i = (int)(y[i] * (1 << 11) + 0.5);
        z_i = 0;

        cordic_V_fixed_point(&x_i, &y_i, &z_i);
    }

    return 0;
}
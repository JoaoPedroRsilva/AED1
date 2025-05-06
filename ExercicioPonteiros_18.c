#include <stdio.h>

#define PI 3,141592653589

void calc_esfera ( float R, float *area, float *volume );

int main ()
{
    float area = 0;
    float volume = 0;
    float raio = 3.5f;

    calc_esfera ( raio, &area, &volume );

    printf("\tRaio da esfera: %.2f\n", raio);
    printf("\tArea da Superficie: %.2f\n", area);
    printf("\tVolume da esfera: %.2f", volume);

    return 0;
}

void calc_esfera ( float R, float *area, float *volume )
{
    *area = 4 * PI * ( R * R );
    *volume = ( 4 / 3 ) * PI * ( R * R * R );
}
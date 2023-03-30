#include "cuboid.h"
#include <stdio.h>

int main() {
    Cuboid cuboid;
    double volume, surface;

    set_size(&cuboid);
    //printf("sides: a=%lf, b=%lf, c=%lf\n", cuboid.a, cuboid.b, cuboid.c);
    printf("\nVolume: %lf\n", volume = calc_volume(cuboid));
    printf("Surface: %lf\n", surface = calc_surface(cuboid));
    check_square(cuboid);

    return 0;
}

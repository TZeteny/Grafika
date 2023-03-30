#include "cuboid.h"
#include <stdio.h>

void set_size(Cuboid* cuboid) {
    int i, ok;
    char ch;
    double a, b, c;

    do {
        ok = 1;
        printf("Sides a, b, c: ");
        if(scanf("%lf,%lf,%lf", &a, &b, &c) != 3) {
            ok = 0;
            printf("Wrong input.\n");
            while ((ch=getchar())!='\n');
        }
        else if( (a <= 0.0) || (b <= 0.0) || (c <= 0.0) ) {
            ok = 0;
            printf("One or more sides were 0 or negative in length.\n");
            while ((ch=getchar())!='\n');
        }
    }while(!ok);

    cuboid->a = a, cuboid->b = b, cuboid->c = c;
}

double calc_volume(Cuboid cuboid) {
    double volume = cuboid.a * cuboid.b * cuboid.c;

    return volume;
}

double calc_surface(Cuboid cuboid) {
    double surface = 2 * (cuboid.a*cuboid.b + cuboid.a*cuboid.c + cuboid.b*cuboid.c);

    return surface;
}

void check_square(Cuboid cuboid) {
    if (cuboid.a == cuboid.b) {
        printf("a * b faces are square.\n");
    }
    if (cuboid.a == cuboid.c) {
        printf("a * c faces are square.\n");
    }
    if (cuboid.b == cuboid.c) {
        printf("b * c faces are square.\n");
    }
}

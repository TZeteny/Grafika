#ifndef CUBOID_H
#define CUBOID_H

//Data of cuboid object.
typedef struct Cuboid {
    double a;
    double b;
    double c;
} Cuboid;

//Set cuboid data.
void set_size(Cuboid* cuboid);

//Calculate volume.
double calc_volume(Cuboid cuboid);

//Calculate surface area.
double calc_surface(Cuboid cuboid);

//check if there are square (nxn) sized sides.
void check_square(Cuboid cuboid);

#endif // CUBOID_H

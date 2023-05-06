#ifndef UTILS_H
#define UTILS_H

#include "model.h"

#define FALSE 0
#define TRUE 1

//3D vector
typedef struct vec3 {
    float x;
    float y;
    float z;
} vec3;

//RGB color
typedef struct Color {
    float red;
    float green;
    float blue;
} Color;

//Material
typedef struct Material {
    struct Color ambient;
    struct Color diffuse;
    struct Color specular;
    float shininess;
} Material;

//Converts degree to radian
double degree_to_radian(double degree);

#endif

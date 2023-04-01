#include "matrix.h"
#include <stdio.h>
#include <math.h>

void init_zero_matrix(float matrix[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            matrix[i][j] = 0.0;
        }
    }
}

void print_matrix(const float matrix[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            printf("%4.4f\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void add_matrices(const float a[3][3], const float b[3][3], float c[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void init_identity_matrix(float matrix[3][3]) {
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (i == j) {
              matrix[i][j] = 1.0;
            }
            else {
              matrix[i][j] = 0.0;
            }
        }
    }
}

void scalar_multiplication(float matrix[3][3], float multiplier) {
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            matrix[i][j] *= multiplier;
        }
    }
}

void multiply_matrices(float a[3][3], float b[3][3], float c[3][3]) {
    int i, j, k;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            c[i][j] = 0;
            for (k = 0; k < 3; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }
}

void transform_point(float point[3], float matrix[3][3], float out[3]) {
    int i, j, k;

    for (i = 0; i < 3; i++) {
        out[i] = 0;
        for (j = 0; j < 3; j++) {
            out[i] = out[i] + matrix[i][j] * point[j];
        }
    }
}

void calc_distance(float p[3], float q[3]) {
    float distance = sqrt( (p[0] - q[0]) + (p[1] - q[1]) + (p[2] - q[2]) );

    printf("The distance between the 2 points is %f.\n", distance);
}

void scale_vector(float p[3], float matrix[3][3], float q[3]) {
    int i;

    for (i = 0; i < 3; i++) {
        q[i] = matrix[i][i] * p[i];
    }
}

void shift_matrix(float a[3][3], float shift[3], float b[3][3]) {
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            b[i][j] = a[i][j] + shift[j];
        }
    }
}

void rotate_vector(float p[3], float matrix[3][3], float q[3]) {
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            q[i] = q[i] + p[j] * matrix[i][j];
        }
    }
}


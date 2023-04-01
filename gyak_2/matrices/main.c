#include "matrix.h"
#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[])
{
	float a[3][3] = {
        { 1.0f, -2.0f,  3.0f},
        { 5.0f, -3.0f,  0.0f},
        {-2.0f,  1.0f, -4.0f}
    };
	float b[3][3];
	float c[3][3];
	float p[3] = {1, 2, 3};
	float q[3];

    init_zero_matrix(b);
    b[1][1] =  8.0f;
    b[2][0] = -3.0f;
    b[2][2] =  5.0f;

    printf("matrix a\n");
    print_matrix(a);
    printf("\n");

    printf("matrix b\n");
    print_matrix(b);
    printf("\n");

    add_matrices(a, b, c);
    printf("matrix c (a + b)\n");
    print_matrix(c);
    printf("\n");

    init_identity_matrix(b);
    printf("matrix b (identity matrix)\n");
    print_matrix(b);
    printf("\n");

    scalar_multiplication(a, 2);
    printf("matrix a (a * 2)\n");
    print_matrix(a);
    printf("\n");

    multiply_matrices(a, c, b);
    printf("matrix b (a * c)\n");
    print_matrix(c);
    printf("\n");

    transform_point(p, a, q);
    printf("q (a * p)\n");
    printf("%f\n%f\n%f\n\n", q[0], q[1], q[2]);

    calc_distance(p, q);
    printf("\n");

    init_zero_matrix(b);
    b[0][0] =  2.0f;
    b[1][1] =  3.0f;
    b[2][2] =  1.0f;
    scale_vector(p, b, q);
    printf("p scaled wih b(diag 2,3,1)\n");
    printf("%f\n%f\n%f\n\n", q[0], q[1], q[2]);

    shift_matrix(a, p, b);
    printf("b (a + p)\n");
    print_matrix(b);
    printf("\n");

    init_zero_matrix(b);
    b[0][0] = sqrt(2) / 2.0;
    b[0][1] = (sqrt(2) / 2.0) * (-1);
    b[1][0] = sqrt(2) / 2.0;
    b[1][1] = sqrt(2) / 2.0;
    q[0] = 0.0;
    q[1] = 0.0;
    q[2] = 0.0;
    rotate_vector(p, b, q);
    printf("q (p rotated by b)\n");
    printf("%f\n%f\n%f\n\n", q[0], q[1], q[2]);

	return 0;
}


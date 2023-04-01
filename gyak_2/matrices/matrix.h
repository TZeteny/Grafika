#ifndef MATRIX_H
#define MATRIX_H

/**
 * Initializes all elements of the matrix to zero.
 */
void init_zero_matrix(float matrix[3][3]);

/**
 * Print the elements of the matrix.
 */
void print_matrix(const float matrix[3][3]);

/**
 * Add matrices.
 */
void add_matrices(const float a[3][3], const float b[3][3], float c[3][3]);

/*Initializes identitty matrix.
The elements in the main diagonal are ones, everything else is zero.
*/
void init_identity_matrix(float matrix[3][3]);

//Multiply all elements with a number.
void scalar_multiplication(float matrix[3][3], float multiplier);

//Multiply two matrices.
void multiply_matrices(float a[3][3], float b[3][3], float c[3][3]);

void transform_point(float point[3], float matrix[3][3], float out[3]);

//The distance between 2 points in 3D.
void calc_distance(float p[3], float q[3]);

//Scales p vector on x by 0,0 and on y by 1,1.
void scale_vector(float p[3], float matrix[3][3], float q[3]);

//Shifts the matrix's x, y, z values by the shift vector.
void shift_matrix(float a[3][3], float shift[3], float b[3][3]);

//rotates the matrix around the origin point.
void rotate_vector(float p[3], float matrix[3][3], float q[3]);

#endif // MATRIX_H


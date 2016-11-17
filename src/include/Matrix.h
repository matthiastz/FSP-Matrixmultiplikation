//
// thanks to benediktg for creating this interface :-)
//

#ifndef FPS_MATRIXMULTIPLIKATION_MATRIX_H
#define FPS_MATRIXMULTIPLIKATION_MATRIX_H


#include <stdbool.h>


/**
 * const matrix ????? ausgangsmatrix
 *
 */


/**
 * Represents a matrix.
 */
typedef struct Matrix {
    /** count of rows */
    int rowCount;
    /** count of columns */
    int columnCount;
    /** the actual matrix which is supposed to have a size of
     * count of rows times columns */
    float *data;
} Matrix;

/*****************************
 * Access and help functions *
 *****************************/

/**
 * Allocates space for the result of a matrix multiplication.
 */
Matrix allocMatrix(Matrix a, Matrix b);

/**
 * creates a matrix with given dimension (rows, columns)
 */
Matrix createRandomizedMatrix(int rowCount, int columnCount);

/**
 * Frees up the space of the matrix data.
 */
int freeMatrix(Matrix *matrix);

/**
 * Checks if the matrix is similar to a null object.
 */
bool isNullMatrix(Matrix matrix);

/**
 * Checks if the matrix is square.
 */
bool isSquareMatrix(Matrix matrix);

/**
 * Retrieves a value of a matrix element.
 *
 * @param matrix the matrix instance (dimension M × N)
 * @param i the row number (must be in the interval 0..M-1)
 * @param j the column number (must be in the interval 0..N-1)
 * @returns the value of the given element
 */
float getElementValue(Matrix matrix, int i, int j);

/**
 * Sets a value of a matrix element.
 *
 * @param matrix the matrix instance (dimension M × N)
 * @param i the row number (must be in the interval 0..M–1)
 * @param j the column number (must be in the interval 0..N–1)
 * @param value the value to set
 */
void setElementValue(Matrix *matrix, int i, int j, float value);

/**
 * Prints a representation of the matrix to stdout.
 */
int prettyPrint(Matrix matrix);

/*************************
 * Matrix multiplication *
 *************************/

/**
 * Naive implementation of a matrix multiplication
 */
int standardMatrixMul(Matrix a, Matrix b, Matrix *result);

/**
 * Cache optimized implemetation of a matrix multiplication (n x n)
 */
int optimizedMatrixMul(Matrix a, Matrix b, Matrix *result, int blockSize);

/**
 * Parallel implementation of a matrix multiplication
 */
int parallelMatrixMul(Matrix a, Matrix b, Matrix *result);

#endif //FPS_MATRIXMULTIPLIKATION_MATRIX_H

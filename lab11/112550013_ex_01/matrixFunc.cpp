#include "matrix.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#define For(z, x, y) for(int z = x; z <= y; z ++)

// to construct the matrix by given row and column
matrix2D* matrix2D_construct(int m, int n) {
	matrix2D *M = (matrix2D*)malloc(sizeof(matrix2D));
	M->row = m;
	M->column = n;
	M->mat = (vector*)calloc(m, sizeof(vector));
	For(i, 0, m - 1) {
		vector* tmp = vector_construct(n);
		M->mat[i] = *tmp;
	}
	return M;
}

// fill the matrix with specific number
void matrix2D_fillwith(matrix2D* A, int num) {
	For(i, 0, A->row - 1) {
		For(j, 0, A->column - 1) {
			A->mat[i].vec[j] = num;
		}
	}
}

// check 2 matrix with the right shape,
// if they can multiple together, return the result, or print "Shape Error"
matrix2D* matrix2D_multiple(matrix2D* A, matrix2D* B) {
	matrix2D* M = matrix2D_construct(A->row, B->column);
	if (A->column == B->row) {
		For(i, 0, A->row - 1) {
			For(j, 0, B->column - 1) {
				For(k, 0, B->row - 1) {
					M->mat[i].vec[j] += A->mat[i].vec[k] * B->mat[k].vec[j];
				}
			}
		}
	}
	else {
		printf("Shape Error\n");
		return NULL;
	}
	return M;
}

// print function
void print_matrix(matrix2D* A) {
	if (A == NULL) return;
	For(i, 0, A->row - 1) {
		For(j, 0, A->column - 1) {
			if (j != 0) printf(" ");
			printf("%d", A->mat[i].vec[j]);
		}
		printf("\n");
	}
}
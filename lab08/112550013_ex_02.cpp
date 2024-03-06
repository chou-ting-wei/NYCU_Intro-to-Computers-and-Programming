#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define  For(z, x, y) for(int z = x; z <= y; z ++)

int** mat1, ** mat2;

int** matrix_multiplication(int** mat1, int** mat2, int m, int n, int p) {
	int** ans = (int**)calloc(m, sizeof(int**));
	For(i, 0, m - 1) {
		int* tmp = (int*)calloc(p, sizeof(int));
		*(ans + i) = tmp;
	}
	For(i, 0, m - 1) {
		For(j, 0, p - 1) {
			For(k, 0, n - 1) {
				ans[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}
	return ans;
}

int main() {
	int m, n, p;
	scanf("%d%d%d", &m, &n, &p);
	mat1 = (int**)calloc(m, sizeof(int**));
	mat2 = (int**)calloc(n, sizeof(int**));
	For(i, 0, m - 1) {
		int* tmp = (int*)calloc(n, sizeof(int));
		*(mat1 + i) = tmp;
	}
	For(i, 0, n - 1) {
		int* tmp = (int*)calloc(p, sizeof(int));
		*(mat2 + i) = tmp;
	}
	For(i, 0, m - 1) {
		For(j, 0, n - 1) {
			int k;
			scanf("%d", &k);
			mat1[i][j] = k;
		}
	}
	For(i, 0, n - 1) {
		For(j, 0, p - 1) {
			int k;
			scanf("%d", &k);
			mat2[i][j] = k;
		}
	}
	
	int **ans = matrix_multiplication(mat1, mat2, m, n, p);

	For(i, 0, m - 1) {
		For(j, 0, p - 1) {
			if (j != 0) printf(" ");
			printf("%d", ans[i][j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}
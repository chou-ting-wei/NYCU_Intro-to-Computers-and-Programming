#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define  For(z, x, y) for(int z = x; z <= y; z ++)

int* sz;
int** a;
int n;

void print() {
	For(i, 1, n) {
		if (sz[i] == 0)continue;
		For(j, 1, sz[i]) {
			if (j == 1) printf("%d", a[i][j]);
			else printf(" %d", a[i][j]);
		}
		printf("\n");
	}
}

int main() {
	printf("input N: ");
	scanf("%d", &n);
	sz = (int*)calloc(n + 1, sizeof(int));
	a = (int**)calloc(n + 1, sizeof(int*));

	printf("step 1:\n");
	printf("input N numbers: ");
	For(i, 1, n) {
		int k;
		scanf("%d", &k);
		sz[i] = k;
		*(a + i) = (int*)calloc(k + 1, sizeof(int));
	}
	print();

	printf("step 2:\n");
	printf("input R and S: ");
	int r, s;
	scanf("%d%d", &r, &s);
	*(a + r) = (int*)realloc(*(a + r), (s + 1) *sizeof(int));
	if (s > sz[r]) {
		For(i, sz[r] + 1, s) {
			a[r][i] = 1;
		}
		sz[r] = s;
	}
	print();

	printf("step 3:\n");
	printf("input N2: ");
	int n2;
	scanf("%d", &n2);
	a = (int**)realloc(a, (n2 + 1) * sizeof(int**));
	sz = (int*)realloc(sz, (n2 + 1) * sizeof(int));
	For(i, n + 1, n2) {
		sz[i] = 2;
		*(a + i) = (int*)calloc(3, sizeof(int));
		a[i][1] = 2;
		a[i][2] = 2;
	}
	n = n2;
	print();

	printf("step 4:\n");
	printf("input D: ");
	int d;
	scanf("%d", &d);
	free(*(a + d));
	sz[d] = 0;
	print();
	
	system("pause");
	return 0;
}
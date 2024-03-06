#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define For(z, x, y) for(int z = x; z <= y; z ++)

int m, n;
int* szA, * szB;
char** A, ** B;

void print() {
	printf("A:\n");
	For(i, 0, m - 1) {
		if (szA[i] > 0) {
			printf("%s", A[i]);
		}
		else printf("(null)");
		printf("\n");
	}
	printf("B:\n");
	For(i, 0, n - 1) {
		if (szB[i] > 0) {
			printf("%s", B[i]);
		}
		else printf("(null)");
		printf("\n");
	}
}

int main() {
	scanf("%d%d", &m, &n);
	A = (char**)calloc(m, sizeof(char*));
	B = (char**)calloc(n, sizeof(char*));
	szA = (int*)calloc(m, sizeof(int));
	szB = (int*)calloc(n, sizeof(int));

	while (1) {
		int p;
		scanf("%d", &p);

		if (p == 0) {
			int x, y, s;
			scanf("%d %d %d\n", &x, &y, &s);
			if (x == 0) {
				char* str = (char*)calloc(s + 1, sizeof(char));
				// scanf("%s", str);
				scanf("%[^\n]", str);
				if ((y >= m) || (szA[y] > 0)) {
					print();
					continue;
				}
				*(A + y) = str;
				szA[y] = s;
			}
			else {
				char* str = (char*)calloc(s + 1, sizeof(char));
				// scanf("%s", str);
				scanf("%[^\n]", str);
				if ((y >= n) || (szB[y] > 0)) {
					print();
					continue;
				}
				*(B + y) = str;
				szB[y] = s;
			}
		}
		else if (p == 1) {
			int x, y;
			scanf("%d %d", &x, &y);
			if (x == 0) {
				if ((y >= m) || (szA[y] == 0)) {
					print();
					continue;
				}
				free(*(A + y));
				szA[y] = 0;
			}
			else {
				if ((y >= n) || (szB[y] == 0)) {
					print();
					continue;
				}
				free(*(B + y));
				szB[y] = 0;
			}
		}
		else if (p == 2) {
			int x, y;
			scanf("%d %d", &x, &y);
			if ((x >= m) || (y >= n)) {
				print();
				continue;
			}
			char* tmp = A[x];
			int sztmp = szA[x];
			A[x] = B[y];
			B[y] = tmp;
			szA[x] = szB[y];
			szB[y] = sztmp;
		}
		else {
			break;
		}
		print();
	}

	system("pause");
	return 0;
}
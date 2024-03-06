#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#define For(z, x, y) for(int z = x; z <= y; z ++)

int it = 0, mxsz = 1;
int* ar = NULL;

int main() {
	ar = (int*)malloc(sizeof(int));

	while (1) {
		printf("action = ");
		int k;
		scanf("%d", &k);
		if (k == 0) {
			break;
		}
		else if (k == 1) {
			printf("element to add = ");
			int t;
			scanf("%d", &t);
			if (it == mxsz) {
				mxsz *= 2;
				ar = (int*)realloc(ar, sizeof(int) * mxsz);
			}
			ar[it] = t;
			it++;
			For(i, 0, mxsz - 1) {
				if (i != 0) printf(" ");
				printf("%d", ar[i]);
			}
			printf("\n");
		}
		else {
			if (it > 0) {
				it--;
				ar[it] = -7777;
			}
			if (it <= (mxsz / 2) && (mxsz / 2) != 0) {
				mxsz /= 2;
				ar = (int*)realloc(ar, sizeof(int) * mxsz);
			}
			For(i, 0, mxsz - 1) {
				if (i != 0) printf(" ");
				printf("%d", ar[i]);
			}
			printf("\n");
		}
	}

	system("pause");
	return 0;
}
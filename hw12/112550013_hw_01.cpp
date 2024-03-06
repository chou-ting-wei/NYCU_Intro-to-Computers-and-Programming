#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define For(z, x, y) for(int z = x; z <= y; z ++)

struct Node {
	int l, r;
}ar[50000];

int main() {
	int T;
	scanf("%d", &T);
	// assert(T <= 5000);

	if (T > 50) return 0;

	For(i, 0, T - 1) {
		int l, r;
		scanf("%d %d", &l, &r);
		struct Node tmp;
		tmp.l = l;
		tmp.r = r;
		ar[i] = tmp;
	}

	For(i, 0, T - 1) {
		For(j, i + 1, T - 1) {
			if (ar[i].l > ar[j].l) {
				struct Node tmp;
				tmp = ar[i];
				ar[i] = ar[j];
				ar[j] = tmp;
			}
		}
	}

	int cst = 0;
	int r = -1;
	For(i, 0, T - 1) {
		if (ar[i].l > r) {
			cst += 2;
		}
		r = r > ar[i].r + 1 ? r : ar[i].r + 1;
	}
	printf("%d\n", cst);

	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define For(z, x, y) for(int z = x; z <= y; z ++)

int ar[15], used[15];

void perm(int n, int k, int cnt, int now) {
	if (cnt == k) {
		For(i, 0, k - 1) printf("%d", ar[i]);
		printf("\n");
		return;
	}
	For(i, now, n) {
		if (used[i] == 0) {
			used[i] = 1;
			ar[cnt] = i;
			perm(n, k, cnt + 1, i + 1);
			used[i] = 0;
		}
	}
}

int main() {
	For(i, 0, 14) {
		ar[i] = 0;
		used[i] = 0;
	}
	int n, k;
	scanf("%d%d", &n, &k);

	perm(n, k, 0, 1);

	system("pause");
	return 0;
}
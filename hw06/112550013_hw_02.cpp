#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define For(z, x, y) for(int z = x; z <= y; z ++)

int ar[50];
int n, cnt = 0;

int max(int x, int y) { return (x > y ? x : y); }

void slv(int now, int sum) {
	if (now + 2 > n) {
		cnt = max(cnt, sum);
		return;
	}
	For(i, now + 2, n) {
		slv(i, sum + ar[i]);
	}
}

int main() {
	scanf("%d", &n);
	For(i, 1, n) {
		scanf("%d", &ar[i]);
	}

	slv(-1, 0);

	printf("%d\n", cnt);

	system("pause");
	return 0;
}
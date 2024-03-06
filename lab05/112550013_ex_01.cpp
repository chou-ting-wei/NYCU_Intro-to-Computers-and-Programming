#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int min(int x, int y) {
	return x <= y ? x : y;
}

int main() {
	int x, y, ans;
	scanf("%d%d", &x, &y);
	ans = min(x, y);
	printf("The min of %d and %d is %d.\n", x, y, ans);
	system("pause");
	return 0;
}
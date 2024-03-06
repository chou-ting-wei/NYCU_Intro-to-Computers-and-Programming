#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void print(int n, int i) {
	char c = (96 + i);
	printf("%c", c);
	if (i == n) return;
	print(n, i + 1);
}

int main() {
	int n;
	scanf("%d", &n);

	print(n, 1);
	printf("\n");

	system("pause");
	return 0;
}
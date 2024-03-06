#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void createGeometric(int arr[], int n, int r, int a) {
	int t = 1;
	for (int i = 0; i < n; i++) {
		arr[i] = a * t;
		t *= r;
	}
}

int main() {
	int geometric_arr[10] = { -1 };
	int n, r, a;
	scanf("%d %d %d", &n, &r, &a);
	createGeometric(geometric_arr, n, r, a);
	for (int i = 0; i < n; ++i) {
		printf("%d ", geometric_arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}

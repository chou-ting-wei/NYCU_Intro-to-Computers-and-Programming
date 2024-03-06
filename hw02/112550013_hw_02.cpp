#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>

int main() {
	int a;
	scanf("%d", &a);
	int x1 = 0, x2 = 0, x3 = a / 4, r = a % 4;
	if (r == 1) {
		x2++;
		x3--;
	}
	else if (r == 2) {
		x1++;
		x3--;
	}
	else if (r == 3) {
		x1++;
		x2++;
		x3 -= 2;
	}
	printf("%d\n", x1 + x2 + x3);

	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>

int main() {
	printf("ax^2 + bx + c\n");
	printf("Please input the coefficients: a b c\n");
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	
	int D = b * b - 4 * a * c;

	printf("'%dx^2", a);
	if (b > 0) printf("+%dx", b);
	else printf("%dx", b);
	if (c > 0) printf("+%d'", c);
	else printf("%d'", c);

	if (D > 0) {
		printf(" has two distinct roots\n");
	}
	else if (D == 0) {
		printf(" has double roots\n");
	}
	else {
		printf(" has no real root\n");
	}

	system("pause");
	return 0;
}
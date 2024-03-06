#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>

int main() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);

	if (a + b <= c || b + c <= a || c + a <= b) {
		printf("%d %d %d cannot form a triangle.\n", a, b, c);
	}
	else {
		printf("%d %d %d can form a triangle.\n", a, b, c);
		if (a * a + b * b < c * c || b * b + c * c < a * a || c * c + a * a < b * b) {
			printf("%d %d %d can form an obtuse triangle.\n", a, b, c);
		}
		else if (a * a + b * b == c * c || b * b + c * c == a * a || c * c + a * a == b * b) {
			printf("%d %d %d can form a right triangle.\n", a, b, c);
		}
		else {
			printf("%d %d %d can form an acute triangle.\n", a, b, c);
		}
		int flg = 0;
		if (a == b && b == c) {
			printf("%d %d %d can form an equilateral triangle.\n", a, b, c);
			flg++;
		}
		if (a == b || b == c || c == a) {
			printf("%d %d %d can form an isosceles triangle.\n", a, b, c);
			flg++;
		}
		if (flg == 0) {
			printf("%d %d %d can form a scalene triangle.\n", a, b, c);
		}
	}

	system("pause");
	return 0;
}
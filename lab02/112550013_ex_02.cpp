#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>

int main() {
	printf("Please input an AD year: ");
	int yr;
	scanf("%d", &yr);

	if ((yr % 400 == 0) || (yr % 4 == 0 && yr % 100 != 0)) {
		printf("%d is a leap year\n", yr);
	}
	else {
		printf("%d is not a leap year\n", yr);
	}

	system("pause");
	return 0;
}
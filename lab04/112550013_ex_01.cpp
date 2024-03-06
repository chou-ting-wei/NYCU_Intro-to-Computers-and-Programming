#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>

int main() {
	char c[100];
	printf("Enter any string: ");
	gets_s(c);

	char cc;
	printf("Enter character to be searched: ");
	cc = getchar();

	for (int i = 0; i < 100 && c[i] != '\0'; i++) {
		if (c[i] == cc) {
			printf("'%c' is found at index %d.\n", cc, i);
		}
	}

	system("pause");
	return 0;
}

/*
Input:
I love watermelon.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#define For(z, x, y) for(int z = x; z <= y; z ++)
#define Forr(z, x, y) for(int z = x; z >= y; z --)

int main() {
	FILE* fptr;
	fptr = fopen("ex2_input.txt", "r");

	if (fptr != NULL) {
		int s, c;
		s = (int)(getc(fptr) - '0');
		getc(fptr);
		c = (int)(getc(fptr) - '0');
		if (s == 1) {
			Forr(i, c, 1) {
				For(j, 1, i) {
					printf("*");
					if (j != i) printf(" ");
				}
				printf("\n");
			}
		}
		else if (s == 2) {
			For(i, 1, c) {
				For(j, 1, c - i) {
					printf(" ");
				}
				For(j, 1, i) {
					printf("*");
					if (j != i) printf(" ");
				}
				printf("\n");
			}
		}
		else {
			For(i, 1, c) {
				For(j, 1, c - i) {
					printf("  ");
				}
				For(j, 1, i) {
					printf("*");
					if (j != i) printf(" ");
				}
				printf("\n");
			}
		}
	}

	system("pause");
	return 0;
}
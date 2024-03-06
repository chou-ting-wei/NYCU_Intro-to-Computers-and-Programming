#include "112550013_struct.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define For(z, x, y) for(int z = x; z <= y; z ++)

int trans[] = { 10, 11, 12, 13, 14, 15, 16, 17, 34, 18, 19, 20, 21, 22, 35, 23, 24, 25, 26, 27, 28, 29, 32, 30, 31, 33 };
int wgt[] = { 1, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

int chkIDValid(char c[]) {
	if (strlen(c) != 10) return 0;
	if (!isupper((int)c[0])) return 0;
	For(i, 1, 9) {
		if (!isdigit((int)c[i])) return 0;
	}
	int tL = trans[(c[0] - 'A')];
	int sum = 0;

	For(i, 0, 9) {
		int tmp;
		if (i == 0) tmp = tL / 10;
		else if (i == 1) tmp = tL % 10;
		else tmp = c[i - 1] - '0';
		sum += tmp * wgt[i];
	}

	int rem = sum % 10;
	// printf("%d\n", rem);
	if ((rem + (c[9] - '0')) % 10) return 0;
	return 1;
}

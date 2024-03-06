#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <cstdio>
#include <cstdlib>
#include <string.h>
#define For(z, x, y) for(int z = x; z <= y; z ++)
#define Forr(z, x, y) for(int z = x; z >= y; z --)

char c1[30], c2[30];
int ans[50];

int main() {
	For(i, 0, 49) ans[i] = 0;
	scanf("%s%s", &c1, &c2);
	strrev(c1);
	strrev(c2);
	int a1 = strlen(c1), a2 = strlen(c2);

	For(i, 0, ((a1 > a2) ? (a1 - 1) : (a2 - 1))) {
		For(j, 0, ((a1 > a2) ? (a2 - 1) : (a1 - 1))) {
			int n1, n2;
			if(a1 > a2) n1 = (int)(c1[i] - '0'), n2 = (int)(c2[j] - '0');
			else n1 = (int)(c2[i] - '0'), n2 = (int)(c1[j] - '0');
			ans[i + j] += n1 * n2;
			// printf("%d %d %d %d\n", i, j, n1, n2);
		}
	}

	For(i, 0, 48) {
		ans[i + 1] += ans[i] / 10;
		ans[i] %= 10;
	}

	int t = 0;
	Forr(i, 48, 0) {
		if (!t && ans[i] != 0) {
			t = 1;
		}
		if (t) printf("%d", ans[i]);
	}
	if (!t) printf("0");
	printf("\n");

	system("pause");
	return 0;
}
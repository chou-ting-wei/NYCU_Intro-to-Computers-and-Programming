#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <cstdio>
#include <cstdlib>
#include <string.h>
#define For(z, x, y) for(int z = x; z <= y; z++)
#define Forr(z, x, y) for(int z = x; z >= y; z--)

char c1[30], c2[30], ans[30];

int main() {
	scanf("%s%s", &c1, &c2);
	strrev(c1);
	strrev(c2);
	int a1 = strlen(c1), a2 = strlen(c2), c = 0;

	For(i, 0, ((a1 > a2) ? (a1 - 1) : (a2 - 1))) {
		int n1 = (int)(c1[i] - '0'), n2 = (int)(c2[i] - '0');
		if (n1 < 0) n1 = 0;
		if (n2 < 0) n2 = 0;
		int s = n1 + n2 + c;
		c = 0;
		if (s >= 10) {
			c = s / 10;
			ans[i] = (char)((s % 10) + 48);
		}
		else ans[i] = (char)(s + 48);
	}
	
	strrev(ans);
	if (c == 1) printf("1");
	printf("%s\n", ans);

	system("pause");
	return 0;
}

/*
12345678912345678912
12345678912345678912
*/
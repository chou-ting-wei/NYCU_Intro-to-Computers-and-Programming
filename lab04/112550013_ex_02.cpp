#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#define For(z, x, y) for(int z = x; z < y; z ++)

int m1[15][15], m2[15][15], m3[15][15];

int main() {
	int m, n, p;
	scanf("%d%d%d", &m, &n, &p);

	For(i, 0, m) {
		For(j, 0, n) {
			scanf("%d", &m1[i][j]);
		}
	}
	For(i, 0, n) {
		For(j, 0, p) {
			scanf("%d", &m2[i][j]);
		}
	}

	For(i, 0, m) {
		For(j, 0, p) {
			For(k, 0, n) {
				m3[i][j] += (m1[i][k] * m2[k][j]);
			}
		}
	}

	For(i, 0, m) {
		For(j, 0, p) {
			printf("%d", m3[i][j]);
			if (j != (p - 1)) printf(" ");
		}
		printf("\n");
	}

	system("pause");
	return 0;
}

/*
6 6 6

1 2 3 4 5 6
7 8 9 10 11 12
13 14 15 16 17 18
19 20 21 22 23 24
25 26 27 28 29 30
31 32 33 34 35 36

37 38 39 40 41 42
43 44 45 46 47 48
49 50 51 52 53 54
55 56 57 58 59 60
61 62 63 64 65 66
67 68 69 70 71 72
*/
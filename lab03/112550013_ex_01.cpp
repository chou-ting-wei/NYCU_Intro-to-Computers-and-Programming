#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <ctime>
#define For(z, x, y) for(int z = x; z <= y; z ++)
#define Forr(z, x, y) for(int z = x; z >= y; z --)

int ans[10];

int main() {
	srand(time(0));
	int a = rand() % 64;
	For(i, 0, 5) ans[i] = 0;

	printf("Decimal number = %d\n", a);
	printf("Binary number = ");

	int cnt = 0;
	while (a) {
		ans[cnt] = a % 2;
		a /= 2;
		cnt++;
	}

	Forr(i, 5, 0) printf("%d", ans[i]);
	printf("\n");

	system("pause");
	return 0;
}
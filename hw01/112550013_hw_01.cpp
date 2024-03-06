#include <stdio.h>
#include <stdlib.h>

int main(){
	float a;
	scanf_s("%f", &a);

	float msbw = 0.7 * (a - 80), fsbw = 0.6 * (a - 70);

	printf("For men with a height of %.1fcm, a body weight between %.1fkg and %.1fkg is considered a normal weight range.\n", a, 0.9 * msbw, 1.1 * msbw);
	printf("For women with a height of %.1fcm, a body weight between %.1fkg and %.1fkg is considered a normal weight range.\n", a, 0.9 * fsbw, 1.1 * fsbw);
	system("pause");
	return 0;
}
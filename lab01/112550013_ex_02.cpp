#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
    int a, b;
    scanf_s("%d%d", &a, &b);
    printf("%d\n%d\n%d\n%.2f\n%d\n", a + b, a - b, a * b, ((float)a) / b, a % b);

    system("pause");
    return 0;
}
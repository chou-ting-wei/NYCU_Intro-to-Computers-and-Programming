#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define For(z, x, y) for(int z = x; z <= y; z ++)

int* compare(const char* S, const char* T, int N) {
    int* cmp = (int*)calloc(N, sizeof(int));
    For(i, 0, N - 1) {
        if (S[i] == T[i]) {
            cmp[i] = 1;
        }
    }

    return cmp;
}

int main() {

    while (1) {
        int n;
        scanf("%d%*c", &n);
        if (n == 0) {
            break;
        }

        char* s = (char*)calloc(n, sizeof(char)), * t = (char*)calloc(n, sizeof(char));
        scanf("%[^\n]%*c", s);
        scanf("%[^\n]%*c", t);

        int* ans = compare(s, t, n);

        For(i, 0, n - 1) {
            printf("%d", ans[i]);
        }
        printf("\n");
    }

    system("pause");
    return 0;
}

/*
6
looong
toooog
30
qqaabbccppqqaabbccppqqaabbccpp
qaabbccppqqaabbccppqqaabbccppq
3
abc
ABC
0
*/
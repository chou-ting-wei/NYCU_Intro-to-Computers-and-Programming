#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define For(z, x, y) for(int z = x; z <= y; z ++)

int main() {
	FILE* fptr1, *fptr2;
	fptr1 = fopen("p1_input.txt", "r");
	fptr2 = fopen("p1_output.txt", "w");

	char s[20];
	scanf("%s", &s);
	int add[20];
	int len = strlen(s);
	// printf("%d\n", len);

	For(i, 0, len - 1) {
		add[i] = (int)(s[i] - 'a');
	}

	int cnt = 0;
	char ch;
	if (fptr1 != NULL && fptr2 != NULL) {
		while (ch = getc(fptr1) != EOF) {
			fseek(fptr1, -1, SEEK_CUR);
			ch = getc(fptr1);
			int nch = (int)ch;
			if (65 <= nch && nch <= 90) {
				int dif = nch - 65;
				fputc((char)(65 + ((dif + add[cnt]) % 26)), fptr2);
				cnt = ((cnt + 1) % len);
			}
			else if (97 <= nch && nch <= 122) {
				int dif = nch - 97;
				fputc((char)(97 + ((dif + add[cnt]) % 26)), fptr2);
				cnt = ((cnt + 1) % len);
			}
			else {
				fputc(ch, fptr2);
			}
		}
	}

	system("pause");
	return 0;
}

/*
int main() {

	char s[20], inp[10000];
	scanf("%s\n", &s);
	scanf("%[^\n]", &inp);
	int add[20];
	int len = strlen(s);
	int len2 = strlen(inp);
	// printf("%d\n", len);

	For(i, 0, len - 1) {
		add[i] = (int)(s[i] - 'a');
	}

	int cnt = 0;
	int now = 0;
	char ch;
	while (now < len2) {
		ch = inp[now];
		int nch = (int)ch;
		if (65 <= nch && nch <= 90) {
			int dif = nch - 65;
			printf("%c", (char)(65 + ((dif + add[cnt]) % 26)));
			cnt = ((cnt + 1) % len);
		}
		else if (97 <= nch && nch <= 122) {
			int dif = nch - 97;
			printf("%c", (char)(97 + ((dif + add[cnt]) % 26)));
			cnt = ((cnt + 1) % len);
		}
		else {
			printf("%c", ch);
		}
		now++;
	}

	system("pause");
	return 0;
}
*/
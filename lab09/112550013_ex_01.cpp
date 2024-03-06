#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

int main() {
	FILE* fptr1, *fptr2;
	fptr1 = fopen("input.txt", "r");
	fptr2 = fopen("output.txt", "w");
	char c, ch;
	// scanf("%c", &c);

	if ((fptr1 != NULL) && (fptr2 != NULL)) {
		c = getc(fptr1);
		getc(fptr1);

		while (ch = getc(fptr1) != EOF) {
			fseek(fptr1, -1, SEEK_CUR);
			ch = getc(fptr1);
			int nch = (int)ch;
			if (65 <= nch && nch <= 90) {
				fputc((char)(nch + 32), fptr2);
			}
			else if(97 <= nch && nch <= 122) {
				fputc((char)(nch - 32), fptr2);
			}
			else {
				fputc(c, fptr2);
			}
		}
	}

	fclose(fptr1);
	fclose(fptr2);

	system("pause");
	return 0;
}

/*
#include <string.h>
char s[100005];

int main() {
	char c, ch;
	scanf("%c\n", &c);
	scanf("%[^\n]", &s);

	int cnt = 0, l = strlen(s);
	while (cnt < l) {
		int nch = (int)s[cnt];
		if (65 <= nch && nch <= 90) {
			printf("%c", (char)(nch + 32));
		}
		else if (97 <= nch && nch <= 122) {
			printf("%c", (char)(nch - 32));
		}
		else {
			printf("%c", c);
		}
		cnt++;
	}
	printf("\n");

	system("pause");
	return 0;
}
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define For(z, x, y) for(int z = x; z <= y; z ++)

int min(const int x, const int y) {
	return x < y ? x : y;
}

int main() {
	FILE* fptr1, * fptr2;
	fptr1 = fopen("p2_input_plaintext.txt", "r");
	fptr2 = fopen("p2_input_ciphertext.txt", "r");

	char s[30];

	int cnt = 0;
	char ch1, ch2;
	if (fptr1 != NULL && fptr2 != NULL) {
		while (ch1 = getc(fptr1) != EOF && cnt < 30) {
			fseek(fptr1, -1, SEEK_CUR);
			ch1 = getc(fptr1);
			ch2 = getc(fptr2);
			// printf("%c %c\n", ch1, ch2);
			int nch1 = (int)ch1, nch2 = (int)ch2;
			if ((65 <= nch1 && nch1 <= 90) || (97 <= nch1 && nch1 <= 122)) {
				int dif = 0;
				if (nch2 - nch1 < 0) {
					dif = nch2 + 26 - nch1;
				}
				else {
					dif = nch2 - nch1;
				}
				// printf("%d %d %d\n", nch1, nch2, dif);
				s[cnt] = (char)(97 + dif);
				cnt++;
			}
		}
	}

	int r = 0;
	For(i, 2, 15) {
		int now = 0, flg = 1;
		For(j, 0, 29) {
			// printf("%c %c\n", s[now], s[j]);
			if (s[now] != s[j]) {
				flg = 0;
				break;
			}
			now = (now + 1) % i;
		}
		// printf("%d %d\n", flg, i);
		if (flg) {
			r = i - 1;
			break;
		}
	}
	For(i, 0, r) {
		printf("%c", s[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}

/*
int main() {
	char inp1[10000], inp2[10000];
	char s[30];

	scanf("%[^\n]%*c", &inp1);
	scanf("%[^\n]%*c", &inp2);

	int cnt = 0;
	char ch1, ch2;
	int now = 0;
	while (cnt < 30) {
		ch1 = inp1[now];
		ch2 = inp2[now];
		// printf("%c %c\n", ch1, ch2);
		int nch1 = (int)ch1, nch2 = (int)ch2;
		if ((65 <= nch1 && nch1 <= 90) || (97 <= nch1 && nch1 <= 122)) {
			int dif = 0;
			if (nch2 - nch1 < 0) {
				dif = nch2 + 26 - nch1;
			}
			else {
				dif = nch2 - nch1;
			}
			// printf("%d %d %d\n", nch1, nch2, dif);
			s[cnt] = (char)(97 + dif);
			cnt++;
		}
		now++;
	}

	int r = 0;
	For(i, 2, 15) {
		int now = 0, flg = 1;
		For(j, 0, 29) {
			// printf("%c %c\n", s[now], s[j]);
			if (s[now] != s[j]) {
				flg = 0;
				break;
			}
			now = (now + 1) % i;
		}
		// printf("%d %d\n", flg, i);
		if (flg) {
			r = i - 1;
			break;
		}
	}
	For(i, 0, r) {
		printf("%c", s[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}
*/
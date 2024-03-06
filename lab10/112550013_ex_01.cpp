#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define For(z, x, y) for(int z = x; z <= y; z ++)

typedef struct _grade{
	int Chinese, Math, English, computer_science;
} grade;

struct student {
	char name[10];
	int student_id;
	grade student_grade;
} st[10];

int main() {
	// FILE* fptr;
	// fptr = fopen("input.txt", "r");

	int cnt = 0;
	int n_st = 5, n_a = 6, n_q = 4;
	/*
	if (fptr != NULL) {
		fscanf(fptr, "%d %d %d\n", &n_st, &n_a, &n_q);
		fscanf(fptr, "%*[^\n]%*c");
		while (cnt < n_st) {
			student tmp;
			fscanf(fptr, "%s", &tmp.name);
			fscanf(fptr, "%d", &tmp.student_id);
			fscanf(fptr, "%d", &tmp.student_grade.Chinese);
			fscanf(fptr, "%d", &tmp.student_grade.Math);
			fscanf(fptr, "%d", &tmp.student_grade.English);
			fscanf(fptr, "%d", &tmp.student_grade.computer_science);
			st[cnt] = tmp;
			cnt++;
		}
	}
	fclose(fptr);
	*/

	strcpy(st[0].name, "Bob");
	st[0].student_id = 309553045;
	st[0].student_grade.Chinese = 0;
	st[0].student_grade.Math = 10;
	st[0].student_grade.English = 20;
	st[0].student_grade.computer_science = 30;

	strcpy(st[1].name, "Kevin");
	st[1].student_id = 309551116;
	st[1].student_grade.Chinese = 100;
	st[1].student_grade.Math = 100;
	st[1].student_grade.English = 50;
	st[1].student_grade.computer_science = 100;

	strcpy(st[2].name, "Dave");
	st[2].student_id = 309551110;
	st[2].student_grade.Chinese = 59;
	st[2].student_grade.Math = 80;
	st[2].student_grade.English = 43;
	st[2].student_grade.computer_science = 70;

	strcpy(st[3].name, "Steve");
	st[3].student_id = 309552003;
	st[3].student_grade.Chinese = 95;
	st[3].student_grade.Math = 33;
	st[3].student_grade.English = 10;
	st[3].student_grade.computer_science = 99;

	strcpy(st[4].name, "Staurt");
	st[4].student_id = 309552052;
	st[4].student_grade.Chinese = 80;
	st[4].student_grade.Math = 40;
	st[4].student_grade.English = 70;
	st[4].student_grade.computer_science = 80;


	int res[10][10];
	char resc[10][20];

	For(i, 0, 9) {
		For(j, 0, 9) {
			res[i][j] = -1;
		}
	}

	// printf("Input queries score:\n");
	For(i, 0, n_q - 1) {
		char tmp[10];
		int sc = 0;
		scanf("%[^\n]%*c", &tmp);
		// printf("%s", tmp);
		for (int j = 0; j <= 6; j++) {
			// printf("%c", tmp[j]);
			if ((tmp[j] >= '0') && (tmp[j] <= '9')) {
				sc = sc * 10 + (tmp[j] - '0');
			}
		}
		// printf("%d\n", sc);
		cnt = 0;

		if (tmp[0] == 'C') {
			if (tmp[1] == 'S') {
				strcpy(resc[i], "ComputerScience");
				For(j, 0, n_st - 1) {
					if (st[j].student_grade.computer_science < sc) {
						res[i][cnt] = st[j].student_id;
						cnt++;
					}
				}
			}
			else {
				strcpy(resc[i], "Chinese");
				For(j, 0, n_st - 1) {
					if (st[j].student_grade.Chinese < sc) {
						res[i][cnt] = st[j].student_id;
						cnt++;
					}
				}
			}
		}
		else if (tmp[0] == 'M') {
			strcpy(resc[i], "Math");
			For(j, 0, n_st - 1) {
				if (st[j].student_grade.Math < sc) {
					res[i][cnt] = st[j].student_id;
					cnt++;
				}
			}
		}
		else {
			strcpy(resc[i], "English");
			For(j, 0, n_st - 1) {
				if (st[j].student_grade.English < sc) {
					res[i][cnt] = st[j].student_id;
					cnt++;
				}
			}
		}
	}

	printf("Result:\n");
	For(i, 0, n_q - 1) {
		printf("%s:", resc[i]);

		cnt = 0;
		while (res[i][cnt] != -1) {
			if (cnt != 0) printf(" ");
			printf("%d", res[i][cnt]);
			cnt++;
		}
		printf("\n");
	}

	system("pause");
	return 0;
}

/*
C 60
M 40
E 75
CS 20
*/
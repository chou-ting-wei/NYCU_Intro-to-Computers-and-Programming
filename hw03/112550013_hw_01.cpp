#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>

int main() {
	int n;
	scanf("%d", &n);

	int st = 0;

	while (n--) {
		int a;
		scanf("%d", &a);

		if (st == 0) {
			if (a == 60 || a == 43) st = 1;
			else if (a == 10) st = 3;
			else if (a == 34 || a == 16) st = 5;
			else continue;
		}
		else if (st == 1) {
			if (a == 30 || a == 87) st = 2;
			else if (a == 15) st = 6;
		}
		else if (st == 2) {
			if (a == 23 || a == 99) st = 7;
			else st = 0;
		}
		else if (st == 3) {
			st = 2;
		}
		else if (st == 4) {
			st = 7;
		}
		else if (st == 5) {
			if (a == 8) st = 4;
			else if (a == 92) st = 6;
		}
		else if (st == 6) {
			if (a == 40 || a == 56 || a == 62) st = 4;
			else st = 5;
		}
		else {
			continue;
		}
	}
	
	if (st == 0) printf("You are in Start.\n");
	else if (st == 1) printf("You are in S1.\n");
	else if (st == 2) printf("You are in S2.\n");
	else if (st == 3) printf("You are in S3.\n");
	else if (st == 4) printf("You are in S4.\n");
	else if (st == 5) printf("You are in S5.\n");
	else if (st == 6) printf("You are in S6.\n");
	else printf("You are in Final.\n");

	system("pause");
	return 0;
}
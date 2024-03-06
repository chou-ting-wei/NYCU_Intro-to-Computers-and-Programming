#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <ctime>

int main() {
	srand(time(0));
	int ans = rand() % 20;
	int l = 0, r = 19;

	while (true) {
		int now = rand() % 20;
		if (now < l || now > r) {
			continue;
		}
		if (now == ans) {
			printf("You win, answer is %d\n", now);
			break;
		}
		else {
			if (now < ans) {
				printf("Guess %d, too small.\n", now);
				l = now + 1;
			}
			else {
				printf("Guess %d, too large.\n", now);
				r = now - 1;
			}
		}
	}

	system("pause");
	return 0;
}
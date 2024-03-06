#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define For(z, x, y) for(int z = x; z <= y; z ++)

struct AoT_Player {
	int player_id;
	char name[10];
}player[] = { {2, "Mikasa"}, {4, "Armin"}, {1, "Eren"}, {5, "Levi"}, {3, "Christa"} };

int main() {
	For(i, 0, 4) {
		For(j, i + 1, 4) {
			if (player[i].player_id > player[j].player_id) {
				struct AoT_Player tmp = player[i];
				player[i] = player[j];
				player[j] = tmp;
			}
		}
	}


	For(i, 0, 4) {
		printf("{%d,%s}\n", player[i].player_id, player[i].name);
	}

	system("pause");
	return 0;
}
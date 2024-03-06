#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define For(z, x, y) for(int z = x; z <= y; z ++)

struct Node {
	int id, money;
	struct Node* nxt;
};

struct Node* init(int _id, int _money) {
	struct Node* ret = (struct Node*)malloc(sizeof(struct Node));
	ret->id = _id;
	ret->money = _money;
	ret->nxt = NULL;

	return ret;
}

int main() {
	int t;
	scanf("%d", &t);

	struct Node* head = init(0, 0);

	while (t--) {
		int k;
		scanf("%d", &k);

		if (k == 1) {
			int idx;
			scanf("%d", &idx);
			struct Node* tmp = head;
			while ((idx--)&&tmp) {
				tmp = tmp->nxt;
			}
			tmp->nxt = (tmp->nxt->nxt);
		}
		else if (k == 2) {
			int id, money;
			scanf("%d %d", &id, &money);
			
			struct Node* node = init(id, money);

			if (head == NULL) {
				head = node;
			}
			else {
				struct Node* tmp = head;
				while (tmp->nxt) {
					tmp = tmp->nxt;
				}
				tmp->nxt = node;
			}
		}
		else {
			int id, money, idx;
			scanf("%d %d %d", &id, &money, &idx);
			struct Node* node = init(id, money);

			struct Node* tmp = head;
			while ((idx-- > 0) && tmp) {
				tmp = tmp->nxt;
			}
			node->nxt = tmp->nxt;
			tmp->nxt = node;
		}
	}

	struct Node* tmp = head->nxt;
	while (tmp) {
		printf("ID money: %d %d\n", tmp->id, tmp->money);
		tmp = tmp->nxt;
	}

	system("pause");
	return 0;
}
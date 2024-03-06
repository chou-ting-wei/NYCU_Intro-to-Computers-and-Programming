#include <stdlib.h>
#include <time.h>
#include "struct.h"

void construct(DeckOfCards* deck) {
    deck->currentCard = 0;
    deck->desk = (Card*)malloc(sizeof(Card) * 52);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            deck->desk[i * 13 + j].suit = i;
            deck->desk[i * 13 + j].face = j;
            deck->currentCard++;
        }
    }
}

void shuffle(DeckOfCards* deck) {
    srand(time(0));
    for (int i = 0; i < 52; i++) {
        for (int j = 0; j < 52; j++) {
            if (i == j) continue;
            if (rand() % 2) {
                Card tmp = deck->desk[i];
                deck->desk[i] = deck->desk[j];
                deck->desk[j] = tmp;
            }
        }
    }
}

int compare(Card player1, Card player2) {
    return (player1.face > player2.face) ? 1 : (player1.face == player2.face ? (player1.suit > player2.suit ? 1 : 0) : 0);
}

typedef struct __Card {
	int face;
	int suit;
} Card;

typedef struct __DeckOfCards {
	Card* desk;
	int currentCard;
} DeckOfCards;

void shuffle(DeckOfCards*);
int compare(Card, Card);
void construct(DeckOfCards*);
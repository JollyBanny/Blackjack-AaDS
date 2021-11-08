#include "card.h"
#include "queue.h"
#include "structures.h"
#include <stdio.h>
#include <stdlib.h>

Card *newCard(int i, int j) {
	Card *card = (Card *)malloc(sizeof(Card));
	card->suit = i;
	card->name = j;
	return card;
}

int cardScore(Player *user) {
	int score = user->total;
	int cardName = user->cards->tail->card->name;
	if (cardName == 14) {
		if (score > 10)
			return 1;
		else
			return 11;
	}
	return cardName >= 10 ? 10 : cardName;
}

char CardGetName(Card *card) {
	char c;
	switch (card->name) {
    case 11: {
      c = 'J';
      break;
    }
    case 12: {
      c = 'Q';
      break;
    }
    case 13: {
      c = 'K';
      break;
    }
    case 14: {
      c = 'A';
      break;
    }
	}
	return c;
}

char *CardGetSuit(Card *card) {
	char *c;
	switch (card->suit) {
    case 1: {
      c = "♥";
      break;
    }
    case 2: {
      c = "♦";
      break;
    }
    case 3: {
      c = "♣";
      break;
    }
    case 4: {
      c = "♠";
      break;
    }
	}
	return c;
}

void CardPrint(Card *card, int i) {
	char c;
	if (i == 0) {
		printf("----------- ");
	} else if (i == 1 && card->name > 10) {
		printf("| %2c      | ", CardGetName(card));
	} else if (i == 1 && card->name <= 10) {
		printf("| %2d      | ", card->name);
	} else if (i == 3) {
		printf("|    %s    | ", CardGetSuit(card));
	} else if (i == 5 && card->name > 10) {
		printf("|     %2c  | ", CardGetName(card));
	} else if (i == 5 && card->name <= 10) {
		printf("|     %2d  | ", card->name);
	} else if (i == 6) {
		printf("----------- ");
	} else
		printf("|         | ");
}

void CardsDisplay(Queue *queue) {
	for (int i = 0; i < 7; ++i) {
		for (QueueNode *node = QueuePeek(queue); node; node = node->next) {
			CardPrint(node->card, i);
		}
		printf("\n");
	}
}
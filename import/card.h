#ifndef CARD_HEADER
#define CARD_HEADER

#include "structures.h"

Card *newCard(int i, int j);

int cardScore(Player *user);

char CardGetName(Card *card);

char *CardGetSuit(Card *card);

void CardPrint(Card *card, int i);

void CardsDisplay(Queue *queue);

#endif
#ifndef BJ_HEADER
#define BJ_HEADER

#include "structures.h"
#include "player.h"
#include <stdbool.h>

BlackJack *newBlackJack();

void BlackJackStart(BlackJack *bj);

void DeckReturn(Queue *deck, Queue *cards);

void BlackJackEnd(BlackJack *bj);

void BlackJackDisplay(BlackJack *bj);

bool UserPlay(int total, int flag);

bool ComputerPlay(int total, int flag);

void UserWin(BlackJack *bj);

#endif
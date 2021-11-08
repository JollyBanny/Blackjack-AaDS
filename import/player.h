#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include "structures.h"

Player *newPlayer();

int PlayerTakeCard(Player *player, Queue *deck);

#endif
#include "structures.h"
#include "queue.h"
#include "card.h"
#include <stdio.h>
#include <stdlib.h>

Player *newPlayer() {
	Player *player = (Player *)malloc(sizeof(Player));
	player->cards = newQueue();
	player->total = 0;
	return player;
}

int PlayerTakeCard(Player *player, Queue *deck) {
	QueuePush(player->cards, QueuePop(deck));
	player->total += cardScore(player);
	return player->total;
}
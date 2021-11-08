#ifndef STRUCTURES_HEADER
#define STRUCTURES_HEADER

struct Card {
	char suit;
	int name;
} typedef Card;

typedef struct QueueNode {
	Card *card;
	struct QueueNode *next;
} QueueNode;

typedef struct Queue {
	QueueNode *head;
	QueueNode *tail;
	int size;
} Queue;

typedef struct Player {
	Queue *cards;
	int total;
} Player;

typedef struct BlackJack {
	Queue *deck;
	Player *computer;
	Player *user;

} BlackJack;

#endif
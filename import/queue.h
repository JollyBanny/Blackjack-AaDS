#ifndef QUEUE_HEADER
#define QUEUE_HEADER

#include "structures.h"
#include "utilities.h"

QueueNode *newNode(Card *c);

Queue *newQueue();

int QueueGetSize(Queue *queue);

void QueuePush(Queue *q, QueueNode *node);

QueueNode *QueuePeek(Queue *queue);

QueueNode *QueuePop(Queue *queue);

void createDeck(Queue *queue);

void ShuffleQueue(Queue *queue);
#endif
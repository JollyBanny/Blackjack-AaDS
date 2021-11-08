#include "structures.h"
#include "utilities.h"
#include "card.h"
#include <stdio.h>
#include <stdlib.h>

QueueNode *newNode(Card *c) {
	QueueNode *node = (QueueNode *)malloc(sizeof(QueueNode));
	node->card = c;
	node->next = NULL;
	return node;
}

Queue *newQueue() {
	Queue *queue = (Queue *)malloc(sizeof(Queue));
	queue->head = NULL;
	queue->tail = NULL;
	queue->size = 0;
	return queue;
}

int QueueGetSize(Queue *queue) { return queue->size; }

void QueuePush(Queue *q, QueueNode *node) {
	node->next = NULL;
	if (q->head) {
		q->tail->next = node;
		q->tail = node;
	} else
		q->head = q->tail = node;
	q->size++;
}

QueueNode *QueuePeek(Queue *queue) { return queue->head; }

QueueNode *QueuePop(Queue *queue) {
	QueueNode *item = queue->head;
	queue->head = queue->head->next;
	queue->size--;
	return item;
}

void createDeck(Queue *queue) {
	for (int i = 1; i < 5; ++i) {
		for (int j = 2; j < 15; ++j) {
			QueueNode *node = newNode(newCard(i, j));
			QueuePush(queue, node);
		}
	}
}

void ShuffleQueue(Queue *queue) {
	for (int i = 0; i < 10000; ++i) {
		QueueNode *node = QueuePeek(queue);
		for (int j = 0; j < random_(QueueGetSize(queue)); ++j) {
			node = node->next;
		}
		swap_(node, node->next, queue);
		QueuePush(queue, QueuePop(queue));
	}
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "card.h"
#include "queue.h"
#include "structures.h"
#include "utilities.h"

int random_(int a) {
	int r = rand() % a;
	return r;
}

void swap_(QueueNode *prev, QueueNode *cur, Queue *deck) {
	prev->next = cur->next;
	QueuePush(deck, cur);
	deck->size--;
}

void clearDisplay() {
#if __unix__ || __linux__ || __APPLE__ || __MACH__
	system("clear");
#elif _WIN32
	system("cls");
#else
	puts("what the OS says?");
#endif
}

char *createLogFile() {
	time_t rawtime;
	struct tm *timeinfo;
	char *buffer = (char *)malloc(
		80 * sizeof(char)); // строка, в которой будет храниться текущее время
	time(&rawtime);			// текущая дата в секундах
	timeinfo = localtime(
		&rawtime); // текущее локальное время, представленное в структуре
	// strftime(buffer, 80, "%d-%m-%Y %X.txt", timeinfo);
	strftime(buffer, 80, "logs//%d-%m-%Y %H.%M.%S.txt", timeinfo);
	return buffer;
}

void logging(BlackJack *bj) {
	FILE *file = fopen(createLogFile(), "w");

	QueueNode *node;
	fprintf(file, "+------------------+\n");
	fprintf(file, "User: %d\n", bj->user->total);
	node = QueuePeek(bj->user->cards);
	while (node) {
		if (node->card->name > 10)
			fprintf(file, "%s%c ", CardGetSuit(node->card),
					CardGetName(node->card));
		else
			fprintf(file, "%s%d ", CardGetSuit(node->card), node->card->name);
		node = node->next;
	}
	fprintf(file, "\n+------------------+\n");
	fprintf(file, "Dealer: %d\n", bj->computer->total);
	node = QueuePeek(bj->computer->cards);
	while (node) {
		if (node->card->name > 10)
			fprintf(file, "%s%c ", CardGetSuit(node->card),
					CardGetName(node->card));
		else
			fprintf(file, "%s%d ", CardGetSuit(node->card), node->card->name);
		node = node->next;
	}
	fprintf(file, "\n+------------------+\n");
	if ((bj->user->total > bj->computer->total && bj->user->total <= 21) ||
		(bj->computer->total > 21)) {
		fprintf(file, "Verdict: User win");
	} else if (bj->user->total == bj->computer->total) {
		fprintf(file, "Verdict: Draw");
	} else {
		fprintf(file, "Verdict: Dealer win");
	}
	fclose(file);
}
#ifndef UTILITIES_HEADER
#define UTILITIES_HEADER

#include "structures.h"
#include "utilities.h"
#include <stdio.h>

int random_(int a);

void swap_(QueueNode *prev, QueueNode *cur, Queue *deck);

void clearDisplay();

char *createLogFile();

void logging(BlackJack *bj);

#endif
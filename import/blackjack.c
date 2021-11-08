#include "blackjack.h"
#include "card.h"
#include "player.h"
#include "queue.h"
#include "structures.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

BlackJack *newBlackJack() {
	BlackJack *bj = (BlackJack *)malloc(sizeof(BlackJack));
	bj->deck = newQueue();
	createDeck(bj->deck);
	bj->user = newPlayer();
	bj->computer = newPlayer();
	return bj;
}

void BlackJackStart(BlackJack *bj) {
	ShuffleQueue(bj->deck);
	PlayerTakeCard(bj->user, bj->deck);
	PlayerTakeCard(bj->user, bj->deck);
	PlayerTakeCard(bj->computer, bj->deck);
}

void DeckReturn(Queue *deck, Queue *cards) {
	QueueNode *node = QueuePeek(cards);
	while (node) {
		QueuePush(deck, QueuePop(cards));
		node = QueuePeek(cards);
	}
}

void BlackJackEnd(BlackJack *bj) {
	logging(bj);
	bj->user->total = 0;
	bj->computer->total = 0;
	DeckReturn(bj->deck, bj->computer->cards);
	DeckReturn(bj->deck, bj->user->cards);
}

void BlackJackDisplay(BlackJack *bj) {
	clearDisplay();
	printf("+------------------------------------------------------------------"
		   "---------+"
		   "\n");
	printf("User: %d\n", bj->user->total);
	CardsDisplay(bj->user->cards);
	printf("Dealer: %d\n", bj->computer->total);
	CardsDisplay(bj->computer->cards);
	printf("+------------------------------------------------------------------"
		   "---------+"
		   "\n");
}

bool UserPlay(int total, int flag) { return total < 21 && !flag; }

bool ComputerPlay(int total, int flag) { return flag && total < 17; }

void WinDisplay() {
	printf("   .      ..                          ..       ..  ......  ..    "
		   "..        ...\n"
		   " |  .    /  .                        |  .  _  |  .|      .|  .  |  "
		   ".      |  .\n"
		   "  .$$.  /  $$______   __    __       | $$ / . | $$ .$$$$$$| $$. | "
		   "$$      | $$\n"
		   "   .$$./  $$/      . |  .  |  .      | $$/  $.| $$  | $$  | $$$.| "
		   "$$      | $$\n"
		   "    .$$  $$|  $$$$$$.| $$  | $$      | $$  $$$. $$  | $$  | $$$$. "
		   "$$      | $$\n"
		   "     .$$$$ | $$  | $$| $$  | $$      | $$ $$.$$.$$  | $$  | $$.$$ "
		   "$$       .$$\n"
		   "     | $$  | $$__/ $$| $$__/ $$      | $$$$  .$$$$ _| $$_ | $$ "
		   ".$$$$       __ \n"
		   "     | $$   .$$    $$ .$$    $$      | $$$    .$$$|   $$ .| $$  "
		   ".$$$      |  .\n"
		   "      .$$    .$$$$$$   .$$$$$$        .$$      .$$ .$$$$$$ .$$   "
		   ".$$       .$$\n");
}

void LoseDisplay() {
	printf(
		"\n /$$     /$$                        /$$        /$$$$$$   /$$$$$$  "
		"/$$$$$$$$\n"
		"|  $$   /$$/                       | $$       /$$__  $$ /$$__  $$| "
		"$$_____/\n"
		" .  $$ /$$//$$$$$$  /$$   /$$      | $$      | $$  . $$| $$  .__/| $$ "
		" "
		"    \n"
		"  .  $$$$//$$__  $$| $$  | $$      | $$      | $$  | $$|  $$$$$$ | "
		"$$$$$   \n"
		"   .  $$/| $$  . $$| $$  | $$      | $$      | $$  | $$ .____  $$| "
		"$$__/   \n"
		"    | $$ | $$  | $$| $$  | $$      | $$      | $$  | $$ /$$  . $$| $$ "
		" "
		"    \n"
		"    | $$ |  $$$$$$/|  $$$$$$/      | $$$$$$$$|  $$$$$$/|  $$$$$$/| "
		"$$$$$$$$\n"
		"    |__/  .______/  .______/       |________/ .______/  .______/ "
		"|________/\n");
}

void DrawDisplay() {
	printf("                  $$.                                  \n"
		   "                  $$ |                                 \n"
		   "             $$$$$$$ | $$$$$$.  $$$$$$.  $$.  $$.  $$. \n"
		   "            $$  __$$ |$$  __$$. .____$$. $$ | $$ | $$ |\n"
		   "            $$ /  $$ |$$ |  .__|$$$$$$$ |$$ | $$ | $$ |\n"
		   "            $$ |  $$ |$$ |     $$  __$$ |$$ | $$ | $$ |\n"
		   "            .$$$$$$$ |$$ |     .$$$$$$$ |.$$$$$.$$$$  |\n"
		   "             ._______|.__|      ._______| ._____.____/ \n");
}

void UserWin(BlackJack *bj) {
	clearDisplay();
	if ((bj->user->total > bj->computer->total && bj->user->total <= 21) ||
		(bj->computer->total > 21)) {
		WinDisplay();
		return;
	} else if (bj->user->total == bj->computer->total) {
		DrawDisplay();
		return;
	} else
		LoseDisplay();
}
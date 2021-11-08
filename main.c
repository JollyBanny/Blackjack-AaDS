#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "import/blackjack.h"

int main() {
	srand(time(NULL));
	BlackJack *blackjack = newBlackJack();
	while (true) {
		BlackJackStart(blackjack);
		Player *player = blackjack->user;
		int total = 0, flag = 0, end = 0;
		BlackJackDisplay(blackjack);
		while (UserPlay(player->total, flag) ||
			   ComputerPlay(player->total, flag)) {
			int choice;
			printf("Do you want to get card?\n1. Yes\t2. No\n");
			if (!flag) {
				scanf("%d", &choice);
			}
			if (choice == 1 || flag) {
				total = PlayerTakeCard(player, blackjack->deck);
			} else {
				flag = 1;
				total = 0;
				player = blackjack->computer;
			}
			BlackJackDisplay(blackjack);
			sleep(1);
		}
		UserWin(blackjack);
		BlackJackEnd(blackjack);
		while (end != 1 && end != 2) {
			printf("\n%50s", "----------------------------\n");
			printf("%50s", "| Do you wanna play again? |\n");
			printf("%50s", "|      1. Yes   2. No      |\n");
			printf("%50s", "----------------------------\n");
			scanf("%d", &end);
		}
		if (end == 2) {
			break;
		}
	}
	return 0;
}
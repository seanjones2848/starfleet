#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{
	struct s_tank *tank = initTank();
	write(1, "init tank done\n", 15);
	/*-------------------
	launch your test here
	--------------------*/
	tankPush(tank, 10);
	printf("pushed 10\n");
	tankPush(tank, 50);
	printf("pushed 50\n");
	for (int i = 0; i < 20; i++) {
		tankPush(tank, 100);
		printf("pushed 100\n");
	}
	for (int k = 0; k < tank->n; k++)
		printf("{main}Tank %d: energy: %d\n", k + 1, tank->stacks[k]->sum);
	for (int j = 0; j < 25; j++)
		printf("{main}tank pop gives me: {%d}\n", tankPop(tank));
	for (int k = 0; k < tank->n; k++)
		printf("{main}Tank %d: energy: %d\n", k + 1, tank->stacks[k]->sum);
	for (int i = 0; i < 30; i++) {
		tankPush(tank, 100);
		printf("pushed 10\n");
	}
	for (int i = 0; i < 20; i++) {
		tankPush(tank, 30);
		printf("pushed 30\n");
	}
	for (int i = 0; i < 20; i++) {
		tankPush(tank, 10);
		printf("pushed 100\n");
	}
	for (int k = 0; k < tank->n; k++)
		printf("{main}Tank %d: energy: %d\n", k + 1, tank->stacks[k]->sum);
	for (int j = 0; j < 75; j++)
		printf("{main}tank pop gives me: {%d}\n", tankPop(tank));


	return (0);
}



// Function used for the test
// Don't go further :)

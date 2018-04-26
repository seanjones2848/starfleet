#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{

	/*-------------------
	launch your test here
	--------------------*/

	struct s_queue *queue;

	printf("initializing empty queue\n");
	queue = queueInit();
	printf("The empty queue should return 1: {%d}\n", isEmpty(queue));
	printf("Enqueue %s, and %s to the queue\n", "ferp", "derp");
	enqueue(queue, "ferp");
	enqueue(queue, "derp");
	printf("Checking to see if ferp is there with peek: {%s}\n", peek(queue));
	printf("Now dequeue should return ferp as well: {%s}\n", dequeue(queue));
	printf("checking to see if its empty should return 0: {%d}\n", isEmpty(queue));
	printf("Now dequeue should return derp: {%s}\n", dequeue(queue));
	printf("peek should return NULL: {%s}\n", peek(queue));

	return (0);
}



// Function used for the test
// Don't go further :)


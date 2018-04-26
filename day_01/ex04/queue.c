#include <stdlib.h>
#include "header.h"

struct s_queue *queueInit(void) {
	struct s_queue *queue;

	if ((queue = (struct s_queue*)malloc(sizeof(struct s_queue)))) {
		queue->first = NULL;
		queue->last = NULL;
	}
	return queue;
}

char *dequeue(struct s_queue *queue) {
	char *message = NULL;

	if (queue->first) {
		message = queue->first->message;
		if (queue->first->next)
			queue->first = queue->first->next;
		else {
			queue->first = NULL;
			queue->last = NULL;
		}
		return message;
	}
	return NULL;
}

void enqueue(struct s_queue *queue, char *message) {
	struct s_node *item;

	if ((item = (struct s_node*)malloc(sizeof(struct s_node)))) {
		item->message = message;
		item->next = NULL;
	}
	if (queue->first == NULL && queue->last == NULL) {
		queue->first = item;
		queue->last = item;
	}
	else {
		queue->last->next = item;
		queue->last = item;
	}
}

char *peek(struct s_queue *queue) {
	if (queue->first)
		return queue->first->message;
	return NULL;
}

int isEmpty(struct s_queue *queue) {
	if (queue->first == NULL && queue->last == NULL)
		return 1;
	return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include "header.h"

struct s_tank *initTank(void) {
	struct s_tank *tank;

	if (!(tank = (struct s_tank*)malloc(sizeof(struct s_tank)))) {
		return NULL;
	}
	tank->stacks = NULL;
	tank->n = 0;
	return tank;
}

struct s_stack *initStack(int energy) {
	struct s_stack *stack;
	struct s_elem *elem;

	if (!(stack = (struct s_stack*)malloc(sizeof(struct s_stack))))
		return NULL;
	if (!(elem = (struct s_elem*)malloc(sizeof(struct s_elem))))
		return NULL;
	elem->energy = energy;
	elem->next = NULL;
	stack->elem = elem;
	stack->sum = energy;
	return stack;
}

void tankPush(struct s_tank *tank, int energy) {
	struct s_elem *elem;
	struct s_stack *new;
	struct s_stack **tmp;

	if ((elem = (struct s_elem*)malloc(sizeof(struct s_elem)))) {
		elem->energy = energy;
		elem->next = NULL;
	}
	if (!tank->stacks) {
		if (!(tank->stacks = (struct s_stack**)malloc(tank->n * sizeof(struct s_stack*))))
			return;
		tank->stacks[tank->n] = initStack(energy);
		tank->n += 1;
	}
	else if (energy + tank->stacks[tank->n - 1]->sum <= 1000) {
		elem->next = tank->stacks[tank->n - 1]->elem;
		tank->stacks[tank->n - 1]->elem = elem;
		tank->stacks[tank->n - 1]->sum += energy;
	}
	else {
		tank->n += 1;
		new = initStack(energy);
		if (!(tmp = (struct s_stack**)malloc(tank->n * sizeof(struct s_stack)))) {
			return;
		}
		for (int i = 0; i < tank->n; i++) {
			tmp[i] = tank->stacks[i];
		}
		tmp[tank->n - 1] = new;
		tank->stacks = tmp;
	}
}

int tankPop(struct s_tank *tank) {
	int ret;

	if (tank->n == 0)
		return 0;
	ret = tank->stacks[tank->n - 1]->elem->energy;
	if (tank->stacks[tank->n - 1]->elem->next) {
		tank->stacks[tank->n - 1]->sum -= ret;
		tank->stacks[tank->n - 1]->elem = tank->stacks[tank->n - 1]->elem->next;
	}
	else {
		if (tank->n > 0)
			--tank->n;
		if (tank->n == 0)
			tank->stacks = NULL;
	}
	return ret;
}

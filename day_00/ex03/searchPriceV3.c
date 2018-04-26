#include <stdlib.h>
#include <string.h>
#include "header.h"

size_t hash(char *input) {
	size_t ret = 0;
	int i = 0;

	while (input[i])
		ret += input[i++];
	return ret;
}

struct s_dict	*dictInit(int capacity) {
	struct s_dict *ret;

	if ((ret = (struct s_dict*)malloc(sizeof(struct s_dict)))) {
		ret->capacity = capacity;
		ret->items = (struct s_item**)malloc(sizeof(struct s_item) * capacity);
	}
	return ret;
}

int		dictInsert(struct s_dict *dict, char *key, struct s_art *value) {
	struct s_item	*head;
	struct s_item	*item;
	int				idx;

	idx = (int)(hash(key) % dict->capacity);
	if ((item = (struct s_item*)malloc(sizeof(struct s_item)))) {
		item->key = key;
		item->value = value;
		item->next = NULL;
	}
	if (dict->items[idx]) {
		head = dict->items[idx];
		while (dict->items[idx]->next != NULL)
			dict->items[idx] = dict->items[idx]->next;
		dict->items[idx]->next = item;
		dict->items[idx] = head;
	}
	else
		dict->items[idx] = item;
	return (0);
}

struct s_art *dictSearch(struct s_dict *dict, char *key) {
	int	idx;
	struct s_item *tmp = NULL;

	idx = hash(key) % dict->capacity;
	if (dict->items[idx])
		tmp = dict->items[idx];
	while (tmp) {
		if (strcmp(key, tmp->value->name) == 0)
			return tmp->value;
		tmp = tmp->next;
	}
	return NULL;
}

int		searchPrice(struct s_dict *dict, char *name) {
	int idx;
	struct s_art *ret;

	idx = hash(name) % dict->capacity;
	if ((ret = dictSearch(dict, name)))
		return ret->price;
	return (-1);
}

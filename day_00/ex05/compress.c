#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include "header.h"

static char *checkWord(char *word, struct s_dict *dict) {
	char *sub;
	int i = 0;
	int val = 0;
	char buffer[strlen(word)];
	int r;
	char *ret = NULL;

	while (i < (int)strlen(word)) {
		sub = strndup(word, i);
		val = dictSearch(dict, sub);
		if (val > 0) {
			sprintf(buffer, "@%c", val);
			r = 2 + strlen(word) - i;
			while (i < (int)strlen(word)) {
				sprintf(buffer, "%c", word[i]);
				i++;
			}
			ret = strndup(buffer, r);
			return ret;
		}
		i++;
	}
	return word;
}

char	*compress(char *book, struct s_dict *dict) {
	int b = 0; //bible iterable
	int w; //word iterable
	int c = 0; //compressed iterable
	char *word;
	char *ret;
	//int val = 0;
	char buffer[strlen(book)];
	char *compressed;

	while (book[b]) {
		if (isalpha(book[b]) != 0) {
			w = 0;
			while (isalpha(book[b+w]) != 0) {
				w++;
			}
			word = strndup(book + b, w);
			ret = checkWord(word, dict);
			printf("this is the word:{%s} and ret:{%s}\n", word, ret);
			//printf("found word:{%s} between b:%d and b+w: %d\n", word, b, (b + w));
			//val = dictSearch(dict, word);
			//if (val > 0) {
				//sprintf(buffer + c,"@%c", val);
				//printf("\nmatched a word:%s compressing it to:@%c\n", word, val);
				//c += 2;
			//}
			//else {
				//sprintf(buffer + c, "%s", word);
				//printf("%s", word);
				//c += w;
			//}
			sprintf(buffer, "%s", ret);
			c += strlen(ret);
			b += w;
			free(word);
		}
		else {
			sprintf(buffer + c, "%c", book[b]);
			printf("%c", book[b]);
			b++;
			c++;
		}
	}
	write(1, "all done\n", 9);
	compressed = strndup(buffer, c);
	return compressed;
}

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

int		dictInsert(struct s_dict *dict, char *key, int value) {
	struct s_item	*item;
	struct s_item	*head = NULL;
	int				idx;

	idx = (int)(hash(key) % dict->capacity);
	if ((item = (struct s_item*)malloc(sizeof(struct s_item)))) {
		item->key = key;
		item->value = value;
		item->next = NULL;
	}
	if (dict->items[idx]) {
		head = dict->items[idx];
		while (dict->items[idx]->next)
			dict->items[idx] = dict->items[idx]->next;
		dict->items[idx]->next = item;
		dict->items[idx] = head;
	}
	else
		dict->items[idx] = item;
	return (0);
}

int	dictSearch(struct s_dict *dict, char *key) {
	int	idx;
	struct s_item *tmp = NULL;

	idx = (int)(hash(key) % dict->capacity);
	if (dict->items[idx])
		tmp = dict->items[idx];
	while (tmp) {
		if (strcmp(key, tmp->key) == 0)
			return tmp->value;
		tmp = tmp->next;
	}
	return -1;
}

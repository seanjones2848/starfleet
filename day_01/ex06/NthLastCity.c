#include "header.h"

char *NthLastCity(struct s_city *city, int n) {
	struct s_city *nth = city;

	for (int i = 0; i < n; i++) {
		if (!city->next)
			return "";
		city = city->next;
	}
	for (int i = 0; city->next; i++) {
		nth = nth->next;
		city = city->next;
	}
	return (nth->name);
}

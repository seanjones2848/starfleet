#include <string.h>
#include "header.h"

//d is number of characters in input alphabet
#define d 256
//q is a prime number
#define q 7919

int howManyJesus(char *bible, char *jesus) {
	int i = 0;
	int k = 0;
	int n = strlen(bible);
	int m = strlen(jesus);
	int b = 0;
	int j = 0;
	int h = 1;
	int ret = 0;

	while (i < m - 1) {
		h = (h*d) % q;
		i++;
	}
	i = 0;
	while (i < m) {
		b = (d * b + bible[i]) % q;
		j = (d * j + jesus[i]) % q;
		i++;
	}
	i = 0;
	while (i <= n - m) {
		if (b == j) {
			k = 0;
			while (k < m) {
				if (bible[i + k] != jesus[k])
					break;
				k++;
			}
			if (k == m)
				ret++;
		}
		if (i < n - m) {
			b = (d * (b - bible[i] * h) + bible[i + m]) % q;
			if (b < 0)
				b += q;
		}
		i++;
	}
	return (ret);
}

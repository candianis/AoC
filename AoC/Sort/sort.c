#include <stdint.h>
#include "sort.h"
#include "../Swap/swap.h"

void insertion_sort_int(int list_to_order[], int size) {
	size_t i, j;
	for (i = 1; i < size; i++) {
		j = i;
		while ((j > 0) && (list_to_order[j] < list_to_order[j - 1])) {
			swap_int(&list_to_order[j], &list_to_order[j - 1]);
			j = j - 1;
		}
	}
}
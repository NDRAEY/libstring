#include <stdio.h>
#include "include/string.h"

int main(void) {
	string_t* str = string_from_charptr("Terve! Olen Zeraora, Sähköistetty kissa!");

	vector_t* splat = string_split(str, " ");

	for(size_t i = 0; i < splat->size; i++) {
		printf("> [%s]\n", ADDR2STRING(splat->data[i])->data);
	}

	string_split_free(splat);

	string_destroy(str);
}
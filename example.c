#include <stdio.h>
#include "include/string.h"

int main(void) {
	string_t* str = string_from_charptr("Terve! Olen Zeraora, Sähköistetty kissa!");

	string_t* str2 = string_clone(str);

//	vector_t* splat = string_split(str, " ");
//
//	for(size_t i = 0; i < splat->size; i++) {
//		printf("> [%s]\n", ADDR2STRING(splat->data[i])->data);
//	}
//
//	string_split_free(splat);

	string_append_charptr(str2, " But this string is cloned...");

	printf("%s\n", str->data);
	printf("%s\n", str2->data);

	string_destroy(str);
	string_destroy(str2);
}
#include <stdio.h>
#include "include/string.h"

int main(void) {
	string_t* str = string_new();
	string_t* str2 = string_new();

	string_append_charptr(str, "Hello");
	string_append_charptr(str2, ", world!");
	string_append(str, str2);

	string_crop(str, 3, 5);

	printf("%s\n", str->data);

	string_destroy(str);
	string_destroy(str2);
}
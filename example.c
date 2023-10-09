#include <stdio.h>
#include "include/string.h"

int main(void) {
	string_t* str = string_new();
	string_t* str2 = string_new();

	string_append_charptr(str, "Hello");
	string_append_charptr(str2, ", world! ");
	string_append(str, str2);

	string_crop(str, 3, 5);

	string_append_char(str, 'a');
	string_append_char(str, 'b');
	string_append_char(str, 'c');
	string_append_char(str, 'd');
	string_append_char(str, '1');
	string_append_char(str, '2');
	string_append_char(str, '3');

	printf("%s\n", str->data);

	string_destroy(str);
	string_destroy(str2);
}
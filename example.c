#include <stdio.h>
#include "include/string.h"

int main(void) {
	string_t* str = string_from_integer(0);

    printf("%s\n", str->data);

	string_destroy(str);
}

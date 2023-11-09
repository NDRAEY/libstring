#include <stdio.h>
#include "include/string.h"

int main(void) {
	string_t* str = string_from_charptr("Hello 12345! 6789 I lOvE TeXt    TEST ");
	vector_t* vec = string_split(str, " ");

	printf("STR LEN: %ld\n", str->length);
	printf("VEC LEN: %ld\n", vec->size);

	for(size_t i = 0; i < vec->size; i++) {
		printf("[%s]\n", ((string_t*)(vec->data[i]))->data);
	}

	string_split_free(vec);
	string_destroy(str);

}

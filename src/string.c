//
// Created by ndraey on 04.10.23.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../include/string.h"

string_t* string_new() {
	string_t* string = calloc(sizeof *string, 1);

	string->data = calloc(1, 1);
	string->length = 0;

	return string;
}

void string_append_charptr(string_t* string, const char* concatenable) {
	if(!string || !concatenable)
		return;

	size_t len = strlen(concatenable);

	size_t alloc_len = len + string->length;

	char* memory = (char*)realloc(string->data, alloc_len + 1);

	if(!memory)
		return;

	memory[alloc_len] = 0;

	string->data = memory;

	if(string->data[0] == 0) {
		strcpy(string->data, concatenable);
	} else {
		strcat(string->data, concatenable);
	}

	string->length = alloc_len;
}

void string_append(string_t* string, const string_t* concatenable) {
	if(!string || !concatenable)
		return;

	string_append_charptr(string, concatenable->data);
}

void string_crop(string_t* string, size_t start, size_t end) {
	if(!string || start >= end || end > string->length)
		return;

	size_t new_length = end - start;

	char* data = malloc(new_length + 1);

	if(!data)
		return;

	data[new_length] = 0;

	memcpy(data, string->data + start, new_length);

	free(string->data);

	string->data = data;
	string->length = new_length;
}

void string_append_char(string_t* string, char ch) {
	if(!string)
		return;

	char* data = realloc(string->data, string->length + 2);

	if(!data)
		return;

	data[string->length] = ch;
	data[string->length + 1] = 0;

	string->length++;

	string->data = data;
}

void string_destroy(string_t *string) {
	if(string->data)
		free(string->data);

	free(string);
}
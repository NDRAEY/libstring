//
// Created by ndraey on 04.10.23.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../include/string.h"
#include "vector.h"

string_t* string_new() {
	string_t* string = calloc(sizeof *string, 1);

	if(!string)
		return 0;

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

string_t* string_from_charptr(const char* chars) {
	string_t* str = string_new();

	if(!str)
		return 0;

	string_append_charptr(str, chars);

	return str;
}

vector_t* string_split(string_t* string, const char* delimiter) {
	if(!string || !delimiter)
		return 0;

	vector_t* vec = vector_new();

	if(!vec)
		return 0;

	char* curptr = string->data;
	size_t delim_len = strlen(delimiter);

	char* el = strstr(curptr, delimiter);

	if(!el) { // If no occurrences, just add whole string and return vector.
		string_t* str = string_new();

		string_append_charptr(str, curptr);

		vector_push_back(vec, (size_t)str);

		return vec;
	}

	while(el) {
		el = strstr(curptr, delimiter);
		size_t len = el - curptr;

		if(el == 0)
			len = strlen(curptr);

		char* temp = malloc(len + 1);
		strncpy(temp, curptr, len);
		temp[len] = 0;

		string_t* substring = string_from_charptr(temp);

		vector_push_back(vec, (size_t)substring);

		free(temp);

		curptr = el + delim_len;
	}

	return vec;
}

void string_split_free(vector_t* vec) {
	if(!vec)
		return;

	for(size_t i = 0; i < vec->size; i++) {
		string_destroy((string_t*)vec->data[i]);
	}

	vector_destroy(vec);
}

void string_destroy(string_t *string) {
	if(string->data)
		free(string->data);

	free(string);
}
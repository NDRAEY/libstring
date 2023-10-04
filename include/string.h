//
// Created by ndraey on 04.10.23.
//

#pragma once

#include <stdint.h>

typedef struct string {
	char* data;

	size_t length;
} string_t;

string_t* string_new();
void string_append_charptr(string_t* string, const char* concatenable);
void string_append(string_t* string, const string_t* concatenable);
void string_crop(string_t* string, size_t start, size_t end);
void string_destroy(string_t *string);

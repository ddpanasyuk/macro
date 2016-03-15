#ifndef _PARSE_H_
#define _PARSE_H_

#include <stdlib.h>

#define TYPE_NULL 0
#define TYPE_STRING 1
#define TYPE_INT 2
#define TYPE_SYMBOL 3
#define TYPE_HEAD 4

struct token{
	char* dat;
	char type;
	struct token* next;
	struct token* prev;
};

//tokenizes text
struct token* tokenize(char* src);

#endif

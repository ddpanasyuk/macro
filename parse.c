#include "parse.h"
#include "string.h"
#include "helper.h"

#define LIST_APPEND(X) X->next=malloc(sizeof(struct token));X->next->prev=X;X=X->next

struct token* tokenize(char* src){
	//make head token
	struct token* list = malloc(sizeof(struct token));
	struct token* curr = list;
	struct token* temp;

	//read from src
	char* read = src;
	
	//while not end of buffer
	while(*read != '\0'){
		
		//check for various token types
		char* buff;
		//if alpha character
		if(isalpha(*read)){
			//read token into buffer
			buff = apply_func_to_string(read,&isalpha);
			read += strlen(buff);
			//make new token and add to end of list
			curr->type = TYPE_STRING;
			curr->dat = strdup(buff);
			LIST_APPEND(curr);
			continue;
		}
		if(isdigit(*read)){
			buff = apply_func_to_string(read, &isdigit);
			read += strlen(buff);
			curr->type = TYPE_INT;
			curr->dat = strdup(buff);
			LIST_APPEND(curr);
			continue;
		}
		if(ispunct(*read)){
			//if it starts with a period, it may be a macro
			if(*read=='.'){
				if(read==src || isblank(*(read-1)) && isalpha(*(read+1))){
					buff=apply_func_to_string(read+1,&isalpha);
					buff=strconcat(2,".",buff);
					read += strlen(buff);
					curr->type = TYPE_STRING;
					curr->dat = strdup(buff);
					LIST_APPEND(curr);
					continue;
				}
			}
			//if not a macro...
			curr->type = TYPE_SYMBOL;
			curr->dat = malloc(sizeof(char)*2);
			sprintf(curr->dat,"%c",*read);
			read++;
			LIST_APPEND(curr);
			continue;
		}
		//iterate read if nothing found
		read++;
	}
	//add end to list
	curr->type = TYPE_NULL;
	curr->next = TYPE_NULL;
	curr->dat = TYPE_NULL;
	return list;
}

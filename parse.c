#include "parse.h"
#include "string.h"

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
			buff = malloc(sizeof(char));
			int i;
			for(i=0;isalpha(*read);i++){
				buff[i]=*read;
				buff=realloc(buff,sizeof(char)*(i+1));
				read++;
			}
			buff[i]='\0';
			//make new token and add to end of list
			curr->type = TYPE_STRING;
			curr->dat = strdup(buff);
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

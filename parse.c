#include "parse.h"
#include "string.h"

struct token* tokenize(char* src){
	//make head token
	struct token* list = malloc(sizeof(struct token));
	struct token* head = list;
	head->type = TYPE_HEAD;
	head->dat = "";
	head->prev = TYPE_NULL;
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
			temp = malloc(sizeof(struct token));
			temp->type = TYPE_STRING;
			temp->dat = strdup(buff);
			list->next = temp;
			temp->prev = list;
			list = temp;
			continue;
		}
		//iterate read if nothing found
		read++;
	}
	//add end to list
	temp = malloc(sizeof(struct token));
	temp->type = TYPE_NULL;
	temp->prev = list;
	list->next = temp;
	temp->next = TYPE_NULL;
	return head;
}

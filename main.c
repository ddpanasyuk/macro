#include "main.h"

int main(){
	struct token* myTok = tokenize("my pet rox");

	while(myTok->type != TYPE_NULL){
		printf("%s %i\n",myTok->dat,myTok->type);
		myTok = myTok->next;
	}

	return 0;
}

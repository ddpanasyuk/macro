#include "main.h"

int main(){
	struct token* myTok = tokenize(".pet .rox r.r");

	while(myTok->type != TYPE_NULL){
		printf("%s %i\n",myTok->dat,myTok->type);
		myTok = myTok->next;
	}

	return 0;
}

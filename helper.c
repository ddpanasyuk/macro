#include "helper.h"

//applies a function that checks if a character is of a certain kind
//to return a string composed soley of that char from src
char* apply_func_to_string(char* src, int (*fpointer)(int)){
	if(fpointer(*src)){
		char* temp = malloc(sizeof(char));
		int i=0;
		for(i=0;fpointer(*src);i++){
			temp[i]=*src;
			temp=realloc(temp,sizeof(char)*(i+1));
			src++;
		}
		temp[i]='\0';
		return temp;
	}
	return 0;
}

//returns a concatenation of multiple strings
char* strconcat(int n, ...){
	va_list list;
	int i;
	char* str=malloc(sizeof(char));
	char* tmp;
	str[0]='\0';
	
	va_start(list,n);
	
	for(i=0;i<n;i++){
		tmp = va_arg(list, char*);
		str = realloc(str, sizeof(char)*strlen(str)+sizeof(char)*strlen(tmp));
		strcat(str,tmp);
	}
	
	va_end(list);
	
	return str;
} 

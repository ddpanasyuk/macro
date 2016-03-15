#ifndef _MACRO_H_
#define _MACRO_H_

#define TYPE_TIMES 1
#define TYPE_MACRO 2
#define TYPE_DEF 3
#define TYPE_IF 4
#define TYPE_ELSE 5

//struct for macro table
struct mac{
	char* name;
	char type;
	char* args;
	char* replace;	
};

//creates a blank macro table
struct mac* create_macro_table();
//adds a macro to a table
int add_macro(struct mac* dest, struct mac src);
//removes a macro from a table
int rem_macro(struct mac* dest, struct mac src);
//checks for a macro in the table
int chk_macro(struct mac* dest, struct mac src);
//applies a macro to a src text and writes it to a destination
int apply_macro(struct mac* table, char* src, char* dest);

#endif

#ifndef _HELPER_H_
#define _HELPER_H_

/* HELPER.H
 *
 * A list of various helper functions, tricks, etc.
 * that I find myself reusing enough to put down in
 * one small file to include in various projects.
 *
 * Will occasionally update with cool little functions
 * I've written and want to save for later
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

//Adds together n strings into one and returns it
char* strconcat(int n,...);
//Applies a tester function to a string and returns it, use for parsing
char* apply_func_to_string(char* src, int (*fpointer)(int));

#endif 

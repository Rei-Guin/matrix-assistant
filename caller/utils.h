#ifndef _MATRIX_SUBMISSION_UTIL_
#define _MATRIX_SUBMISSION_UTIL_

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <inttypes.h>

enum utils_enum {ruler_length = 30};

void displayRuler(char sym){
	for(int i = 0 ; i < ruler_length ; ++i){
		printf("%c", sym);
	}
	printf("\n");
}


void displayMenu(){
	fprintf(stdout, "Scripts Menu\n");
	displayRuler('-');
	fprintf(stdout, "1. Login\n");
	fprintf(stdout, "2. Submit\n");
	fprintf(stdout, "3. Alias\n");
	fprintf(stdout, "0. Exit\n");
	displayRuler('-');
	fprintf(stdout, "Enter your choice:> ");
}


int validate_input(char* str){
	int done = 1;

	for(int i = 0 ; i < strlen(str) - 1 && done == 1 ; ++i){
		if(!isdigit(str[i])) done = 0;
	}

	return done;
}


int getInt(){
	int ret = 0;
	char str[256];
	char* end;

	do {
		fgets(str, 256, stdin);

		if(!validate_input(str)){
			fprintf(stdout, "Value is not digit. Try again :> ");
			ret = -1;
		} else ret = strtoimax(str, &end, 10);
	} while (ret == -1);

	return ret;
}


int getIntInRange(int min, int max){
	int ret = 0; 
	int done = 0;

	do{
		ret = getInt();

		if(ret <= max && ret >= min) done = 1;
		else fprintf(stdout, "Value must be between %d and %d:> ", min, max);
	} while (!done);

	return ret;
}

#endif

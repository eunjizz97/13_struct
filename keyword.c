#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NKEYS       13

struct keytab{
	int num;
	char keyword[10];
}; 

struct keytab keywrds[NKEYS] = {
       {0, "int"},
       {0, "float"},
       {0, "return"},
       {0, "if"},
       {0, "for"},
       {0, "while"},
       {0, "goto"},
       {0, "switch"},
       {0, "case"},
       {0, "void"},
       {0, "default"},
       {0, "char"},
       {0, "do"}
};

void count_word(char* word){
	int i;
	
	for(i=0;i<NKEYS;i++){
		if(strncmp(word, keywrds[i].keyword, strlen(keywrds[i].keyword))== 0)
		{
			(keywrds[i].num)++;
			break;
		}
	}
}


void print_word(void) {
	int i;
	
	for(i=0;i<NKEYS;i++){
		printf("%s : %d �� \n", keywrds[i].keyword, keywrds[i].num);
	}
}

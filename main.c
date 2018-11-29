#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "keyword.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int is_whitespace(char c){
	
	if(	c == ' '||
		c == '\t'||
		c == '\n'||
		c == '\r'||
		c == '('||
		c == ')')
		
		return 1;
		
	return 0;		//유의미한 글자  
}

int fget_word(FILE* fp, char* word){
	
	int cnt;
	char c; 
	
	while((c=fgetc(fp)) != EOF)
	{
		if(is_whitespace(c) == 0)	//유의미하면 
		{
			break;					//와일문에서 나옴 
		}
	}
	
	if(c==EOF)
	{
		return 0;
	}
	
	//본격적으로 단어를 한글자씩 읽음
	cnt = 0;
	word[cnt++] = c;		//아까 읽은 첫글자 입력  
	word[cnt] = '\0';		//혹시 뒤에서 못읽을 수 있으므로 
	
	while((word[cnt]=fgetc(fp)) != EOF)		//끝날 때까지 와일문으로 문자 받음 
	{
		if(is_whitespace(word[cnt]) == 1)	//화이트스페이스면 나감 
		{
			word[cnt] = '\0';				
			break;
		}
		cnt++;
	}
	return cnt;
}


int main(int argc, char *argv[]) {
	FILE *fp;
	char fileName[100];
	char word[100];
	
	//printf, scanf
	printf("file name : ");
	scanf("%s", fileName);
	
	//fopen
	fp = fopen(fileName, "r");
	
	//error handling
	if(fp==NULL)
	{
		printf("[error] check the file name : %s\n", fileName);
		return -1;
	}
	
	while(fget_word(fp, word) != 0)
	{
		//word pricessing
		count_word(word);
	}
	
	print_word();
	
	//fclose
	fclose(fp);
	
	return 0;
}

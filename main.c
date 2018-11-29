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
		
	return 0;		//���ǹ��� ����  
}

int fget_word(FILE* fp, char* word){
	
	int cnt;
	char c; 
	
	while((c=fgetc(fp)) != EOF)
	{
		if(is_whitespace(c) == 0)	//���ǹ��ϸ� 
		{
			break;					//���Ϲ����� ���� 
		}
	}
	
	if(c==EOF)
	{
		return 0;
	}
	
	//���������� �ܾ �ѱ��ھ� ����
	cnt = 0;
	word[cnt++] = c;		//�Ʊ� ���� ù���� �Է�  
	word[cnt] = '\0';		//Ȥ�� �ڿ��� ������ �� �����Ƿ� 
	
	while((word[cnt]=fgetc(fp)) != EOF)		//���� ������ ���Ϲ����� ���� ���� 
	{
		if(is_whitespace(word[cnt]) == 1)	//ȭ��Ʈ�����̽��� ���� 
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

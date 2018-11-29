#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	FILE *fp;
	char fileName[100];
	
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
	
	printf("%c\n", fgetc(fp));
	
	//fclose
	fclose(fp);
	
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "grep.h"
#define MAX 500
int main(int argc, char* argv[])
	{
		if(argc< 3){
			fputs("\nUsage :\n\t ./project <options> <Pattern that want to search> <file-name>\n",stderr);
			fputs("Must provide a search pattern and at least 1 file.\n", stderr);
			return 1;
		}
		int numop= checkoptions(argv);
		char* pattern= argv[numop+ 1];
		// If "-i" is used, change the pattern to lowercase
		if(op2)
			pattern = switchToLower(pattern);
		int i;
		for(i=numop + 2; i < argc; i++){
			char* filename = argv[i];
			processfile(filename, pattern);
		}
		if(op2){
			free(pattern);
		}
		return 0;
	}


void processfile(char* filename, char* pattern){
	FILE* f = fopen(filename, "r");
	if(!f){
		fprintf(stderr, "File %s can not be opened.\n", filename);
		return;
	}
	char* line = (char*)malloc(MAX*sizeof(char)); 
	int lineNum = 1;
	while(!feof(f)){
		line = getLine(line, f);
		if(line)
		{
			if(op2)
			{
				char* lowerLine = switchToLower(line);
				if(checkStringMatch(lowerLine, pattern))
				{
					printLine(lineNum*op1, filename, line);
				}
			free(lowerLine);
			}
		else
		{
			if(checkStringMatch(line, pattern))
			{
				printLine(lineNum*op1, filename, line);
			}
		} 
		lineNum++;
		}
	}
	fclose(f); 
	free(line);
}

char* getLine(char* loc, FILE* fp){
	return fgets(loc, MAX, fp);
	}

int checkoptions(char* argv[]){
	int numop = 0;
	if(checkStringMatch(argv[1], "-n") || checkStringMatch(argv[2], "-n")){
		op1= 1;
		numop++;
	}
	if(checkStringMatch(argv[1], "-i") || checkStringMatch(argv[2], "-i")){
		op2= 1;
		numop++;
	}  
	return numop;
	}


int checkStringMatch(char* toSearch, char* pattern){
	char* exists = strstr(toSearch, pattern);
	if(exists)
		return 1;
	return 0;
}
	char* switchToLower(char* str){
		char* newString = (char*)malloc(sizeof(char)*strlen(str));
		int i;
		for(i = 0; str[i]; i++){
			newString[i]=tolower(str[i]);
		}
		return newString;
	}

void printLine(int lineNum, char* fileName, char* text){
	if(lineNum)
		printf("%d %s %s", lineNum, fileName, text);
	else
		printf("%s %s", fileName, text);

}

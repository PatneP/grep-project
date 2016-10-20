#include<stdio.h>
char* getLine(char* loc, FILE* fp);		 	 
int checkStringMatch(char* toSearch, char* pattern);	 
char* switchToLower(char* string); 
void printLine(int lineNum, char* fileName, char* text);
void processfile(char* filename, char* pattern );
int checkoptions(char* argv[]);
int op1=0;
int op2=0;
int op3=0;

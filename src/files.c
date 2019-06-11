#include "files.h"

void init(){
	FILE * file;
	char string [LINE_MAX];
	int i = 0;
	
	
	char *filename;
	char aux1[100];
	char aux2[100];
	
	//Get workfile like (~/.subliminar)
	strcpy(aux1,getenv("HOME"));
	strcpy(aux2,"/.mentis");
	filename = strcat(aux1,aux2);
	
	//Open the file
	file = fopen (aux1, "r");
	if ( file == NULL){
		printf("\nError in open ~/.mentis file\n");
		exit(0);
	}
	
	
	while (fgets(string, LINE_MAX, file) != NULL){
		string[strlen(string)-1] = '\0';
		WORDS[WORDS_TAM] = (char *) malloc(sizeof string);
		strcpy(WORDS[WORDS_TAM++],string);
		//printf("%s",string);
	}
	
	
	
}

char * get_word(){
	int key = rand()%WORDS_TAM;
	return(WORDS[key]);
}

#include <stdio.h>
#include <ctype.h>
#include "dictionary.h"
#include "dictionary.c"
int readWord(FILE *fd, char *buffer){
	int c;
	do {
		c = fgetc(fd);				
		if(c == EOF)
			return 0;
	} while(!isalpha(c));

	do {
		*buffer = tolower(c);
		buffer++;
		c = fgetc(fd);
		if(c == 146) //C=' '
			c = '\'';
	} while(isalpha(c) || c == '\'');
	*buffer = '\0';
	return 1;
}

void main(){
	FILE *fd;
	char buffer[1024];
	Dictionary dict;
	fd = fopen("liar.txt", "rt");
	if(fd == NULL)	{
		printf("Error opening file.\n");
		return;
	}
	dict = create();
	while(readWord(fd, buffer))	{
		add(dict, buffer);
	}
	fclose(fd);
	//print(dict);
	filterDictionary(dict, filter);
	printf ("IZA FILTERA\n");
	print(dict);
	destroy(dict);
}
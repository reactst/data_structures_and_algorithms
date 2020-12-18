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
	// print(dict);
	// filterDictionary(dict, filter);
	// printf ("IZA FILTERA\n");
	// print(dict);
	char str1[]="jebenti";
	char str2[]="boga";
	int index=5;
	//dodaj(dict,str);
	//insert(dict,str,index);
	//delete_first(dict);
	//delete_last(dict);
	//reverse_list(dict);
	//delete_with_more_than10(dict);
	//swap_first_last(dict);
	add_second_third (dict,str1,str2);
	print(dict);
	//printf("%d \n",ukupno(dict));
	destroy(dict);
}
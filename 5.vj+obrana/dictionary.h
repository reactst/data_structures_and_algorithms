#ifndef DICTIONARY_H
#define DICTIONARY_H 1
typedef struct Word {
	char *word; // rijec
	int count; // broj pojavljivanja rijeci
	struct Word *next; 
} Word;

typedef Word* Dictionary;

Dictionary create();
void add(Dictionary dict, char *str);
void print(Dictionary dict);
void destroy(Dictionary dict);
Dictionary filterDictionary(Dictionary indict, int (*filter)(Word *w));
int filter(Word *w);
void dodaj (Dictionary dict, char* str);
char* najduza(Dictionary dict);
int ukupno(Dictionary dict);
void prije_elementa(Dictionary dict, char* str);
void prije_indeksa(Dictionary dict,char* str);
void brisanje_prvog(Dictionary dict);
void brisanje_zadnjeg(Dictionary dict);
#endif
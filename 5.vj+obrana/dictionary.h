#ifndef DICTIONARY_H
#define DICTIONARY_H 1
typedef struct Word {
	char *word; // rijec
	int count; // broj pojavljivanja rijeci
	struct Word *next; //pokazivanje na iduci Word*
} Word;

typedef Word* Dictionary;

Dictionary create();
void add(Dictionary dict, char *str);
void print(Dictionary dict);
void destroy(Dictionary dict);
Dictionary filterDictionary(Dictionary indict, int (*filter)(Word *w));
int filter(Word *w);
void add_word (Dictionary dict, char* str);
char* longest_word(Dictionary dict);
int word_sum(Dictionary dict);
void delete_before_element(Dictionary dict, char* str);
void insert(Dictionary dict,char* str,int index);
void delete_first(Dictionary dict);
void delete_last(Dictionary dict);
void delete_word (Dictionary dict, char* str);
void delete_last_10(Dictionary dict);
void delete_with_more_than10(Dictionary dict);
#endif
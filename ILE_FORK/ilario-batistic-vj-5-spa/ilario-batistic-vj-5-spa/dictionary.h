#include <stdio.h>
#include <ctype.h>
#include <string.h>

//zbog nekog razloga ovaj glupi program se buni kada koristim strdup, pa tribam ovo iskljuciti(nesto vezano za c++ se buni)
#pragma warning(disable : 4996)

#ifndef DICTIONARY_H
#define DICTIONARY_H

typedef struct Word {
	char* word; // rijec
	int count; // broj pojavljivanja rijeci
	struct Word* next;
} Word;

typedef Word* Dictionary;

// kreaira novi prazni rjecnik
//Rjeseno?
Dictionary create();

// dodaje rijec ili uvecava broj pojavljivanja rijeci u rjecniku
// rijeci se dodaju u abecednom redu
void add(Dictionary dict, char* str);

// ispisuje sve rijeci i broj pojavljivanja svake rijeci
void print(Dictionary dict);

// briše cijeli rjeènik
void destroy(Dictionary dict);
Dictionary filterDictionary(Dictionary indict, int(*filter)(Word* w));
int filter(Word* w);
#endif
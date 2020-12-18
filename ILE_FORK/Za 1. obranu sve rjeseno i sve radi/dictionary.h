#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include  <stdbool.h> 
#define duljina_niza(x) (sizeof(x)/sizeof(x[0]))
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
Dictionary filterDictionary(Dictionary indict, int (*filter)(Word* w));
int filter(Word* w);
void dodaj_prije_odredenog_elemeata(Dictionary dict, char* trazena_rijec, char* dodat_rijec);
void dodavanje_prije_odredenog_indeks(Dictionary dict, int indeks, char* str);
Dictionary obrnuta_lista(Dictionary dict);
void brisanje_pod_odredenim_uvjetima(Dictionary dict);
void dodavanje_elementa_nakon_nekog_uvjeta(Dictionary dict,char* str);
void kopirani_elemnti_nova_lista(Dictionary kopirani_list,Dictionary dict, int koliko_kopirati);
void zamjena_prvi_zdanji(Dictionary dict);
void lista_sa_odrdedenim_rjecima(Dictionary dict,Dictionary nova_lista);
Dictionary brisanje_glavu(Dictionary dict);
Dictionary dodaj_na_glavu(Dictionary dict, char* str);
Dictionary najdulja_rijec(Dictionary dict);
int broj_rijeci(Dictionary dict);
void dodaj_na_karj(Dictionary dict, char* str);
void brisanje_nakraju(Dictionary dict);
void brisanje_odredenog_elemenata(Dictionary dict, char* element);
void dodavanje_iz_niza_u_listu(Dictionary dict, char* niz_rijeci, int velicina_niza);
void dodavanje_na_2_i_3_poziciju(Dictionary dict);
char** dodavanje_iz_liste_u_niz(Dictionary dict, int n);
#endif
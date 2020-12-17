#include "dictionary.h"


Dictionary create()
{
	Dictionary rjecnik = (Word*)malloc(sizeof(Word));
	rjecnik->word = "Bezveze";
	rjecnik->count = 0;
	rjecnik->next = NULL;
	return rjecnik;
}

// dodaje rijec ili uvecava broj pojavljivanja rijeci u rjecniku
// rijeci se dodaju u abecednom redu
//radi sve
void add(Dictionary dict, char* str)
{
	Dictionary novi = (Dictionary*)malloc(sizeof(Word));
	Dictionary temp = dict;
	novi->word = strdup(str);
	novi->count = 1;
	novi->next = NULL;
	//ovako je petlja trajna i nikada nece prestat
	while (1)
	{
		//hvala jebenom bogu radi napokon!
		if (temp->next == NULL)
		{
			//ovdje se crasha kada idem oslobodit zbog nekog razloga
			temp->next = novi;
			return;
		}
		else if (strcmp(temp->next->word, str) == 0)
		{
			temp->next->count++;
			free(novi->word);
			free(novi);
			return;
		}
		else if (strcmp(temp->next->word, str) > 0)
		{
			//zamjena rijeci
			novi->next = temp->next;
			temp->next = novi;
			return;
		}
		//svaki put triba prolistat do kraja jer uvijek pocne od pocetka
		else
		{
			temp = temp->next;
		}
	}
}

// ispisuje sve rijeci i broj pojavljivanja svake rijeci
//radi i ovo
void print(Dictionary dict)
{
	Dictionary temp = dict->next;
	printf("*****************************Novi Rjecnik*****************************\n");
	while (temp != NULL)
	{
		printf("Rijec->.......%s....... i Broj->.......%d.......\n", temp->word, temp->count);
		temp = temp->next;
	}
}

void destroy(Dictionary dict)
{
	Dictionary sljedeci;
	sljedeci = dict->next;
	free(dict);
	dict = sljedeci;
	while (dict)
	{
		sljedeci = dict->next;
		free(dict->word);
		free(dict);
		dict = sljedeci;
	}
}
int filter(Word* w)
{
	if (strlen(w->word) > 3 && (w->count > 4 && w->count < 11))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

Dictionary filterDictionary(Dictionary indict, int(*filter)(Word* w))
{
	//oba tribaju biti dictionary zbog nekog razloga?
	Dictionary temp = indict, novi;
	while (temp->next != NULL) {
		if (filter(temp->next) == 0)
		{
			novi = temp->next;
			temp->next = novi->next;
			free(novi->word);
			free(novi);
		}
		else
		{
			temp = temp->next;
		}
	}
}
//RADI
void dodaj_prije_odredenog_elemeata(Dictionary dict, char* trazena_rijec, char* dodat_rijec) {
	Dictionary temp = dict, novi = (Word*)malloc(sizeof(Word));
	novi->word = strdup(dodat_rijec);
	novi->next = NULL;
	novi->count = 1;
	while (temp->next!=NULL) {
		if (strcmp(temp->next->word,trazena_rijec)==0) {
			novi->next = temp->next;
			temp->next = novi;
			return;
		}
		else {
			temp = temp->next;
		}
	}
	if (temp->next == NULL) {
		printf("Nemozemo dodati trazenu rijec jer nepostoji rijec koju zelimo dodat prije\n");
		return;
	}
}
//RADI
int broj_rijeci(Dictionary dict)
{
	Dictionary temp = dict;
	int brojac = 0;
	while (temp->next != NULL)
	{
		brojac++;
		temp = temp->next;
	}
	return brojac;
}
//RADI
void dodaj_na_karj(Dictionary dict, char* str)
{
	Dictionary temp = dict, novi = (Word*)malloc(sizeof(Word));
	novi->word = strdup(str);
	novi->count = 1;
	novi->next = NULL;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = novi;
	return;
}
//RADI
void brisanje_nakraju(Dictionary dict)
{
	Dictionary sljedeci, temp = dict;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	free(temp->next->word);
	free(temp->next);
	temp->next = NULL;
}
//RADI
void brisanje_odredenog_elemenata(Dictionary dict, char* element) {
	Dictionary novi, temp = dict;
	while (temp->next!=NULL)
	{
		if (strcmp(temp->next->word, element) == 0) {
			novi = temp->next->next;
			free(temp->next->word);
			free(temp->next);
			temp->next= novi;
			return;
		}
		else {
			temp = temp->next;
		}
	}
	if (temp->next == NULL) {
		printf("*******************************************\n\n");
		printf("Trazena rijec za uklanjanje nepostoji!\n");
		printf("\n\n");
		printf("*******************************************\n\n");
		return;
	}
}
//RADI
Dictionary najdulja_rijec(Dictionary dict)
{
	Dictionary najdulja = dict, temp = dict;
	while (temp->next != NULL)
	{
		if (strlen(temp->word) > strlen(najdulja->word))
		{
			najdulja = temp;
		}
		temp = temp->next;
	}
	return najdulja;
}
//RADI
Dictionary dodaj_na_glavu(Dictionary dict, char* str)
{
	Dictionary novi = (Word*)malloc(sizeof(Word));
	novi->word = strdup(str);
	novi->count = 1;
	novi->next = dict;
	return novi;
}
//RADI
Dictionary brisanje_glavu(Dictionary dict)
{
	Dictionary sljedeci;
	sljedeci = dict->next;
	free(dict->word);
	free(dict);
	dict = sljedeci;
	return dict;
}
//radi
void dodavanje_prije_odredenog_indeks(Dictionary dict, int indeks, char* str)
{
	Dictionary temp = dict, novi = (Word*)malloc(sizeof(Word));
	novi->word = strdup(str);
	novi->next = NULL;
	novi->count = 1;
	int i = 0;
	while (i + 1 != indeks)
	{
		i++;
		temp = temp->next;
	}
	novi->next = temp->next;
	temp->next = novi;
	return;
}
//Radi
Dictionary obrnuta_lista(Dictionary dict) {
	Dictionary obrnuta_lista = NULL,temp;
	while (dict->next != NULL) {
		temp = dict;
		dict = dict->next;
		temp->next = obrnuta_lista;
		obrnuta_lista = temp;
	}
	return obrnuta_lista;
}
//RADI
void brisanje_pod_odredenim_uvjetima(Dictionary dict) {
	Dictionary novi, temp = dict;
	while (temp->next != NULL) {
		if (strlen(temp->next->word) > 3) {
			novi = temp->next->next;
			free(temp->next->word);
			free(temp->next);
			temp->next = novi;
		}
		else {
			temp = temp->next;
		}
	}
}

//RADI
void dodavanje_elementa_nakon_nekog_uvjeta(Dictionary dict,char* str) {
	Dictionary temp = dict,novi;
	while (temp->next != NULL) {
		if (strlen(temp->word) > 5) {
			novi = (Word*)malloc(sizeof(Word));
			novi->word = strdup(str);
			novi->count = 1;
			novi->next = temp->next;
			temp->next = novi;
		}
		temp = temp->next;
	}
}
//radi
void kopirani_elemnti_nova_lista(Dictionary kopirani_list,Dictionary dict, int koliko_kopirati) {
	Dictionary temp = dict->next, nova_lista = kopirani_list,novi;
	int i = 0;
	while (i < koliko_kopirati) {
		novi = (Word*)malloc(sizeof(Word));
		novi->word = strdup(temp->word);
		novi->count = temp->count;
		novi->next = NULL;
		while (nova_lista->next != NULL) {
			nova_lista = nova_lista->next;
		}
		nova_lista->next = novi;
		temp = temp->next;
		i++;
	}
}
//radi
void zamjena_prvi_zdanji(Dictionary dict) {
	Dictionary temp = dict, prvi = dict->next,setac=prvi->next,prijesetac=prvi,zadnji;
	while (setac->next != NULL) {
		setac = setac->next;
		prijesetac = prijesetac->next;
	}
	zadnji = setac;
	temp->next = setac;
	setac->next = prvi->next;
	prijesetac->next = prvi;
	prvi->next = NULL;
}
//radi
void lista_sa_odrdedenim_rjecima(Dictionary dict,Dictionary nova_lista) {
	Dictionary temp = dict, novi_lista=nova_lista,novi;
	while (temp->next != NULL) {
		novi = (Word*)malloc(sizeof(Word));
		novi->word = strdup(temp->word);
		novi->count = 1;
		novi->next = NULL;
		if (strlen(temp->word) > 10) {
			while (novi_lista->next != NULL) {
				novi_lista = novi_lista->next;
			}
			novi_lista->next = novi;
		}
		temp = temp->next;
	}
}
//radi
void dodavanje_iz_niza_u_listu(Dictionary dict, char* niz_rijeci[], int velicina_niza) {
	for (int i = 0;i < velicina_niza;i++) {
		Dictionary temp = dict,novi=(Word*)malloc(sizeof(Word));
		novi->word = strdup(niz_rijeci[i]);
		novi->count = 1;
		novi->next = NULL;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = novi;
	}
}
//radi
char** dodavanje_iz_liste_u_niz(Dictionary dict, int n) {
	Dictionary temp = dict->next;
	char** niz_vratit = (char*)malloc(n* sizeof(char*));
	for (int i = 0;i < n;i++) {
		niz_vratit[i] = temp->word;
		temp = temp->next;
	}
	return niz_vratit;
}

void dodavanje_na_2_i_3_poziciju(Dictionary dict) {
	Dictionary temp = dict, novi = (Word*)malloc(sizeof(Word));
	novi->word = "Koko";
	novi->count = 1;
	novi->next = NULL;
	int a = 2, b = 3,i=0;
	while(i<a){
		temp = temp->next;
		i++;
	}
	novi->next = temp->next;
	temp->next = novi;
	temp = dict;
	i = 0;
	while (i < b) {
		temp = temp->next;
		i++;
	}
	novi = (Word*)malloc(sizeof(Word));
	novi->word = "Koko";
	novi->count = 1;
	novi->next = NULL;
	novi->next = temp->next;
	temp->next = novi;
}
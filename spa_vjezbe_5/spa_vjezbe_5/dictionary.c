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

        //HVALA JEBENOM BOGU RADI NAPOKKON!!!!!!!!!!!!!
        if (temp->next == NULL)
        {
            //ovdje se crasha kada idem oslobodit zbog nekog razloga
            temp->next = novi;
            return;
        }
        else if (strcmp(temp->next->word,str)==0)
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
    //ostavljam ovdje linkove za videa od nekog indijanca koji je dobro obajsnia ova sranja
    //https://www.youtube.com/watch?v=dQw4w9WgXcQ\n
}

void destroy(Dictionary dict)
{
    Dictionary sljedeci;
    while (dict)
    {
        sljedeci = dict->next;
        free(dict);
        dict = sljedeci;
    }
}
int filter(Word* w)
{
    int duljina = strlen(w->word);
    if (duljina > 3 && (w->count > 4 && w->count < 11))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

Dictionary filterDictionary(Dictionary indict, int (*filter)(Word* w))
{
    //oba tribaju biti dictionary zbog nekog razloga?
    Dictionary temp = indict,novi;
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
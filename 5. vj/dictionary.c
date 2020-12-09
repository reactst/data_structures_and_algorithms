#include "dictionary.h"
#include <malloc.h>
#include <string.h>
Dictionary create(){
    Dictionary dict=(Word*)malloc(sizeof(Word));
    dict->word = "Bezveze";
    dict->count=0;
    dict->next=NULL;
    return dict;
}
void add(Dictionary dict, char *str){
    Dictionary novi = (Dictionary*)malloc(sizeof(Word));
    Dictionary temp = dict;
    novi->word = strdup(str);
    novi->count = 1;
    novi->next = NULL;
    while (1) {
        if (temp->next == NULL) {
            temp->next = novi;
            return;
        }
        else if (strcmp(temp->next->word,str)==0) {
            temp->next->count++;
            return;
        }
        else if (strcmp(temp->next->word, str) > 0) {
            novi->next = temp->next;
            temp->next = novi;
            return;
        }
        else {
            temp = temp->next;
        }
    }
}
void print(Dictionary dict){
    Dictionary priv=dict;
    while (priv){
        printf ("%s\t|\t%d\n",priv->word,priv->count);
        priv=priv->next;
    }
}
void destroy(Dictionary dict){
    Dictionary sljedeci;
    while (dict) {
        sljedeci = dict->next;
        free(dict);
        dict = sljedeci;
    }
}
Dictionary filterDictionary(Dictionary indict, int (*filter)(Word *w)){
    Dictionary temp = indict;
    Dictionary novi = (Word*)malloc(sizeof(Word));
    while (temp->next != NULL) {
        if (filter(temp->next) == 0) {
            novi = temp->next;
            temp->next = novi->next;
            free(novi);
        }
        else {
            temp = temp->next;
        }
    }
    indict = temp;
    return indict;
}
int filter(Word *w){
    int duljina = strlen(w->word);
    if (duljina > 3 && (w->count > 4 && w->count < 11)) {
        return 1;
    }
    else {
        return 0;
    }
}

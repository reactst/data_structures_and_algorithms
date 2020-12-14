#include <stdio.h>
#include <stdlib.h>
void main(){
    int niz[10]={1,2,3,4,5,6,7,8,9,10};
    int brojac=0;
    for (int i=0;i<10;i++){
        if (niz[i]%3==0)
        brojac++;
    }
    int djeljivsatri[brojac];
    int ostataknizaLEN=10-brojac;
    brojac=0;
    int brojac1=0;
    int ostatakniza[ostataknizaLEN];
    for (int i=0;i<10;i++){
        if (niz[i]%3==0){
            djeljivsatri[brojac]=niz[i];
            brojac++;
        }
        else{
            ostatakniza[brojac1]=niz[i];
            brojac1++;
        }
    }
    for (int i=0;i<brojac;i++)
    printf ("NIZ DJELJIV SA TRI: %d. %d\n",i,djeljivsatri[i]);
    for (int i=0;i<brojac1;i++)
    printf ("OSTATAK NIZA: %d. %d\n",i,ostatakniza[i]);
}
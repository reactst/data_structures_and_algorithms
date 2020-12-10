#include <stdio.h>
#include <stdlib.h>

void main (){
    int niz[10];
    int rez=0;
    for (int i=0;i<10;i++){
        scanf ("%d \n",&niz[i]);
        if (i>0 && i<10){
            rez+=niz[i];
        }
    }
    printf ("Rezultat: %d\n",rez);
}
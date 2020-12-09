#include "sortiranja.h"
#include "sortiranja.c"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

void main (){
    srand(time(NULL));
    int* niz;
    double timeunsort,timesort;
    int n=10000;
    choose_pivot=1;
    for (int i=0;i<10;i++){
        //print (niz,n);
        niz=generiraj(n);
        int* mixmixmix=duplicate(niz,n);
        shuffle(mixmixmix,n);
        timesort=measure(quicksort,niz,n);
        timeunsort=measure(quicksort,mixmixmix,n);
        printf ("%d.QUICKSORT(SORTIRAN)   SA PIVOTOM %lfs ZA DULJINU %d\n",i,timesort,n);
        printf ("%d.QUICKSORT(NESORTIRAN) SA PIVOTOM %lfs ZA DULJINU %d\n",i,timeunsort,n);
        printf ("\n");
        free(mixmixmix);
        free(niz);
        n+=10000;
    }
    printf ("------------------------------------\n");
    n=10000;
    choose_pivot=0;
    for (int i=0;i<10;i++){
        //print (niz,n);
        niz=generiraj(n);
        int* mixmixmix=duplicate(niz,n);
        shuffle(mixmixmix,n);
        timesort=measure(quicksort,niz,n);
        timeunsort=measure(quicksort,mixmixmix,n);
        printf ("%d.QUICKSORT(SORTIRAN)   BEZ PIVOTA %lfs ZA DULJINU %d\n",i,timesort,n);
        printf ("%d.QUICKSORT(NESORTIRAN) BEZ PIVOTA %lfs ZA DULJINU %d\n",i,timeunsort,n);
        printf ("\n");
        free(mixmixmix);
        free(niz);
        n+=10000;
    }
    printf ("--------SELECTION-SORT---------------\n");
    for (n_min;n_min<2001;n_min+=50){
        niz=generiraj(n_min);
        int* mixmixmix=duplicate(niz,n_min);
        shuffle(mixmixmix,n_min);
        timesort=measure(selectionsort,niz,n_min);
        timeunsort=measure(selectionsort,mixmixmix,n_min);
        printf ("%d.UNSORTED: %lf\tSORTED: %lf\n",n_min,timesort,timeunsort);
        free (mixmixmix);
        free (niz);
    }
    printf ("--------INSERTION-SORT---------------\n");
    for (n_min=0;n_min<2001;n_min+=50){
        niz=generiraj(n_min);
        int* mixmixmix=duplicate(niz,n_min);
        shuffle(mixmixmix,n_min);
        timesort=measure(insertionsort,niz,n_min);
        timeunsort=measure(insertionsort,mixmixmix,n_min);
        printf ("NIZ SIZE=%d\tUNSORTED: %lf\tSORTED: %lf\n",n_min,timesort,timeunsort);
        free (mixmixmix);
        free (niz);
    }
}
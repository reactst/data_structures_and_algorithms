#include "sortiranja.h"
#include "sortiranja.c" //JEREHAKER

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
        printf ("%d.QUICKSORT(SORTIRAN)         PIVOT:YES\t VRIJEME:%lfs\t ZA DULJINU %d\n",i,timesort,n);
        printf ("%d.QUICKSORT(NESORTIRAN)       PIVOT:YES\t VRIJEME:%lfs\t ZA DULJINU %d\n",i,timeunsort,n);
        printf ("\n");
        free(mixmixmix);
        free(niz);
        n+=10000;
    }
    printf ("------------------------------------\n");
    n=10000; //NEPODNOSLJIV IZA 1000000
    choose_pivot=0;
    for (int i=0;i<10;i++){
        //print (niz,n);
        niz=generiraj(n);
        int* mixmixmix=duplicate(niz,n);
        shuffle(mixmixmix,n);
        timesort=measure(quicksort,niz,n);
        timeunsort=measure(quicksort,mixmixmix,n);
        printf ("%d.QUICKSORT(SORTIRAN)         PIVOT:NO\t VRIJEME:%lf s\t ZA DULJINU %d\n",i,timesort,n);
        printf ("%d.QUICKSORT(NESORTIRAN)       PIVOT:NO\t VRIJEME:%lf s\t ZA DULJINU %d\n",i,timeunsort,n);
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
        printf ("NIZ SIZE:%d\tUNSORTED: %lf\tSORTED: %lf\n",n_min,timesort,timeunsort);
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
        printf ("NIZ SIZE:%d\tUNSORTED: %lf\tSORTED: %lf\n",n_min,timesort,timeunsort);
        free (mixmixmix);
        free (niz);
    }
    //n_min=25; //najbolje
    printf ("--------AUTO-SORT-------------------\n");
        for (n_min=0;n_min<201;n_min+=5){
        niz=generiraj(n_min);
        int* mixmixmix=duplicate(niz,n_min);
        shuffle(mixmixmix,n_min);
        timesort=measure(autosort,niz,n_min);
        timeunsort=measure(autosort,mixmixmix,n_min);
        printf ("NIZ SIZE:%d\tUNSORTED: %lf\tSORTED: %lf\n",n_min,timesort,timeunsort);
        free (mixmixmix);
        free (niz);
    }
}
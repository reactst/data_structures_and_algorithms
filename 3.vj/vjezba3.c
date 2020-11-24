#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
int* generiraj (int n){
    srand(time(0));
    int* rezultant=(int*)malloc(n*sizeof(int));
    for (int i=0;i<n;i++){
        rezultant[i]=rand();
    }
    return rezultant;
}
int main () {
    int n=30000;
    int* novibroj=generiraj(n);
    for (int i=0;i<n;i++){
        printf ("%d ",novibroj[i]);
    }
}
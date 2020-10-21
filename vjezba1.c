#include <stdio.h>
int* podniz (int* niz[], int start, int stop) {
    int razlika=stop-start;
    int* noviniz[razlika];
    printf ("START=%d\nSTOP=%d\n",start,stop);
    for (int i=0;i<=razlika;i++){
        noviniz[i]=niz[start];

        printf ("noviniz je %d\n",noviniz[i]);
    }
    return noviniz;
}
void main (){
    int* niz[10]={1,2,3,4,5,6,7,8,10};
    int a=3, b=6;
    int nn[3]=podniz(&niz,a,b);
    for (int i=0;i<3;i++){
        printf ("%d je na %d\n",nn[i],i);
    }
}
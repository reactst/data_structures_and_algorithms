#include <stdio.h>
#include <malloc.h>
//int* podniz(int *niz, int start, int stop) – vraća novi niz koji je kopija dijela niza od indeksa start do indeksa stop. 
int* podniz (int* niz, int start, int stop) {
    int razlika=stop-start;
    int* newarray=((int*)malloc(sizeof(int)*razlika));
    for (int i=0;i<razlika;i++){
        newarray[i]=niz[start];
        start++;
    }
    return newarray;
}
/*  int* filtriraj(int *niz, int n, int th, int *nth) – vraća novi niz 
koji sadrži brojeve iz originalnog niza koji su manji od th. 
Originalni niz ima dužinu n. 
Dužinu novog niza sa brojevima koji su prošli filter treba spremiti u nth. 
*/
int* filtriraj(int *niz, int n, int th, int *nth) {
    int* noviniz;
    int i,j=0;
    for (i=0;i<n;i++){
        if (niz[i]<th)
        nth++;
    }
    *noviniz=(int*)malloc(sizeof(int)*sizeof(nth));
    for (i=0;i<n;i++){
        if (niz[i]<th)
        noviniz[i]=niz[i];
        
    }
    return noviniz;
}
/*  int** podijeli(int *niz, int n) – dijeli niz dužine n na dva jednaka dijela
 i stvara kopije prvog i drugog dijela. 
Funkcija vraća dva pokazivača koji pokazuju na prvi i na drugi dio.*/
int** podijeli(int *niz, int n){
    if (n == 0)	{
		return NULL;
	}
    int** returner;
    int* prviniz,*druginiz;
    **returner=((int*)malloc(sizeof(int)*2));
    *prviniz=((int*)malloc(sizeof(int)*(n/2)));
    *druginiz=((int*)malloc(sizeof(int)*(n/2)));
    for (int i=0;i<n/2;i++){
        prviniz[i]=niz[i];
    }
    for (int i=n/2;i<n;i++){
        druginiz[i-(n/2)]=niz[i];
    }
    returner[0]=prviniz;
    returner[1]=druginiz;
    return returner;
}


void main (){
    int niz[10]={1,2,3,4,5,6,7,8,10};
    int nizlen=sizeof(niz)/sizeof(niz[0]);
    int th=10;
    int* nth;
    int start=3, stop=8;
    int len=stop-start;
    int* nn=podniz(niz,start,stop);
    int* nnn=filtriraj(niz,nizlen,th,nth);
    // int** nnnn=podijeli(niz,nizlen);
    for (int i=0;i<len;i++){
        printf ("nn[i]\t%d[%d]\n",nn[i],i);
    }
    printf ("\n");
    for (int i=0;i<sizeof(nth);i++){
        printf ("nnn[i]\t%d[%d]\n",nnn[i],i);
    }
    printf ("\n");
}
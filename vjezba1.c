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
/*
int* filtriraj(int *niz, int n, int th, int *nth) – vraća novi niz 
koji sadrži brojeve iz originalnog niza koji su manji od th. 
Originalni niz ima dužinu n. 
Dužinu novog niza sa brojevima koji su prošli filter treba spremiti u nth. 
*/
int* filtriraj(int *niz, int n, int th, int *nth) {
    int* noviniz;
    for (int i=0;i<n;i++){
        if (niz[i]<th)
        nth++;
    }
    *noviniz=(int*)malloc(sizeof(int)*sizeof(nth));
    for (int i=0;i<n;i++){
        if (niz[i]<th)
        noviniz[i]=niz[i];
    }
    return noviniz;
}
/* 
int** podijeli(int *niz, int n) – dijeli niz dužine n na dva jednaka dijela
 i stvara kopije prvog i drugog dijela. 
Funkcija vraća dva pokazivača koji pokazuju na prvi i na drugi dio.
*/
int** podijeli(int *niz, int n){
    if (n==0){
		return NULL;
	}
    int len1,len2;
    if (n%2==0){
	    len1=n/2;
	    len2=n/2;
	}
	else{
	    len1=n/2;
	    len2=n-(n/2);
	}
    int **returner=((int*)malloc(sizeof(int)*2));
    int *prviniz=((int*)malloc(sizeof(int)*(len1)));
    int *druginiz=((int*)malloc(sizeof(int)*(len2)));
    for (int i=0;i<n/2;i++){
        prviniz[i]=niz[i];
    }
    for (int i=n/2;i<n-1;i++){
        druginiz[i-len2]=niz[i];
    }
    returner[0]=prviniz;
    returner[1]=druginiz;
    return returner;
}
/*
Deklarirati strukturu Tocka koja sadrži dva člana:
 x i y (oba su float). Deklarirati strukturu Poligon 
 koja se sadrži dva člana: niz vrhova (svaki vrh u nizu je Tocka) i broj vrhova n. 
Napisati funkcije za rad sa poligonima 
*/
typedef struct {
    float x,y;
}Tocka;
typedef struct {
    int n;
    Tocka *niz_t;
}Poligon;
/* 
Poligon* novi_poligon(float *niz_x, float *niz_y, int n) – 
prima niz x i y koordinata i stvara 
novi poligon koji će kao vrhove imati parove brojeva iz nizova. 
Nizovi su dužine n (≥ 3).
*/
Poligon* novi_poligon(float *niz_x, float *niz_y, int n){
    Poligon *poly=((Poligon*)malloc(sizeof(Poligon)));
    Tocka *niz_tck=((Tocka*)malloc(sizeof(Tocka)*n));
}
void main (){
    int niz[10]={1,2,3,4,5,6,7,8,10};
    int nizlen=sizeof(niz)/sizeof(niz[0]);
    int th=10;
    int* nth;
    int start=3, stop=8;
    int lenn=stop-start;
    float nizx[2]={2.231,1.324};
    float nizy[2]={-1.521,-2,352};
    int* nn=podniz(niz,start,stop);
    int* nnn=filtriraj(niz,nizlen,th,nth);
    int** nnnn=podijeli(niz,nizlen);
    for (int i=0;i<lenn;i++){
        printf ("nn[i]\t%d[%d]\n",nn[i],i);
    }
    printf ("\n");
    for (int i=0;i<sizeof(nth);i++){
        printf ("nnn[i]\t%d[%d]\n",nnn[i],i);
    }
    printf ("\n");
    for (int i=0;i<nizlen/2-1;i++){
        printf ("nnnn[0][i] %d[%d]\n",nnnn[0][i],i);
        printf ("nnnn[1][i] %d[%d]\n",nnnn[1][i],i);
    }
    printf ("\n");
}
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
int bsearchfunc(const void* a, const void* b) {
	int bsa = *((int*)a);
	int bsb = *((int*)b);
	return bsa - bsb;
}
int* generiraj (int n){
    srand(time(0));
    int* rezultant=(int*)malloc(n*sizeof(int));
    for (int i=0;i<n;i++){
        rezultant[i]=rand();
    }
    return rezultant;
}
void shuffle(int* niz1, int n){
	for (int i=0;i<n;i++){
		int j=(rand()*rand())%n;
		int tmp=niz1[i];
		niz1[i]=niz1[j];
		niz1[j]=tmp;
	}
}
int presjek(int* niz1, int* niz2, int len1, int len2){
	int brojac=0;
	for (int i=0;i<len1;i++){
		for (int j=0;j<len2;j++){
			if (niz1[i]==niz2[j]){
				brojac++;
			}
		}
	}
	return brojac;
}
int presjek_sort_nobsrch(int* niz1, int* niz2, int len1, int len2){
	int temp;
	for (int i=0;i<len2;i++){
		for (int j=i+1;j<len2;j++){
			if (niz2[i]>niz2[j]){
				temp=niz2[i];
				niz2[i]=niz2[j];
				niz2[j]=temp;
			}
		}
	}
	int brojac=0;
	for (int i=0;i<len1;i++){
		for (int j=0;j<len2;j++){
			if (niz1[i]==niz2[j]){
				brojac++;
			}
		}
	}
	return brojac;
}
int presjek_bsearch_sort(int* niz1, int* niz2, int len1, int len2){
	int temp;
	for (int i=0;i<len2;i++){
		for (int j=i+1;j<len2;j++){
			if (niz2[i]>niz2[j]){
				temp=niz2[i];
				niz2[i]=niz2[j];
				niz2[j]=temp;
			}
		}
	}
	int brojac = 0;
	int* bin_srch;
	for (int i=0;i<len1;i++){
		bin_srch=(int*)bsearch(&niz1[i], niz2, len2, sizeof(int), bsearchfunc);
		if (bin_srch!=NULL){
			brojac++;
		}
	}
	return brojac;
}
int presjek_bsearch_qsort(int* niz1, int* niz2, int n1, int n2){
	qsort(niz2, n2, sizeof(int), bsearchfunc);
	int brojac=0;
	int* bin_srch;
	for (int i=0;i<n1; i++){
		bin_srch=(int*)bsearch(&niz1[i], niz2, n2, sizeof(int), bsearchfunc);
		if (bin_srch!=NULL){
			brojac++;
		}
	}
	return brojac;
}
void main(){
	int n1len = 30000;
	int n2len = 10000;
	for (int i=0;i<9;i++){
		printf("Trenutacna velicina\t niz1:%d\t niz2:%d\n", n1len, n2len);
		int* niz1 = generiraj(n1len);
		int* niz2 = generiraj(n2len);
		int start = clock();
		int* presjek_niz = presjek(niz1, niz2, n1len, n2len);
		int stop = clock();
		printf("Vrijeme(Dva nesort niza-B++):\t\t\t%.2lf\n", (double)(stop - start) / CLOCKS_PER_SEC);
		n2len+=5000;
		free(niz1);
		free(niz2);
	}
	n1len = 10000;
	n2len = 30000;
	for (int i=0;i<9;i++){
		printf("Trenutacna velicina\t niz1:%d\t niz2:%d\n", n1len, n2len);
		int* niz1 = generiraj(n1len);
		int* niz2 = generiraj(n2len);
		int start = clock();
		int* presjek_niz = presjek(niz1, niz2, n1len, n2len);
		int stop = clock();
		printf("Vrijeme(Dva nesort niza-A++):\t\t\t%.2lf\n", (double)(stop - start) / CLOCKS_PER_SEC);
		n1len+=5000;
		free(niz1);
		free(niz2);
	}
    n1len = 30000;
    n2len = 10000;
	for (int i=0;i<9;i++){
		printf("Trenutacna velicina\t niz1:%d\t niz2:%d\n", n1len, n2len);
		int* niz1 = generiraj(n1len);
		int* niz2 = generiraj(n2len);
		int start = clock();
		int* presjek_niz = presjek_sort_nobsrch(niz1, niz2, n1len, n2len);
		int stop = clock();
		printf("Vrijeme(Jedan sort,drugi ne; bez qs i bs;B++):\t\t\t%.2lf\n", (double)(stop - start) / CLOCKS_PER_SEC);
		n2len+=5000;
		free(niz1);
		free(niz2);
	}
	n1len = 10000;
	n2len = 30000;
	for (int i=0;i<9;i++){
		printf("Trenutacna velicina\t niz1:%d\t niz2:%d\n", n1len, n2len);
		int* niz1 = generiraj(n1len);
		int* niz2 = generiraj(n2len);
		int start = clock();
		int* presjek_niz = presjek_sort_nobsrch(niz1, niz2, n1len, n2len);
		int stop = clock();
		printf("Vrijeme(Oba sortirana; bez bs):\t\t\t%.2lf\n", (double)(stop - start) / CLOCKS_PER_SEC);
		n1len+=5000;
		free(niz1);
		free(niz2);
	}
	n1len = 30000;
	n2len = 10000;
	for (int i=0;i<9;i++){
		printf("Trenutacna velicina\t niz1:%d\t niz2:%d\n", n1len, n2len);
		int* niz1 = generiraj(n1len);
		int* niz2 = generiraj(n2len);
		int start = clock();
		int* presjek_niz = presjek_bsearch_sort(niz1, niz2, n1len, n2len);
		int stop = clock();
		printf("Vrijeme(oba sortirana sa bs;n1>n2):\t\t\t%.2lf\n", (double)(stop - start) / CLOCKS_PER_SEC);
		n2len+=5000;
		free(niz1);
		free(niz2);
	}
	n1len = 10000;
	n2len = 30000;
	for (int i=0;i<9;i++){
		printf("Trenutacna velicina\t niz1:%d\t niz2:%d\n", n1len, n2len);
		int* niz1 = generiraj(n1len);
		int* niz2 = generiraj(n2len);
		int start = clock();
		int* presjek_niz = presjek_bsearch_sort(niz1, niz2, n1len, n2len);
		int stop = clock();
		printf("Vrijeme(oba sortirana sa bs;n2>n1):\t\t\t%.2lf\n", (double)(stop - start) / CLOCKS_PER_SEC);
		n1len+=5000;
		free(niz1);
		free(niz2);
	}
	n1len = 30000;
	n2len = 10000;
	for (int i=0;i<9;i++){
        printf("Trenutacna velicina\t niz1:%d\t niz2:%d\n", n1len, n2len);
		int* niz1 = generiraj(n1len);
		int* niz2 = generiraj(n2len);
		int start = clock();
		int* presjek_niz = presjek_bsearch_qsort(niz1, niz2, n1len, n2len);
		int stop = clock();
		printf("Vrijeme(qs+bs;n1>n2):\t\t\t%.2lf\n", (double)(stop - start) / CLOCKS_PER_SEC);
		n2len+=5000;
		free(niz1);
		free(niz2);
	}
	n1len = 10000;
	n2len = 30000;
	for (int i=0;i<9;i++){
		printf("Trenutacna velicina\t niz1:%d\t niz2:%d\n", n1len, n2len);
		int* niz1 = generiraj(n1len);
		int* niz2 = generiraj(n2len);
		int start = clock();
		int* presjek_niz = presjek_bsearch_qsort(niz1, niz2, n1len, n2len);
		int stop = clock();
		printf("Vrijeme(qs+bs;n2>n1):\t\t\t%.2lf\n", (double)(stop - start) / CLOCKS_PER_SEC);
		n1len+=5000;
		free(niz1);
		free(niz2);
	}
	printf("\nkraj!\n");
}
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <stdbool.h>
bool choose_pivot=1;
int n_min=0;
// pomocne funkcije
int *generiraj(int n){
	srand((unsigned int)time(NULL));
	int *niz = (int *)malloc(sizeof(int) * n);
	niz[0] = rand() % 5;
	for (int i = 1; i < n; i++)
	{
		niz[i] = niz[i - 1] + rand() % 5;
	}
	return niz;
}
void shuffle(int *niz, int n){
	for (int i = 0; i < n; i++)	{
		int k1 = rand() % n;
		int tmp = niz[i];
		niz[i] = niz[k1];
		niz[k1] = tmp;
	}
}
void print(int *niz, int n){
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d\t", niz[i]);
	}
	printf("\n");
}
void swap(int *niz, int left, int right){
	int tmp;
	tmp = niz[left];
	niz[left] = niz[right];
	niz[right] = tmp;
}
int median(int *niz, int n){
	int l, r, mid;
	l = 0;
	r = n - 1;
	mid = n / 2;
	if (niz[r] < niz[l])
		swap(niz, l, r);
	if (niz[mid] < niz[l])
		swap(niz, mid, l);
	if (niz[r] < niz[mid])
		swap(niz, r, mid);
	return mid;
}
// selection sort
void selectionsort(int *niz, int n){
	int i;
	for (i = 0; i < n - 1; i++)
	{
		int j, tmp, maxi = i;
		for (j = i + 1; j < n; j++)
		{
			if (niz[j] < niz[maxi])
				maxi = j;
		}
		tmp = niz[maxi];
		niz[maxi] = niz[i];
		niz[i] = tmp;
	}
}
// insertion sort
void insertionsort(int *niz, int n){
	int i;
	for (i = 1; i < n; i++)
	{
		int j = i;
		while (j > 0 && niz[j - 1] > niz[j])
		{
			int tmp = niz[j - 1];
			niz[j - 1] = niz[j];
			niz[j] = tmp;
			j--;
		}
	}
}
// quick sort
int partition(int *niz, int n){
	int l, r;
	l = 1;
	r = n - 1;
	// if (choose_pivot==1)  {
    //     if ((niz[0] <= niz[n/2] && niz[n/2] <= niz[n-1]) || (niz[n-1] <= niz[n/2] && niz[n/2] <= niz[0]))
    //         pivot =  &niz[n/2];
    //     else if ((niz[n/2] <= niz[0] && niz[0] <= niz[n-1]) || (niz[n-1] <= niz[0] && niz[0] <= niz[n/2]))
    //         pivot =  &niz[0];
    //     else
    //         pivot =  &niz[n-1];
    //     swap (niz,pivot, niz[0]);
    // }
	if (choose_pivot==1){
		int tmp, med;
		med = median(niz, n);
		l = 0;
		swap(niz, l, med);
	}
	while (l < r){
		if (niz[r] >= niz[0]){
			r--;
		}
		else if (niz[l] < niz[0]){
			l++;
		}
		else{
			int tmp = niz[l];
			niz[l] = niz[r];
			niz[r] = tmp;
		}
	}
	if (niz[0] < niz[r]){ // 1
		return 0;
	}
	else{ // 3
		int tmp = niz[r];
		niz[r] = niz[0];
		niz[0] = tmp;
		return r;
	}
}
void quicksort(int *niz, int n){
	if (n < 2)
		return;
	int pi = partition(niz, n);
	quicksort(niz, pi);
	quicksort(niz + pi + 1, n - pi - 1);
}
// merge
void merge(int *niz, int *niza, int na, int *nizb, int nb){
	int a, b;
	a = 0;
	b = 0;
	while (a < na || b < nb){
		if (a == na){
			niz[a + b] = nizb[b];
			b++;
		}
		else if (b == nb){
			niz[a + b] = niza[a];
			a++;
		}
		else if (niza[a] < nizb[b])	{
			niz[a + b] = niza[a];
			a++;
		}
		else{
			niz[a + b] = nizb[b];
			b++;
		}
	}
}
int *duplicate(int *niz, int n){
	int i;
	int *novi = (int *)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
	{
		novi[i] = niz[i];
	}
	return novi;
}
void autosort(int *niz, int n){
	if (n < 2)
		return;
	if (n <= n_min)	{
		selectionsort(niz, n);
	}
	else	{
		if (n < 2)
			return;
		int pi = partition(niz, n);
		autosort(niz, pi);
		autosort(niz + pi + 1, n - pi - 1);
	}
}
// mjerenje vremena izvodenja funkcije sortiranja
double measure(void (*sort)(int *niz, int n), int *niz, int n){
	int start_time = clock();
	sort(niz, n);
	int end_time = clock();
	return (double)(end_time - start_time) / CLOCKS_PER_SEC;
}
//GOTOVO

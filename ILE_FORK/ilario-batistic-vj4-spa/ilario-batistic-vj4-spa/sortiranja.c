#include "sortiranja.h"

bool choose_pivot = false;
int n_min = 0;
// pomocne funkcije
int* generiraj(int n) {
	int* niz = (int*)malloc(sizeof(int) * n);
	niz[0] = rand() % 5;
	for (int i = 1; i < n; i++) {
		niz[i] = niz[i - 1] + rand() % 5;
	}
	return niz;
}

void zamjena(int* niz, int livo, int desno) {
	int tmp;
	tmp = niz[livo];
	niz[livo] = niz[desno];
	niz[desno] = tmp;
}


//nova metoda
int median(int* niz, int n)
{
	int median, temp;
	if ((niz[0] >= niz[n / 2] && niz[0] <= niz[n - 1]) || (niz[0] <= niz[n / 2] && niz[0] >= niz[n - 1]))
	{
	    median = 0;
	}
	else if ((niz[n / 2] >= niz[0] && niz[n / 2] <= niz[n - 1]) || (niz[n / 2] <= niz[0] && niz[n / 2] >= niz[n - 1]))
	{
		median = n - 1;
	}
	else
	{
		median = n / 2;
	}
	return median;
}

void shuffle(int* niz, int n) {
	for (int i = 0; i < n; i++) {
		int k1 = rand() % n;
		int tmp = niz[i];
		niz[i] = niz[k1];
		niz[k1] = tmp;
	}
}

void print(int* niz, int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d", niz[i]);
	}
	printf("\n");
}

// selection sort
void selectionsort(int* niz, int n) {
	int i;
	for (i = 0; i < n - 1; i++) {
		int j, tmp, maxi = i;
		for (j = i + 1; j < n; j++) {
			if (niz[j] < niz[maxi])
				maxi = j;
		}

		tmp = niz[maxi];
		niz[maxi] = niz[i];
		niz[i] = tmp;
	}
}

// insertion sort
void insertionsort(int* niz, int n) {
	int i;
	for (i = 1; i < n; i++) {
		int j = i;
		while (j > 0 && niz[j - 1] > niz[j]) {
			int tmp;
			tmp = niz[j - 1];
			niz[j - 1] = niz[j];
			niz[j] = tmp;
			j--;
		}
	}
}

// quick sort
int partition(int* niz, int n) {
	if (choose_pivot == false)
	{
		int l, r, tmp;
		l = 1;
		r = n - 1;
		while (l < r) {
			if (niz[r] >= niz[0]) {
				r--;
			}
			else if (niz[l] < niz[0]) {
				l++;
			}
			else {
				tmp = niz[l];
				niz[l] = niz[r];
				niz[r] = tmp;
			}
		}
		if (niz[0] < niz[r]) { // 1
			return 0;
		}
		else { // 3
			int tmp = niz[r];
			niz[r] = niz[0];
			niz[0] = tmp;
			return r;
		}
	}
	else
	{
		int l, r, temp, med;
		l = 1;
		r = n - 1;
		med = median(niz, n);
		//zamjena vruhednisoti sa pozicije med na 0
		temp = niz[0];
		niz[0] = niz[med];
		niz[med] = temp;
		while (l < r) {
			if (niz[r] >= niz[0]) {
				r--;
			}
			else if (niz[l] < niz[0]) {
				l++;
			}
			else {
				temp = niz[l];
				niz[l] = niz[r];
				niz[r] = temp;
			}
		}
		if (niz[0] < niz[r]) { // 1
			return 0;
		}
		else { // 3
			temp = niz[r];
			niz[r] = niz[0];
			niz[0] = temp;
			return r;
		}
	}
}

void quicksort(int* niz, int n) {
	if (n < 2)
		return;
	int pi = partition(niz, n);
	quicksort(niz, pi);
	quicksort(niz + pi + 1, n - pi - 1);
}
void quicksort_novi(int* niz, int n)
{
	//velicina n_min je najbolje staviti oko 25 za najbolju performansu(10 je na drugom mjestu)
	if (n < 2)
		return;
	if (n <= n_min)
	{
		selectionsort(niz, n);
	}
	else
	{
		if (n < 2)
			return;
		int pi = partition(niz, n);
		quicksort_novi(niz, pi);
		quicksort_novi(niz + pi + 1, n - pi - 1);
	}
}
// merge sort
void merge(int* niz, int* niza, int na, int* nizb, int nb)
{
	for (int i = 0; i < na; i++)
	{
		niz[i] = niza[i];
	}
	for (int i = na, k = 0; k < nb; i++, k++)
	{
		niz[i] = nizb[k];
	}
}

// alocira i vraæa kopiju niza
int* duplicate(int* niz, int n) {
	int i;
	int* novi = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		novi[i] = niz[i];
	}
	return novi;
}
//popravi kasnije
void mergesort(int* niz, int n) {
	if (n < 2)
		return;
	int pola = n / 2;
	int* niz1 = duplicate(niz, pola);
	int* niz2 = duplicate(niz + pola, n - pola);
	mergesort(niz1, pola);
	mergesort(niz2, n - pola);
	merge(niz1, pola, niz2, n - pola, niz);
	free(niz1);
	free(niz2);

}

// mjerenje vremena izvoðenja funkcije sortiranja
double measure(void(*sort)(int* niz, int n), int* niz, int n) {
	int start_time = clock();
	sort(niz, n);
	int end_time = clock();
	return (double)(end_time - start_time) / CLOCKS_PER_SEC;
}
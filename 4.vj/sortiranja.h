#ifndef SORTIRANJA_H
#define SORTIRANJA_H 1
int* generiraj(int n);
void shuffle(int *niz, int n);
void print(int *niz, int n);
void selectionsort(int *niz, int n);
void insertionsort(int *niz, int n);
void swap(int* niz, int left, int right);
int median(int* niz, int n);
int partition(int *niz, int n);
void quicksort(int *niz, int n);
void merge(int *niz, int *niza, int na, int *nizb, int nb);
int* duplicate(int *niz, int n);
void autosort(int *niz, int n);
double measure(void(*sort)(int *niz, int n), int *niz, int n);
#endif
//GOTOVO
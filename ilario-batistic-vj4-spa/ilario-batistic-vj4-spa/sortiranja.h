#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <stdbool.h>

#ifndef SORTIRANJA_C
#define SORTIRANJA_C

int* generiraj(int n);
void shuffle(int* niz, int n);
void print(int* niz, int n);
void selectionsort(int* niz, int n);
void insertionsort(int* niz, int n);
int partition(int* niz, int n);
void quicksort(int* niz, int n);
void merge(int* niz, int* niza, int na, int* nizb, int nb);
int* duplicate(int* niz, int n);
void mergesort(int* niz, int n);
double measure(void(*sort)(int* niz, int n), int* niz, int n);
int median(int* niz, int n);
void quicksort_novi(int* niz, int n);
bool choose_pivot;
int n_min;
#endif//SORTIRANJA_H
#include "sortiranja.h"

void main()
{
	int n = 1000000;
	//preko 100 milijuna nemoj ic jer ce trajat zauvijek da odradi sve(i mozda nece radit)
	//quicksort ovdi
	//razlika se pocinje viditi kada imamo niz od 1 000 000 elemenata(i prije se vidi ali u ovom slucaju je puno lakse za vidit)
	//pivot ubrzava prtragu
	printf("\n Prvi Zadatak \n");
	for (int i = 0; i < 10; i++)
	{
		printf("Velicina niza: %d\n", n);
		int* niz = generiraj(n);
		shuffle(niz, n);
		int* niz_duplikat = duplicate(niz, n);
		printf("------------------------------------------------------------\n");
		printf("Quicksort bez pivota: %lf\n", measure(quicksort, niz, n));
		choose_pivot = true;
		printf("Quicksort sa pivotom: %lf\n", measure(quicksort, niz_duplikat, n));
		choose_pivot = false;
		printf("------------------------------------------------------------\n");
		free(niz);
		free(niz_duplikat);
		n = n + 1000000;
	}
	printf(" \n Drugi Zadatak\n");
	n = 1000000;
	while (n_min <= 200)
	{
		printf("Broj varijabli za selectsort: %d\n", n_min);
		int* niz = generiraj(n);
		shuffle(niz, n);
		printf("------------------------------------------------------------\n");
		printf("Quicksort bez pivota: %lf\n", measure(quicksort_novi, niz, n));
		printf("------------------------------------------------------------\n");
		free(niz);
		n_min = n_min + 5;
	}
	//porpravi kasnije
   /*
	int n1 = 500;
	int n2 = 153;
	int* niz1 = generiraj(n1);
	int* niz2 = generiraj(n2);
	int ukupan_broj = n1 + n2;
	int* niz_merge = (int*)malloc(sizeof(int) * (n1 + n2));
	merge(niz_merge, niz1, n1, niz2, n2);
	mergesort(niz_merge, ukupan_broj);
	print(niz_merge, ukupan_broj);
	*/
}
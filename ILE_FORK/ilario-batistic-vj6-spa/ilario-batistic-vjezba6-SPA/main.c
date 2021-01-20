#include "queue.h"
#include "queue.c"

void main()
{
	Queue* qq = create();
	Element e1 = { "Stol",1 };
	Element e2 = { "Koko",7 };
	Element e3 = { "Roko",6 };
	Element e4 = { "Jabuka",10 };
	Element e5 = { "Plenki",12 };
	Element e6 = { "Laptop",8 };
	Element e7 = { "Jamnica",2 };
	Element e8 = { "Biokovo",5 };
	Element e9 = { "Secer",14 };
	Element e10 = { "Monitor",15 };

	dodavanje_queue(qq, &e1);
	dodavanje_queue(qq, &e2);
	dodavanje_queue(qq, &e3);
	dodavanje_queue(qq, &e4);
	dodavanje_queue(qq, &e5);
	dodavanje_queue(qq, &e6);
	dodavanje_queue(qq, &e7);
	dodavanje_queue(qq, &e8);
	dodavanje_queue(qq, &e9);
	dodavanje_queue(qq, &e10);
	printPQ(qq);
	printf("\nSkidanje Elementa:\n");
	skidanje_queue(qq);
	printPQ(qq);

}
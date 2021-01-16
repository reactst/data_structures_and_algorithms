#include <stdio.h>
#include <stdlib.h>

#ifndef QUEUE_H
#define QUEUE_H
#define max_velicina 10000
typedef struct Element {
	void* data;
	int prioritet;
}Element;

typedef struct {
	int  kapacitet, velicina_trenutna;
	Element* buffer;
}Queue;

Queue* create();
void dodavanje_queue(Queue* q, Element* novi);
void skidanje_queue(Queue* q);
void printPQ(Queue* q);
void fix_down(Queue* q, int r);
void fix_up(Queue* q, int c);

#endif // QUEUE_H
#include "queue.h"

Queue* create() {
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->kapacitet = max_velicina;
	q->buffer = (Element*)malloc(sizeof(Element) * max_velicina);
	q->velicina_trenutna = 0;
	return q;
}

void dodavanje_queue(Queue* q, Element* novi) {
	if (q->velicina_trenutna == max_velicina) {
		return;
	}
	int i = q->velicina_trenutna;
	q->buffer[i] = *novi;
	q->velicina_trenutna++;
	fix_up(q, i-1);
}

void fix_up(Queue* q, int c) {
	Element temp;
	if (c == 0) {
		return;
	}
	int r = (c-1) / 2;
	if (q->buffer[r].prioritet < q->buffer[c].prioritet) {
		temp = q->buffer[r];
		q->buffer[r] = q->buffer[c];
		q->buffer[c] = temp;
		fix_up(q, r);
	}
}

void skidanje_queue(Queue* q) {
	if (q->velicina_trenutna <= 0) {
		return;
	}
	Element temp;
	temp = q->buffer[0];
	q->buffer[0] = q->buffer[q->velicina_trenutna-1];
	q->velicina_trenutna--;
	fix_down(q, 0);
}

void fix_down(Queue* q, int r) {
	Element temp;
	int l = 2 * r+1, d = 2 * r+2;
	if ((d >= q->velicina_trenutna)&&(l>=q->velicina_trenutna)) {
		return;
	}
	//treba provjeriti jeli livo i desno dijete postoje
	//koji je veci po prioritetu
	if (d >= q->velicina_trenutna) {
		if (q->buffer[l].prioritet < q->buffer[r].prioritet) {
			temp = q->buffer[l];
			q->buffer[l] = q->buffer[r];
			q->buffer[r]= temp;
			fix_down(q, l);
		}
		return;
	}
	if (q->buffer[l].prioritet > q->buffer[d].prioritet) {
		if (q->buffer[l].prioritet > q->buffer[r].prioritet) {
			temp = q->buffer[r];
			q->buffer[r] = q->buffer[l];
			q->buffer[l] = temp;
			fix_down(q, l);
		}
	}
	else if (q->buffer[l].prioritet < q->buffer[d].prioritet) {
		if (q->buffer[d].prioritet > q->buffer[r].prioritet) {
			temp = q->buffer[r];
			q->buffer[r] = q->buffer[d];
			q->buffer[d] = temp;
			fix_down(q, d);
		}
	}
}

void printPQ(Queue* q) {
	for (int i = 0; i < q->velicina_trenutna; i++) {
		printf("Rijec: %s \t Prioritet: %d\n", (char*)q->buffer[i].data, q->buffer[i].prioritet);
	}
}
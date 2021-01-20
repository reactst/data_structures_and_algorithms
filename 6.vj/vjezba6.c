#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
typedef struct {
    void* ignore;
    int priority;
}element;

typedef struct {
    element *array;
}queue;

int unaprijedzadanaduzina = 10;

void print_queue (queue *q){
    for (int i=0;i<unaprijedzadanaduzina;i++) {
        printf ("Element; %d\n",q->array[i].priority);
    }
}

void element_switch (queue *q,int livi, int desni){
    element temp=q->array[livi];
    q->array[livi]=q->array[desni];
    q->array[desni]=temp;
}

void fix_to_top (queue *q,int num){
    if (num==0)
    return;
    int parent=floor((num-1)/2);
    element parentelement=q->array[parent];
    if (parentelement.priority<q->array[num].priority){
        element_switch(q,parent,num);
        fix_to_top(q,parent);
    }
}

void add (queue *q,int num){
    q->array[num].priority=rand()%unaprijedzadanaduzina;
    fix_to_top(q,num);
}

void fix_to_bottom (queue *q, int num){
    int livo=2*num+1;
    int desno=2*num+2;
    if (desno>=unaprijedzadanaduzina || livo>=unaprijedzadanaduzina){
        return;
    }
    if (q->array[num].priority < q->array[livo].priority && q->array[livo].priority>=q->array[desno].priority){
        element_switch (q,num,livo);
        fix_to_bottom(q,livo);
    }
    else if (q->array[num].priority < q->array[desno].priority && q->array[desno].priority>=q->array[livo].priority){
        element_switch (q,num,desno);
        fix_to_bottom (q,desno);
    }
}

void remove_from_top (queue *q){
    q->array[0]=q->array[unaprijedzadanaduzina-1];
    unaprijedzadanaduzina-=1;
    q->array=(element*)realloc(q->array,unaprijedzadanaduzina*sizeof(element));
    fix_to_bottom(q,0);
}

void main (){
    queue *q=(queue*)malloc(sizeof(queue));
    q->array=(element*)malloc(unaprijedzadanaduzina*sizeof(element));
    for (int i=0;i<unaprijedzadanaduzina;i++){
        add(q,i);
    }
    printf ("\tprije uklanjanja s vrha\n");
    print_queue(q);
    printf ("\tposli uklanjanja s vrha\n");
    remove_from_top(q);
    print_queue(q);
    remove_from_top(q);
    printf ("\n");
    print_queue(q);
    remove_from_top(q);
    printf ("\n");
    print_queue(q);
    free (q->array);
    free (q);
}
//GOTOVO
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct{
    float n1,n2,n3,v1x,v1y,v1z,v2x,v2y,v2z,v3x,v3y,v3z;
    unsigned short boja;
}trokut;
typedef struct{
    trokut* niz_trokuta;
    int n;
}objekt3d;

objekt3d binstl_to_object3d (const char binstl[],int n){
    float buffer[13];
    int brojac=1;
    objekt3d* noviobjekt=(objekt3d*)malloc(sizeof(objekt3d)*n);
    FILE* fp1=fopen(binstl,"rb");
    if(feof(fp1)){
        printf ("INVALID");
    }
   
}
void object3d_to_binstl (objekt3d* struktura3d){

}
void object3d_to_txtstl (objekt3d* struktura3d){

}
void deleter (objekt3d* struktura3d){

}


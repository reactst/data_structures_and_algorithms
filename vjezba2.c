#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct{
    float vars[12];
    unsigned short boja;
}trokut;
typedef struct{
    trokut* niz_trokuta;
    int n;
}objekt3d;

objekt3d binstl_to_object3d (const char binstl[],int n){
    float buffer[13];
    int brojac=0;
    objekt3d* noviobjekt=(objekt3d*)malloc(sizeof(objekt3d)*n);
    FILE* fp1=fopen(binstl,"rb");
    if(feof(fp1)){
        printf ("INVALID");
    }
    fread(buffer,sizeof(buffer),1,fp1);
    for (int i=0;i<EOF;i++){
        while (i!=0){
            // noviobjekt->niz_trokuta->n1=buffer[i];
            // noviobjekt->niz_trokuta->n2=buffer[i+1];
            // noviobjekt->niz_trokuta->n3=buffer[i+2];
            // noviobjekt->niz_trokuta->v1x=buffer[i+3];
            // noviobjekt->niz_trokuta->v2x=buffer[i+4];
            // noviobjekt->niz_trokuta->v3x=buffer[i+5];
            // noviobjekt->niz_trokuta->v1y=buffer[i+6];
            // noviobjekt->niz_trokuta->v2y=buffer[i+7];
            // noviobjekt->niz_trokuta->v3y=buffer[i+8];
            // noviobjekt->niz_trokuta->v1z=buffer[i+9];
            // noviobjekt->niz_trokuta->v2z=buffer[i+10];
            // noviobjekt->niz_trokuta->v3z=buffer[i+11];
        }
    }
}
void object3d_to_binstl (objekt3d* struktura3d){

}
void object3d_to_txtstl (objekt3d* struktura3d){

}
void deleter (objekt3d* struktura3d){

}


#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct{
    float niz[3];
}vrh;
typedef struct{
    float normala[3];
    vrh vrhovi [3];
    unsigned short nula;
}trokut;
typedef struct {
    unsigned int n;
    trokut* niz;
}objekt3d;
//PRETVARANJE BINARNE STL DATOTEKE U OBJEKT3D STRUKTURU
objekt3d* binstl_to_object3d (const char binstl[]){
    FILE* open=fopen (binstl,"rb");
    unsigned int num;
	float tmp[3];
    fseek(open,80,SEEK_SET);
    fread(&num,4,1,open);
    objekt3d * objetto=(objekt3d*)malloc(sizeof(objekt3d));
    objetto->n=num;
    objetto->niz=(trokut*)malloc(objetto->n*(sizeof(trokut)));
    for (int i=0;i<objetto->n;i++){
        fread(&tmp,4,3,open); //normala
        for (int j=0;j<3;j++){
            objetto->niz[i].normala[j]=tmp[j];
        }
        fread(&tmp,4,3,open); //1.vrh
        for (int j=0;j<3;j++){
            objetto->niz[i].vrhovi[0].niz[j]=tmp[j];
        }
        fread(&tmp,4,3,open); //2. vrh
        for (int j=0;j<3;j++){
            objetto->niz[i].vrhovi[1].niz[j]=tmp[j];
        }
        fread(&tmp,4,3,open); //3.vrh
        for (int j=0;j<3;j++){
            objetto->niz[i].vrhovi[2].niz[j]=tmp[j];
        }
        fseek (open,2,SEEK_CUR);
    }
    fclose (open);
    return objetto;
}
//CITANJE 3D STRUKTURE
void object3d_read (objekt3d* struktura3d){
    for (int i=0;i<struktura3d->n;i++){
        printf ("\n");
        printf ("Normala: ");
        for (int j=0;j<3;j++){
            printf ("%f ",struktura3d->niz[i].normala[j]);
        }
        printf ("\nVrhovi: \n");
        for (int z=0; z < 3; z++) {
			for (int j=0; j < 3; j++) {
				printf("%f ", struktura3d->niz[i].vrhovi[z].niz[j]);
			}
			printf("\n");
		}
    }
    printf("\n");
}
//PRETVARANJE OBJEKT3D STRUKTURE U BIN FILE
void object3d_to_binstl (objekt3d* struktura3d){
    float nula[20];
    int nula_len=sizeof(nula)/sizeof(nula[0]);
    int broj_trokuta=struktura3d->n;
    short boja=0;
    FILE* newfile=fopen("pretvorbabin.stl","wb");
    for (int i=0;i<nula_len;i++){
        nula[i]=0;
    }
    fwrite(&nula,4,nula_len,newfile);
    fwrite (&broj_trokuta,4,1,newfile);
    for (int i=0;i<broj_trokuta;i++){
        fwrite(struktura3d->niz[i].normala, 12, 1, newfile);
		fwrite(struktura3d->niz[i].vrhovi, 36, 1, newfile);
		fwrite(&boja, 2, 1, newfile);
    }
    fclose (newfile);
}
//OBJEKT3D U TXT FILE
void object3d_to_txt(objekt3d* struktura3d) {
	FILE *newfiletxt= fopen("pretvorbatxt.stl","w");
	fprintf(newfiletxt, "solid STL\n");
	for (int i=0; i < struktura3d->n; i++) {
		fprintf(newfiletxt, "facet normal %f %f %f\n", struktura3d->niz[i].normala[0], struktura3d->niz[i].normala[1], struktura3d->niz[i].normala[2]);
		fprintf(newfiletxt, "outer loop\nvertex %f %f %f\n", struktura3d->niz[i].vrhovi->niz[0], struktura3d->niz[i].vrhovi[0].niz[1], struktura3d->niz[i].vrhovi[0].niz[2]);
		fprintf(newfiletxt, "vertex %f %f %f\n", struktura3d->niz[i].vrhovi->niz[1], struktura3d->niz[i].vrhovi[1].niz[1], struktura3d->niz[i].vrhovi[1].niz[2]);
		fprintf(newfiletxt, "vertex %f %f %f\nendloop\nendfacet\n", struktura3d->niz[i].vrhovi->niz[2], struktura3d->niz[i].vrhovi[2].niz[1], struktura3d->niz[i].vrhovi[2].niz[2]);
	}
	fprintf(newfiletxt, "endsolid STL");
}
//BRISACH OBJEKT3D STRUKTURE
void deleter (objekt3d* struktura3d){
    free (struktura3d);
}
void main (){
    const char* binstl="primjerbin.stl"; 
    const char* txtstl="primjertxt.stl"; 
    objekt3d* main_objekt=binstl_to_object3d(binstl);
    object3d_read(main_objekt);
    object3d_to_binstl (main_objekt);
    object3d_to_txt (main_objekt);
    deleter (main_objekt);
}


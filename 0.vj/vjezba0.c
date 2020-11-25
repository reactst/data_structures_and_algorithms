#include <stdio.h>
//mystrlen() – funkcija prima string (char*) i vraća integer koji predstavlja dužinu stringa.
int mystrlen (char* unos) {
    int lenght=0;
    for (int i=0;unos[i]!='\0';i++){
        lenght++;
    }
    return lenght;
}
//mystrcpy() – funkcija prima dva stringa i kopira drugi string u prvi string.
char* mystrcpy (char source[],char dest[]){
    int i=0;
    while (dest[i]!='\0'){
        source[i]=dest[i];
        i++;
    }
    source[i]='\0';
    return source;
}
/*
mystrcmp() – funkcija prima dva stringa i uspoređuje ih. 
Funkcija vraća: broj manji od nula ako je prvi string manji od drugog stringa (po leksikografskom poretku), 
broj veći od nula ako je drugi string manji od prvog i nula ako su stringovi jednaki.
*/
int mystrcmp (char str1[],char str2[]){
    int len1=mystrlen(str1);
    int len2=mystrlen(str2);
    int longer = len1 > len2 ? len1 : len2;
    for (int i=0;i<longer;i++) {
        if (str1[i]<str2[i]){
            return -1;
        }
        if (str1[i]>str2[i]){
            return 1;
        }
    }
    if (len1==len2)
    return 0;
}
//mystrcat() – funkcija „dodaje“ drugi string na kraj prvog stringa.
char* mystrcat(char str1[],char str2[]) {
    int len2 = mystrlen(str2);
    int len1 = mystrlen(str1);
    for (int i=0; i < len2; i++) {
        str1[len1] = str2[i];
        len1++;
    }
    return str1;
}
/*
mystrstr() – funkcija vraća pokazivač (unutar prvog stringa) 
koji pokazuje na prvo pojavljivanje drugog stringa. 
Ako ga ne pronađe, funkcija vraća NULL.
*/
char* mystrstr(char* string1[],char* string2[]){
    int test;
    int len1=mystrlen(string1);
    int len2=mystrlen(string2);
    for(int i=0;i<=len1-len2;i++) {
        test=1;
        for(int j=0; j<len2; j++)  {
            if(string1[i+j]!=string2[j]) {
                test=0;
                break;
            }
        }
        if(test==1){
           return &(string2[len1]);
        }
    }
    return NULL;
}
//reverse() – prima dva stringa i kopira prvi string u drugi string naopako (funkcija ne postoji u string.h)
char* reverse (char source[],char dest[]){
    int i=mystrlen(source)-1;
    int j=0;
    dest[i+1]='\0';
    while (i >= 0){
        dest[j]=source[i];
        i--;
        j++;
    }
    dest[j+1]='\0';
    return dest;
}
void main (){
    char string[] = "ABCDE";
    char string2[] = "ABCDP";
    char test[] = "TESTREVERSE";
    char testReverse[] = "REVERSE";
    printf ("Duljina stringa je %d\n", mystrlen(string));
    printf ("Duljina stringa je %d\n", mystrlen(string2));
    //printf ("ISKOPIRAN string je %s\n", mystrcpy(test,string2));    //MIJENJA (test)string
    //printf ("Leksikografski veći je %d\n",mystrcmp (string,string2));  
    // printf("strcat string je %s\n", mystrcat(string, string2));             //MIJENJA string
    printf ("mystrstr: %s\n",mystrstr(test,testReverse));               
    // printf ("reverse string ježž %s\n", reverse(string,testReverse));         //MIJENJA testReverse
}
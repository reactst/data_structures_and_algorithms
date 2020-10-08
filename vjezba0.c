int mystrlen (char unos[]) {
    int lenght=0;
    for (int i=0;unos[i]!='\0';i++){
        lenght++;
    }
    return lenght;
}
//test push
char * mystrcpy (char source[],char dest[]){
    int i=0;
    while (dest[i]!='\0'){
        source[i]=dest[i];
        i++;
    }
    i++;
    dest[i]='\0';
    return dest;
}
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
char* mystrcat(char str1[],char str2[]) {
    int len2 = mystrlen(str2);
    int len1 = mystrlen(str1);
    for (int i=0; i <= len2; i++,len1++) {
        str1[len1] = str2[i];
    }
    return str1;
}

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

int main (){
    char string[] = "ABCDE";
    char string2[] = "ABCDP";
    char test[] = "TEST";
    char testReverse[] = "TESTREVERSE";
    printf ("Duljina stringa je %d\n", mystrlen(string));
    printf ("Duljina stringa je %d\n", mystrlen(string2));
    // printf ("ISSKOPIRAN string je %s\n", mystrcpy(test,string2));
    // printf ("Leksikografski veći je %d\n",mystrcmp (string,string2));  //ODKOMENTIRAJTE 1 po 1
    // printf("strcat string je %s\n", mystrcat(string, string2));
    // printf ("reverse string je %s\n", reverse(string,testReverse));

    return 0;
}
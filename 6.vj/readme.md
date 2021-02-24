**6. Laboratorijska vježba**
Prioritetni red

Implementacija sa gomilom

Potrebno je implementirati prioritetni red kao apstraktnu strukturu podataka sa operacijama: 

    •stvaranje prioritetnog reda 
    •dodavanje elementa sa prioritetom 
    •vađenje „najvažnijeg“ elementa.

Implementacija će koristiti gomilu koja je predstavljena nizom unaprijed zadane dužine (N=10000). 
Svaki član niza je struktura koja sadrži void* na neke podatke (koji ćemo ignorirati) i integer koji označava prioritet. 

Operacija dodavanja dodaje novi element na kraj niza. Operacija dodavanja novog elementa će se oslanjati na funkciju koja popravlja gomilu „prema vrhu“. 
Ta funkcija će za neki element zadan svojim indeksom c provjeriti da li je njegov roditelj na indeksu r manji ili veći, ako je element na r manji od elementa na c, elementi će se zamijeniti i funkcija će se rekurzivno pozvati za element na indeksu r.

Operacija uklanjanja elementa na vrhu gomile (na indeksu 0) i prebacuje zadnji element niza na indeks 0. 
Operacija uklanjanja će se oslanjati na funkciju koja popravlja gomilu „prema dnu“. 
Ta funkcija će za neki element r provjeravati da li je manji od svoje djece na indeksima l i d. Ako je, zamijeniti će se sa većim od njih i funkcija će se rekurzivno pozvati za element na indeksu tog djeteta.

(Na slideovima sa predavanja su ilustrirane obje operacije).

Dodatno:
Napisati iterativne verzije funkcija. 
Implementirati heap-sort:


    1. Popraviti prema dolje sve čvorove u nizu od kraja niza prema početku niza
    2. Sortirati hrpu:
        a. Zamijeniti dva elementa: na vrhu hrpe i na kraju niza
        b. Smanjiti veličinu hrpe za jedan
        c. Popraviti hrpu od vrha
        d. Ponavljati dok se veličina hrpe ne smanji na 0


GOTOVO

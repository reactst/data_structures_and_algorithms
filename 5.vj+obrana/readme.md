5. Laboratorijska vježba

Vezane liste 

Unutar dictionary.c je potrebno implementirati funkcije opisane u dictionary.h datoteci. Kôd je na stranicama kolegija.

Uz opisane funkcije, treba dodati i funkciju za filtriranje liste:


    Dictionary filterDictionary(Dictionary indict, int (*filter)(Word *w));


Funkcija prima rječnik (lista ispunjena sa abecedno poredanim riječima i brojem pojavljivanja u tekstu) i pokazivač na funkciju:


    int filter(Word *w);


Funkcija filterDictionary() vraća izmijenjenu indict listu koja sadrži samo riječi za koje je filter() funkcija vratila 1 (sve druge riječi se oslobađaju). Funkcija filter() vraća 1 ako je broj pojavljivanja riječi između 5 i 10 i ako je riječ duža od 3 znaka.

//OBRANA

Za pristup obrani je potrebno imati prvih 6 vježbi podignutih na moodle.
Umjesto obrane vježbi možete riješiti i pokazati mi (do termina obrana) dodatnu vježbu koja je stavljena na moodle.

Obrana će se sastojati od zadatka koji je vezan uz vježbu sa vezanim listama gdje će biti potrebno dodati ili promijeniti neku od funkcionalnosti. Zadatak će obuhvaćati neke od operacija sa listama:


    • Šetanje po listi
        ◦ Traženje najduže riječi
        ◦ Ukupan broj riječi
    • Kreiranje i dodavanje novog elementa:
        ◦ Na početak liste
        ◦ Na kraj liste
        ◦ Prije određenog elementa u listi
        ◦ Na određenom indeksu u listi
    • Pronalazak i uklanjanje elementa iz liste:
        ◦ Sa početka liste
        ◦ Sa kraja liste
        ◦ Određenu riječ
    • Okretanje liste
    • Uklanjanje više elemenata iz liste po nekom kriteriju (npr. zadnjih 10 elemenata ili sve elemente sa više od 10 znakova)
    • Dodavanje više elemenata u listu (npr. ispred svake riječi duže od 10 znakova)
    • Prebacivanje elementa u listi (npr. sa kraja na početak liste)
    • Prebacivanje dijela liste u novu listu po nekom kriteriju (npr. sve riječi duže od 10 znakova)
    • Zamjena dva elementa u listi (npr. prvi i zadnji)
    • Kopiranje jednog ili više elemenata u novu listu
    • Kopiranje jednog ili više elemenata u niz
    • Dodavanje elemenata iz niza u listu
    • Druge moguće kombinacije operacija u okviru navedenog.

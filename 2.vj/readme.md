**2. Laboratorijska vježba**
Datoteke i strukture


Napisati funkcije za rad sa datotekama u STL formatu (format za opis 3D objekata). Osnovni STL format je sastavljen od zaglavlja i niza trokuta (od kojih je sastavljena površina 3D objekta). STL format može biti tekstualan ili binaran. 


Za tekstualni format:

	• Zaglavlje je jedna linija teksta „solid ime„ gdje je ime proizvoljno i može biti prazno
	• Svaki trokut je opisan sa idućim linijama gdje su n i v realni brojevi:
		
        facet normal ni nj nk
            outer loop
                vertex v1x v1y v1z
                vertex v2x v2y v2z
                vertex v3x v3y v3z
            endloop
        endfacet

Za binarni format:

    • Zaglavlje je dugo 80 byte-ova i može biti ignorirano pri čitanju i ispunjeno nulama pri stvaranju datoteke. Nakon toga se nalazi broj trokuta u datoteci (unsigned int).
    • Svaki trokut je opisan sa 12 realnih brojeva (float):
        ◦ Prva tri 3 broja su normala
        ◦ Idućih 9 brojeva su koordinate vrha svakog trokuta
    • Nakon svakog trokuta se nalazi dodatni broj (unsigned short) koji će biti 0

Prilikom čitanja/pisanja pripazite da će zapis u binarnoj datoteci zauzimati 50 byte-ova, a struktura trokut 52 byte-a.

Potrebno je definirati strukturu Trokut koja će predstavljati jedan trokut sa normalom i sa dodatnim unsigned short brojem (boja trokuta), ukupno 50 byte-ova. Definirati dodatnu strukturu Objekt3D koja će sadržati niz trokuta i njihov broj. Možete definirati i iskoristiti dodatnu strukturu Vrh za koordinate vrhova trokuta. Potrebno je napisati i testirati funkcije:
   	
	1) Funkciju koja čita binarnu STL datoteku i vraća ispunjenu Objekt3D  strukturu
   	2) Funkciju koja Objekt3D strukturu zapisuje u binarnu STL datoteku
   	3) Funkcija koja Objekt3D strukturu zapisuje u tekstualnu STL datoteku
   	4) Funkciju koja briše Objekt3D strukturu


Dodatno:
Organizirati sve funkcije u stl.h i stl.c kao biblioteku. Napisati funkciju koja čita tekstualnu STL datoteku.

Laboratorijska vježba

Dodatne vježbe za strukture i datoteke

    1) Napisati program koji od korisnika čita n brojeva u niz i zatim ih sprema u binarnu datoteku (sa fwrite). Prije samog niza se sprema broj n. Broj n se isto čita od korisnika prije čitanja samih brojeva niza.
    2) Napisati program koji čita datoteku iz prethodnog zadatka (sa fread) i ispisuje brojeve na ekran.
    3) Napisati program koji od korisnika čita n struktura u niz i zatim ih sprema u binarnu datoteku. Prije samog niza se sprema broj n. Broj n se isto čita od korisnika prije čitanja struktura. Strukture su tipa Koordinata i sastoje se od dva float broja.
    4) Napisati program koji od korisnika čita jedan broj odnosno indeks. Program iz datoteke iz prethodnog zadatka čita i ispisuje na ekran koordinatu koja odgovara tom indeksu. (koristite fseek)
    5) Napisati program koji od korisnika čita dvije koordinate. Program u datoteku (iz zadatka 3) dodaje još jednu točku na kraj datoteke. Program zatim čita i ispisuje sve koordinate unazad. (otvorite datoteku za čitanje i pisanje)

    
 GOTOVO

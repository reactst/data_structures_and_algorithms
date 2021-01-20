#include "dictionary.h"

int readWord(FILE* fd, char* buffer)
{
	int c;

	do {
		c = fgetc(fd);
		if (c == EOF)
			return 0;
	} while (!isalpha(c));

	do {
		*buffer = tolower(c);
		buffer++;
		c = fgetc(fd);
		if (c == 146)
			c = '\'';
	} while (isalpha(c) || c == '\'');

	*buffer = '\0';
	return 1;
}

void main()
{
	FILE* fd;
	char buffer[1024];
	Dictionary dict,novi_dict,kopirani_list,nova_lista;
	fd = fopen("liar.txt", "rt");
	if (fd == NULL)
	{
		printf("Error opening file.\n");
		return;
	}
	dict = create();
	while (readWord(fd, buffer))
	{
		add(dict, buffer);
	}
	fclose(fd);
	//char* niz_stringova[4] = { "Bog","Sirija","i","Bashar" };
	//int n = duljina_niza(niz_stringova);
	int n = 100;
	char** niz_stringova2 = dodavanje_iz_liste_u_niz(dict, n);
	//dict=dodaj_na_glavu(dict, "Bashar Al-Assad");
	//dodavanje_na_2_i_3_poziciju(dict);
	//dodavanje_iz_niza_u_listu(dict, niz_stringova, n);
	//dodaj_prije_odredenog_elemeata(dict, "a", "KOKO");
	//dodavanje_prije_odredenog_indeks(dict, 3, "Bubamara");
	//dict = obrnuta_lista(dict);
	//brisanje_pod_odredenim_uvjetima(dict);
	//print(novi_dict);
	//brisanje_odredenog_elemenata( dict,"Sotona");
    //dodavanje_elementa_nakon_nekog_uvjeta(dict,"OK");
	//kopirani_list = create();
    //kopirani_elemnti_nova_lista(kopirani_list,dict, 7);
	//zamjena_prvi_zdanji(dict);
	//nova_lista = create();
	//lista_sa_odrdedenim_rjecima(dict,nova_lista);
	print(dict);
	//filterDictionary(dict, filter);
	printf("\n\n\n");
	printf("Filtrinaraanranran rjecnik:\n");
	printf("\n\n\n");
	for (int i = 0;i < n;i++) {
		printf("%s\n", niz_stringova2[i]);
	}
	//print(nova_lista);
	//print(dict);
	//destroy(dict);

}
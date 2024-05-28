//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include<malloc.h>
//#include<string.h>
//
//typedef struct Cinema Cinema;
//typedef struct Nod Nod;
//
//struct Cinema {
//	int id;
//	int nrFilme;
//	char** listaFilme;
//};
//
//struct Nod {
//	Cinema info;
//	Nod* st;
//	Nod* dr;
//};
// 
//Cinema citireCinema(FILE* f) {
//	Cinema c;
//	fscanf(f, "%d", &c.id);
//	fscanf(f, "%d", &c.nrFilme);
//	if (c.nrFilme != 0) {
//		c.listaFilme = (char**)malloc(sizeof(char*) * c.nrFilme);
//		for (int i = 0; i < c.nrFilme; i++) {
//			char buffer[100];
//			fscanf(f, "%s", buffer);
//			c.listaFilme[i] = malloc(sizeof(char) * (strlen(buffer) + 1));
//			strcpy(c.listaFilme[i], buffer);
//
//		}
//	}
//	else {
//		c.listaFilme = NULL;
//	}
//
//	return c;
//}
//
//
//void afisareCinema(Cinema c) {
//	printf("Cinematograful cu id-ul %d are in derulare %d filme:", c.id, c.nrFilme);
//	for (int i = 0; i < c.nrFilme; i++) {
//		printf("%s, ", c.listaFilme[i]);
//	}
//	printf("\n");
//}
//
//void afisareArborePreordine(Nod* rad) {
//	if (rad) {
//		afisareCinema(rad->info);
//		afisareArborePreordine(rad->st);
//		afisareArborePreordine(rad->dr);
//	}
//}
//
//void afisareArboreInordine(Nod* rad) {
//	if (rad) {
//		afisareArboreInordine(rad->st);
//		afisareCinema(rad->info);
//		afisareArboreInordine(rad->dr);
//	}
//}
//
//int calculNrFilmeRedate(Nod* rad) {
//	if (rad) {
//		int suma = rad->info.nrFilme;
//		suma += calculNrFilmeRedate(rad->st);
//		suma += calculNrFilmeRedate(rad->dr);
//		return suma;
//	}
//	else {
//		return 0;
//	}
//}
//Nod* rotireDreapta(Nod* rad) {
//	if (rad) {
//		Nod* aux = rad->st;
//		rad->st = aux->dr;
//		aux->dr = rad;
//		return aux;
//	}
//	else {
//		return rad;
//	}
//}
//Nod* rotireStanga(Nod* rad) {
//	if (rad) {
//		Nod* aux = rad->dr;
//		rad->dr = aux->st;
//		aux->st = rad;
//		return aux;
//	}
//	else {
//		return rad;
//	}
//}
//
//int calculInaltime(Nod* rad) {
//	if (rad != NULL) {
//		int inaltimeSt = calculInaltime(rad->st);
//		int inaltimeDr = calculInaltime(rad->dr);
//		if (inaltimeSt > inaltimeDr)
//			return 1 + inaltimeSt;
//		else return 1 + inaltimeDr; 
//	}
//	else return 0;
//}
//
//int calculGradEchilibru(Nod* rad) {
//	int inaltimeSubarboreStang = calculInaltime(rad->st);
//	int inaltimeSubarboreDrept = calculInaltime(rad->dr);
//	return inaltimeSubarboreStang - inaltimeSubarboreDrept;
//}
//
//void inserareInArbore(Nod** radacina, Cinema c) {
//	if (*radacina) {
//		if ((*radacina)->info.id > c.id) {
//			inserareInArbore(&((*radacina)->st), c);
//		}
//		else {
//			inserareInArbore(&((*radacina)->dr), c);
//		}
//		int grad = calculGradEchilibru(*radacina);
//		if (grad == 2) { //dezechilibru in stanga
//			int gradCopil = calculGradEchilibru((*radacina)->st);
//			if (gradCopil==-1) {//situatia complexa de dezechilibru
//				(*radacina)->st = rotireStanga((*radacina)->st);
//			}
//			*radacina = rotireDreapta((*radacina));
//		}
//		else if (grad == -2) {
//			int gradCopil = calculGradEchilibru((*radacina)->dr);
//			if (gradCopil == 1) {//situatia complexa de dezechilibru
//				(*radacina)->dr = rotireDreapta((*radacina)->dr);
//			}
//			*radacina = rotireStanga((*radacina));
//		}
//	}
//	else {
//		Nod* nod = malloc(sizeof(Nod));
//		nod->dr = NULL;
//		nod->st = NULL;
//		nod->info = c;
//		*radacina = nod;
//	}
//}
//
//Nod* citireFisier(const char* fisier) {
//	Nod* radacina = NULL;
//	if (fisier != NULL && strlen(fisier) != 0) {
//		FILE* f = fopen(fisier, "r");
//		if (f != NULL) {
//			int dim = 0;
//			fscanf(f, "%d", &dim);
//
//			for (int i = 0; i < dim; i++) {
//				Cinema cinema;
//				cinema = citireCinema(f);
//				inserareInArbore(&radacina, cinema);
//			}
//		}
//	}
//	return radacina;
//}
//
//void stergereArbore(Nod** rad) {
//	if (*rad) {
//		stergereArbore(&((*rad)->st));
//		stergereArbore(&((*rad)->dr));
//		if ((*rad)->info.listaFilme) {
//			for (int i = 0; i < (*rad)->info.nrFilme; i++) {
//				free((*rad)->info.listaFilme[i]);
//			}
//			free((*rad)->info.listaFilme);
//		}
//		free((*rad));
//		(*rad) = NULL;
//	}
//}
//
//Cinema calculCinemaCuNrMax(Nod* rad) {
//	if (rad) {
//		Cinema cinemaStanga = calculCinemaCuNrMax(rad->st);
//		Cinema cinemaDreapta = calculCinemaCuNrMax(rad->dr);
//		Cinema cinemaMaxim;
//		if (rad->info.nrFilme > cinemaStanga.nrFilme && rad->info.nrFilme > cinemaDreapta.nrFilme) {
//			cinemaMaxim = rad->info;
//		}
//		else if (cinemaStanga.nrFilme > cinemaDreapta.nrFilme) {
//			cinemaMaxim = cinemaStanga;
//		}
//		else {
//			cinemaMaxim = cinemaDreapta;
//		}
//		return cinemaMaxim;
//	}
//	else {
//		Cinema c;
//		c.id = -1;
//		c.listaFilme = NULL;
//		c.nrFilme = 0;
//		return c;
//	}
//}
//
//void main() {
//	Nod* arbore = NULL;
//	arbore = citireFisier("cinema.txt");
//	afisareArborePreordine(arbore);
//
//	printf("\n\nNumar filme: %d", calculNrFilmeRedate(arbore));
//
//	printf("\nCinema cu nr filme max:\n");
//	Cinema cinema = calculCinemaCuNrMax(arbore);
//	afisareCinema(cinema);
//
//	stergereArbore(&arbore);
//	afisareArborePreordine(arbore);
//}
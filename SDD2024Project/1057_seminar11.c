//#define	_CRT_SECURE_NO_WARNINGS
//
//#include<stdio.h>
//#include<malloc.h>
//
//typedef struct Rezervare Rezervare;
//struct Rezervare {
//	int id;
//	char* numeClient;
//	int nrPersoane;
//};
//
//typedef struct Nod Nod;
//struct Nod {
//	Nod* stanga;
//	Nod* dreapta;
//	Rezervare info;
//};
//
//
//Rezervare citireRezervare(FILE* f)
//{
//	Rezervare r;
//	char aux[30];
//	fgets(aux, 30, f);
//	fscanf(f, "%d",&r.id);
//	fscanf(f, "%s", &aux);
//	r.numeClient = malloc(sizeof(char) * (strlen(aux) + 1));
//	strcpy(r.numeClient, aux);
//	fscanf(f, "%d", &r.nrPersoane);
//	return r;
//
//}
//
//Nod* rotireLaDreapta(Nod* rad) {
//
//	if (rad) {
//		Nod* aux = rad->stanga;
//		rad->stanga = aux->dreapta;
//		aux->dreapta = rad;
//		return aux;
//	}
//	else {
//		return NULL;
//	}
//}
//
//Nod* rotireLaStanga(Nod* rad) {
//	if (rad) {
//		Nod* aux = rad->dreapta;
//		rad->dreapta = aux->stanga;
//		aux->stanga = rad;
//		return aux;
//	}
//	else {
//		return NULL;
//	}
//}
//
//Nod* inserareInArbore(Nod* arbore, Rezervare rez) {
//	if (arbore != NULL) {
//		if (arbore->info.id < rez.id) {
//			arbore->dreapta = inserareInArbore(arbore->dreapta, rez);
//		}
//		else {
//			arbore->stanga = inserareInArbore(arbore->stanga, rez);
//		}
//
//		int grad = calculGradEchilibru(arbore);
//		if (grad == 2) {
//			if (calculGradEchilibru(arbore->stanga) == -1) {
//				arbore->stanga = rotireLaStanga(arbore->stanga);
//			}
//			arbore = rotireLaDreapta(arbore);
//		}
//
//		if (grad == -2) {
//			if (calculGradEchilibru(arbore->dreapta) == 1) {
//				arbore->dreapta = rotireLaDreapta(arbore->dreapta);
//			}
//			arbore = rotireLaStanga(arbore);
//		}
// 
//	}
//	else {
//		Nod* temp = (Nod*)malloc(sizeof(Nod));
//		temp->info = rez; //shallow copy
//		temp->dreapta = NULL;
//		temp->stanga = NULL;
//
//		arbore = temp;
//	}
//
//	return arbore;
//}
//
//void citireFisier(char* numeFisier,Nod** radacina)
//{
//	int nrRezervari;
//	FILE* f = fopen(numeFisier, "r");
//	fscanf(f, "%d", &nrRezervari);
//	for (int i = 0; i < nrRezervari; i++)
//	{
//		Rezervare rez;
//		rez = citireRezervare(f);
//		*radacina = inserareInArbore(*radacina, rez);
//	}
//
//}
//
//void afisareRezervare(Rezervare r) {
//	printf("Rezervarea cu ID-ul %d a fost facuta de %s pentru %d persoane.\n", r.id, r.numeClient, r.nrPersoane);
//}
//
//void afisareArborePreOrdine(Nod* arbore) {
//	if (arbore != NULL) {
//		afisareRezervare(arbore->info);
//		afisareArborePreOrdine(arbore->stanga);
//		afisareArborePreOrdine(arbore->dreapta);
//	}
//}
//
//void afisareArboreInOrdine(Nod* arbore) {
//	if (arbore != NULL) {
//		afisareArboreInOrdine(arbore->stanga);
//		afisareRezervare(arbore->info);
//		afisareArboreInOrdine(arbore->dreapta);
//	}
//}
//
//void afisareArborePostOrdine(Nod* arbore) {
//	if (arbore != NULL) {
//		afisareArborePostOrdine(arbore->stanga);
//		afisareArborePostOrdine(arbore->dreapta);
//		afisareRezervare(arbore->info);
//	}
//}
//
//Rezervare cautarezervareDupaId(Nod* rad, int id) {
//	if (rad) {
//		if (rad->info.id < id) {
//			return cautarezervareDupaId(rad->dreapta, id);
//		}
//		else {
//			if (rad->info.id > id) {
//
//				return cautarezervareDupaId(rad->stanga, id);
//			}
//			else {
//				return rad->info;
//			}
//		}
//	}
//	else {
//		Rezervare r;
//		r.id = -1;
//		r.numeClient = NULL;
//		r.nrPersoane = -1;
//		return r;
//	}
//
//}
//
//
//int calculNrTotalPersoane(Nod* rad) {
//	if (rad) {
//		int rPersoane = rad->info.nrPersoane;
//		int sPersoane = calculNrTotalPersoane(rad->stanga);
//		int dPersoane = calculNrTotalPersoane(rad->dreapta);
//		int suma = rPersoane + sPersoane + dPersoane;
//		return suma;
//	}
//	else {
//		return 0;
//	}
//}
//
//
//
//int inaltimeArbore(Nod* rad) {
//	if (rad) {
//		int inaltimeStanga = inaltimeArbore(rad->stanga);
//		int inaltimeDreapta = inaltimeArbore(rad->dreapta);
//		return 1 + (inaltimeStanga > inaltimeDreapta ? inaltimeStanga : inaltimeDreapta);
//	}
//	else {
//		return 0;
//	}
//}
//
//int calculGradEchilibru(Nod* rad) {
//	if (rad) {
//		int inaltimeStanga = inaltimeArbore(rad->stanga);
//		int inaltimeDreapta = inaltimeArbore(rad->dreapta);
//		return inaltimeStanga - inaltimeDreapta;
//	}
//	else {
//		return 0;
//	}
//}
//
//void stergereArbore(Nod** rad) {
//	if ((*rad)) {
//		stergereArbore(&(*rad)->stanga);
//		stergereArbore(&(*rad)->dreapta);
//		free((*rad)->info.numeClient);
//		free((*rad));
//		(*rad) = NULL;
//	}
//}
//
//
//void main()
//{
//	Nod* radacina = NULL;
//	citireFisier("Rezervari.txt", &radacina);
//	afisareArborePreOrdine(radacina);
//	//afisareArboreInOrdine(radacina);
//	//afisareArborePostOrdine(radacina);
//
//	printf("\n\n");
//	afisareRezervare(cautarezervareDupaId(radacina, 10));
//
//	printf("\nNumar total persoane:%d", calculNrTotalPersoane(radacina));
//
//	stergereArbore(&radacina);
//	afisareArboreInOrdine(radacina);
//
//}
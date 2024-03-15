//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//#include <stdlib.h>
//
//struct Masina {
//	int id;
//	char* producator;
//	int nrUsi;
//	float pret;
//};
//
//struct Masina* adaugareInVector(struct Masina* masini, struct Masina m, int* nrMasini) {
//	struct Masina* aux = (struct Masina*)malloc(sizeof(struct Masina) * ((*nrMasini)+1));
//	for(int i=0; i<*nrMasini;i++){
//		aux[i] = masini[i];
//	}
//	aux[*nrMasini] = m;
//	(*nrMasini)++;
//	if(masini!=NULL)
//		free(masini);
//	
//	return aux;
//
//}
//
//struct Masina* citireFisier(const char* numeFisier, 
//	int* nrMasini) {
//	FILE* file = fopen(numeFisier, "r");
//	char buffer[100];
//	char delimitare[] = ",\n";
//	struct Masina* masini = NULL;
//	(*nrMasini) = 0;
//	while (fgets(buffer, 100, file) != NULL) {
//		char* element = strtok(buffer, delimitare);
//
//		struct Masina m;
//		m.id = atoi(element);
//		element = strtok(NULL, delimitare);
//		m.producator = malloc(strlen(element) + 1);
//		strcpy(m.producator, element);
//		element = strtok(NULL, delimitare);
//		m.nrUsi = atoi(element);
//		element = strtok(NULL, delimitare);
//		m.pret = atof(element);
//		masini = adaugareInVector(masini, m, nrMasini);
//	}
//	fclose(file);
//	return masini;
//
//	
//
//
//}
//
//struct Masina* masiniMulteUsi(struct Masina* masini, int* nrMasini) {
//	int nrMasiniNoi = 0;
//	for (int i = 0; i < nrMasini; i++) {
//		if (masini[i].nrUsi > 2) {
//			nrMasiniNoi++;
//		}
//	}
//	struct Masina* masiniUsi = malloc(sizeof(struct Masina) * nrMasiniNoi);
//	int j = 0;
//	for (int i = 0; i < nrMasiniNoi; i++) {
//		if (masini[i].nrUsi > 2) {
//			masiniUsi[j] = masini[i];
//			j++;
//		}
//	}
//	return masiniUsi;
//
//}
//
//void afisareMatrice(struct Masina** matrice, int nrLinii, int* nrCol) {
//	for (int i = 0; i < nrLinii; i++) {
//		for (int j = 0; j < nrCol[i]; j++) {
//			printf("%d, %s, %d, %.2f \t", matrice[i][j].id, matrice[i][j].producator, matrice[i][j].nrUsi, matrice[i][j].pret);
//		}
//		printf("\n");
//	}
//}
//
//void citireMatrice(const char* numeFisier, struct Masina** matrice, int nrLinii, int* nrColoane) {
//	FILE* file = fopen(numeFisier, "r");
//	char buffer[100];
//	char delimitare[] = ",\n";
//	while (fgets(buffer, 100, file) != NULL) {
//		char* element = strtok(buffer, delimitare);
//
//		struct Masina m;
//		m.id = atoi(element);
//		element = strtok(NULL, delimitare);
//		m.producator = malloc(strlen(element) + 1);
//		strcpy(m.producator, element);
//		element = strtok(NULL, delimitare);
//		m.nrUsi = atoi(element);
//		element = strtok(NULL, delimitare);
//		m.pret = atof(element);
//		matrice[m.nrUsi-2] = adaugareInVector(matrice[m.nrUsi-2], m,  &(nrColoane[m.nrUsi - 2]));
//	}
//	fclose(file);
//}
//
////pret mediu al masinilor cu nr de usi dat ca param
//
//float pretMediu(struct Masina** matrice, int nrLinii, int* nrColoane, int nrUsi) {
//	if (nrUsi < 2 || nrUsi>4) {
//		return 0;
//	}
//	float pretTotal = 0;
//	int index = nrUsi - 2;
//	if (nrColoane[index] == 0) {
//		return 0;
//	}
//	for (int i = 0; i < nrColoane[index]; i++) {
//		pretTotal += matrice[index][i].pret;
//	}
//	return pretTotal / nrColoane[index];
//}
//
//struct Masina cautareMasinaID(struct Masina** matrice, int nrLinii, int* nrCol, int id) {
//
//	for (int i = 0; i < nrLinii; i++) {
//		for (int j = 0; j < nrCol[i]; j++) {
//			if (matrice[i][j].id == id)
//				return matrice[i][j];
//
//		}
//	}
//	struct Masina m;
//	m.id = -1;
//	m.producator = NULL;
//	m.nrUsi = -1;
//	m.pret = -1;
//	return m;
//}
//
//void dezalocareMatrice(struct Masina*** matrice, int nrLinii, int** nrCol) {
//
//	for (int i = 0; i < nrLinii; i++) {
//		for (int j = 0; j < (*nrCol)[i]; j++) {
//			free((*matrice)[i][j].producator);
//			//(*matrice)[i][j].producator = NULL; optional
//		}
//		free((*matrice)[i]);
//	}
//	free((*nrCol));
//	(*nrCol) = NULL;
//	free((*matrice));
//	(*matrice) = NULL;
//}
//
//int main() {
//	struct Masina** matrice;
//	int nrLinii = 3;
//	int* nrCol;
//	nrCol = (int*)malloc(sizeof(int) * nrLinii); // vectorul de lungimi
//	matrice = (struct Masina**)malloc(sizeof(struct Masina*) * nrLinii);
//	for (int i = 0; i < nrLinii; i++) {
//		nrCol[i] = 0;
//		matrice[i] = NULL;
//	}
//	citireMatrice("masini.txt", matrice, nrLinii, nrCol);
//	afisareMatrice(matrice, nrLinii, nrCol);
//	printf("Pretul mediu este: %5.2f", pretMediu(matrice, nrLinii, nrCol, 3));
//
//	struct Masina masina_cautata;
//	masina_cautata = cautareMasinaID(matrice, nrLinii, nrCol, 20);
//	printf("\n\n%i %s %i %.2f", masina_cautata.id, masina_cautata.producator, masina_cautata.nrUsi, masina_cautata.pret);
//
//	dezalocareMatrice(&matrice, nrLinii, &nrCol);
//}
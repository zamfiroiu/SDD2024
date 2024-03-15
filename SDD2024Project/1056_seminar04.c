//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//struct Locuinta {
//	int id;
//	char* strada;
//	int numar;
//};
//
//void inserareLocuinta(struct Locuinta** vector, int* dim,
//	struct Locuinta l)
//{
//	struct Locuinta* copie;
//	copie = malloc(sizeof(struct Locuinta) * 
//		(++(*dim)));
//	for (int i = 0; i < (*dim) - 1; i++)
//	{
//		copie[i] = (*vector)[i];
//	}
//	copie[(*dim) - 1] = l;
//	if ((*vector) != NULL)
//	{
//		free((*vector));
//	}
//	(*vector) = copie;
//}
//
//void citesteFisier(const char* nume_fisier, struct Locuinta** vector,
//	int* dim) {
//	if (nume_fisier != NULL && strlen(nume_fisier) > 0) {
//		FILE* f = fopen(nume_fisier, "r");
//		if (f != NULL) {
//			(*dim) = 0;
//			char buffer[100];
//			char delimitator[] = ",\n";
//			while (fgets(buffer, 100, f) != NULL) {
//				char* token;
//				token = strtok(buffer, delimitator);
//				struct Locuinta locuinta;
//				locuinta.id = atoi(token);
//				token = strtok(NULL, delimitator);
//				locuinta.strada = (char*)malloc(strlen(token) + 1);
//				strcpy(locuinta.strada, token);
//				token = strtok(NULL, delimitator);
//				locuinta.numar = atoi(token);
//				inserareLocuinta(vector, dim, locuinta);
//			}
//			fclose(f);
//		}
//	}
//}
//void afisareLocuinta(struct Locuinta l) {
//	printf("ID-ul: %d\t%s numarul %d\t", 
//		l.id, l.strada, l.numar);
//}
//void afisareVectorLocuinte(struct Locuinta* vector, int dim) {
//	for (int i = 0; i < dim; i++)
//		afisareLocuinta(vector[i]);
//}
//
//
//void stergeLocuinta(struct Locuinta** vector, int* dim, int id) {
//	char flag = 0;
//	for (int i = 0; i < (*dim); i++) {
//		if ((*vector)[i].id == id) {
//			flag = 1;
//			break;
//		}
//	}
//	if (flag==1) { //avem o locuinta de sters
//		struct Locuinta* copie = (struct Locuinta*)malloc(sizeof(struct Locuinta)
//			*((*dim) - 1));
//		int j = 0;
//		for (int i = 0; i < (*dim); i++) {
//			if ((*vector)[i].id != id) {
//				copie[j++] = (*vector)[i];
//			}
//		}
//		(*dim)--;
//		if ((*vector) != NULL)
//		{
//			free((*vector));
//		}
//		(*vector) = copie;
//	}
//}
//
//void dezalocareMatrice(struct Locuinta*** matrice, int* nr_linii, int** nr_coloane) {
//	for (int i = 0; i < (*nr_linii); i++) {
//		for(int j = 0; j < (*nr_coloane)[i]; j++) {
//			free((*matrice)[i][j].strada);
//			(*matrice)[i][j].strada = NULL;
//		}
//		free((*matrice)[i]);
//
//	}
//	free(*matrice);
//	*matrice = NULL;
//
//	(*nr_linii) = 0;
//	free(*nr_coloane);
//	*nr_coloane = NULL;
//
//
//}
//
//void citesteMatriceFisier(const char* nume_fisier, struct Locuinta** matrice, int nr_linii, int* nr_coloane) {
//	if (nume_fisier != NULL && strlen(nume_fisier) > 0) {
//		FILE* f = fopen(nume_fisier, "r");
//		if (f != NULL) {
//			char buffer[100];
//			char delimitator[] = ",\n";
//			while (fgets(buffer, 100, f) != NULL) {
//				char* token;
//				token = strtok(buffer, delimitator);
//				struct Locuinta locuinta;
//				locuinta.id = atoi(token);
//				token = strtok(NULL, delimitator);
//				locuinta.strada = (char*)malloc(strlen(token) + 1);
//				strcpy(locuinta.strada, token);
//				token = strtok(NULL, delimitator);
//				locuinta.numar = atoi(token);
//				int pozitie = locuinta.numar % 2;
//				inserareLocuinta(&(matrice[pozitie]), &(nr_coloane[pozitie]), locuinta);
//			}
//			fclose(f);
//		}
//	}
//}
//
//void afisareMatrice(struct Locuinta** matrice, int nr_linii, int* nr_coloane)
//{
//	for (int i = 0; i < nr_linii; i++)
//	{
//		for (int j = 0; j < nr_coloane[i]; j++)
//		{
//			afisareLocuinta(matrice[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//void afisareIdDePeOParte(int paritate, struct Locuinta** matrice, int nr_linii, int* nr_coloane) {
//	paritate = paritate % 2;
//
//		for (int j = 0; j < nr_coloane[paritate]; j++) {
//				printf("%d ", matrice[paritate][j].id);
//		}
//
//}
//
//struct Locuinta cautareLocuintaDupaID(int idCautat, struct Locuinta** matrice, int nr_linii, int* nr_coloane) {
//	for (int i = 0; i < nr_linii; i++) {
//		for (int j = 0; j < nr_coloane[i]; j++) {
//			if (matrice[i][j].id == idCautat) {
//				return matrice[i][j];
//			}
//		}
//	}
//
//	struct Locuinta copie;
//	copie.id = -1;
//	copie.numar = -1;
//	copie.strada = NULL;
//	
//	return copie;
//	
//}
//
//void schimbareNumarLocuinta(struct Locuinta** matrice, int nrLinii, int* nrColoane, int numarLocuinta) {
//	int pozitie = numarLocuinta % 2;
//	int idLocuinta = -1;
//	int indexInVector = -1;
//	for (int i = 0; i < nrColoane[pozitie]; i++) {
//		if (matrice[pozitie][i].numar == numarLocuinta) {
//			matrice[pozitie][i].numar++;
//			idLocuinta = matrice[pozitie][i].id;
//			indexInVector = i;
//		}
//	}
//
//	if (idLocuinta != -1) {
//		int index = (numarLocuinta + 1) % 2;
//		inserareLocuinta(&(matrice[index]), &(nrColoane[index]), matrice[pozitie][indexInVector]);
//		stergeLocuinta(&(matrice[pozitie]), &(nrColoane[pozitie]), idLocuinta);
//	}
//}
//
//
//void main() {
//	int nr_linii;
//	int* nr_coloane;
//	struct Locuinta** matrice;
//
//	nr_linii = 2;
//	nr_coloane = (int*)malloc(sizeof(int) * nr_linii);
//	matrice = (struct Locuinta**)malloc(sizeof(struct Locuinta*) * nr_linii);
//	for (int i = 0; i < nr_linii; i++) {
//		matrice[i] = NULL;
//		nr_coloane[i] = 0;
//	}
//	citesteMatriceFisier("locuinte.txt", matrice, nr_linii, nr_coloane);
//	afisareMatrice(matrice, nr_linii, nr_coloane);
//	int paritate = 11;
//	printf("Id-urile cu paritate impara a numarului: \n");
//	afisareIdDePeOParte(paritate, matrice, nr_linii, nr_coloane);
//
//	struct Locuinta locuinta1 = cautareLocuintaDupaID(17, matrice, nr_linii, nr_coloane);
//	afisareLocuinta(locuinta1);
//
//	schimbareNumarLocuinta(matrice, nr_linii, nr_coloane, 5);
//
//	printf("\n\n dupa mutare\n");
//	afisareMatrice(matrice, nr_linii, nr_coloane);
//
//	dezalocareMatrice(&matrice, &nr_linii, &nr_coloane);
//}
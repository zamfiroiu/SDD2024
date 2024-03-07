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
//	printf("ID-ul: %d\t%s numarul %d\n", 
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
//
//void main() {
//	struct Locuinta *locuinte = NULL;
//	int dim = 3;
//	citesteFisier("locuinte.txt", &locuinte, &dim);
//	printf("Initial\n\n");
//	afisareVectorLocuinte(locuinte, dim);
//	
//	printf("\n\nUlterior\n\n");
//	stergeLocuinta(&locuinte, &dim, 22);
//	afisareVectorLocuinte(locuinte, dim);
// 
// 
//}
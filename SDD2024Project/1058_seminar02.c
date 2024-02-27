//#include<stdio.h>
//#include<malloc.h>
//
//struct Calculator {
//	char* serie;
//	float pret;
//	int nrPorturi;
//};
//
//struct Calculator initializare(const char* serie, float pret, int nrPorturi) {
//	struct Calculator c;
//	c.serie = (char*)malloc(sizeof(char) * (strlen(serie) + 1));
//	strcpy(c.serie, serie);
//	c.nrPorturi = nrPorturi;
//	c.pret = pret;
//	return c;
//}
//
//void afisareCalculator(struct Calculator c) {
//	printf("Calculatorul cu seria %s, costa %5.2f si are %d porturi\n", c.serie, c.pret, c.nrPorturi);
//}
//
//void afisareVectorCalculatoare(struct Calculator* vector, int nrCalculatoare) {
//	if (nrCalculatoare > 0 && vector != NULL) {
//		for (int i = 0; i < nrCalculatoare; i++) {
//			afisareCalculator(vector[i]);
//		}
//	}
//}
//
//
//struct Calculator* copiazaNCalculatoare(struct Calculator* calculatoare, int nrCalculatoare, int nrCalculatoareCopiate) {
//	struct Calculator* copiate = (struct Calculator*)malloc(sizeof(struct Calculator) * nrCalculatoareCopiate);
//	for (int i = 0; i < nrCalculatoareCopiate; i++) {
//		copiate[i] = calculatoare[i];
//		copiate[i].serie = (char*)malloc(sizeof(char) * (1 + strlen(calculatoare[i].serie)));
//		strcpy(copiate[i].serie, calculatoare[i].serie);
//	}
//	return copiate;
//}
//
//struct Calculator* copiazaCalculatoareCuMultePorturi(struct  Calculator* calculatoare, int nrCalculatoare, int pragNrPorturi, int* nrCalculatoarePorturi) {
//	*nrCalculatoarePorturi = 0;
//	for (int i = 0; i < nrCalculatoare; i++) {
//		if (calculatoare[i].nrPorturi > pragNrPorturi) {
//			(*nrCalculatoarePorturi)++;
//		}
//	}
//	struct Calculator* v = (struct Calculator*)malloc(sizeof(struct Calculator) * (*nrCalculatoarePorturi));
//	int k = 0;
//	for (int i = 0; i < nrCalculatoare; i++) {
//		if (calculatoare[i].nrPorturi > pragNrPorturi) {
//			v[k++] = initializare(calculatoare[i].serie, calculatoare[i].pret, calculatoare[i].nrPorturi);
//		}
//	}
//	return v;
//}
//
//void dezalocare(struct Calculator** vector, int* dim) {
//	for (int i = 0; i < (*dim); i++) {
//		free((*vector)[i].serie);
//	}
//	free(*vector);
//	*vector = NULL;
//	*dim = 0;
//}
//
//void main() {
//
//	int nrCalculatoare = 5;
//	struct Calculator* calculatoare = (struct Calculator*)malloc(sizeof(struct Calculator) * nrCalculatoare);
//	for (int i = 0; i < nrCalculatoare; i++) {
//		calculatoare[i] = initializare("1234567890", i * 20 + 10, i + 1);
//	}
//
//	afisareVectorCalculatoare(calculatoare, nrCalculatoare);
//
//	int nrCalculatoareCopiate = 3;
//
//	struct Calculator* calculatoareCopiate = copiazaNCalculatoare(calculatoare, nrCalculatoare, nrCalculatoareCopiate);
//
//	printf("\n\n");
//	afisareVectorCalculatoare(calculatoareCopiate, nrCalculatoareCopiate);
//
//	int nrCalculatoarePorturi = 0;
//	struct Calculator* calculatoarePorturi = copiazaCalculatoareCuMultePorturi(calculatoare, nrCalculatoare, 3, &nrCalculatoarePorturi);
//
//	printf("\n\n");
//	afisareVectorCalculatoare(calculatoarePorturi, nrCalculatoarePorturi);
//
//	dezalocare(&calculatoare, &nrCalculatoare);
//}
#include<stdio.h>
#include<malloc.h>


struct Masina {
	char* marca;
	float capacitateCilindrica;
	int an;
};

void afisareMasina(const struct Masina* m) {
	if (m->marca != NULL) {
		printf("Marca: %s\n", m->marca);
	}
		printf("Capacitate cilindrica:%5.2f\n", m->capacitateCilindrica);
		printf("An:%d\n\n", m->an);
}

struct Masina initializareMasina(const char* marca, int an, float cc) {
	struct Masina m;
	m.an = an;
	m.capacitateCilindrica = cc;
	if (marca != NULL) {
		m.marca = malloc(strlen(marca) + 1);
		strcpy(m.marca, marca);
	}
	else {
		m.marca = (char*)malloc(strlen("N/A") + 1);
		strcpy(m.marca, "N/A");
	}
	return m;
}

void dezalocareMasina(struct Masina* masina) {
	free(masina->marca);
	masina->marca = NULL;
}

int main() {
	struct Masina masina1;
	//Dacia
	masina1.marca = (char*)malloc(sizeof(char) * (strlen("Dacia") + 1));
	strcpy(masina1.marca, "Dacia");
	masina1.capacitateCilindrica = 1.9;
	masina1.an = 2023;

	afisareMasina(&masina1);

	dezalocareMasina(&masina1);

	struct Masina masina2 = initializareMasina("Ford", 2022, 2.49);
	afisareMasina(&masina2);

	dezalocareMasina(&masina2);

	afisareMasina(&masina2);

	return 0;
}
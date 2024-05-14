//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//
//typedef struct Quiz Quiz;
//typedef struct Heap Heap;
//
//struct Quiz {
//	char* materie;
//	int grileGresite;
//};
//
//
//struct Heap {
//	Quiz* vector;
//	int dimensiune;
//	int dimensiuneTotala;
//};
//
//Heap initializareHeap(int nr) {
//	Heap heap;
//	heap.vector = malloc(nr * sizeof(Quiz));
//	heap.dimensiuneTotala = nr;
//	heap.dimensiune = 0;
//	return heap;
//}
//
//Quiz initializareQuiz(char* materie, int grileGresite) {
//	Quiz q;
//	q.materie = (char*)malloc(strlen(materie) + 1);
//	strcpy(q.materie, materie);
//	q.grileGresite = grileGresite;
//	return q;
//}
//
//Heap adaugareQuizInHeap(Quiz quiz, Heap heap) {
//	if (heap.dimensiune < heap.dimensiuneTotala) {
//		heap.vector[heap.dimensiune] = quiz;
//		heap.dimensiune++;
//		//TO DO filtrare
//		
//	}
//	return heap;
//}
//
//void afisareQuiz(Quiz q) {
//	printf("Materia: %s ", q.materie);
//	printf("Grile gresite: %d \n", q.grileGresite);
//}
//
//void afisareHeap(Heap h) {
//	for (int i = 0; i < h.dimensiune; i++) {
//		afisareQuiz(h.vector[i]);
//	}
//}
//void afisareTotalaHeap(Heap h) {
//	for (int i = 0; i < h.dimensiuneTotala; i++) {
//		afisareQuiz(h.vector[i]);
//	}
//}
//
//
//void filtreazaHeap(Heap heap, int pozRadacina) {
//	int nodSt = pozRadacina * 2 + 1;
//	int nodDr = pozRadacina * 2 + 2;
//	int pozMin = pozRadacina;
//	if (nodSt < heap.dimensiune && heap.vector[nodSt].grileGresite<heap.vector[pozMin].grileGresite) {	//exista nod stanga si e mai mic decat radacina
//		pozMin = nodSt;
//	}
//	if (nodDr < heap.dimensiune && heap.vector[nodDr].grileGresite < heap.vector[pozMin].grileGresite) {	//exista nod dreapta si e mai mic decat minimul dintre stanga si radacina
//		pozMin = nodDr;
//	}
//	if (pozMin != pozRadacina) {
//		Quiz aux;
//		aux = heap.vector[pozRadacina];
//		heap.vector[pozRadacina] = heap.vector[pozMin];
//		heap.vector[pozMin] = aux;
//		if(pozMin*2+1<heap.dimensiune-1)	//daca nodul de la pozMin are copii
//			filtreazaHeap(heap, pozMin);
//	}
//}
//
//Quiz extragereMinim(Heap* heap) {
//	if (heap->dimensiune > 0) {
//		Quiz aux;
//		aux = heap->vector[0];
//		heap->vector[0] = heap->vector[heap->dimensiune - 1];
//		heap->vector[heap->dimensiune - 1] = aux;
//		//am schimbat primul element cu ultimul
//		heap->dimensiune--;
//		//am ascuns ultimul element
//
//		for (int i = (heap->dimensiune) / 2 - 1; i >= 0; i--)
//			filtreazaHeap((*heap), i);
//		//refiltram
//		return aux;
//	}
//	else
//		return initializareQuiz("N/A", -1);
//	
//}
//
//void dezalocareTotHeap(Heap* heap) {
//	for (int i = 0; i < heap->dimensiuneTotala; i++) {
//		free(heap->vector[i].materie);
//	}
//	free(heap->vector);
//	heap->vector = NULL;
//	heap->dimensiune = 0;
//	heap->dimensiuneTotala = 0;
//}
//
//
//void main() {
//	Heap heap;
//	heap = initializareHeap(6);
//	heap.vector[0] = initializareQuiz("Structuri de date", 3);
//	heap.vector[1] = initializareQuiz("Java", 7);
//	heap.vector[2] = initializareQuiz("Baze de date", 5);
//	heap.vector[3] = initializareQuiz("ATP", 2);
//	heap.vector[4] = initializareQuiz("POO", 9);
//	heap.vector[5] = initializareQuiz("Analiza", 4);
//	
//	heap.dimensiune = 6;
//	afisareHeap(heap);
//	
//	for (int i = (heap.dimensiune) / 2 - 1; i >= 0; i--)
//		filtreazaHeap(heap, i);
//
//	printf("\n\n");
//	afisareHeap(heap);
//
//	printf("\n\n");
//	afisareQuiz(extragereMinim(&heap));
//	afisareQuiz(extragereMinim(&heap));
//	afisareQuiz(extragereMinim(&heap));
//	afisareQuiz(extragereMinim(&heap));
//	afisareQuiz(extragereMinim(&heap));
//	afisareQuiz(extragereMinim(&heap));
//	printf("\n\n");
//	afisareTotalaHeap(heap);
//
//	dezalocareTotHeap(&heap);
//	afisareTotalaHeap(heap);
//
//}
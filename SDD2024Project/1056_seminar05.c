//#include<stdio.h>
//#include <malloc.h>
//typedef struct CafeneaMea Cafenea;
//typedef struct Nod Nod;
//
//struct CafeneaMea
//{
//    char* nume;
//    int nrLocuri;
//    float suprafata;
//};
//
//struct Nod
//{
//    Cafenea info;
//    Nod* next;
//};
//
//Cafenea initializareCafenea(const char* nume, int nrLocuri, float suprafata)
//{
//    Cafenea cafenea;
//    cafenea.nrLocuri = nrLocuri;
//    cafenea.suprafata = suprafata;
//    cafenea.nume = (char*)malloc(sizeof(char) * (strlen(nume) + 1));
//    strcpy(cafenea.nume, nume);
//
//    return cafenea;
//}
//Nod* inserareInceput(Cafenea c, Nod* cap)
//{
//    Nod* nou = malloc(sizeof(Nod));
//    nou->next = cap;
//    nou->info = initializareCafenea(c.nume, c.nrLocuri, c.suprafata);
//    return nou;
//
//}
//void afisareCafenea(Cafenea c)
//{
//    printf("\nDenumire: %s Nr scaune: %i Suprafara %.2f\n", c.nume, c.nrLocuri, c.suprafata);
//}
//void afisareCafenele(Nod* lista)
//{
//    while (lista != NULL)
//    {
//        afisareCafenea(lista->info);
//        lista = lista->next;
//    }
//}
////numele cafenelei cu densitatea cea mai mica
//char* numeCafeneaDensitateMinima(Nod* lista)
//{
//    if (lista != NULL)
//    {
//        if (lista->info.suprafata != 0)
//        {
//            float minim = lista->info.nrLocuri / lista->info.suprafata;
//            Nod* adresa = lista;
//            lista = lista->next;
//            while (lista != NULL)
//            {
//                if (lista->info.nrLocuri / lista->info.suprafata < minim)
//                {
//                    minim = lista->info.nrLocuri / lista->info.suprafata;
//                    adresa = lista;
//                }
//                lista = lista->next;
//            }
//            char* nume;
//            nume = malloc(sizeof(char) * (strlen(adresa->info.nume) + 1));
//            strcpy(nume, adresa->info.nume);
//            return nume;
//        }
//    }
//    return NULL;
//}
//void stergeLista(Nod** nod) {
//    while (*nod != NULL) {
//        Nod* aux;
//        aux = *nod;
//        *nod = (*nod)->next;
//        free(aux->info.nume);
//        free(aux);
//
//
//    }
//    *nod = NULL;
//}
//void inserareFinal(Nod** lista, Cafenea c) {
//    if ((*lista) == NULL) {
//        (*lista) = inserareInceput(c,*lista);
//    }
//    else {
//        Nod* curent = (*lista);
//        while (curent->next!=NULL) {
//            curent = curent->next;
//        }
//        Nod* n = (Nod*)malloc(sizeof(Nod));
//       
//        n->info = initializareCafenea(c.nume,c.nrLocuri,c.suprafata);
//        n->next = NULL;
//        curent->next = n;
//    }
//
//}
//
//void main()
//{
//    Nod* cap = NULL;
//    Cafenea cafenea = initializareCafenea("Tucano", 12, 20);
//    Cafenea cafenea2 = initializareCafenea("Teds", 17, 17.3);
//    Cafenea cafenea3 = initializareCafenea("Urban", 65, 33);
//    Cafenea sb = initializareCafenea("Sb", 25, 43);
//    cap = inserareInceput(cafenea, cap);
//    cap = inserareInceput(cafenea2, cap);
//    cap = inserareInceput(cafenea3, cap);
//    afisareCafenele(cap);
//    char* numeMinim = numeCafeneaDensitateMinima(cap);
//    printf("\nCafenea cu dens minima: %s", numeMinim);
//    inserareFinal(&cap, sb);
//    afisareCafenele(cap);
//    stergeLista(&cap);
//    
//    afisareCafenele(cap);
//
//    free(cafenea.nume);
//    cafenea.nume = NULL;
//
//    free(cafenea2.nume);
//    cafenea2.nume = NULL;
//
//    free(cafenea3.nume);
//    cafenea3.nume = NULL;
//
//    free(numeMinim);
//    numeMinim = NULL;
//}
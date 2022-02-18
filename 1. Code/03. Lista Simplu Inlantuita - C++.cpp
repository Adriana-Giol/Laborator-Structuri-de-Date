#include <stdio.h>
#include <iostream>

using namespace std;

//0. Definire structura de lucru
struct Produs {
	int cod; 
	char* denumire;
	float pret;
	float cantitate;
};

struct NodListaSimpla
{
	Produs infoUtila;
	NodListaSimpla* next;
};

//INSERARE - LA SFARSIT
NodListaSimpla* inserare(NodListaSimpla* nodCap, Produs p) {

	//I. Creare nod nou
	NodListaSimpla* nodNou = new NodListaSimpla;

	//Initializare componente din nod
	   // 1.  informatia utila
	nodNou->infoUtila.cod = p.cod;
	nodNou->infoUtila.denumire = new char[strlen(p.denumire) + 1];
	strcpy(nodNou->infoUtila.denumire, p.denumire);
	nodNou->infoUtila.pret = p.pret;
	nodNou->infoUtila.cantitate = p.cantitate;

	// 2. Pointerul de legatura catre nodul urmator
	nodNou->next = NULL;


	//II. Inserare nod in lista 
			//Verificam daca lista este goala
	if (nodCap == NULL) {    //Daca pointerul este NULL inseamna ca nu exista nici un nod in lista
		nodCap = nodNou;	// pointerul nodCap trebuie sa pointeze catre primul nod creat, adica spre nodNou.
	}
	else {				//Daca pointerul nu este NULL inseamna ca mai exsita noduri in lista, deci pointerul curent se afiseaza la finalul listei.

		// Ne creem un nod auxiliar cu care sa parcurgem lista si cat timp nodul pe care ne pozitionam nu are pointerul NULL, mergem mai departe
		NodListaSimpla* nodTemporar = nodCap;

		while (nodTemporar->next != NULL) {
			nodTemporar = nodTemporar->next;
		}
		nodTemporar->next = nodNou; // In momentul in care iesim din while adica am intalnit un nod care este NULL, atunci nodul auxiliar devine noul nod inserat
	}
	return nodCap; // Returnam cap deoarece functia returneaza Nodls* (adica o adresa) - adresa primului nod din lista indiferent de situatie
}

/*Daca lista e NULL, pointerul cap este NULL initial si la sfarsit returneaza adresa valida a unui spatiu alocat si initializat cu nodul nou.
Daca lista nu e nula, atunci returneaza aceeasi valoare a primului element*/

//IV. DEZALOCARE
void dezalocare(NodListaSimpla* nodCap)
{
	NodListaSimpla* nodTemporar = nodCap;
	while (nodTemporar != NULL)
	{
		NodListaSimpla* nodTemporar2 = nodTemporar->next;
		delete[] nodTemporar->infoUtila.denumire;
		delete nodTemporar;
		nodTemporar = nodTemporar2;
	}
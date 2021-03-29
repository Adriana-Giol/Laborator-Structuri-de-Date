#include<stdio.h>
#include<iostream>

using namespace std;

struct Produs {
	int cod;
	char* denumire;
	float pret;
	float cantitate;
};
//******************** LISTA SIMPLA *************************************************
//Declarare lista simpla
struct NodLS {
	Produs inf;
	NodLS* next;
};

//Functie de inserare in lista simpla
NodLS* inserare(NodLS* cap, Produs p) {
	NodLS* nodNou = new NodLS;

	//Initializam componentele din nod 
	//-- Informatia Utila
	nodNou->inf.cod = p.cod;
	nodNou->inf.denumire = new char[strlen(p.denumire)+1];
	strcpy(nodNou->inf.denumire, p.denumire);
	nodNou->inf.pret = p.pret;
	nodNou->inf.cantitate = p.cantitate;

	//-- Pointerul de legatura catre nodul urmator
	nodNou->next = NULL;


	//*** FUNCTIA SE APELEAZA SI ATUNCI CAND LISTA E GOALA, DAR SI ATUNCI CAND VOI ADAUGA NODUL LA FINAL
	if (cap == NULL) {
		cap = nodNou;		//Daca pointerul cap este NULL inseamna ca nu exista nici un nod in lista - vom face pointerul cap 
							// sa pointeze catre primul nod creat, adica spre nodNouu
	}
	else {						//Daca pointerul nu este NULL inseamna ca mai exista noduri in lista, 
								//deci pointerul nodului curent se va aseza a finalul listei

//Ne creem un nod auxiliar cu care sa parcurgem lista si cat timp nodul pe care ne pozitionam nu are pointerul NULL, mergem mai departe
//In momentul in care iesim din while adica am intalnit un nod care este NULL, atunci nodul auxiliar devine noul nod inserat
		NodLS* aux = cap;		
	
		while (aux->next != NULL) {
			aux = aux->next;
		}
		aux->next = nodNou;
	}
	return cap;	// Returnam cap deoarece functia returneaza Nodls* (adica o adresa) - adresa primului nod din lista indiferent de situatie


	//Daca lista e NULL, pointerul cap este NULL initial si la sfarsit returneaza adresa valida a unui spatiu alocat si initializat cu nodul nou
	//Daca lista nu e nula, atunci returneaza aceeasi valoare a primului element.
}

//Traversarea listei cu afisare - traversarea o facem pana aux !=NULL, nu pana la aux->next !=NULL  ca mai sus pentru ca ar ramane ultimul nod neafisat

void traversare(NodLS* cap) {
	NodLS* aux = cap;
	while (aux != NULL) {
	
	//O sa avem o afisare pentru ca trecem prin fiecare nod si ii afisam elementele adica INFORMATIA UTILA

		aux = aux->next;
	}
	aux->next = nodNou;
}



void main() {

}
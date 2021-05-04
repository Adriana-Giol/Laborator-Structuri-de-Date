# 1. Lista Simpla 
Lista Simpla = O inlantuire de noduri si fiecare nod are un pointer catre nodul urmator.
- Lista se va crea nod cu nod.</br>
- Este o structura de date dinamica cu acces secvential.</br>

## 🗝️ Rezolvare: </br>
0️⃣**PAS 0: Definim structura Produs**</br>
```cpp
#include<stdio.h>
#include<iostream>

using namespace std;

struct Produs {
	int cod;				
	char* denumire;
	float pret;
	float cantitate;
};
```

0️⃣**PAS 0: Definim structura Nodls**</br>
*In structura Nodls avem informatie utila de tip Produs si pointerul de legatura.*</br>
```cpp
struct Nodls
{
	produs inf;
	nodls *next;
};
```

**Pentru fiecare nod in parte trebuie sa alocam denumirile si spatiul in sine pentru Nod. Acum un nod ocupa: 20B = 16B(informatie utila) + 4B(pointerul de lagtura).**</br>
**Avem o functie de `creare Nod` care sa imi creeze primul nod din lista si apoi cu functie de inserare adaugam in lista nodurile urmatoare.Adaugarea nodurilor in lista se va face la finalul lui Nod Cap.**</br>

1️⃣**PAS 1: Functie de `Creare Nod`**</br>
Returnam Nodls* si primim ca parametri nolds* cap (adresa de inceput a structurii si informatie utila de tip Produs).</br>
- Fiecare nod inseamna un spatiu alocat in HEAP trebuie sa definim un Nodls* nou care trebuie alocat.
- Initializam componentele nodului: Informatia utila (cod, denumire, pret, cantitate) si Pointerul de legatura.

<!--************************************ TABEL****************************************************-->
<table>
<tbody>
<!------------------------------------------ TITLU-------------------------------------------------->
<tr>
<th>Limbajul C</th>
<th>Limbajul C++</th>
</tr>
<!----------------------------------------- TITLU--------------------------------------------------->	
<!--------------------------------------- PRIMA COLOANA - LIMBAJUL C--------------------------------->
<tr>-
<td>

```cpp

```
				
</td>
<!------------------------------------ A DOUA COLOANA - LIMBAJUL C++------------------------------------>
<td>
	
```cpp
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
```

</td>
</tr>
</tbody>
</table>
<!--************************************ TABEL****************************************************-->

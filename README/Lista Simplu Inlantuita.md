# 1. Lista Simplu Inlantuita
Lista Simplu Inlantuita = O inlantuire de noduri si fiecare nod are un pointer catre nodul urmator.
- Lista se va crea nod cu nod.</br>
- Este o structura de date dinamica cu acces secvential.</br>

## 🗝️ Rezolvare: </br>
![Lista Simpla -Inserare, Dezalocare, Afisare](https://user-images.githubusercontent.com/60271540/117066914-0479e700-ad32-11eb-84ff-4a07b7ac37f9.png)

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

1️⃣**PAS 1: Definim structura listei - NodLista**</br>
*In structura NodLista avem informatie utila de tip Produs si pointerul de legatura.*</br>
```cpp
struct NodLista
{
	Produs infoUtila;
	NodLista *next;
};
```

**Pentru fiecare nod in parte trebuie sa alocam denumirile si spatiul in sine pentru Nod. Acum un nod ocupa: 20B = 16B(informatie utila) + 4B(pointerul de lagtura).**</br>
**Avem o functie de `creare Nod` care sa imi creeze primul nod din lista si apoi cu functie de inserare adaugam in lista nodurile urmatoare.Adaugarea nodurilor in lista se va face la finalul lui Nod Cap.**</br>

## Operatii cu liste

2️⃣**PAS 2: Functie de `Creare Nod`**</br>
Returnam NodLista* si primim ca parametri NoldLista* cap (adresa de inceput a structurii si informatie utila de tip Produs).</br>
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
//Functie de inserare in lista simpla
NodLista* inserare(NodLista *nodCap, Produs p)
{
	NodLista *nodNou = (NodLista*)malloc(sizeof(NodLista));
	
	//Initializam componentele din nod 
	//-- Informatia Utila
	nodNou->infoUtila->denumire = (char*)malloc((strlen(p->denumire)+1)*sizeof(char));
	strcpy(nodNou->infoUtila->denumire, p->denumire);
	nodNou->infoUtila->cod = p->cod;
	nodNou->infoUtila->pret = p->pret;
	nodNou->infoUtila->cantitate = p->cantitate;
	
	//-- Pointerul de legatura catre nodul urmator
	nodNou->next = NULL;
	
	if(nodCap==NULL)
		nodCap = nodNou;
	else
	{
		NodLista *nodTemporar = nodCap;
		while(nodTemporar->next!=NULL)
			nodTemporar = nodTemporar->next;
		nodTemporar->next = nodNou;
	}
	return nodCap;
}


```
				
</td>
<!------------------------------------ A DOUA COLOANA - LIMBAJUL C++------------------------------------>
<td>
	
```cpp
//Functie de inserare in lista simpla
NodLista* inserare(NodLista* nodCap, Produs p) {
	NodLista* nodNou = new NodLista;

	//Initializam componentele din nod 
	//-- Informatia Utila
	nodNou->infoUtila.cod = p.cod;
	nodNou->infoUtila.denumire = new char[strlen(p.denumire)+1];
	strcpy(nodNou->infoUtila.denumire, p.denumire);
	nodNou->infoUtila.pret = p.pret;
	nodNou->infoUtila.cantitate = p.cantitate;

	//-- Pointerul de legatura catre nodul urmator
	nodNou->next = NULL;


	//*** FUNCTIA SE APELEAZA SI ATUNCI CAND LISTA E GOALA, DAR SI ATUNCI CAND VOI ADAUGA NODUL LA FINAL
	if (nodCap == NULL) {
		nodCap = nodNou;		//Daca pointerul cap este NULL inseamna ca nu exista nici un nod in lista - vom face pointerul cap 
							// sa pointeze catre primul nod creat, adica spre nodNouu
	}
	else {						//Daca pointerul nu este NULL inseamna ca mai exista noduri in lista, 
								//deci pointerul nodului curent se va aseza a finalul listei

//Ne creem un nod auxiliar cu care sa parcurgem lista si cat timp nodul pe care ne pozitionam nu are pointerul NULL, mergem mai departe
//In momentul in care iesim din while adica am intalnit un nod care este NULL, atunci nodul auxiliar devine noul nod inserat
		NodLista* nodTemporar = nodCap;		
	
		while (nodTemporar->next != NULL) {
			nodTemporar = nodTemporar->next;
		}
		nodTemporar->next = nodNou;
	}
	return nodCap;	// Returnam cap deoarece functia returneaza Nodls* (adica o adresa) - adresa primului nod din lista indiferent de situatie


	//Daca lista e NULL, pointerul cap este NULL initial si la sfarsit returneaza adresa valida a unui spatiu alocat si initializat cu nodul nou
	//Daca lista nu e nula, atunci returneaza aceeasi valoare a primului element.
}
```

</td>
</tr>
</tbody>
</table>
<!--************************************ TABEL****************************************************-->

2️⃣**PAS 2: Functie de `Traversare cu afisare`**</br>
**Traversarea listei cu afisare - traversarea o facem pana aux !=NULL, nu pana la aux->next !=NULL  ca mai sus pentru ca ar ramane orimul nod neafisat.**</br>

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
//Functie de taversare cu afisare a listei
void traversare(NodLista *cap)
{
	nodLista * nodTemporar = nodCap;
	while(nodTemporar!=NULL)
	{
		printf("\nCod=%d, Denumire=%s, Pret=%5.2f, Cantitate=%5.2f",
			nodTemporar->infoUtila->cod, nodTemporar->infoUtila->denumire, nodTemporar->infoUtila->pret, nodTemporar->infoUtila->cantitate);
		nodTemporar=nodTemporar->next;
	}
}
```
				
</td>
<!------------------------------------ A DOUA COLOANA - LIMBAJUL C++------------------------------------>
<td>
	
```cpp
//Functie de taversare cu afisare a listei
void traversare(nodls* cap)
{
	nodLista* nodTemporar = nodCapcap;
	while (nodTemporar != NULL)
	{
		cout << "Cod = " << nodTemporar->infoUtila.cod << " Denumire = " << nodTemporar->infoUtila.denumire << " Pret = " << nodTemporar->infoUtila.pret << " Cantitate = " << nodTemporar->infoUtila.cantitate << endl;
		nodTemporar = nodTemporar->next;
	}
}
```

</td>
</tr>
</tbody>
</table>
<!--************************************ TABEL****************************************************-->

2️⃣**PAS 2: Functie de `Traversare cu dezalocare`**</br>
**Traversarea listei cu dezalocare - avem de sters fiecare denumire si fiecare nod in parte. Daca facem stergerea o sa se sterga si pointerul next. De accea ar trebui ca inainte sa apelez acel delete sa retin pe temp->next.**</br>

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
void dezalocare(NodLista *nodCap)
{
	NodLista *nodTemporar = nodCap;
	while(nodTemporar!= NULL)
	{
		NodLista* nodTemporar2 = nodTemporar->next;
		free(nodTemporar->infoUtila->denumire);
		free(nodTemporar->infoUtila);
		free(nodTemporar);
		nodTemporar = nodTemporar2;
	}
}
```
				
</td>
<!------------------------------------ A DOUA COLOANA - LIMBAJUL C++------------------------------------>
<td>
	
```cpp
void dezalocare(NodLista* cap)
{
	NodLsta* nodTemporar = nodap;
	while (nodTemporar != NULL)
	{
		nodLista* nodTemporar2 = nodTemporar->next;
		delete[] nodTemporar->infoUtila.denumire;
		delete nodTemporar;
		nodTemporar = nodTemporar2;
	}
```

</td>
</tr>
</tbody>
</table>
<!--************************************ TABEL****************************************************-->


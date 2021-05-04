# 1. Lista Simpla 
Lista Simpla = O inlantuire de noduri si fiecare nod are un pointer catre nodul urmator.
- Lista se va crea nod cu nod.</br>
- Este o structura de date dinamica cu acces secvential.</br>

## 🗝️ Rezolvare: </br>
🔴Creare si inserare nod in lista</br>
🟠Traversare cu afisare lista </br>
🟡Traversare cu dezalocare lista</br>
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
//Functie de inserare in lista simpla
nodls* inserare(NodLS *cap, Produs p)
{
	NodLS *nou = (nodls*)malloc(sizeof(nNdLS));
	
	//Initializam componentele din nod 
	//-- Informatia Utila
	nou->inf->denumire = (char*)malloc((strlen(p->denumire)+1)*sizeof(char));
	strcpy(nou->inf->denumire, p->denumire);
	nou->inf->cod = p->cod;
	nou->inf->pret = p->pret;
	nou->inf->cantitate = p->cantitate;
	
	//-- Pointerul de legatura catre nodul urmator
	nou->next = NULL;
	
	if(cap==NULL)
		cap = nou;
	else
	{
		NodLS *temp = cap;
		while(temp->next!=NULL)
			temp = temp->next;
		temp->next = nou;
	}
	return cap;
}


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
void traversare(nodls *cap)
{
	nodls * temp = cap;
	while(temp!=NULL)
	{
		printf("\nCod=%d, Denumire=%s, Pret=%5.2f, Cantitate=%5.2f",
			temp->inf->cod, temp->inf->denumire, temp->inf->pret, temp->inf->cantitate);
		temp=temp->next;
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
	nodls* temp = cap;
	while (temp != NULL)
	{
		cout << "Cod = " << temp->inf.cod << " Denumire = " << temp->inf.denumire << " Pret = " << temp->inf.pret << " Cantitate = " << temp->inf.cantitate << endl;
		temp = temp->next;
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
void dezalocare(nodls *cap)
{
	nodls *temp = cap;
	while(temp!=NULL)
	{
		nodls* temp2 = temp->next;
		free(temp->inf->denumire);
		free(temp->inf);
		free(temp);
		temp = temp2;
	}
}
```
				
</td>
<!------------------------------------ A DOUA COLOANA - LIMBAJUL C++------------------------------------>
<td>
	
```cpp
void dezalocare(nodls* cap)
{
	nodls* temp = cap;
	while (temp != NULL)
	{
		nodls* temp2 = temp->next;
		delete[] temp->inf.denumire;
		delete temp;
		temp = temp2;
	}
```

</td>
</tr>
</tbody>
</table>
<!--************************************ TABEL****************************************************-->


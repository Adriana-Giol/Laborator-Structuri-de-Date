# 1. Vector
🔮[**Cod Sursa**](https://github.com/Adriana-Giol/Structuri-de-Date/blob/main/%5BCiurea%5DSDD_Laborator/Seminar1_1046%5Bvector-matrice%5D.cpp)🔮
## ❓ Cerinte:</br>
Avem la dispozitie doar vectori si matrici alocate dinamic.
Avem de gestionat niste produse pe care sa le salvam in aceste structuri.
  - Afisare
  - Dezalocare
  - Calculul cosului de cumparaturi</br>
  🔜 Vector -> Lista Simpla -> Lista Dubla -> Lista Dubla Circulara

## 🗝️ Rezolvare: </br>
0️⃣**PAS 0: Definim structura Produs**</br>
<a>
	<img src ="https://github.com/Adriana-Giol/Structuri-de-Date/blob/main/Resurse/StructuraProdus.jpg" weidth="200px" height="200px" align="right"/>
</a>


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
<a>
	<img src ="https://user-images.githubusercontent.com/60271540/113738138-50237b80-9707-11eb-959c-c7f8517da02f.jpg" weidth="250px" height="270px" align="right"/>
</a>

❓ **Un produs o sa ocupe 16 Bytes:**
- int cod(4B),
- 🎇denumire(4b),
- float pret(4B), 
- float cantitate(4B)</br>

**Vectorul o sa fie alocat in HEAP pentru ca o sa il declaram ca pe un vector dinamic de tipul `Produs* p`. Denumirea produsului pe care o alocam in HEAP pentru un numr de caractere corespunzator celor citite de la tastatura folosind BUFFER-ul (un sir static cu o lungime fixa) folosit pentru a prelua date de la consola si a le muta in acel spatiu alocat dinamic. Nu putem sa alocam de la inceput pentru ca nu stim dimensiunea sirului de caractere pe care o sa il introduca utilizatorul.**</br>

# Vector de Produse
1️⃣**PAS 1: Citire Vector de Produse**</br>
*Citim tot vectorul pe componente, deci o sa ne folosim de un for. Citire pe componente inseamna ca citim cod, denumire, pret, cantitate si astfel citesc un intreg element al vectorului (un singur produs din vectorul de produse). Si acest mecanism introdus in for o sa ma ajute sa citesc toate elementele vectorului.*</br>
****</br>
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
//Vectorul (pointerul - adresa catre primul element din vector - *p) si Dimensiunea vectorului (n)

void citireVector(Produs* p, int n)
for (int i = 0; i < n; i++)
	{
		printf("Cod=");
	  						 //	p[i].cod = (int*)malloc(1 * sizeof(int));   - pentru int*cod;
		scanf("%d", p[i].cod);

		printf("Denumire=");
		char buffer[20];
		scanf("%s", buffer);
		p[i].denumire = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
		strcpy(p[i].denumire, buffer);

		printf("Pret=");
		scanf("%f", &p[i].pret);

		printf("Cantitate=");
		scanf("%f", &p[i].cantitate);
	}
```
				
</td>
<!------------------------------------ A DOUA COLOANA - LIMBAJUL C++------------------------------------>
<td>
	
```cpp
// Vectorul (pointerul - adresa catre primul element din vector - *p) si Dimensiunea vectorului (n)

void citireVector(Produs* p, int n)
for (int i = 0; i < n; i++) {
		cout << "Cod = ";
		cin >> p[i].cod;			//cin>> *(p[i].cod) = new int[1]; -- pentru int* cod;
	

		cout << "Denumire = ";
		//1. La char-uri se declara bufferul
		char buffer[20];

		//2. Citim in buffer
		cin >> buffer;

		//3. Alocam spatiu pentru denumire
		p[i].denumire = new char[strlen(buffer) + 1];

		//4.Copiem in vector din buffer
		strcpy(p[i].denumire, buffer);

		cout << "Pret = ";
		cin >> p[i].pret;

		cout << "Cnatitate = ";
		cin >> p[i].cantitate;
	}
```

</td>
</tr>
</tbody>
</table>
<!--************************************ TABEL****************************************************-->

2️⃣**PAS 2: Afisare Vector de Produse**</br>
*La afisare o sa ne folosim tot de for. O sa afisam componenta cu componenta (cod, denumire, pret, cantitate).*
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
void afisareVectProd(produs *p, int n)
{
	for(int i=0;i<n;i++)
		printf("\nCod=%d, Denumire=%s, Pret=%5.2f, Cantitate=%5.2f",
		p[i].cod, p[i].denumire, p[i].pret, p[i].cantitate);
		//*(p[i].cod)  -- pentru int* cod;
		
}
```
				
</td>
<!------------------------------------ A DOUA COLOANA - LIMBAJUL C++------------------------------------>
<td>
	
```cpp
void afisareVector(produs* p, int n)
{
	for (int i = 0; i < n; i++)
		cout << "Cod=" << p[i].cod << ", Denumire=" << p[i].denumire << ", Pret=" << p[i].pret << ", Cantitate=" << p[i].cantitate << endl;
	                       //*(p[i].cod)  -- pentru int* cod;
		
}
```

</td>
</tr>
</tbody>
</table>
<!--************************************ TABEL****************************************************-->

3️⃣**PAS 3: Dezalocare Vector de Produse**</br>
*Trebuie sa dezaloc mai intai toate denumirile pentru fiecare produs in parte. Si apoi dezalocam spatiul vectorului de produse de 48B = 16B(un Produs) * 3 (Produse).Eu ocup in HEAP 48B pentru un vector de 3 elemente, doar ca pentru fiecare produs se mai acupa un spatiu tot in HEAP de 4B aferent denumirii lui.*
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
void dezalocareVector(produs *p, int n)
{
	for(int i=0;i<n;i++)
		free(p[i].denumire);
		                                  //free(p[i].cod); -- pentru int* cod;
	free(p);
}
```
				
</td>
<!------------------------------------ A DOUA COLOANA - LIMBAJUL C++------------------------------------>
<td>
	
```cpp
void dezalocareVector(produs* p, int n)
{
	for (int i = 0; i < n; i++)
		delete[] p[i].denumire;
		                                //delete[] p[i].cod; -- pentru int* cod;
	delete[] p;
}
```

</td>
</tr>
</tbody>
</table>
<!--************************************ TABEL****************************************************-->


4️⃣🟢**PAS 4: In Main declaram numarul de elemente ale vectorului (numarul de produse din vector) pe care il citim. Apoi alocam spatiu pentru vectorul de produse.**
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
void main()
{ 
   // Declaram o variabila int n - numar de elemente(Produs) din vector pe care il citim
	int n;
	printf("Nr. produse=");
	scanf("%d", &n);
	
  // Alocare spatiu pentru vector de produse
  produs *p = (produs*)malloc(n*sizeof(produs));
  
  //Apelul functiilor anterior create
	citireVectProd(p, n);
	afisareVectProd(p, n);
	dezalocareVectProd(p, n);
}
```
				
</td>
<!------------------------------------ A DOUA COLOANA - LIMBAJUL C++------------------------------------>
<td>
	
```cpp
void main()
{ 
 // Declaram o variabila int n - numar de elemente(Produs) din vector pe care il citim
	int n;
	cout << "Nr. produse=";
	cin >> n;
	
 // Alocare spatiu pentru vector de produse
	produs* p = new produs[n];
	
//Apelul functiilor anterior create
	citireVector(p, n);
	afisareVector(p, n);
	dezalocareVector(p, n);
}
```

</td>
</tr>
</tbody>
</table>
<!--************************************ TABEL****************************************************-->

### Rezultat 
![image](https://user-images.githubusercontent.com/60271540/116915115-47fe2380-ac54-11eb-8792-380408e55e62.png)

# Vector de tipuri fundanmentale - int, char, float
![image](https://user-images.githubusercontent.com/60271540/116919603-2e5fda80-ac5a-11eb-81fd-57507132080b.png)
1️⃣**PAS 1: Citire Vector de Vectori de Produse
In cazul in care nu stiam sa definim structura Produs si nu voiam sa lucram cu vectori de articole, ci cu vectori de tipuri fundamentale (int, char, float), atunci ar trebui sa adaptam cele 3 functii (citire, afisare, dezalocare) pentru 4 vectori de tipuri fundamentale.**</br>
**In loc de char* o sa le avem pe toate cu steluta - adica o sa avem un vector de vectori (pointeri)**

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
void citire4Vectori(int *cod, char **denumire, float *pret, float *cantitate, int n)
{
	for(int i=0;i<n;i++)
	{
		printf("Cod=");
		scanf("%d", &cod[i]);
		
		printf("Denumire=");
		char buffer[20];
		scanf("%s", buffer);
		den[i] = (char*)malloc((strlen(buffer)+1)*sizeof(char));
		strcpy(denumire[i], buffer);
		
		printf("Pret=");
		scanf("%f", &pret[i]);
		
		printf("Cantitate=");
		scanf("%f", &cantitate[i]);
	}
}
```
				
</td>
<!------------------------------------ A DOUA COLOANA - LIMBAJUL C++------------------------------------>
<td>
	
```cpp
void citire4Vectori(int *cod, char**denumire, float *pret, float *cantitate, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Cod=";
		cin >>cod[i];
		
		cout << "Denumire=";
		char buffer[20];
		cin >> buffer;
		den[i] = new char[strlen(buffer) + 1];
		strcpy(denumire[i], buffer);
		
		cout << "Pret=";
		cin >> pret[i];
		
		cout << "Cantitate=";
		cin >> cantitate[i];
	}
}
```
</td>
</tr>
</tbody>
</table>
<!--************************************ TABEL****************************************************-->

2️⃣**PAS 2: Afisare Vector de Vectori de Produse**
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
void afisare4Vectori(int *cod, char **denumire, float *pret, float *cantitate, int n)
{
	for(int i=0;i<n;i++)
		printf("\nCod=%d, Denumire=%s, Pret=%5.2f, Cantitate=%5.2f",
		cod[i], denumire[i], pret[i], cantitate[i]);
}
```
				
</td>
<!------------------------------------ A DOUA COLOANA - LIMBAJUL C++------------------------------------>
<td>
	
```cpp
void afisare4Vectori(int* cod, char** denumire, float* pret, float* cantitate, int n)
{
	for (int i = 0; i < n; i++)
		cout << "Cod=" << cod[i] << ", Denumire=" << denumire[i] << ", Pret=" << pret[i] << ", Cantitate=" << cantitate[i] << endl;
}
```

</td>
</tr>
</tbody>
</table>
<!--************************************ TABEL****************************************************-->

3️⃣**PAS 3: Dezalocare Vector de Vectori de Produse**
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
void dezalocare4Vectori(int *cod, char **denumire, float *pret, float *cantitate, int n)
{
	free(cod);
	for(int i=0;i<n;i++)
		free(denumire[i]);
	free(den);
	free(pret);
	free(cantitate);
}
```
				
</td>
<!------------------------------------ A DOUA COLOANA - LIMBAJUL C++------------------------------------>
<td>
	
```cpp
void dezalocare4Vectori(int* cod, char** denumire, float* pret, float* cantitate, int n)
{
	delete[] cod;
	for (int i = 0; i < n; i++)
		delete[] denumire[i];
	delete[] denumire;
	delete[] pret;
	delete[] cantitate;
}
```

</td>
</tr>
</tbody>
</table>
<!--************************************ TABEL****************************************************-->

4️⃣🟢**PAS 4: In Main facem alocari pentru 4 vectori diferiti.**
Putem sa vedem aceasta matrice ca o matricea `denumire` in scara deoarece are un numar de linii, dar pe fiecare linie numarul de caractere e variabil. Si in Main ii fac doar alocarea liniilor, urmand ca fiecare linie sa se aloce la citire, in functie de numarul de caractere pe care il citesc de la tastatura.
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
	int *cod = (int*)malloc(n*sizeof(int));
	char** denumire = (char**)malloc(n*sizeof(char*));
	float *pret = (float*)malloc(n*sizeof(float));
	float *cantitate = (float*)malloc(n*sizeof(float));
	citire4Vectori(cod, denumire, pret, cantitate, n);
	afisare4Vectori(cod, denumire, pret, cantitate, n);
	dezalocare4Vectori(cod, denumire, pret, cantitate, n)
```
				
</td>
<!------------------------------------ A DOUA COLOANA - LIMBAJUL C++------------------------------------>
<td>
	
```cpp
	iint* cod = new int[n];
	char** denumire = new char* [n];
	float* pret = new float[n];
	float* cantitate = new float[n];
	citire4Vectori(cod, denumire, pret, cantitate, n);
	afisare4Vectori(cod, denumire, pret, cantitate, n);
	dezalocare4Vectori(cod, denumire, pret, cantitate, n);
```

</td>
</tr>
</tbody>
</table>
<!--************************************ TABEL****************************************************-->

### Rezultat (obtin acelasi rezultat ca cel de la vectorul de Produse)
![image](https://user-images.githubusercontent.com/60271540/116915115-47fe2380-ac54-11eb-8792-380408e55e62.png)

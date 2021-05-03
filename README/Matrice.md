# 2. Matrice
🔮[**Cod Sursa**](https://github.com/Adriana-Giol/Structuri-de-Date/blob/main/%5BCiurea%5DSDD_Laborator/Seminar1_1046%5Bvector-matrice%5D.cpp)🔮</br>
Vectorul este un spatiu contiguu de memorie, unde trebuie sa stiu adresa de inceput (acel P[0] - care este adresa primului element din vector si apoi celelalte elemente sunt dispuse in continuare. Am acces la toate elementele pe baza de index.
Matricea inseamna un vector de vectori cu conditia ca toate elementele din acei vectori sa fie de acelasi tip.

## ❓ Cerinte:</br>
Deoarece vrem sa folosim matrici, denumirile nu le vom putea stoca. De aceea vom merge pe varianta de a avea o `matrice de float` (avem pret, cantitate cu float). Deoarece float este mai puternic decat int va suplini si nevoie de stocare a codului.
Denumirile le pastram separat intr-un vector **denumire.

## 🗝️ Rezolvare: </br>
0️⃣**PAS 0: Definim structura Produs**</br>
<a>
	<img src ="" weidth="200px" height="200px" align="right"/>
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

1️⃣**PAS 1: Citire Matrice**</br>
*Facem citirea cu 2 for-uri: o data pentru linii si apoi pe coloane.*
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

```
				
</td>
<!------------------------------------ A DOUA COLOANA - LIMBAJUL C++------------------------------------>
<td>
	
```cpp
void citireMatrice(float** mat, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
		{
			cout << "mat[" << i << "][" << j << "]=";
			cin >> mat[i][j];
		}
}
```

</td>
</tr>
</tbody>
</table>
<!--************************************ TABEL****************************************************-->

2️⃣**PAS 2: Afisare Matrice**</br>
*Afisare tot cu 2 for-uri.*
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
void afisareMatrice(float** mat, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << mat[i][j] << " ";
		  cout << endl;
	}
}
```

</td>
</tr>
</tbody>
</table>
<!--************************************ TABEL****************************************************-->

3️⃣**PAS 3: Dezalocare Matrice**</br>
*Dezalocarea se face in ordinea inversa alocarii.*
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
void dezalocareMatrice(float** mat, int n)
{
	for (int i = 0; i < n; i++)
		delete[] mat[i];
	delete[] mat;
}
```

</td>
</tr>
</tbody>
</table>
<!--************************************ TABEL****************************************************-->


4️⃣🟢**PAS 4: In Main, dupa ce am alocat matricea, apelam functiile create mai sus.**
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
void main()
{
//Alocare matrice
	float** mat = new float*[n];
	for (int i = 0; i < n; i++)
		mat[i] = new float[3];      //3 pentru ca avem 3 elemente (cod, pret, cantitate)
   
   //Apelare functii create anterior
  citireMatrice(mat, n);
	afisareMatrice(mat, n);
	dezalocareMatrice(mat, n);
  
}
```
</td>
</tr>
</tbody>
</table>
<!--************************************ TABEL****************************************************-->

### Rezultat 
![image](https://user-images.githubusercontent.com/60271540/116927789-cc58a280-ac64-11eb-98eb-de9bdcba6238.png)

## Matrice cu denumirile atasate
5️⃣**PAS 5: Adaugare in cele 3 functii (citire, afisare, dezalocare) si vectorul de denumiri, iar la afisare sa se vada si denumirile.**
🔴**CITIRE**
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
void citireMatrice(float** mat,char**denumire, int n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				cout << "mat[" << i << "][" << j << "]=";
				cin >> mat[i][j];
			}
			cout << "Denumire = ";
			char buffer[20];
			cin >> buffer;
			denumire[i] = new char[strlen(buffer) + 1];
			strcpy(denumire[i], buffer);

		}
	}
```
</td>
</tr>
</tbody>
</table>
<!--************************************ TABEL****************************************************-->

🟠**AFISARE**
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
void afisareMatrice(float** mat,char**denumire, int n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {

				cout << mat[i][j] << " ";
			}
			cout << denumire[i] << endl;
			cout << endl;
		}
	}
```
</td>
</tr>
</tbody>
</table>
<!--************************************ TABEL****************************************************-->

🟡**DEZALOCARE**
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
void dezalocareMatrice(float** mat,char**denumire, int n) {
		for (int i = 0; i < n; i++) {
			delete[]mat[i];
		}
		delete[]mat;
		for (int i = 0; i < n; i++) {
			delete[]denumire[i];
		}
		delete[]denumire;
	}
```
</td>
</tr>
</tbody>
</table>
<!--************************************ TABEL****************************************************-->

# Rezultat
![image](https://user-images.githubusercontent.com/60271540/116928705-142bf980-ac66-11eb-9f58-cecb01ede310.png)


 

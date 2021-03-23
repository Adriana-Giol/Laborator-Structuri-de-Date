#include<stdio.h>
#include<iostream>

using namespace std;

struct Produs {
	int cod;
	char* denumire;
	float pret;
	float cantitate;
};

//*************************************** VECTOR DE PRODUSE ********************************************************
//-- CITIRE: Vectorul (pointerul - adresa catre primul element din vector - *p) si Dimensiunea vectorului (n)

void citireVector(Produs* p, int n) {
	//Varianta C++ (POO)
	for (int i = 0; i < n; i++) {
		cout << "Cod = ";
		cin >> p[i].cod;

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


	//Varianta C 
	/*for (int i = 0; i < n; i++)
	{
		printf("Cod=");
		p[i].cod = (int)malloc(1 * sizeof(int));    // daca codul ar fi vector  - p[i].cod = (int*)malloc(1 * sizeof(int));
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
	}*/

}

//-- AFISARE

void afisareVector(Produs* p, int n) {
	//Varianta C++
	for (int i = 0; i < n; i++) {
		cout << "Codul produsului " << p[i].denumire << " este " << p[i].cod << " si are cantitatea de " << p[i].cantitate << " la pretul de " << p[i].pret <<" lei."<< endl;
		
		//Daca codul ar fi vector -- *(p[i].cod)
		
	}

//Varianta C
	/*for (int i = 0; i < n; i++)
		printf("\nCod=%d, Denumire=%s, Pret=%5.2f, Cantitate=%5.2f",
			(p[i].cod), p[i].denumire, p[i].pret, p[i].cantitate);*/
}

//--DEZALOCARE

void dezalocareVector(Produs* p, int n) {

	//VARIANTA C++
//Stergem mai intai spatiul din HEAP pentru denumire
	for (int i = 0; i < n; i++) 
	{
		delete[] p[i].denumire;

		//daca codul ar fi vector s-ar dezaloca si el -- delete[] p[i].cod;
	}
	delete[]p;

	//VARIANTA C
	/*for (int i = 0; i < n; i++)
	{
		free(p[i].denumire);
	}
	free(p);*/
}

void main() {
	//******** VARIANTA C++***************
	//Declaram o variabila int n - numar de elemente (Produs) din vector pe care il citim
	int n;
	cout << "Nuamrul de produse din vector: ";
	cin >> n;

	//Alocare spatiu pentru vector de produse
	Produs* p = new Produs[n];

	//Apelul functiilor anterior create
	citireVector(p, n);
	afisareVector(p, n);
	dezalocareVector(p, n);

	//************ VARIANTA C *****************
/*	int n;
	printf("Nr. produse=");
	scanf("%d", &n);

	Produs* p = (Produs*)malloc(n * sizeof(Produs));
	citireVector(p, n);
	afisareVector(p, n);
	dezalocareVector(p, n);*/
}
#include<stdio.h>
#include<iostream>

using namespace std;

struct Produs {
	int cod;				//int* cod;
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
		cin >> p[i].cod;			//cin>> *p[i].cod = new int[1]; -- pentru int* cod;
	

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
		p[i].cod = (int)malloc(1 * sizeof(int));    //	p[i].cod = (int*)malloc(1 * sizeof(int));   - pentru int*cod;
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
		
		//*(p[i].cod)   -- pentru int* cod;
		
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

//************************************* VECTOR DE TIPURI FUNDAMENTALE - INT, CHAR, FLOAT*******************************
// in loc de char* o sa le avem pe toate cu steluta - adica o sa avem un vector de vectori (pointeri)

// ----------- CITIRE PENTRU VECTOR DE VECTORI
void citire4Vectori(int* cod, char** denumire, float* pret, float* cantitate, int n) {
	//Varianta C++ (POO)
	for (int i = 0; i < n; i++) {
		cout << "Cod = ";
		cin >> cod[i];

		cout << "Denumire = ";
		//1. La char-uri se declara bufferul
		char buffer[20];

		//2. Citim in buffer
		cin >> buffer;

		//3. Alocam spatiu pentru denumire
		denumire[i] = new char[strlen(buffer) + 1];

		//4.Copiem in vector din buffer
		strcpy(denumire[i], buffer);

		cout << "Pret = ";
		cin >> pret[i];

		cout << "Cnatitate = ";
		cin >> cantitate[i];
	}
}
	//VARIANTA C
	/*for (int i = 0; i < n; i++)
	{
		printf("Cod=");
		scanf("%d", &cod[i]);
		printf("Denumire=");
		char buffer[20];
		scanf("%s", buffer);
		denumire[i] = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
		strcpy(denumire[i], buffer);
		printf("Pret=");
		scanf("%f", &pret[i]);
		printf("Cantitate=");
		scanf("%f", &cantitate[i]);
	}*/

	//-- AFISARE PENTRU VECTOR DE VECTORI (POINTERI)
	void afisare4Vectori(int* cod, char** denumire, float* pret, float* cantitate, int n) 
	{
		//Varianta C++
		for (int i = 0; i < n; i++) {
			cout << "Codul produsului " << denumire[i] << " este " << cod[i] << " si are cantitatea de " << cantitate[i] << " la pretul de " << pret[i] << " lei." << endl;
		}
		
	}
	//VARIANTA C
		/*void afisare4Vectori(int* cod, char** denumire, float* pret, float* cantitate, int n)
		{
			for (int i = 0; i < n; i++)
				printf("\nCod=%d, Denumire=%s, Pret=%5.2f, Cantitate=%5.2f",
					cod[i], denumire[i], pret[i], cantitate[i]);
		}*/

	//DEZALOCARE 
	void dezalocare4Vectori(int* cod, char** denumire, float* pret, float* cantitate, int n) {

		//VARIANTA C++
		delete[]cod;
		for (int i = 0; i < n; i++)
		{
			delete[] denumire[i];
		}
		delete[]denumire;
		delete[]pret;
		delete[]cantitate;

		//VARIANTA C
		/*void dezalocare4Vectori(int* cod, char** denumire, float* pret, float* cantitate, int n)
		{
			free(cod);
			for (int i = 0; i < n; i++)
				free(denumire[i]);
			free(denumire);
			free(pret);
			free(cantitate);
		}*/
	}
	//**************************************** MATRICE *********************************************************
	/*
//-- CITIRE MATRICE
	void citireMatrice(float** mat, int n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				cout << "mat[" << i << "][" << j << "]=";
				cin >> mat[i][j];
			}
		}
	}
//-- AFISARE
	void afisareMatrice(float** mat, int n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}
	}
//--DEZALOCARE
	void dezalocareMatrice(float** mat, int n) {
		for (int i = 0; i < n; i++) {
			delete[]mat[i];
		}
		delete[]mat;
		
		
	}
	*/

	//************************************** MATRICE CU DENUMIRILE ATASATE ********************************************
	// Atasare matricei curente vectorul de denumiri
	//-- CITIRE MATRICE
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
	//-- AFISARE
	void afisareMatrice(float** mat,char**denumire, int n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {

				cout << mat[i][j] << " ";
			}
			cout << denumire[i] << endl;
			cout << endl;
		}
	}
	//--DEZALOCARE
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

void main() {
	// Declaram o variabila int n - numar de elemente(Produs) din vector pe care il citim
		int n;
		cout << "Nuamrul de produse= ";
		cin >> n;
	
	//******** VARIANTA C++***************
	/*/
	//Alocare spatiu pentru vector de produse
	Produs* p = new Produs[n];

	//Apelul functiilor anterior create
	citireVector(p, n);
	afisareVector(p, n);
	dezalocareVector(p, n);*/

	//************ VARIANTA C *****************
/*	int n;
	printf("Nr. produse=");
	scanf("%d", &n);

	Produs* p = (Produs*)malloc(n * sizeof(Produs));
	citireVector(p, n);
	afisareVector(p, n);
	dezalocareVector(p, n);*/


	//**************************************** VECTOR DE VECTORI ***********************
	/*//Alocari pentru cei 4 vectori ai Produsului
	int* cod = new int[n];
	char** denumire = new char* [n];
	float* pret = new float[n];
	float* cantitate = new float[n];
	citire4Vectori(cod, denumire, pret, cantitate, n);
	afisare4Vectori(cod, denumire, pret, cantitate, n);
	dezalocare4Vectori(cod, denumire, pret, cantitate, n);*/

	//ALOCARE MATRICE 

	float** mat = new float* [n];

	//Alocare spatiu pentru denumirea atasata vectorului
	char** denumire = new char* [n];

	for (int i = 0; i < n; i++) {
		mat[i] = new float[3];
	}

	//APEL FUNCTII MATRICE
	citireMatrice(mat,denumire, n);
	afisareMatrice(mat, denumire,n);
	dezalocareMatrice(mat,denumire, n);
}
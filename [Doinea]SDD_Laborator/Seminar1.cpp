#include <malloc.h>
void main() {

	//declarare de variabila
	int x = 6;
	int px;

	/*Pointerul are 2 tipuri de adrese care pot fi folosite pentru initializarea unui pointer din punct de vadere al alocarii
	- Static 
	- Dinamic */

	//Initializarea pointerului cu adresa statica
	int* px = &x; // este o adresa care se gaseste pe Stack-ul lui Main

	//Initializarea pointerului cu adresa dinamica
	int* px = (int*)malloc(sizeof(int));
}
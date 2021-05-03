# Prezentare Generala:
Avem structura in cadrul careia incapsulam diferite atribute de tipuri fundamentale (int, float, char*, double) pentru a avea o lista de carti, o stiva de farfurii, o coada de studenti.

## 💡 Pentru fiecare structura ne intereseaza:</br>
1️⃣Informatia utila (cum este ea structurata)</br>
2️⃣Operatia de creare a structurii</br>
3️⃣Operatia de stergere (Dezalocare a spatiului de memorie)</br>
4️⃣Traversare cu **afisare**</br>
➖ Traversare doar intr-o anumita ordine - **Lista Simpla: traversare de la cap la coada**</br>
➖ Traversare in abele directii - **Lista Dubla: pastrarea ambilor pointeri, actualizati permanant cand se adauga sau se sterge un nod**</br>
5️⃣Traversare cu **prelucrare**: numarare</br>
6️⃣Operatii ce presupun scoaterea de elemente</br>
7️⃣**CONVERSII**</br>
*Avem o structura de baza (lista simpla) si vreau sa fac conversie din lista simpla in vector* *In urma conversiei lista o sa dispara: deci nu o sa am si vector si lista*
*In momentul in care iau nod cu nod din lista pentru a insera in vector, atunci ma asigur ca lista este si dezalocata*

## 🚩Structuri de date
⛓️ **Stiva si Coada = avem implementate operatii de inserare/scoatere (Stiva - push/pop)(Coada - put/get) din lista cu dezalocare**</br>

⛓️ **ARBORI BINARI DE CAUTARE:**</br>
     - operatii de inserare: toate nodurile Stanga < Radacina < Dreapta</br>
     - numarare de noduri</br>
     - 🔺CAZ PARTICUALAR DE ARBORE BINAR = HEAP (Coada de prioritati) - se implementeaza ca vector</br>
    
⛓️ **TABELE DE DISPERSIE:**(2 implementari):</br>
     1. Evitarea coeziunilor (Chaining) - Vectori de pointeri la liste</br>
     2. Linear Probing - un singur vector in care sunt ocupate doar pozitiile cu functia HASH care ne spune unde ar trebui sa se insereze</br>
 
⛓️**GRAFURI**</br>

⛓️**FISIERE:**</br>
      - Citire/Salvare date dintr-un fisier text</br>
      - Arbore binar - preluare date dintr-un fisier text (inserare nodurilor intr-un arbore)</br>
                         

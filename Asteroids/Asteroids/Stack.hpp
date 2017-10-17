#pragma once

class Stack
{
private:
	size_t max_size; /*<! Taille maximale de la pile*/
	size_t *head; /*<! T�te de pile*/
	size_t *current_ptr; /*<! Pointeur vers l'emplacement actuelle*/

public:
	/*
	* Constructeur permettant d'initialiser une stack de taille max_size
	*/
	Stack(size_t max_size);

	/*
	* Destructeur par d�faut
	*/
	~Stack();


	/*
	* Op�rateurs d'acc�s � la pile
	*/
	size_t operator[](const int i);
	const size_t operator[](const int i) const;

	void push(size_t number);

	size_t pop();
};
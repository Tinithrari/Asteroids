#pragma once

class Allocator {

protected:
	void **head; /*<! T�te de la zone m�moire*/
	void **current_position_ptr; /*<! Pointeur sur la position actuelle sur la zone m�moire*/
	size_t current_position; /*<! Num�ro de la place actuelle sur la zone m�moire*/
	size_t size; /*<! Taille de la zone allou�e*/
	size_t used_memory; /*<! Nombre de cases utilis�es*/

public:
	/*
	* On bloque l'acc�s au constructeurs par copie pour �viter d'empi�ter sur la zone m�moire d�ja allou�e
	*/
	Allocator(const Allocator &alloc);
	Allocator& operator=(const Allocator &alloc);

	/*
	* Constructeur par d�faut de l'allocator, ou l'on sp�cifie une taille pour la zone m�moire
	*/
	Allocator(size_t size);

	/*
	* Destructeur par d�faut
	*/
	~Allocator();

	void* allocate(size_t size);
	void deallocate(void *ptr);

	void* getHead() const;

	size_t getSize() const;

	size_t getUsedMemory() const;

	void* operator[](const int i);

	const void* operator[](const int i) const;
};
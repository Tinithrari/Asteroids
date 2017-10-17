#pragma once

class Allocator {

protected:
	void **head; /*<! Tête de la zone mémoire*/
	void **current_position_ptr; /*<! Pointeur sur la position actuelle sur la zone mémoire*/
	size_t current_position; /*<! Numéro de la place actuelle sur la zone mémoire*/
	size_t size; /*<! Taille de la zone allouée*/
	size_t used_memory; /*<! Nombre de cases utilisées*/

public:
	/*
	* On bloque l'accés au constructeurs par copie pour éviter d'empiéter sur la zone mémoire déja allouée
	*/
	Allocator(const Allocator &alloc);
	Allocator& operator=(const Allocator &alloc);

	/*
	* Constructeur par défaut de l'allocator, ou l'on spécifie une taille pour la zone mémoire
	*/
	Allocator(size_t size);

	/*
	* Destructeur par défaut
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
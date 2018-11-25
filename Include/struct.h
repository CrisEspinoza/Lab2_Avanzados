# ifndef STRUCT_H
# define STRUCT_H

// Definimos las estructuras a ocupar dentro de la aplicacion

typedef struct List
{
	int* path;
	int weigth;
}List;

typedef struct Matriz
{
	int numbersNodo;
	int** adjacency;
	List* listPath;
	int minimoPeso;
	int combinaciones;
}Matriz;

// Definimos las funciones que se van a utilizar dentro del codigo 

Matriz *loadMatriz(char nombre[]);
void saveTablero (Matriz* matriz);
void freeMemory(Matriz* matriz);


# endif
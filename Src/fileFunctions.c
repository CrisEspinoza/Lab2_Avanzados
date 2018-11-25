#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../Include/struct.h"

// ******************   Funciones para realizar escritura y lectura de archivos  ******************//

Matriz* loadMatriz (char nombre[])
{
	FILE *file; // Declaramos un puntero File para poder leer el file de entrada.
	char* route = (char*)calloc(100, sizeof(char));
	strcat(route, "../Documents/");
	strcat(route, nombre);
    strcat(route, ".txt");
    file = fopen (route, "r"); // Estamos abriendo el file en modo lectura

    Matriz* matriz; // Se declara una variable de tipo matriz
    int numbersNodo,destination,origin,weight; 

    //Verificamos si el file se encuentra nulo
    if( file == NULL)
    {
        printf("Error al abrir archivo \n");
        return NULL;
    }

    // Leemos las primeras lineas del file para un mejor manejo de este
    fscanf(file, "%d", &numbersNodo); 

    while(getc(file) != '\n'); // Que lea el file siempre y cuando no sea un salto de linea
    while (!feof(file)) 
    {
        
    }
    
    fclose(file); // Cerramos el file
 
    return matriz; //Retornamo la variable matriz, con el tablero contenido, el cual se leyó desde el file ingresado

}

void saveTablero (Matriz* matriz)
{   
    FILE *txt;  // Incialzamos una variable de tipo FILE para poder trabajar con los archivos
    txt = fopen("../Out/Salida.out", "wt");
    int i , j;

    fclose(txt); // Cerramos el archivo
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../Include/struct.h"

// ******************   Funciones para realizar escritura y lectura de archivos  ******************//

Investments* loadInvestments (char nombre[])
{
	FILE *file; // Declaramos un puntero File para poder leer el file de entrada.
	char* route = (char*)calloc(100, sizeof(char));
	strcat(route, "../Documents/");
	strcat(route, nombre);
    strcat(route, ".in");
    file = fopen (route, "r"); // Estamos abriendo el file en modo lectura

    Investments* investments; // Se declara una variable de tipo matriz
    int cost,utility,initialCapital,numberTheInnvestments,counter = 0; 

    //Verificamos si el file se encuentra nulo
    if( file == NULL)
    {
        printf("Error al abrir archivo \n");
        return NULL;
    }

    // Leemos las primeras lineas del file para un mejor manejo de este
    fscanf(file, "%d", &initialCapital);
    fscanf(file, "%d", &numberTheInnvestments); 

    //printf("%d %d\n", investments->initialCapital, investments->numberTheInnvestments);

    investments = createInvestments(numberTheInnvestments);

    investments->numberTheInnvestments = numberTheInnvestments;
    investments->initialCapital = initialCapital;

    while(getc(file) != '\n'); // Que lea el file siempre y cuando no sea un salto de linea
    while (!feof(file)) 
    {
        fscanf(file, "%d %d",&cost, &utility);
        investments->investmentList[counter].cost = cost;
        investments->investmentList[counter].utility = utility;
        //printf("%d %d \n" , cost,utility);
        counter++;
    }

    //printInvestments(investments);
    
    fclose(file); // Cerramos el file
 
    return investments; //Retornamo la variable matriz, con el tablero contenido, el cual se leyó desde el file ingresado

}

void saveInvestments (Investments* investments)
{   
    FILE *txt;  // Incialzamos una variable de tipo FILE para poder trabajar con los archivos
    txt = fopen("../Out/Salida.out", "wt");
    int i ;

    fprintf(txt,"%d %d ",investments->maxUtility.cost, investments->maxUtility.utility); // Se coloca el peso total ocupado en la ruta minima obtenida y se pone en el archivo
    fprintf(txt, "\n"); // S ehace un salto de linea en ele archio

    for (i = 0 ; i < investments->numberTheInnvestments ; i++)
    {
        if (investments->maximumUtility[i] == 1)
            fprintf(txt,"%d \n",investments->investmentList[i].utility);
        
    }

    fclose(txt); // Cerramos el archivo
}
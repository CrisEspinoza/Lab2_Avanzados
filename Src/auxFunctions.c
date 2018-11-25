#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "../Include/struct.h"

#define DEBUG

// **************** Funciones auxiliares ******************

/* 
Entrada: Recibe la matriz que se utiliza actualmente.
Procedimiento: Se encarga de ir imprimiendo cada uno de los caminos generados y su respectivo costo de viaje.
Salida: -.
*/
void printCurrent(Investments* matriz)
{
    #ifdef DEBUG
    
    #endif
}

/* 
Entrada: Recibe la variable matriz.
Procedimiento: Se encarga de liberar la memoria de la variable matriz que se ocupa a lo largo del programa, que ayuda a reiniciar el programa 
sin necesidad que se tenga que volver a ejecutar.
Salida: -.
*/

void freeMemory(Investments* investments)
{
    //free(investments->investmentList);
    free(investments->maximumUtility);
    free(investments);
}

int myPow(int base, int exponent)
{
    int result = 1,i;
    for (i = 0; i < exponent; i++)
        result = result * base;
    return result;
}

int* convertToBinary(int number, int length)
{
    int* binaryNumber = (int*)calloc(length, sizeof(int));
    int i;
    for (i = 0; i < length; i++)
    {
        binaryNumber[i] =  number % 2;;
        number = number/2; 
    }
    return binaryNumber;
}

int benefitGranted (int* binaryList, Investments* investments)
{
    int benefit = 0,i,cost = 0;

    for (i = 0 ; i < investments->numberTheInnvestments ; i++)
    {
        if (binaryList[i] == 1)
        {
            benefit = benefit + investments->investmentList[i].utility;
            cost = cost + investments->investmentList[i].cost;
            if (cost > investments->initialCapital)
                return -1;
        }
    }

    return benefit;
}

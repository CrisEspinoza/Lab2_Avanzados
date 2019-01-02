#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "../Include/struct.h"

//#define DEBUG

// **************** Funciones auxiliares ******************

/* 
Entrada: Recibe la matriz que se utiliza actualmente.
Procedimiento: Se encarga de ir imprimiendo cada uno de los caminos generados y su respectivo costo de viaje.
Salida: -.
*/
void printCurrent(Investments* investments,InvestmentList investmentsAux)
{
    #ifdef DEBUG
    printf("\n");
    printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~| \n");
    printf("| Beneficio antiguo: %d  | | Beneficio nuevo: %d | \n",investments->maxUtility.utility,investmentsAux.utility);
    printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~| \n");
    printf("\n");
    printf("Presione una tecla para continuar ... .. . \n");
    while(getchar() != '\n')
    {
        printf("Tecla errónea...\n");
    }
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

InvestmentList benefitGranted (int* binaryList, Investments* investments)
{
    InvestmentList benefit;
    benefit.cost = 0;
    benefit.utility = 0;
    int i,cost = 0;

    for (i = 0 ; i < investments->numberTheInnvestments ; i++)
    {
        if (binaryList[i] == 1)
        {
            benefit.utility = benefit.utility + investments->investmentList[i].utility;
            benefit.cost = benefit.cost + investments->investmentList[i].cost;
            if (benefit.cost > investments->initialCapital)
            {
                benefit.utility = 0;
                benefit.cost = -1;
                return benefit;
            }
        }
    }

    return benefit;
}

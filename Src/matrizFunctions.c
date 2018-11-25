#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../Include/struct.h"

Investments* createInvestments(int numberTheInnvestments)
{
    int i;
    // Procedemos a crear una variable de tipo Tablero y a solicitar memoria para dicha variable
    Investments *investments;
    investments = (Investments*)malloc(sizeof(Investments));
    investments->investmentList = (InvestmentList*)malloc(sizeof(InvestmentList)*numberTheInnvestments);
    return investments; // retornamos el tablero inicilizado (con elemento que representa estar vacio)
}

void printInvestments(Investments *investments)
{
    printf("%d %d\n", investments->initialCapital, investments->numberTheInnvestments);
    int i,j;
    printf("El capital inicial es: %d \n",investments->initialCapital);
    for(i = 0 ; i < investments->numberTheInnvestments ; i++)
    {
        printf("%d %d \n",investments->investmentList[i].cost ,investments->investmentList[i].utility);
    } 

    /*int numberCombinations = myPow(2,investments->numberTheInnvestments);

    for (i = 0 ; i < numberCombinations ; i++)
    {
        for (j = 0 ; j < investments->numberTheInnvestments ; j++)
        {
            printf("%d" , investments->listOfBinaries[i][j]);
        }
        printf("\n");
    }
    */
}

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "../Include/struct.h"


// ****************** Funcion principal ******************//

int* backtraking(Investments* investments)
{
    int* auxiliary = (int*)malloc(sizeof(int));
    int i,auxUtility;
    int numberCombinations = myPow(2,investments->numberTheInnvestments);

    investments->maximumUtility = convertToBinary(0,investments->numberTheInnvestments);
    int auxiliaryUtility = benefitGranted(investments->maximumUtility , investments );
    investments->maxUtility = auxiliaryUtility;

    printf("Beneficio %d \n", auxiliaryUtility);

    for (i = 1 ; i < numberCombinations ;i++)
    {
        auxiliary = convertToBinary(i,investments->numberTheInnvestments);
        auxUtility = benefitGranted(auxiliary, investments );

        printf("Beneficio nuevo %d \n ", auxUtility);
        
        if (auxUtility > auxiliaryUtility)
        {
            investments->maximumUtility = auxiliary;
            investments->maxUtility = auxUtility;
            auxiliaryUtility = auxUtility;
        }
    }

    return investments->maximumUtility; // retornamos el tablero inicilizado (con elemento que representa estar vacio)
}
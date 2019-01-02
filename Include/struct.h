# ifndef STRUCT_H
# define STRUCT_H

// Definimos las estructuras a ocupar dentro de la aplicacion

typedef struct InvestmentList
{
	int cost;
	int utility;
}InvestmentList;

typedef struct Investments
{
	int initialCapital;
	int numberTheInnvestments;
	InvestmentList* investmentList; 
	int* maximumUtility;
	InvestmentList maxUtility;

}Investments;

// Definimos las funciones que se van a utilizar dentro del codigo 

Investments* loadInvestments (char nombre[]);
void saveInvestments (Investments* matriz);
void freeMemory(Investments* matriz);
void printInvestments(Investments *investments);
Investments* createInvestments(int numberTheInnvestments);
int* convertToBinary(int number, int length);
int myPow(int base, int exponent);
int* backtraking(Investments* investments);
InvestmentList benefitGranted (int* binaryList, Investments* investments);
void printCurrent(Investments* investments,InvestmentList investmentsAux);


# endif
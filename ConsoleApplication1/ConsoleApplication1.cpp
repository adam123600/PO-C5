#include "zad1.h"


int main()
{
	Pojemnik* Box1 = new Pojemnik("Pudelko1", 10, 500, 0);
	Box1->Wypisz();

	printf("\n\n");

	// utworzenie obiektu Box2 ktory pobiera cechy Box1
	Pojemnik* Box2 = new Pojemnik(*Box1);
	Box2->Wypisz();

	printf("\n\n");

	Bipojemnik* BiPojemnik1 = new Bipojemnik(
		"ALLLLLLAASDASDASDASDASD",
		"Box2",
		10,
		10,
		50,
		50,
		0,
		0);

	printf("\n\n");

	try
	{
		BiPojemnik1->Dolej(50);
	}

	catch(double ex2)
	{
		printf("Przelalo sie o:  %.2lf\n\n", ex2);
	}
	
	try
	{
		BiPojemnik1->Odlej(75);
	}

	catch(double ex2)
	{
		printf("Za duzo odlane o:  %.2lf\n\n", ex2);
	}


	delete(Box1);
	delete(Box2);
	delete(BiPojemnik1);

	system("pause");
	return 0;
}
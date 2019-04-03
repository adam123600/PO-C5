#include "zad1.h"


double Dodaj(struct pojemnik* struktura, double dodawanaZawartosc)
{
	if ((struktura->pojemonosc - struktura->zajete) < dodawanaZawartosc)
	{
		double aktualnyStan = struktura->pojemonosc - struktura->zajete;
		struktura->zajete += aktualnyStan;
		return dodawanaZawartosc - aktualnyStan;
	}
	struktura->zajete += dodawanaZawartosc;
	return 0;
}

double Odbierz(struct pojemnik* struktura, double odejmowanaZawartosc)
{
	if (struktura->zajete < odejmowanaZawartosc)
	{
		double odejmowana = struktura->zajete;
		struktura->zajete -= odejmowana;
		return odejmowana;
	}

	struktura->zajete -= odejmowanaZawartosc;
	return odejmowanaZawartosc;
}

void Wypisz(struct pojemnik struktura)
{
	printf("Wykladnik 10^: %d\n", struktura.jednostka);
	printf("Pojemnosc:     %.2lf\n", struktura.pojemonosc);
	printf("Zajete:        %.2lf\n", struktura.zajete);
}


//////////////////////////////////////////
////////////////////////////////////////////
//// ZAD2


Pojemnik::Pojemnik()
{
	nazwa = "Pojemnik";
	jednostka = 10;
	pojemnosc = 10;
	zajete = 0;
}

Pojemnik::Pojemnik(string nazwa, int jednostka, double pojemnosc, double zajete)
{
	this->nazwa = nazwa;
	this->jednostka = jednostka;
	this->pojemnosc = pojemnosc;
	this->zajete = zajete;
}

double Pojemnik::Dodaj(double dodawanaZawartosc)
{
	if ((pojemnosc - zajete) < dodawanaZawartosc)
	{
		double aktualnyStan = pojemnosc - zajete;
		zajete += aktualnyStan;
		//return dodawanaZawartosc - aktualnyStan;

		throw( dodawanaZawartosc - aktualnyStan);
	}
	zajete += dodawanaZawartosc;
	return dodawanaZawartosc;
}

double Pojemnik::Odejmij(double odejmowanaZawartosc)
{
	//if (( pojemnosc - zajete ) < odejmowanaZawartosc)
	if ( zajete < odejmowanaZawartosc)
	{
		double Odlana = odejmowanaZawartosc - zajete;
		zajete = 0;

		throw(Odlana);
	}
	else
	{
		zajete -= odejmowanaZawartosc;
	}
}

void Pojemnik::Wypisz()
{
	cout << "Nazwa:         " << nazwa << endl;
	cout << "Wykladnik 10^: " << jednostka << endl;
	cout << "Pojemnosc:     " << pojemnosc << endl;
	cout << "Zajete:        " << zajete << endl;
}

Pojemnik::Pojemnik(const Pojemnik& copy)
{
	nazwa = copy.nazwa;
	jednostka = copy.jednostka;
	pojemnosc = copy.pojemnosc;
	zajete = copy.zajete;
}

///////////////////////////////////////////
///////////////////////////////////////////


Bipojemnik::Bipojemnik(string nazwaA, string nazwaB, int jednostkaA,
		int jednostkaB,double pojemnoscA, double pojemnoscB,
		double zajeteA, double zajeteB) : 
		PojemnikA(nazwaA, jednostkaA, pojemnoscA, zajeteA),
		PojemnikB(nazwaB, jednostkaB, pojemnoscB, zajeteB)
{

			cout << "******************************************" << endl;
			cout << "Pojemnik pierwszy:" << endl;
			cout << "Nazwa:        " << nazwaA << endl;
			cout << "Jednostka:    " << jednostkaA << endl;
			cout << "Pojemnosc:    " << pojemnoscA << endl;
			cout << "Zajete:       " << zajeteA << endl;

			printf("\n\n");

			cout << "Pojemnik drugi:" << endl;
			cout << "Nazwa:        " << nazwaB << endl;
			cout << "Jednostka:    " << jednostkaB << endl;
			cout << "Pojemnosc:    " << pojemnoscB << endl;
			cout << "Zajete:       " << zajeteB << endl;
			
			cout << "******************************************" << endl;
}


		
void Bipojemnik::Dolej(double dodawanaZawartosc)
{
	try
	{
		PojemnikA.Dodaj(dodawanaZawartosc);
	}

	catch(double ex)
	{
		try
		{
			PojemnikB.Dodaj(ex);
		}

		catch(double ex2)
		{
			throw ex2;
		}
	}
	
}

void Bipojemnik::Odlej(double odejmowanaZawartosc)
{
	try
	{
		PojemnikB.Odejmij(odejmowanaZawartosc);
	}

	catch(double ex1)
	{
		try
		{
			PojemnikA.Odejmij(ex1);
		}

		catch(double ex2)
		{
			throw ex2;
		}
	}
}
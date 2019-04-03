#pragma once

#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;


struct pojemnik
{
	int jednostka;
	double pojemonosc;
	double zajete;
};

double Dodaj(struct pojemnik* struktura, double dodawanaZawartosc);
double Odbierz(struct pojemnik* struktura, double odejmowanaZawartosc);
void Wypisz(struct pojemnik struktura);

//// zad 2

class Pojemnik
{
public:
	string nazwa;
	int jednostka;
	double pojemnosc;
	double zajete;

public:
	Pojemnik(); // konstruktor bezparametrowy
	Pojemnik(string nazwa, int jednostka, double pojemnosc, double zajete); // konstruktor z parametrami

	//metody
	double Dodaj(double dodawanaZawartosc); 
	double Odejmij(double odejmowanaZawartosc);
	void Wypisz();

	// konstrutkor kopiujacy
	Pojemnik(const Pojemnik& copy);
};

//// zad3

class Bipojemnik
{
	Pojemnik PojemnikA;
	Pojemnik PojemnikB;

public:
	Bipojemnik(string nazwaA, string nazwaB, int jednostkaA,
		int jednostkaB,double pojemnoscA, double pojemnoscB,
		double zajeteA, double zajeteB);

	void Dolej(double dodawanaZawartosc);
	void Odlej(double odejmowanaZawartosc);
};

class Wyjatki 
{

};
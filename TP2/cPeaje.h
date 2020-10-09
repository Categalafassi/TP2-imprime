#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ctime>
#include "ListaTemplate.h"
using namespace std;

class cPersona;
class cVehiculo;

class cPeaje
{
	string nombre;
	float caja;
	const float preciobase = 10;
	
public:
	cPeaje(string nombre, float caja);
	void cobrar(cPersona* persona);
	float getprecio(cPersona*persona);
	string getclave();
	~cPeaje();
};


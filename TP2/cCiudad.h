#pragma once
#include <iostream>
#include <string>
#include "sCoordenadas.h"
#include "ListaTemplate.h"
#define _USE_MATH_DEFINES
#include "math.h"
using namespace std;


class cCiudad
{
	string nombre;
	int poblacion_total;
	sCoordenadas* coordenadas;
	static cListaT<cCiudad> Lista_Ciudades;
	static bool Lista_Ciudades_Poblacionada;

public: 
	cCiudad(string nombre, int poblacion_tot, float longitud, float latitud);
	cCiudad();
	~cCiudad();
	float calculardistancia(cCiudad* destino);
	string getnombre(){ return nombre; }
	string getclave();
	static cListaT<cCiudad>& getLista_ciuidades();
	static void Poblacionar_Lista();
	static int getcantCiudades();
	// cCiudad* getciudad(int pos);
	void imprimir();
    string tostring();
    friend class cCamino;
    
    void operator=(const cCiudad* otraciudad);
};


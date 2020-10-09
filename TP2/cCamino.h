#pragma once
#include <iostream>
#include <string>
#include "cCiudad.h"
#include "ListaTemplate.h"
#include "cPeaje.h"
class sCoordenadas;
class cVehiculo;
template<class cCamino> class cListaT;


class cCamino
{
	cCiudad* ciudad1;
	cCiudad* ciudad2;
	int cantpeajes;
	cListaT<cPeaje> *ListaPeajes;
    static cListaT<cCamino> Lista_Caminos;
    static bool Lista_Caminos_Poblacionada;

public:
	cCamino(cCiudad* ciudad1, cCiudad* ciudad2);
    cCamino();
	float calculardistancia();
	float preciopeajeporpeso(cVehiculo* vehiculo);
	int getcantpeajes(){ return cantpeajes;} 
	cPeaje* peaje(int pos){return ListaPeajes->getItem(pos);}
	cCiudad* getCiudad1();
	cCiudad* getCiudad2();
    static cListaT<cCamino>& getLista_caminos();
    static void Poblacionar_Lista();
    string nombrePeajeRandom(int p);
	~cCamino();
	string getclave();
	
};


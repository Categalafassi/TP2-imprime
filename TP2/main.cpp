#include <iostream>
#include <string>
#include "cCamino.h"
#include "cCiudad.h"
#include "cPeaje.h"
#include "cVehiculo.h"
#include "cPersona.h"
using namespace std;

int main()
{
	cCiudad::Poblacionar_Lista();
    //cCamino::Poblacionar_Lista();
	//cListaT<cPersona> lista_personas;
	//cListaT<cVehiculo> lista_vehiculos;

    cVehiculo* Corolla = new cVehiculo(cCiudad::getLista_ciuidades().getItem(1), 1000, 23, 2, 1000000, "toyota", "2020", "corolla", 44, "ASD 443");
    cPersona* Mario = new cPersona(Corolla, cCiudad::getLista_ciuidades().getItem(0), 1000, 42724595, "Mario Casas", 15, 6, 1990);
    cVehiculo* Prius = new cVehiculo(cCiudad::getLista_ciuidades().getItem(0), 900, 23, 5, 10000, "toyota", "2016", "prius", 44, "ZZS 443");
    cPersona* Blanca = new cPersona(Prius, cCiudad::getLista_ciuidades().getItem(0), 1000, 43729595, "Blanca Suarez", 15, 6, 1990);
    cPersona* Mia = new cPersona(NULL, cCiudad::getLista_ciuidades().getItem(0), 90000, 20983832, "Mia Perez", 12, 8, 1987);
    
    Blanca->vendervehiculo(Mia);

    Mario->imprimir();
    Corolla->imprimir();
    
    Mia->viajar(cCiudad::getLista_ciuidades().getItem(1));
    Blanca->viajar(cCiudad::getLista_ciuidades().getItem(3));//No puede viajar porque no tiene auto
    Mario->viajar(cCiudad::getLista_ciuidades().getItem(2));

	return 0;
}

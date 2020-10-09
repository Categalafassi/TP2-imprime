#pragma once 
#include <iostream>
#include <string>
#include "math.h"
#include "cCiudad.h"
#include "cCamino.h"
#include "ListaTemplate.h"

#define PRECIONAFTA 50 //precio por litro

using namespace std;
template<class cCiudad> class cListaT;

class cVehiculo
{

	cListaT<cCiudad>* Lista_Ciudades_Fav;
	cCiudad* ubicacion_actual;
	int dist_recorrida;
	const int dist_mantenimiento;
	const int capacidad_tanque; //en litros
	const int consumo; //cant de nafta que consume c/100km
	float precio;
	const string modelo, marca, anio_lanzamiento;
	int nafta_actual;
	float precionafta; //por litro
	int cantaire; //presion actual de las ruedas, se expresa en libra por pulgada cuadrada
	int capmaxaire; //capacidad maxima de presion para las ruedas 
    string  patente;
	int peso;
	
public: 
	cVehiculo(cCiudad* ubicacionactual, const int dist_mantenimiento, const int capacidad_tanque, const int consumo,float prec, const string marca, const string anio, const string modelo, int capacidadmax, string patente);
	cVehiculo();
	cVehiculo(const cVehiculo& otro);
	float recargartanque(int cantnafta);
	float viajar(cCiudad* detino); //devuelve el precio del viaje para despues cobrarle a la persona
	float mantenimiento();//mantenimiento cada dist_mantenimiento
	cCamino* buscarCamino(cCiudad* destino);
	float precionaftaviaje(cCamino* camino);


	string tostring();
	void imprimir();
	string getmodelo();
	string getpatente();
	int getprecio();
	string getanio();
	int getpeso();
	//void setciudadesfav(string nombre);
	string getclave();
	cCiudad* getUbicacionActual(){return ubicacion_actual;}

	~cVehiculo();

};


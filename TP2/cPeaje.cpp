#include "cPeaje.h"
#include "cPersona.h"
#include "cVehiculo.h"

cPeaje::cPeaje(string nombre, float caja)
{
	this->nombre = nombre;
	this->caja = caja;
}

float cPeaje::getprecio(cPersona* persona){
	
	float precio=preciobase;//cobro minimo
	time_t timestamp;
	tm* t = localtime(&timestamp);
	
    if((t->tm_hour>17 && t->tm_hour<21) || (t->tm_hour>11 && t->tm_hour<15)){
		precio=20;//hora pico
	}
	//si pesa menos de 1500 no multiplico por nada, queda el mismo precio
	if (persona->getvehiculo()->getpeso() > 1500 && persona->getvehiculo()->getpeso() < 1801){
		precio*=1.2;
	}
	if (persona->getvehiculo()->getpeso() > 1800){
		precio*=1.5;
	}

	return precio;
}

string cPeaje::getclave()
{
	return nombre;
}

void cPeaje::cobrar(cPersona* persona)
{	
	//Asegurarse antes de usar la funcion que a la persona le alcance la plata
	float precio = getprecio(persona);
	persona->cobrar(precio);
	caja+=precio;

	return;
}

cPeaje::~cPeaje()
{
}

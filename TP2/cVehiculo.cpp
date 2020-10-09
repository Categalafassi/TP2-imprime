#include "cVehiculo.h"
#include "cCamino.h"


cVehiculo::cVehiculo(cCiudad* ubicacionactual, const int dist_mantenimiento, const int capacidad_tanque, const int consumo, float prec, const string marca, const string anio, const string modelo, int capacidadmax, string patente):
	dist_mantenimiento(dist_mantenimiento), capacidad_tanque(capacidad_tanque), consumo(consumo), marca(marca), anio_lanzamiento(anio), modelo(modelo)
{   
	if (capacidadmax < 0)
		capmaxaire = 30; // si me pasan un parametro invalido la cap maxima de presion en las rudas sera 30
	else capmaxaire = capacidadmax;
	cantaire = capacidadmax; 
	this->ubicacion_actual = ubicacionactual;
	precio = prec;
	nafta_actual = capacidad_tanque;
	dist_recorrida = 0;
	this->patente = patente;
	peso=rand()%1001+1000;//Peso entre 1000 y 2000;
	Lista_Ciudades_Fav = new cListaT<cCiudad>;
    Lista_Ciudades_Fav->AgregarItem(ubicacionactual);
	precionafta=PRECIONAFTA;
}

cVehiculo::cVehiculo():
dist_mantenimiento(0), capacidad_tanque(0), consumo(0), marca(" "), anio_lanzamiento("2020"), modelo(" "){
    
    capmaxaire = 0;
    cantaire = 0;
    ubicacion_actual = new cCiudad();
    precio = 0;
    nafta_actual = 0;
    dist_recorrida = 0;
    patente=" ";
    peso=rand()%1001+1000;//Peso entre 1000 y 2000;
    precionafta = PRECIONAFTA;

}

cVehiculo::cVehiculo(const cVehiculo& otro): cVehiculo(otro.ubicacion_actual, otro.dist_mantenimiento, otro.capacidad_tanque, otro.consumo,
	otro.precio, otro.marca, otro.anio_lanzamiento, otro.modelo, otro.capmaxaire, otro.patente)
{
	precionafta=PRECIONAFTA;
}

cVehiculo::~cVehiculo()
{
	ubicacion_actual = NULL;
}

string cVehiculo::tostring(){

	return ("Ubicacion Actual: "+ ubicacion_actual->tostring( )+"\nDistancia recorrida: "+to_string(dist_recorrida)+"\nCapacidad del tanque"+to_string(capacidad_tanque)+"\nConsumo: "+to_string(consumo)+"\nPrecio: "+to_string(precio)+"\nModelo: "+modelo+"\nMarca: "+marca+"\nAnio de lanzamiento: "+anio_lanzamiento)+"\n";

}

void cVehiculo::imprimir(){
	cout<<this->tostring();
	return;
}

string cVehiculo::getmodelo()
{
	return modelo;
}

string cVehiculo::getpatente()
{
	return patente;
}

int cVehiculo::getprecio()
{
	return precio;
}

string cVehiculo::getanio()
{
	return anio_lanzamiento;
}

int cVehiculo::getpeso()
{
	return peso;
}

//void cVehiculo::setciudadesfav(string nombre)
//{
//   // Lista_Ciudades_Fav->AgregarItem(cCiudad::getLista_ciuidades().BuscarItem(nombre));
//    return;
//}

string cVehiculo::getclave()
{
	return patente;
}

float cVehiculo::recargartanque(int cantnafta){
	
	if(cantnafta<0 || cantnafta>(capacidad_tanque-nafta_actual)) {
		//si es un numero negativo o la cantidad haria que supere la capacidad
		cout<<"//Cantidad invalida//"<<endl;
		return 0;
	}
	else nafta_actual += cantnafta; 

	return cantnafta*precionafta;
}

float cVehiculo::mantenimiento(){
	
	cout << "----- Realizando Mantenimiento---- \n inflando neumaticos y recargando tanque..." << endl;
	
	if (cantaire < capmaxaire)
		cantaire = capmaxaire; // vuelvo a inflar los neumaticos 
	return recargartanque(capacidad_tanque-nafta_actual); //llenar tanque y devolver el precio
}

float cVehiculo::viajar(cCiudad*destino){


	float distancia = ubicacion_actual->calculardistancia(destino);
	float precioviaje=0;
	
	cout<<"-- Viajando de "<<ubicacion_actual->getnombre()<<" a "<<destino->getnombre()<<" --"<<endl;
	for(int i=0; i<=distancia; i++){ 
		
		dist_recorrida++;
		
		if(dist_recorrida%100==0){
			nafta_actual-=consumo;//consumo de nafta cada 100km
			cantaire --; // a medida que el auto viaja se disminuye la presion en sus neumaticos
		}
		if( dist_recorrida%dist_mantenimiento == 0 || cantaire==0){
			//mantenimiento cada dist_mantenimiento o cuando las ruedas se quedan sin aire
			precioviaje+=mantenimiento();
		}
		if(nafta_actual==0){
			precioviaje+=recargartanque(capacidad_tanque);
		}

	}
	cout<<"Llegando a "<<destino->getnombre()<<endl;
    ubicacion_actual=destino;
	cout<<endl;
	return precioviaje;
}

cCamino* cVehiculo::buscarCamino(cCiudad* destino){

    cCamino* camino= new cCamino();

    for(int i=0; i< cCamino::getLista_caminos().getCA(); i++){

        camino= cCamino::getLista_caminos().getItem(i); //busco en la lista de caminos el que tiene las dos ciudades

        if((camino->getCiudad1()==ubicacion_actual && camino->getCiudad2()==destino) || (camino->getCiudad1()==destino && camino->getCiudad2()== ubicacion_actual) )
            return camino;

    }

    return NULL;
}


float cVehiculo::precionaftaviaje(cCamino* camino){

	float naftanecesaria = consumo*(camino->calculardistancia()/100); //nafa necesaria para realizar el viaje
	float canttanquecompleto = capacidad_tanque/(naftanecesaria-nafta_actual); //cantidad de veces que va a haber que cargar el tanque en el viaje

	return capacidad_tanque*precionafta*canttanquecompleto;

}

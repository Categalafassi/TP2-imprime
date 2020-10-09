#include "cPersona.h"

cPersona::cPersona(cVehiculo* vehiculo_personal, cCiudad* ciudad_or, float plata_actual, int dni, string nombre_apellido, int dia, int mes, int anio)
: ciudad_origen(ciudad_or), DNI(dni), nya(nombre_apellido) {
	this-> plata_actual=plata_actual;
	vehiculo = vehiculo_personal;
	fecha_nacimiento = new sFecha(dia,mes,anio);
}

cPersona::cPersona()
: ciudad_origen(new cCiudad()), DNI(00000000), nya(" "){
    plata_actual = 0;
    vehiculo = NULL;
    fecha_nacimiento = new sFecha (1,1,2020);
}

void cPersona::vendervehiculo(cPersona* cliente)
{
	if (cliente->getplata_actual() < vehiculo->getprecio())
	{
		cout << "no tiene dinero suficiente para pagar el vehiculo" << endl;
		return;
	}
	else {
		cliente->cambiarvehiculo(vehiculo);// el cliente obtiene su auto nuevo
		cliente->cobrar(vehiculo->getprecio()); // el cliente pierde dinero por su compra 
		setplata_actual(plata_actual + vehiculo->getprecio()); // el due�o obtiene el dinero del auto
		vehiculo = NULL;
	}
	return;
}

void cPersona::cobrar(float precio){

	plata_actual-=precio;
	return;
}

void cPersona::cambiarvehiculo(cVehiculo* compra)
{
	vehiculo = compra;
	return;

}

cVehiculo* cPersona::getvehiculo()
{
	return vehiculo;
}

int cPersona::getplata_actual()
{
	return plata_actual;
}

void cPersona::setplata_actual(int p)
{
	plata_actual = p;
	return;
}

string cPersona::getclave()
{
	string aux = to_string(DNI);
	return aux;
}

string cPersona::tostring()
{

    return "NOMBRE Y APELLIDO:"+nya+"\nDNI" + to_string(DNI)+ fecha_nacimiento->tostring()+ "\nciudad de origen: " +ciudad_origen->getnombre() +"\nModelo del auto: " + vehiculo->getmodelo() + " patente: "+vehiculo->getpatente() + " anio de lanzamiento:"+ vehiculo->getanio()+"\n";
}

void cPersona::imprimir()
{
    cout << this->tostring()<<endl;
}

void cPersona::viajar(cCiudad* destino)
{
    if(vehiculo==NULL){
        cout<<"(!)"<<this->nya<<" no tiene un vehiculo"<<endl;
        return;
    }
    
	if(destino == vehiculo->getUbicacionActual()){
		cout<<"(!)"<<this->nya<<" ya se encuentra en esta ciudad"<<endl;
		return;
	}

    cCamino* camino = vehiculo->buscarCamino(destino);
    if(camino==NULL){
        cout<<"(!) No existe un camino que conecte estas ciudades"<<endl;
        return;
    }

	while((camino->preciopeajeporpeso(vehiculo)*10)+platanafta(camino)<plata_actual){
		//trabajar hasta tener plata para 10 peajes y la nafta
		trabajar();
	}

	for(int i =0; i<camino->getcantpeajes(); i++){
		camino->peaje(i)->cobrar(this);
	}
	cobrar(vehiculo->viajar(destino));
	return;
}

cPersona::~cPersona()
{
	vehiculo = NULL; 
	fecha_nacimiento = NULL;
	ciudad_origen = NULL;
	delete fecha_nacimiento;
}

void cPersona::trabajar(){
	plata_actual+=100;
}

float cPersona::platanafta(cCamino* camino){

	return vehiculo->precionaftaviaje(camino);

}

#include "cCamino.h"
#include "cPeaje.h"
#include "cCiudad.h"
#include "sCoordenadas.h"
#include "cVehiculo.h"
#define R_tierra 6371
cListaT<cCamino> cCamino::Lista_Caminos;
bool cCamino::Lista_Caminos_Poblacionada = false;


cCamino::cCamino(cCiudad* ciudad1, cCiudad* ciudad2)
{this->ciudad1 = ciudad1;
	this->ciudad2 = ciudad2;
    cantpeajes = rand() % (int)calculardistancia() / 50;
    ListaPeajes = new cListaT<cPeaje>(cantpeajes);
    for (int i = 0; i < cantpeajes; i++)
    {
        ListaPeajes->AgregarItem(new cPeaje(nombrePeajeRandom(i), rand()% 100));

    }
}

cCamino::cCamino(){
    ciudad1=NULL;
    ciudad2=NULL;
    cantpeajes=0;
    ListaPeajes=NULL;
    return;
}

float cCamino::calculardistancia() {

    float lat1, lat2, long1, long2;
    float a = 0, c = 0, dif_long = 0, dif_lat = 0;

    lat1 = ciudad1->coordenadas->getLatitud();
    lat2 = ciudad2->coordenadas->getLatitud();
    long1 = ciudad1->coordenadas->getLongitud();
    long2 = ciudad2->coordenadas->getLongitud();


    dif_long = (long2 - long1) * M_PI / 180;
    dif_lat = (lat2 - lat1) * M_PI / 180;

    lat1 = (lat1)*M_PI / 180;
    lat2 = (lat2)*M_PI / 180;
    long1 = (long1)*M_PI / 180;
    long2 = (long2)*M_PI / 180;

    a = pow(sin(dif_lat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dif_long / 2), 2);

    c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return R_tierra * c;

}

float cCamino::preciopeajeporpeso(cVehiculo* vehiculo){
  
   //calcular precio aproximado de los peajes para saber si a la persona le va a alcanzar la plata
    float precio = 20; 
 
    if (vehiculo->getpeso() > 1500 && vehiculo->getpeso() < 1801){
		precio*=1.2;
	}
	if (vehiculo->getpeso() > 1800){
		precio*=1.5;
	}

   return precio;
}

cCiudad* cCamino::getCiudad1(){
    return ciudad1;
}
cCiudad* cCamino::getCiudad2(){
    return ciudad2;
}

cListaT<cCamino>& cCamino::getLista_caminos()
{
    return Lista_Caminos;
}

void cCamino::Poblacionar_Lista()
{
    if (!Lista_Caminos_Poblacionada) {
        cListaT<cCiudad> lista_ciudades = cCiudad::getLista_ciuidades();

        for (int i = 0; i < cCiudad::getLista_ciuidades().getCA(); i++) {
            for (int j = i + 1; j < cCiudad::getLista_ciuidades().getCA() - 1; j++)
                Lista_Caminos.AgregarItem(new cCamino(lista_ciudades.getItem(i), lista_ciudades.getItem(j)));
        }
    }
    Lista_Caminos_Poblacionada = true;
    return;
}

cCamino::~cCamino()
{
    if (!Lista_Caminos.IsDeleting())
        Lista_Caminos.Quitar(this);
}

string cCamino::getclave()
{
    return ciudad1->getnombre();
}

string cCamino::nombrePeajeRandom(int p){
   
        switch (p) {
            case 1:
                return "del sol";
                break;
            case 2:
                return "Caminos";
                break;
            case 3:
                return "Las palomas";
                break;
            case 4:
                return "Los Pinos";
                break;
            case 5:
                return "Ruta";
                break;
            case 6:
                return "Nubes";
                break;
            case 7:
                return "Almirante Brown";
                break;
            case 8:
                return "Buenavista";
                break;
            case 9:
                return "El mar";
                
            default:
                return "Los Ojos";
                break;
        }
        
        
}

    
    


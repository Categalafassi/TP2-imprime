#include "cCiudad.h"
#include "sCoordenadas.h"

#define R_tierra 6371 //km
cListaT<cCiudad> cCiudad::Lista_Ciudades;
bool cCiudad::Lista_Ciudades_Poblacionada = false;
cCiudad::cCiudad(string nombre, int poblacion_tot, float longitud, float latitud)
: nombre(nombre){
    coordenadas = new sCoordenadas(longitud, latitud);
    poblacion_total = poblacion_tot;
}

cCiudad::cCiudad()
: nombre(" ") {
   
    coordenadas = new sCoordenadas();
    poblacion_total=0;

}

cCiudad::~cCiudad()
{
    
    if (!Lista_Ciudades.IsDeleting())
        Lista_Ciudades.Quitar(this);
}

float cCiudad::calculardistancia(cCiudad* destino){
	
	float lat1, lat2, long1, long2;
	float a=0, c=0, dif_long=0, dif_lat=0;
   
    lat1=coordenadas->getLatitud();
    lat2=destino->coordenadas->getLatitud();
    long1=coordenadas->getLongitud();
    long2=destino->coordenadas->getLongitud();
    
    
    dif_long = (long2-long1)*M_PI/180;
    dif_lat = (lat2-lat1)*M_PI/180;
    
    lat1=(lat1)*M_PI/180;
    lat2=(lat2)*M_PI/180;
    long1=(long1)*M_PI/180;
    long2=(long2)*M_PI/180;
    
	a = pow(sin(dif_lat/2),2) + cos(coordenadas->getLatitud()) * cos(destino->coordenadas->getLatitud()) * pow(sin(dif_long/2),2);

	c = 2*atan2(sqrt(a),sqrt(1-a) );

	return R_tierra * c;

}

string cCiudad::getclave()
{
    return nombre;
}

cListaT<cCiudad>& cCiudad::getLista_ciuidades()
{
    return Lista_Ciudades;
}

void cCiudad::Poblacionar_Lista()
{
    if (!Lista_Ciudades_Poblacionada)// bool se usa para que se pueda llamar solo una vez al metodo
    {
        Lista_Ciudades.AgregarItem(new cCiudad("buenos aires", 300000, -34.5988, -58.4722));
        Lista_Ciudades.AgregarItem(new cCiudad("bahia blanca", 299101, -38.716666, -62.266));
        Lista_Ciudades.AgregarItem(new cCiudad("rosario", 948312, -32.957, -60.639));
        Lista_Ciudades.AgregarItem(new cCiudad("baradero", 28537, -33.8, -59.516));
        Lista_Ciudades.AgregarItem(new cCiudad("mar del plata", 65645, -38.004, -57.548));
        Lista_Ciudades_Poblacionada = true;
    }
}

void cCiudad::imprimir()
{
    cout << this->tostring() << endl;
}

string cCiudad::tostring(){
    return "nombre: "+nombre+"\n poblacion total: "+to_string(poblacion_total);
}

int cCiudad::getcantCiudades(){
    return Lista_Ciudades.getCA();
}


void cCiudad::operator=(const cCiudad* otraciudad){
  
    this->nombre=otraciudad->nombre;
    this->poblacion_total= otraciudad->poblacion_total;
    this-> coordenadas = otraciudad->coordenadas;
    
}

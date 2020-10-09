#include "sCoordenadas.h"

sCoordenadas::sCoordenadas(float lat, float longitud)
{
	latitud = lat;
	this->longitud = longitud;
}

sCoordenadas::sCoordenadas(){

	latitud=0;
	longitud=0;

}

sCoordenadas::~sCoordenadas()
{
}

string sCoordenadas::tostring(){

	return  ("-Coordenadas-\n Latitud:" +to_string(latitud)+"  Longitud:"+to_string(longitud));

}
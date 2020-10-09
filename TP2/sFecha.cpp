#include "sFecha.h"

sFecha::sFecha(int d, int m, int a)
{
	dia = d;
	mes = m;
	anio = a;
}

sFecha::~sFecha()
{
}

string sFecha::tostring()
{
    return to_string(dia) +"/"+to_string(mes)+ "/"+to_string(anio);
}

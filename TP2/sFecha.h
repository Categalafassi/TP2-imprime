#pragma once
#include <iostream>
using namespace std;
class sFecha
{
	int dia, mes, anio;
public:
	sFecha(int d, int m, int a);
	~sFecha();
    string tostring();
};


#pragma once
#define NMAX 10
#include <iostream>
#include <string>
using namespace std;

template<class T>
class cListaT
{
protected:
	T **vector;
	unsigned int CA, TAM;
	bool eliminado = false;

public:
	cListaT(unsigned int TAM = NMAX);
	~cListaT();

	bool AgregarItem(T *item);

	 T* Quitar(T *item);
	 T* QuitarenPos(unsigned int pos);
	 bool IsDeleting();
	 void Eliminar(string clave);
	

	void Listar();
	T* BuscarItem(string clave);
	T* getItem(unsigned int pos);

	unsigned int getItemPos(string clave);

	unsigned int getCA();
	unsigned int getTAM();
};

template<class T>
unsigned int cListaT<T>::getTAM()
{
	return TAM;
}
template<class T>
unsigned int cListaT<T>::getCA()
{
	return CA;
}

template<class T>
cListaT<T>::cListaT(unsigned int TAM)
{
	vector = new T*[TAM];
	for (unsigned int i = 0; i < TAM; i++)
	{
		vector[i] = NULL;
	}

	this->TAM = TAM;
	CA = 0;

}
template<class T>
cListaT<T>::~cListaT()
{
	eliminado = true;
	if (vector != NULL)
	{
		for (unsigned int i = 0; i < CA; i++)
		{
			if (vector[i] != NULL)
				delete vector[i];
		}
		delete[] vector;
	}


}

 template<class T>
 void cListaT<T>::Listar()
 {

 	for (unsigned int i = 0; i < CA; i++)
 	{
 		vector[i]->imprimir();
 	}
 }

template<class T>
bool cListaT<T>::AgregarItem(T * item)
{ 
	T *i_f = BuscarItem(item->getclave());
  	if (i_f != NULL){
        cout<<"Este elemento ya se encuentra en la lista"<<endl;
        return false;
    }

	if (CA < TAM){
		vector[CA++] = item;
		return true;
	}
    else {
        cout<<"No hay tamanio suficiente para agregar el item"<<endl;
        return false;
    }
	return true;
}

template<class T>
 T* cListaT<T>::Quitar( T *item) {
 	unsigned int pos = getItemPos(item->getclave());
 	if (pos >= CA)return NULL;
 	return QuitarenPos(pos);
 }

 template<class T>
 T* cListaT<T>::QuitarenPos(unsigned int pos) {

	 if (pos >= CA){
         cout<<"Posicion invalida"<<endl;
         return NULL;
     }

	 T* aux = vector[pos];

	 for (unsigned int i = 0; i < CA - 1; i++)
	 {
		 vector[i] = vector[i + 1];
	 }

	 vector[CA - 1] = NULL;
	 CA--;
	 return aux;
 }


 template<class T>
 inline bool cListaT<T>::IsDeleting()
 {
	 return eliminado;
 }

template<class T>
void cListaT<T>::Eliminar(string clave) {

 	unsigned int pos = getItemPos(clave);

 	if (pos < CA)
 		Eliminar(pos);


 }

template<class T>
T* cListaT<T>::BuscarItem(string clave)
{
	for (unsigned int i = 0; i < CA; i++)
	{
		if (vector[i]->getclave() == clave)
			return vector[i];
	}
	return NULL;
}

template<class T>
T* cListaT<T>::getItem(unsigned int pos)
{
	if (pos < CA)
		return vector[pos];
	else return NULL;
}
template<class T>
unsigned int cListaT<T>::getItemPos(string clave)
{
	for (unsigned int i = 0; i < CA; i++)
	{
		if (vector[i]->getclave() == clave)
			return i;
	}

	return INT_MAX;
}


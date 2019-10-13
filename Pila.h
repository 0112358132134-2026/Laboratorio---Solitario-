#pragma once
#include "Carta.h"
using namespace System;

ref class Pila
{
private:
	Carta^ primera;
public:
	String^ peek();
	void MeterCarta(String^ valor);
	String^ SacarCarta();
	bool vacio();
	//void limpiar();	
};


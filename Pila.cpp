#include "pch.h"
#include "Pila.h"

void Pila::MeterCarta(String^ valor)
{
	Carta^ nuevaCarta = gcnew Carta;
	nuevaCarta->valor = valor;
	nuevaCarta->siguiente = primera;
	primera = nuevaCarta;
}

String^ Pila::SacarCarta()
{
	if (vacio())
	{
		return "Está vacia la pila.";
	}
	else
	{
		String^ valorR = primera->valor;
		Carta^ borrar = primera;
		primera = primera->siguiente;
		delete borrar;
		return valorR;
	}
}

bool Pila::vacio()
{
	return primera == nullptr;
}

String^ Pila::peek()
{
	if (!vacio())
	{
		return primera->valor;
	}
	else
	{
		return "Esta vacio.";
	}
}
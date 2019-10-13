#include "pch.h"
#include "Pila.h"
#include "ctime"
#include "cstdlib"

using namespace System;

int main(array<System::String ^> ^args)
{
	Console::BackgroundColor = ConsoleColor::Red;
	Console::ForegroundColor = ConsoleColor::White;
	Console::Clear();
	srand(time(NULL));
	Pila^ mazo = gcnew Pila;
	Pila baraja1;
	Pila baraja2;
	Pila baraja3;
	Pila baraja4;

	bool generarMazo = false;
	while (generarMazo == false)
	{
		String^ generar;
		Console::WriteLine("¿Empezar a generar mazo? (Si/No)");
		generar = Console::ReadLine();
		if (generar == "Si" || generar == "SI")
		{
			generarMazo = true;
		}
	}
	
	for (int i = 1; i <= 2; i++)
	{
		for (int c1 = 1; c1 <= 13; c1++)
		{
			mazo->MeterCarta(c1.ToString() + "-R");
		}
		for (int c2 = 1; c2 <= 13; c2++)
		{
			mazo->MeterCarta(c2.ToString() + "-N");
		}
	}
	Console::WriteLine("¡Mazo generado con éxito!");
	Console::WriteLine("¡Presione alguna tecla para continuar!");
	Console::ReadKey();
	Console::Clear();
	
	bool repartir = false;
	while (repartir == false)
	{
		String^ generar;
		Console::WriteLine("¿Quiere empezar a repartir cartas para revolverlas? (Si/No)");
		generar = Console::ReadLine();
		if (generar == "Si" || generar == "SI")
		{
			repartir = true;
		}
	}
	Console::WriteLine();

	while (mazo->vacio() == false)
	{
		int contador = 1;
		int num = rand() % 4;
		switch (num)
		{
		case 0:
			baraja1.MeterCarta(mazo->SacarCarta());
			Console::WriteLine("Ingresado a baraja 1 carta: ");
			Console::WriteLine(baraja1.peek() + "\n");
			break;
		case 1:
			baraja2.MeterCarta(mazo->SacarCarta());
			Console::WriteLine("Ingresado a baraja 2 carta: ");
			Console::WriteLine(baraja2.peek() + "\n");
			break;
		case 2:
			baraja3.MeterCarta(mazo->SacarCarta());
			Console::WriteLine("Ingresado a baraja 3 carta: ");
			Console::WriteLine(baraja3.peek() + "\n");
			break;
		case 3:
			baraja4.MeterCarta(mazo->SacarCarta());
			Console::WriteLine("Ingresado a baraja 4 carta: ");
			Console::WriteLine(baraja4.peek() + "\n");
			break;
		default:
			break;
		}
		contador += 1;
	}
	Console::WriteLine("¡Cartas repartidas con éxito!");
	Console::WriteLine("¡Presione alguna tecla para continuar!");
	Console::ReadKey();
	Console::Clear();

	bool devolveraMazo = false;
	while (devolveraMazo == false)
	{
		String^ generar;
		Console::WriteLine("¿Quieres devolverlas al mazo y repartir cartas en 7 barajas para comenzar a jugar? (Si / No)");
		generar = Console::ReadLine();
		if (generar == "Si" || generar == "SI")
		{
			devolveraMazo = true;
		}
	}

	while (baraja1.vacio() == false)
	{
		mazo->MeterCarta(baraja1.SacarCarta());
	}
	while (baraja2.vacio() == false)
	{
		mazo->MeterCarta(baraja2.SacarCarta());
	}while (baraja3.vacio() == false)
	{
		mazo->MeterCarta(baraja3.SacarCarta());
	}while (baraja4.vacio() == false)
	{
		mazo->MeterCarta(baraja4.SacarCarta());
	}

	Pila NuevaBaraja1;
	Pila NuevaBaraja2;
	Pila NuevaBaraja3;
	Pila NuevaBaraja4;
	Pila NuevaBaraja5;
	Pila NuevaBaraja6;
	Pila NuevaBaraja7;

	for (int i = 0; i < 1; i++)
	{
		NuevaBaraja1.MeterCarta(mazo->SacarCarta());
	}
	for (int i = 0; i < 2; i++)
	{
		NuevaBaraja2.MeterCarta(mazo->SacarCarta());
	}
	for (int i = 0; i < 3; i++)
	{
		NuevaBaraja3.MeterCarta(mazo->SacarCarta());
	}
	for (int i = 0; i < 4; i++)
	{
		NuevaBaraja4.MeterCarta(mazo->SacarCarta());
	}
	for (int i = 0; i < 5; i++)
	{
		NuevaBaraja5.MeterCarta(mazo->SacarCarta());
	}
	for (int i = 0; i < 6; i++)
	{
		NuevaBaraja6.MeterCarta(mazo->SacarCarta());
	}
	for (int i = 0; i < 7; i++)
	{
		NuevaBaraja7.MeterCarta(mazo->SacarCarta());
	}

	//Acá meto el resto de lo que quedaba en el mazo
	Pila Mazo;
	while (mazo->vacio() == false)
	{
		Mazo.MeterCarta(mazo->SacarCarta());
	}
	//

	Console::WriteLine("¡Listo!");
	Console::WriteLine("¡Presione alguna tecla para continuar!");
	Console::ReadKey();
	Console::Clear();

	bool comenzar = false;
	while (comenzar == false)
	{
		String^ aceptar;
		Console::WriteLine("Presione R para mostrar barajas:");
		aceptar = Console::ReadLine();
		if (aceptar == "R" || aceptar == "r")
		{
			comenzar = true;
		}
	}

	String^ carta;
	String^ color;
	//
	String^ numBaraja;
	String^ numMano;
	String^ numMano1;
	//
	int cartaTomada = 0;
	int contadorGanador1 = 0;
	int contadorGanador2 = 0;
	int contadorGanador3 = 0;
	int contadorGanador4 = 0;
	int contadorGanador5 = 0;
	int contadorGanador6 = 0;
	int contadorGanador7 = 0;

	Pila^ GuardarCarta = gcnew Pila;
	Console::WriteLine("... \n");
	bool ganaste = false;
	while (ganaste == false)
	{
		Console::Write("Baraja 1 ----------- ");
		Console::WriteLine(NuevaBaraja1.peek());
		Console::Write("Baraja 2 ----------- ");
		Console::WriteLine(NuevaBaraja2.peek());
		Console::Write("Baraja 3 ----------- ");
		Console::WriteLine(NuevaBaraja3.peek());
		Console::Write("Baraja 4 ----------- ");
		Console::WriteLine(NuevaBaraja4.peek());
		Console::Write("Baraja 5 ----------- ");
		Console::WriteLine(NuevaBaraja5.peek());
		Console::Write("Baraja 6 ----------- ");
		Console::WriteLine(NuevaBaraja6.peek());
		Console::Write("Baraja 7 ----------- ");
		Console::WriteLine(NuevaBaraja7.peek());
		Console::Write("Mazo 8 ------------- ");
		Console::WriteLine(Mazo.peek());
		Console::WriteLine("Preciona 9 para salir. \n");

		bool tomado = false, ingresado = false;
		while (tomado == false)
		{
			int opcion1 = 0;
			Console::WriteLine("¿Eliga la baraja de la que desea mover la carta?");
			opcion1 = int::Parse(Console::ReadLine());
			switch (opcion1)
			{
			case 1:
				if (NuevaBaraja1.vacio() == false)
				{
					GuardarCarta->MeterCarta(NuevaBaraja1.SacarCarta());
					tomado = true;
					//
					cartaTomada = 1;
				}
				else
				{
					Console::WriteLine("Esta baraja está vacía, elije otra.");
				}
				break;
			case 2:
				if (NuevaBaraja2.vacio() == false)
				{
					GuardarCarta->MeterCarta(NuevaBaraja2.SacarCarta());
					tomado = true;
					cartaTomada = 2;
				}
				else
				{
					Console::WriteLine("Esta baraja está vacía, elije otra.");
				}
				break;
			case 3:
				if (NuevaBaraja3.vacio() == false)
				{
					GuardarCarta->MeterCarta(NuevaBaraja3.SacarCarta());
					tomado = true;
					cartaTomada = 3;
				}
				else
				{
					Console::WriteLine("Esta baraja está vacía, elije otra.");
				}
				break;
			case 4:
				if (NuevaBaraja4.vacio() == false)
				{
					GuardarCarta->MeterCarta(NuevaBaraja4.SacarCarta());
					tomado = true;
					cartaTomada = 4;
				}
				else
				{
					Console::WriteLine("Esta baraja está vacía, elije otra.");
				}
				break;
			case 5:
				if (NuevaBaraja5.vacio() == false)
				{
					GuardarCarta->MeterCarta(NuevaBaraja5.SacarCarta());
					tomado = true;
					cartaTomada = 5;
				}
				else
				{
					Console::WriteLine("Esta baraja está vacía, elije otra.");
				}
				break;
			case 6:
				if (NuevaBaraja6.vacio() == false)
				{
					GuardarCarta->MeterCarta(NuevaBaraja6.SacarCarta());
					tomado = true;
					cartaTomada = 6;
				}
				else
				{
					Console::WriteLine("Esta baraja está vacía, elije otra.");
				}
				break;
			case 7:
				if (NuevaBaraja7.vacio() == false)
				{
					GuardarCarta->MeterCarta(NuevaBaraja7.SacarCarta());
					tomado = true;
					cartaTomada = 7;
				}
				else
				{
					Console::WriteLine("Esta baraja está vacía, elije otra.");
				}
				break;
		     case 8:
				 //Si el usuario elige que desea mover el mazo 8, que en este caso 
				 //es el "mazo"... Le preguntará si desea quedarse con esa carta o 
				 //si quiere tomar otra. Cuando tome la que desee, ya podrá elegir
				 //a que baraja la desea ingresar. Y las barajas ya sacadas anteriormente
				 //regresaran al mazo.
				if (Mazo.vacio() == false)
				{
					String^ SiNoo;
					bool Sino = false;
					while (Sino == false)
					{
						Console::WriteLine("¿Desea tomar otra carta?");
						SiNoo = Console::ReadLine();
						if ((SiNoo == "No") || (SiNoo == "no"))
						{
							Console::WriteLine();
							GuardarCarta->MeterCarta(Mazo.SacarCarta());
							Sino = true;
							tomado = true;
						}
						else
						{
							if ((SiNoo == "Si") || (SiNoo == "si"))
							{
								GuardarCarta->MeterCarta(Mazo.SacarCarta());
								Console::WriteLine();
								Console::WriteLine("La carta que tienes ahora es: " + Mazo.peek());
								Sino = false;
							}
						}
					}
					cartaTomada = 8;
				}
				break;
			 case 9:
				 //
				 //Metodo para salir.
				 String^ confirmar;
				 Console::WriteLine("¿Desea terminar el juego?");
				 confirmar = Console::ReadLine();
				 if (confirmar == "Si" || confirmar == "si")
				 {
					 ganaste = true;
					 tomado = true;
					 ingresado = true;
					 cartaTomada = 9;
				 }
				 else
				 {
					 if (confirmar == "No" || confirmar == "no")
					 {
						 tomado = true;
						 ingresado = true;
					 }
				 }
				 //
				 //
				 break;
			default:
				Console::WriteLine("Esa baraja no existe.");
				break;
			}
		}
		while (ingresado == false)
		{
			int opcion2 = 0;
			Console::WriteLine("¿Eliga la baraja a la que desea ingresar la carta elegida?");
			opcion2 = int::Parse(Console::ReadLine());
			switch (opcion2)
			{
			case 1:
				carta = NuevaBaraja1.peek();
				color = carta->Substring(carta->Length - 1);
				numMano = GuardarCarta->peek();
				ingresado = true;
				if (color != GuardarCarta->peek()->Substring(GuardarCarta->peek()->Length - 1))
				{
					if (NuevaBaraja1.vacio() == false)
					{
						numBaraja = carta->Substring(0, carta->Length - 2);
						int num1 = Int32::Parse(numBaraja);
						numMano1 = numMano->Substring(0, numMano->Length - 2);
						int num2 = Int32::Parse(numMano1);
						if (num1 == num2 + 1)
						{
							contadorGanador1 += 1;
						}
					}	
					NuevaBaraja1.MeterCarta(GuardarCarta->SacarCarta());
					//Regreso de lo que tenia en maso.
					while (GuardarCarta->vacio() == false)
					{
						Mazo.MeterCarta(GuardarCarta->SacarCarta());
					}
				}
				else
				{
					Console::WriteLine("Error, no puedes poner eso ahí.");
					switch (cartaTomada)
					{
						case 1:
							NuevaBaraja1.MeterCarta(GuardarCarta->SacarCarta());
							break;
						case 2:
							NuevaBaraja2.MeterCarta(GuardarCarta->SacarCarta());
							break;
						case 3:
							NuevaBaraja3.MeterCarta(GuardarCarta->SacarCarta());
							break;
						case 4:
							NuevaBaraja4.MeterCarta(GuardarCarta->SacarCarta());
							break;
						case 5:
							NuevaBaraja5.MeterCarta(GuardarCarta->SacarCarta());
							break;
						case 6:
							NuevaBaraja6.MeterCarta(GuardarCarta->SacarCarta());
							break;
						case 7:
							NuevaBaraja7.MeterCarta(GuardarCarta->SacarCarta());
							break;
						case 8:
							Mazo.MeterCarta(GuardarCarta->SacarCarta());
							break;
					default:
						break;
					}
				}
				break;
			case 2:
				carta = NuevaBaraja2.peek();
				color = carta->Substring(carta->Length - 1);
				numMano = GuardarCarta->peek();
				ingresado = true;
				if (color != GuardarCarta->peek()->Substring(GuardarCarta->peek()->Length - 1))
				{
					if (NuevaBaraja2.vacio() == false)
					{
						numBaraja = carta->Substring(0, carta->Length - 2);
						int num1 = Int32::Parse(numBaraja);
						numMano1 = numMano->Substring(0, numMano->Length - 2);
						int num2 = Int32::Parse(numMano1);
						if (num1 == num2 + 1)
						{
							contadorGanador2 += 1;
						}
					}
					NuevaBaraja2.MeterCarta(GuardarCarta->SacarCarta());
					while (GuardarCarta->vacio() == false)
					{
						Mazo.MeterCarta(GuardarCarta->SacarCarta());
					}
				}
				else
				{
					Console::WriteLine("Error, no puedes poner eso ahí.");
					switch (cartaTomada)
					{
					case 1:
						NuevaBaraja1.MeterCarta(GuardarCarta->SacarCarta());
						break;
					case 2:
						NuevaBaraja2.MeterCarta(GuardarCarta->SacarCarta());
						break;
					case 3:
						NuevaBaraja3.MeterCarta(GuardarCarta->SacarCarta());
						break;
					case 4:
						NuevaBaraja4.MeterCarta(GuardarCarta->SacarCarta());
						break;
					case 5:
						NuevaBaraja5.MeterCarta(GuardarCarta->SacarCarta());
						break;
					case 6:
						NuevaBaraja6.MeterCarta(GuardarCarta->SacarCarta());
						break;
					case 7:
						NuevaBaraja7.MeterCarta(GuardarCarta->SacarCarta());
						break;
					case 8:
						Mazo.MeterCarta(GuardarCarta->SacarCarta());
						break;
					default:
						break;
					}
				}
				break;
			case 3:
				carta = NuevaBaraja3.peek();
				color = carta->Substring(carta->Length - 1);
				numMano = GuardarCarta->peek();
				ingresado = true;
				if (color != GuardarCarta->peek()->Substring(GuardarCarta->peek()->Length - 1))
				{
					if (NuevaBaraja3.vacio() == false)
					{
						numBaraja = carta->Substring(0, carta->Length - 2);
						int num1 = Int32::Parse(numBaraja);
						numMano1 = numMano->Substring(0, numMano->Length - 2);
						int num2 = Int32::Parse(numMano1);
						if (num1 == num2 + 1)
						{
							contadorGanador3 += 1;
						}
					}
					NuevaBaraja3.MeterCarta(GuardarCarta->SacarCarta());
					while (GuardarCarta->vacio() == false)
					{
						Mazo.MeterCarta(GuardarCarta->SacarCarta());
					}
				}
				else
				{
					Console::WriteLine("Error, no puedes poner eso ahí.");
					switch (cartaTomada)
					{
					case 1:
						NuevaBaraja1.MeterCarta(GuardarCarta->SacarCarta());
						break;
					case 2:
						NuevaBaraja2.MeterCarta(GuardarCarta->SacarCarta());
						break;
					case 3:
						NuevaBaraja3.MeterCarta(GuardarCarta->SacarCarta());
						break;
					case 4:
						NuevaBaraja4.MeterCarta(GuardarCarta->SacarCarta());
						break;
					case 5:
						NuevaBaraja5.MeterCarta(GuardarCarta->SacarCarta());
						break;
					case 6:
						NuevaBaraja6.MeterCarta(GuardarCarta->SacarCarta());
						break;
					case 7:
						NuevaBaraja7.MeterCarta(GuardarCarta->SacarCarta());
						break;
					case 8:
						Mazo.MeterCarta(GuardarCarta->SacarCarta());
						break;
					default:
						break;
					}
				}
				break;
			case 4:
				carta = NuevaBaraja4.peek();
				color = carta->Substring(carta->Length - 1);
				numMano = GuardarCarta->peek();
				ingresado = true;
				if (color != GuardarCarta->peek()->Substring(GuardarCarta->peek()->Length - 1))
				{
					if (NuevaBaraja4.vacio() == false)
					{
						numBaraja = carta->Substring(0, carta->Length - 2);
						int num1 = Int32::Parse(numBaraja);
						numMano1 = numMano->Substring(0, numMano->Length - 2);
						int num2 = Int32::Parse(numMano1);
						if (num1 == num2 + 1)
						{
							contadorGanador4 += 1;
						}
					}	
					NuevaBaraja4.MeterCarta(GuardarCarta->SacarCarta());
					while (GuardarCarta->vacio() == false)
					{
						Mazo.MeterCarta(GuardarCarta->SacarCarta());
					}
				}
				else
				{
					Console::WriteLine("Error, no puedes poner eso ahí.");
					switch (cartaTomada)
					{
					case 1:
						NuevaBaraja1.MeterCarta(GuardarCarta->SacarCarta());
						break;
					case 2:
						NuevaBaraja2.MeterCarta(GuardarCarta->SacarCarta());
						break;
					case 3:
						NuevaBaraja3.MeterCarta(GuardarCarta->SacarCarta());
						break;
					case 4:
						NuevaBaraja4.MeterCarta(GuardarCarta->SacarCarta());
						break;
					case 5:
						NuevaBaraja5.MeterCarta(GuardarCarta->SacarCarta());
						break;
					case 6:
						NuevaBaraja6.MeterCarta(GuardarCarta->SacarCarta());
						break;
					case 7:
						NuevaBaraja7.MeterCarta(GuardarCarta->SacarCarta());
						break;
					case 8:
						Mazo.MeterCarta(GuardarCarta->SacarCarta());
						break;
					default:
						break;
					}
				}
				break;
			case 5:
				carta = NuevaBaraja5.peek();
				color = carta->Substring(carta->Length - 1);
				numMano = GuardarCarta->peek();
				ingresado = true;
				if (color != GuardarCarta->peek()->Substring(GuardarCarta->peek()->Length - 1))
				{
					if (NuevaBaraja5.vacio() == false)
					{
						numBaraja = carta->Substring(0, carta->Length - 2);
						int num1 = Int32::Parse(numBaraja);
						numMano1 = numMano->Substring(0, numMano->Length - 2);
						int num2 = Int32::Parse(numMano1);
						if (num1 == num2 + 1)
						{
							contadorGanador5 += 1;
						}
					}	
					NuevaBaraja5.MeterCarta(GuardarCarta->SacarCarta());
					while (GuardarCarta->vacio() == false)
					{
						Mazo.MeterCarta(GuardarCarta->SacarCarta());
					}
				}
				else
				{
					Console::WriteLine("Error, no puedes poner eso ahí.");
					switch (cartaTomada)
					{
					case 1:
						NuevaBaraja1.MeterCarta(GuardarCarta->SacarCarta());
						break;
					case 2:
						NuevaBaraja2.MeterCarta(GuardarCarta->SacarCarta());
						break;
					case 3:
						NuevaBaraja3.MeterCarta(GuardarCarta->SacarCarta());
						break;
					case 4:
						NuevaBaraja4.MeterCarta(GuardarCarta->SacarCarta());
						break;
					case 5:
						NuevaBaraja5.MeterCarta(GuardarCarta->SacarCarta());
						break;
					case 6:
						NuevaBaraja6.MeterCarta(GuardarCarta->SacarCarta());
						break;
					case 7:
						NuevaBaraja7.MeterCarta(GuardarCarta->SacarCarta());
						break;
					case 8:
						Mazo.MeterCarta(GuardarCarta->SacarCarta());
						break;
					default:
						break;
					}
				}
				break;
			case 6:
				carta = NuevaBaraja6.peek();
				color = carta->Substring(carta->Length - 1);
				numMano = GuardarCarta->peek();
				ingresado = true;
				if (color != GuardarCarta->peek()->Substring(GuardarCarta->peek()->Length - 1))
				{
					if (NuevaBaraja6.vacio() == false)
					{
						numBaraja = carta->Substring(0, carta->Length - 2);
						int num1 = Int32::Parse(numBaraja);
						numMano1 = numMano->Substring(0, numMano->Length - 2);
						int num2 = Int32::Parse(numMano1);
						if (num1 == num2 + 1)
						{
							contadorGanador6 += 1;
						}
					}
					NuevaBaraja6.MeterCarta(GuardarCarta->SacarCarta());
					while (GuardarCarta->vacio() == false)
					{
						Mazo.MeterCarta(GuardarCarta->SacarCarta());
					}
				}
				else
				{
					Console::WriteLine("Error, no puedes poner eso ahí.");
					switch (cartaTomada)
					{
					case 1:
						NuevaBaraja1.MeterCarta(GuardarCarta->SacarCarta());
						break;
					case 2:
						NuevaBaraja2.MeterCarta(GuardarCarta->SacarCarta());
						break;
					case 3:
						NuevaBaraja3.MeterCarta(GuardarCarta->SacarCarta());
						break;
					case 4:
						NuevaBaraja4.MeterCarta(GuardarCarta->SacarCarta());
						break;
					case 5:
						NuevaBaraja5.MeterCarta(GuardarCarta->SacarCarta());
						break;
					case 6:
						NuevaBaraja6.MeterCarta(GuardarCarta->SacarCarta());
						break;
					case 7:
						NuevaBaraja7.MeterCarta(GuardarCarta->SacarCarta());
						break;
					case 8:
						Mazo.MeterCarta(GuardarCarta->SacarCarta());
						break;
					default:
						break;
					}
				}
				break;
			case 7:
				carta = NuevaBaraja7.peek();
				color = carta->Substring(carta->Length - 1);
				numMano = GuardarCarta->peek();
				ingresado = true;
				if (color != GuardarCarta->peek()->Substring(GuardarCarta->peek()->Length - 1))
				{
					if (NuevaBaraja7.vacio() == false)
					{
						numBaraja = carta->Substring(0, carta->Length - 2);
						int num1 = Int32::Parse(numBaraja);
						numMano1 = numMano->Substring(0, numMano->Length - 2);
						int num2 = Int32::Parse(numMano1);
						if (num1 == num2 + 1)
						{
							contadorGanador7 += 1;
						}
					}	
					NuevaBaraja7.MeterCarta(GuardarCarta->SacarCarta());
					while (GuardarCarta->vacio() == false)
					{
						Mazo.MeterCarta(GuardarCarta->SacarCarta());
					}
				}
				else
				{
					Console::WriteLine("Error, no puedes poner eso ahí.");
					switch (cartaTomada)
					{
					case 1:
						NuevaBaraja1.MeterCarta(GuardarCarta->SacarCarta());
						break;
					case 2:
						NuevaBaraja2.MeterCarta(GuardarCarta->SacarCarta());
						break;
					case 3:
						NuevaBaraja3.MeterCarta(GuardarCarta->SacarCarta());
						break;
					case 4:
						NuevaBaraja4.MeterCarta(GuardarCarta->SacarCarta());
						break;
					case 5:
						NuevaBaraja5.MeterCarta(GuardarCarta->SacarCarta());
						break;
					case 6:
						NuevaBaraja6.MeterCarta(GuardarCarta->SacarCarta());
						break;
					case 7:
						NuevaBaraja7.MeterCarta(GuardarCarta->SacarCarta());
						break;
					case 8:
						Mazo.MeterCarta(GuardarCarta->SacarCarta());
						break;
					default:
						break;
					}
				}
				break;
			default:
				Console::WriteLine("Esa baraja no existe.");
				break;
			}
		}
		//Verificacion de juego ganado.
		if ((contadorGanador1 == 5) || (contadorGanador2 == 5) || (contadorGanador3 == 5) || (contadorGanador4 == 5) || (contadorGanador5 == 5) || (contadorGanador6 == 5) || (contadorGanador7 == 5))
		{
			ganaste = true;
			Console::WriteLine("¡Haz ganado!");
		}
	}
	if (cartaTomada == 9)
	{
		Console::WriteLine("Juego terminado...");
	}
	Console::ReadLine();
}


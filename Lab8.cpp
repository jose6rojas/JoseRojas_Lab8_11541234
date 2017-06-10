// viernes, 9 de junio de 2017
// Laboratorio 8 - Programacion III
// Jose Carlos Rojas Herrera - 11541234

#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <vector>
#include "Real.h"
#include "Racional.h"
#include "Radical.h"

int main(int argc, char const *argv[])
{
	int opcion = 0;
	while(opcion != 3)
	{
		cout << "Menu" << endl;
		cout << "1. Agregar Numeros Reales" << endl;
		cout << "2. Operar Numeros Reales" << endl;
		cout << "3. Salir" << endl;
		cout << "Escoja una opcion: ";
		cin >> opcion;

		if(opcion == 1) // Agregar Numeros Reales
		{
			int opcion1 = 0;
			while(opcion1 != 3)
			{
				cout << endl << "Agregar Numeros Reales" << endl;
				cout << "1. Racional" << endl;
				cout << "2. Radical" << endl;
				cout << "3. Salir" << endl;
				cout << "Escoja una opcion: ";

				if(opcion1 == 1)
				{
					int num, den;
					cout << endl << "Ingrese el numerador: ";
					cin >> num;
					cout << "Ingrese el denominador: ";
					cin >> den;
				}
				else if(opcion1 == 2)
				{

				}
				else if(opcion1 == 3) { }
				else
				{
					cout << endl << "Debe ingresar una opcion valida." << endl;
				}
			}
		}

		else if(opcion == 2) // Operar Numeros Reales
		{
			int opcion2 = 0;
			while(opcion2 != 3)
			{
				cout << endl << "Operar Numeros Reales" << endl;
				cout << "1. Racional" << endl;
				cout << "2. Radical" << endl;
				cout << "3. Salir" << endl;
				cout << "Escoja una opcion: ";

				if(opcion2 == 1)
				{

				}
				else if(opcion2 == 2)
				{

				}
				else if(opcion2 == 3) { }
				else
				{
					cout << endl << "Debe ingresar una opcion valida." << endl;
				}
		}

		else if(opcion == 3) { }
		else
		{
			cout << endl << "Debe ingresar una opcion valida." << endl;
		}
	}

	return 0;
}
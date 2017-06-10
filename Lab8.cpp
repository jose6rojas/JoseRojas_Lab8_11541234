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
	vector<Real*> reales;

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
				cin >> opcion1;

				if(opcion1 == 1) // Racional
				{
					int num, den;
					cout << endl << "Ingrese el numerador: ";
					cin >> num;
					cout << "Ingrese el denominador: ";
					cin >> den;

					Racional* R = new Racional(num, den);
					reales.push_back(R);
					cout << endl << "Numero Racional agregado correctamente." << endl;
				}
				else if(opcion1 == 2) // Radical
				{
					int coeficiente, indice, radicando;
					cout << endl << "Ingrese el coeficiente: ";
					cin >> coeficiente;
					cout << "Ingrese el indice: ";
					cin >> indice;
					cout << "Ingrese el radicando: ";
					cin >> radicando;

					Radical* R = new Radical(coeficiente, indice, radicando);
					reales.push_back(R);
					cout << endl << "Numero Radical agregado correctamente." << endl;
				}
				else if(opcion1 == 3) { cout << endl; }
				else
				{
					cout << endl << "Debe ingresar una opcion valida." << endl;
				}
			}
		}

		else if(opcion == 2) // Operar Numeros Reales
		{
			cout << endl << "Reales en el banco" << endl;
			for(int i = 0; i < reales.size(); i++)
			{
				if(dynamic_cast<Racional*> (reales[i]))
				{
					int num, den;
					num = (dynamic_cast<Racional*> (reales[i])) -> getNumerador();
					den = (dynamic_cast<Racional*> (reales[i])) -> getDenominador();
					cout << i << ". " << "Racional -> " << num << "/" << den << endl;
				}
				else
				{
					int coef, indice, radicando;
					coef = (dynamic_cast<Radical*> (reales[i])) -> getCoeficiente();
					indice = (dynamic_cast<Radical*> (reales[i])) -> getIndice();
					radicando = (dynamic_cast<Radical*> (reales[i])) -> getRadicando();
					cout << i << ". " << "Radical -> " << "(" << coef << ")(" << radicando << ")^(1/" << indice << ")" 
					<< endl;
				}
			}

			int op;
			cout << "Escoja un numero Real: ";
			cin >> op;

			Racional* Rac;
			Radical* Rad;

			if(dynamic_cast<Racional*> (reales[op]))
			{
				cout << endl << "Escogio un Racional" << endl;
				Rac = dynamic_cast<Racional*> (reales[op]);

				int opRac;
				cout << endl << "Operando un Racional" << endl;
				cout << "1. Racional" << endl;
				cout << "2. Radical" << endl;
				cout << "3. Entero" << endl;
				cout << "4. Decimal" << endl;
				cout << "Escoja una opcion: ";
				cin >> opRac;

				if(opRac == 1)
				{
					cout << endl << "Racionales en el banco" << endl;
					for(int i = 0; i < reales.size(); i++)
					{
						if(dynamic_cast<Racional*> (reales[i]))
						{
							int num, den;
							num = (dynamic_cast<Racional*> (reales[i])) -> getNumerador();
							den = (dynamic_cast<Racional*> (reales[i])) -> getDenominador();
							cout << i << ". " << "Racional -> " << num << "/" << den << endl;
						}
					}

					int op2;
					cout << "Escoja un numero Real: ";
					cin >> op2;

					Racional* Rac2;
					Rac2 = dynamic_cast<Racional*> (reales[op2]);

					int operacion;
					cout << endl << "Racional y Racional" << endl;
					cout << "1. Suma" << endl;
					cout << "2. Resta" << endl;
					cout << "3. Multiplicacion" << endl;
					cout << "4. Division" << endl;
					cout << "Escoja una operacion: ";
					cin >> operacion;

					string resultado;
					if(operacion == 1) // Suma
					{
						resultado = *Rac + Rac2;
						cout << endl << resultado << endl;
					}
					else if(operacion == 2) // Resta
					{
						resultado = *Rac - Rac2;
						cout << endl << resultado << endl;
					}
					else if(operacion == 3) // Multiplicacion
					{
						resultado = *Rac * (Rac2);
						cout << endl << resultado << endl;
					}
					else if(operacion == 4) // Division
					{
						resultado = *Rac / Rac2;
						cout << endl << resultado << endl;
					}
					else
						cout << endl << "Debe ingresar una opcion valida." << endl;
				}
				else if(opRac == 2)
				{

				}
				else if(opRac == 3)
				{

				}
				else if(opRac == 4)
				{

				}
				else
					cout << endl << "Debe escoger una opcion valida." << endl;
			}
			else
			{
				cout << endl << "Escogio un Radical" << endl;
				Rad = dynamic_cast<Radical*> (reales[op]);


			}
		}

		else if(opcion == 3) { }
		else
		{
			cout << endl << "Debe ingresar una opcion valida." << endl;
		}
	}

	// Limpia el vector de Reales
	for (int i = 0; i < reales.size(); i++)
		delete reales[i];
	reales.clear();

	return 0;
}
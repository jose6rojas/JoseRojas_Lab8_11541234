// Radical.h

#ifndef RADICAL_H
#define RADICAL_H

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include "Real.h"
// #include "Racional.h"

using namespace std;

class Radical : public Real
{
	private:
		int coeficiente;
		int indice;
		int radicando;

	public:
		Radical();
		Radical(int, int, int); // coeficiente, indice, radicando

		// coeficiente
		void setCoeficiente(int);
		int getCoeficiente();

		// indice
		void setIndice(int);
		int getIndice();

		// radicando
		void setRadicando(int);
		int getRadicando();

		// Operaciones con Enteros
		string sumaEntero(int);
		string restaEntero(int);
		string multiplicacionEntero(int);
		string divisionEntero(int);

		// Operaciones con Decimales
		string sumaDecimal(double);
		string restaDecimal(double);
		string multiplicacionDecimal(double);
		string divisionDecimal(double);

		// Operaciones con Radicales
		string operator+(Radical* Rad)
		{
			if((this -> indice) == (Rad -> getIndice()) && (this -> radicando) == (Rad -> getRadicando()))
			{
				// Pueden sumarse
				int nuevo_coeficiente;
				nuevo_coeficiente = (this -> coeficiente) + (Rad -> getCoeficiente());

				stringstream ss;
				ss << "(" << nuevo_coeficiente << ")(" << this -> radicando << ")^(1/" << this -> indice << ")";
				return ss.str();
			}
			else
			{
				// No pueden sumarse
				stringstream ss;
				ss << "(" << this -> coeficiente << ")(" << this -> radicando << ")^(1/" << this -> indice << ")" << 
				" + " << "(" << Rad -> getCoeficiente() << ")(" << Rad -> getRadicando() << ")^(1/" << 
				Rad -> getIndice() << ")";
				return ss.str();
			}
		}
		string operator-(Radical* Rad)
		{
			if((this -> indice) == (Rad -> getIndice()) && (this -> radicando) == (Rad -> getRadicando()))
			{
				// Pueden sumarse
				int nuevo_coeficiente;
				nuevo_coeficiente = (this -> coeficiente) - (Rad -> getCoeficiente());

				stringstream ss;
				ss << "(" << nuevo_coeficiente << ")(" << this -> radicando << ")^(1/" << this -> indice << ")";
				return ss.str();
			}
			else
			{
				// No pueden sumarse
				stringstream ss;
				ss << "(" << this -> coeficiente << ")(" << this -> radicando << ")^(1/" << this -> indice << ")" << 
				" - " << "(" << Rad -> getCoeficiente() << ")(" << Rad -> getRadicando() << ")^(1/" << 
				Rad -> getIndice() << ")";
				return ss.str();
			}
		}
		string operator*(Radical* Rad)
		{
			if(this -> indice == Rad -> getIndice())
			{
				// Mismo indice
				int nuevo_coeficiente, nuevo_radicando;
				nuevo_coeficiente = (this -> coeficiente) * (Rad -> getCoeficiente());
				nuevo_radicando = (this -> radicando) * (Rad -> getRadicando());

				stringstream ss;
				ss << "(" << nuevo_coeficiente << ")(" << nuevo_radicando << ")^(1/" << this -> indice << ")";
				return ss.str();
			}
			else
			{
				// Distinto indice
				int mcd;
				for(int i = 1; i <= (this -> indice) && i <= (Rad -> getIndice()); i++)
				{
					if((this -> indice) % i == 0 && (Rad -> getIndice()) % i == 0 )
						mcd = i;
				}

				int nuevo_coeficiente;
				nuevo_coeficiente = (this -> coeficiente) * (Rad -> getCoeficiente());

				int nuevo_numerador1, nuevo_numerador2, retNumerador;
				nuevo_numerador1 = mcd / this -> indice;
				nuevo_numerador2 = mcd / Rad -> getIndice();
				retNumerador = nuevo_numerador1 + nuevo_numerador2; // numerador del nuevo indice

				int nuevo_radicando1, nuevo_radicando2, retRadicando;
				nuevo_radicando1 = pow(this -> radicando, nuevo_numerador1);
				nuevo_radicando2 = pow(Rad -> radicando, nuevo_numerador2);
				retRadicando = nuevo_radicando1 * nuevo_radicando2; // radicando del nuevo radical

				stringstream ss;
				ss << "(" << nuevo_coeficiente << ")(" << retRadicando << ")^(" << retNumerador << "/" << mcd << ")";
				return ss.str();
			}
		}
		string operator/(Radical* Rad)
		{
			if(this -> indice == Rad -> getIndice())
			{
				// Mismo indice
				stringstream ss;
				ss << "(" << this -> coeficiente << "/" << Rad -> getCoeficiente() << ") * (" << this -> radicando << 
				"/" << Rad -> getRadicando() << ")^(1/" << this -> indice << ")";
				return ss.str();
			}
			else
			{
				// Distinto indice
				int mcd;
				for(int i = 1; i <= (this -> indice) && i <= (Rad -> getIndice()); i++)
				{
					if((this -> indice) % i == 0 && (Rad -> getIndice()) % i == 0 )
						mcd = i;
				}

				int nuevo_numerador1, nuevo_numerador2, retNumerador;
				nuevo_numerador1 = mcd / this -> indice;
				nuevo_numerador2 = mcd / Rad -> getIndice();
				retNumerador = nuevo_numerador1 - nuevo_numerador2;

				int nuevo_radicando1, nuevo_radicando2;
				nuevo_radicando1 = pow(this -> radicando, nuevo_numerador1);
				nuevo_radicando2 = pow(Rad -> radicando, nuevo_numerador2);
				
				stringstream ss;
				ss << "(" << this -> coeficiente << "/" << Rad -> getCoeficiente() << ") * (" << nuevo_radicando1 
				<< "/" << nuevo_radicando2 << ")^(" << retNumerador << "/" << mcd << ")";
			}
		}

		// Operaciones con Racionales
		/* string operator+(Racional*);
		string operator-(Racional*);
		string operator*(Racional*);
		string operator/(Racional*); */
};

#endif
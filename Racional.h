// Racional.h

#ifndef RACIONAL_H
#define RACIONAL_H

#include <iostream>
#include <string>
#include <sstream>
#include "Real.h"
#include "Radical.h"

using namespace std;

class Racional : public Real
{
	private:
		int numerador;
		int denominador;

	public:
		Racional();
		Racional(int, int); // numerador, denominador

		// numerador
		void setNumerador(int);
		int getNumerador();

		// denominador
		void setDenominador(int);
		int getDenominador();

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

		// Operaciones con Racionales
		string operator+(Racional* Rac)
		{
			// Determinar el Minimo Comun Divisor
			int mcd;
			for(int i = 1; i <= (this -> denominador) && i <= (Rac -> getDenominador()); i++)
			{
				if((this -> denominador) % i == 0 && (Rac -> getDenominador()) % i == 0 )
					mcd = i;
			}

			// Operar los numeradores
			int nuevo_numerador1, nuevo_numerador2, retNumerador;
			nuevo_numerador1 = (mcd / (this -> denominador)) * (this -> numerador);
			nuevo_numerador2 = (mcd / (Rac -> getDenominador())) * (Rac -> getNumerador());
			retNumerador = nuevo_numerador1 + nuevo_numerador2;

			// Retornar la nueva fraccion
			stringstream ss;
			ss << retNumerador << " / " << mcd;
			return ss.str();
		}
		string operator-(Racional* Rac)
		{
			int mcd;
			for(int i = 1; i <= (this -> denominador) && i <= (Rac -> getDenominador()); i++)
			{
				if((this -> denominador) % i == 0 && (Rac -> getDenominador()) % i == 0 )
					mcd = i;
			}

			int nuevo_numerador1, nuevo_numerador2, retNumerador;
			nuevo_numerador1 = (mcd / (this -> denominador)) * (this -> numerador);
			nuevo_numerador2 = (mcd / (Rac -> getDenominador())) * (Rac -> getNumerador());
			retNumerador = nuevo_numerador1 - nuevo_numerador2;

			stringstream ss;
			ss << retNumerador << " / " << mcd;
			return ss.str();
		}
		string operator*(Racional* Rac)
		{
			int nuevo_numerador, nuevo_denominador;
			nuevo_numerador = (this -> numerador) * (Rac -> getNumerador());
			nuevo_denominador = (this -> denominador) * (Rac -> getDenominador());

			stringstream ss;
			ss << nuevo_numerador << " / " << nuevo_denominador;
			return ss.str();
		}
		string operator/(Racional* Rac)
		{
			int nuevo_numerador, nuevo_denominador;
			nuevo_numerador = (this -> numerador) * (Rac -> getDenominador());
			nuevo_denominador = (this -> denominador) * (Rac -> getNumerador());

			stringstream ss;
			ss << nuevo_numerador << " / " << nuevo_denominador;
			return ss.str();
		}

		// Operaciones con Radicales
		string operator+(Radical*);
		string operator-(Radical*);
		string operator*(Radical*);
		string operator/(Radical*);
};

#endif
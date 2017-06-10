// Real.h

#ifndef REAL_H
#define REAL_H

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Real
{
	// No contiene atributos

	public:
		Real();

		// Operaciones con Enteros
		virtual string sumaEntero(int) = 0;
		virtual string restaEntero(int) = 0;
		virtual string multiplicacionEntero(int) = 0;
		virtual string divisionEntero(int) = 0;

		// Operaciones con Decimales
		virtual string sumaDecimal(double) = 0;
		virtual string restaDecimal(double) = 0;
		virtual string multiplicacionDecimal(double) = 0;
		virtual string divisionDecimal(double) = 0;
};

#endif
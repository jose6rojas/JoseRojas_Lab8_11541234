// Racional.cpp

#include "Racional.h"

Racional::Racional() { }

Racional::Racional(int numerador, int denominador)
{
	this -> numerador = numerador;
	this -> denominador = denominador;
}

// numerador
void Racional::setNumerador(int numerador) { this -> numerador = numerador; }
int Racional::getNumerador() { return numerador; }

// denominador
void Racional::setDenominador(int denominador) { this -> denominador = denominador; }
int Racional::getDenominador() { return denominador; }

// Operaciones con Radicales
string Racional::operator+(Radical* Rad)
{
	int mcd;
	mcd = this -> denominador;

	int nuevo_coeficiente;
	nuevo_coeficiente = (Rad -> getCoeficiente()) * mcd;

	stringstream ss;
	ss << this -> numerador << " + " << "(" << nuevo_coeficiente << ")(" << Rad -> getRadicando() << ")^(1/" << 
	Rad -> getIndice() << ")" << " / " << mcd;
	return ss.str();
}
string Racional::operator-(Radical* Rad)
{
	int mcd;
	mcd = this -> denominador;

	int nuevo_coeficiente;
	nuevo_coeficiente = mcd * Rad -> getCoeficiente();

	stringstream ss;
	ss << this -> numerador << " - " << "(" << nuevo_coeficiente << ")(" << Rad -> getRadicando() << ")^(1/" << 
	Rad -> getIndice() << ")" << " / " << mcd;
	return ss.str();
}
string Racional::operator*(Radical* Rad)
{
	int nuevo_numerador, nuevo_denominador;
	nuevo_numerador = (this -> numerador) * (Rad -> getCoeficiente());
	nuevo_denominador = this -> denominador;

	stringstream ss;
	ss << "(" << nuevo_numerador << ")(" << Rad -> getRadicando() << ")^(1/" << Rad -> getIndice() << ")" << 
	" / " << nuevo_denominador;
	return ss.str();
}
string Racional::operator/(Radical* Rad)
{
	int nuevo_numerador, nuevo_denominador;
	nuevo_numerador = this -> numerador;
	nuevo_denominador = (this -> denominador) * (Rad -> getCoeficiente());

	stringstream ss;
	ss << nuevo_numerador << " / " << "(" << nuevo_denominador << ")(" << Rad -> getRadicando() << ")^(1/" << 
	Rad -> getIndice() << ")";
	return ss.str();
}

// Operaciones con Enteros
string Racional::sumaEntero(int entero)
{
	int mcd;
	mcd = this -> denominador;

	int nuevo_numerador;
	nuevo_numerador = (this -> numerador) + (mcd * entero);

	stringstream ss;
	ss << nuevo_numerador << " / " << mcd;
	return ss.str();
}
string Racional::restaEntero(int entero)
{
	int mcd;
	mcd = this -> denominador;

	int nuevo_numerador;
	nuevo_numerador = (this -> numerador) - (mcd * entero);

	stringstream ss;
	ss << nuevo_numerador << " / " << mcd;
	return ss.str();
}
string Racional::multiplicacionEntero(int entero)
{
	int nuevo_numerador, nuevo_denominador;
	nuevo_numerador = (this -> numerador) * entero;
	nuevo_denominador = this -> denominador;

	stringstream ss;
	ss << nuevo_numerador << " / " << nuevo_denominador;
	return ss.str();
}
string Racional::divisionEntero(int entero)
{
	int nuevo_numerador, nuevo_denominador;
	nuevo_numerador = this -> numerador;
	nuevo_denominador = (this -> denominador) * entero;

	stringstream ss;
	ss << nuevo_numerador << " / " << nuevo_denominador;
	return ss.str();
}

// Operaciones con Decimales
string Racional::sumaDecimal(double decimal)
{
	int mcd;
	mcd = this -> denominador;

	int nuevo_numerador;
	nuevo_numerador = (this -> numerador) + (mcd * decimal);

	stringstream ss;
	ss << nuevo_numerador << " / " << mcd;
	return ss.str();
}
string Racional::restaDecimal(double decimal)
{
	int mcd;
	mcd = this -> denominador;

	int nuevo_numerador;
	nuevo_numerador = (this -> numerador) - (mcd * decimal);

	stringstream ss;
	ss << nuevo_numerador << " / " << mcd;
	return ss.str();
}
string Racional::multiplicacionDecimal(double decimal)
{
	int nuevo_numerador, nuevo_denominador;
	nuevo_numerador = (this -> numerador) * decimal;
	nuevo_denominador = this -> denominador;

	stringstream ss;
	ss << nuevo_numerador << " / " << nuevo_denominador;
	return ss.str();
}
string Racional::divisionDecimal(double decimal)
{
	int nuevo_numerador, nuevo_denominador;
	nuevo_numerador = this -> numerador;
	nuevo_denominador = (this -> denominador) * decimal;

	stringstream ss;
	ss << nuevo_numerador << " / " << nuevo_denominador;
	return ss.str();
}
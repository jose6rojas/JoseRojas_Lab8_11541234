// Radical.cpp

#include "Radical.h"

Radical::Radical() { }

Radical::Radical(int coeficiente, int indice, int radicando)
{
	this -> coeficiente = coeficiente;
	this -> indice = indice;
	this -> radicando;
}

// coeficiente
void Radical::setCoeficiente(int coeficiente) { this -> coeficiente = coeficiente; }
int Radical::getCoeficiente() { return coeficiente; }

// indice
void Radical::setIndice(int indice) { this -> indice = indice; }
int Radical::getIndice() { return indice; }

// radicando
void Radical::setRadicando(int radicando) { this -> radicando = radicando; }
int Radical::getRadicando() { return radicando; }

// Operaciones con Enteros
string Radical::sumaEntero(int entero)
{
	stringstream ss;
	ss << "(" << this -> coeficiente << ")(" << this -> radicando << ")^(1/" << this -> indice << ")" << " + " << entero;
	return ss.str();
}
string Radical::restaEntero(int entero)
{
	stringstream ss;
	ss << "(" << this -> coeficiente << ")(" << this -> radicando << ")^(1/" << this -> indice << ")" << " - " << entero;
	return ss.str();
}
string Radical::multiplicacionEntero(int entero)
{
	int nuevo_coeficiente;
	nuevo_coeficiente = (this -> coeficiente) * entero;

	stringstream ss;
	ss << "(" << nuevo_coeficiente << ")(" << this -> radicando << ")^(1/" << this -> indice << ")";
	return ss.str();
}
string Radical::divisionEntero(int entero)
{
	stringstream ss;
	ss << "(" << this -> coeficiente << "/" << entero << ") * (" << this -> radicando << ")^(1/" << this -> indice << ")";
	return ss.str();
}

// Operaciones con Decimales
string Radical::sumaDecimal(double decimal)
{
	stringstream ss;
	ss << "(" << this -> coeficiente << ")(" << this -> radicando << ")^(1/" << this -> indice << ")" << " + " << decimal;
	return ss.str();
}
string Radical::restaDecimal(double decimal)
{
	stringstream ss;
	ss << "(" << this -> coeficiente << ")(" << this -> radicando << ")^(1/" << this -> indice << ")" << " - " << decimal;
	return ss.str();
}
string Radical::multiplicacionDecimal(double decimal)
{
	int nuevo_coeficiente;
	nuevo_coeficiente = (this -> coeficiente) * decimal;

	stringstream ss;
	ss << "(" << nuevo_coeficiente << ")(" << this -> radicando << ")^(1/" << this -> indice << ")";
	return ss.str();
}
string Radical::divisionDecimal(double decimal)
{
	stringstream ss;
	ss << "(" << this -> coeficiente << "/" << decimal << ") * (" << this -> radicando << ")^(1/" << this -> indice << ")";
	return ss.str();
}

// Operaciones con Racionales
/* string Radical::operator+(Racional* Rac)
{
	int mcd;
	mcd = Rac -> getDenominador();

	int nuevo_coeficiente;
	nuevo_coeficiente = mcd * this -> coeficiente;

	stringstream ss;
	ss << "(" << nuevo_coeficiente << ")(" << this -> radicando << ")^(1/" << this -> indice << ")" << 
	" + " << Rac -> getNumerador() << " / " << mcd;
	return ss.str();
}
string Radical::operator-(Racional* Rac)
{
	int mcd;
	mcd = Rac -> getDenominador();

	int nuevo_coeficiente;
	nuevo_coeficiente = mcd * this -> coeficiente;

	stringstream ss;
	ss << "(" << nuevo_coeficiente << ")(" << this -> radicando << ")^(1/" << this -> indice << ")" << 
	"-" << Rac -> getNumerador() << " / " << mcd;
	return ss.str();
}
string Radical::operator*(Racional* Rac)
{
	int nuevo_numerador, nuevo_denominador;
	nuevo_numerador = (Rac -> getNumerador()) * coeficiente;
	nuevo_denominador = Rac -> getDenominador();

	stringstream ss;
	ss << "(" << nuevo_numerador << ")(" << radicando << ")^(1/" << indice << ")" << " / " << nuevo_denominador;
	return ss.str();
}
string Radical::operator/(Racional* Rac)
{
	int nuevo_numerador, nuevo_denominador;
	nuevo_numerador = Rac -> getNumerador();
	nuevo_denominador = (Rac -> getDenominador()) * coeficiente;

	stringstream ss;
	ss << nuevo_numerador << " / " << "(" << nuevo_denominador << ")(" << radicando << ")^(1/" << indice << ")";
	return ss.str();
} */
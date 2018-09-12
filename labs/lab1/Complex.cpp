// file Complex.cpp
#include "Complex.hpp"
#include <iostream>

Complex::Complex()
{

}

void Complex::setData(double _real, double _imag)
{
  real = _real;
  imag = _imag;
}
void Complex::printComplexNumber()
{
   std::cout << "(" << real << "," << imag << "i)" << std::endl;
}

double Complex::getImag(){
		return imag;
}
double Complex::getReal(){
	return real;
}
void Complex::setImag(double _imag){
	imag = _imag;
}
void Complex::setReal(double _real){
	real = _real;
}

Complex Complex::add(Complex &a){
	Complex sum;
	sum.real = this->real + a.getReal();
	sum.imag = this->imag + a.getImag();
	return sum;
}
Complex Complex::subtract(Complex &a){
	Complex num;
	num.real = this->real - a.getReal();
	num.imag = this->imag - a.getImag();
	return num;
}
Complex Complex::multiply(Complex &a){
	Complex num;
	num.real = this->real * a.getReal() - this->imag * a.getImag();
	num.imag = this->real * a.getImag() + this->imag * a.getReal();
	return num;
}
Complex Complex::divide(Complex &a){
	Complex num;
	num.real = (this->real * a.getReal() + this->imag * a.getImag()) / (a.getReal() * a.getReal() + a.getImag() * a.getImag());
	num.imag = (this->imag * a.getReal() - this->real * a.getImag()) / (a.getReal() * a.getReal() + a.getImag() * a.getImag());
	return num;
}

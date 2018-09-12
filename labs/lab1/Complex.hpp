// file Complex.hpp
#ifndef COMPLEX_HPP
#define COMPLEX_HPP

class Complex
{
  private:
     double real;
     double imag;
  public:
		Complex( );
	 	void setData(double _real, double _imag);
	 	void printComplexNumber();
		double getImag();
		double getReal();
		void setImag(double _imag);
		void setReal(double _real);
		Complex add(Complex &a);
		Complex subtract(Complex &a);
		Complex multiply(Complex &a);
		Complex divide(Complex &a);
};
#endif
 

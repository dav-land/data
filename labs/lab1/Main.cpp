//file Main.cpp
#include "Complex.hpp"
#include <iostream>

using namespace std;
int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Usage: " << argv[0] << " realNum imagNum" << endl;
		return 1;
	}

 	// complex numbers declarations
 	Complex c1,c2,c3;
 	c1.setData(1.2, 5.6);
 	c2.setData(3, 12.3);
 	c3.setData(11, 3.2);

	Complex c4;
	c4.setReal(stod(argv[1]));
	c4.setImag(stod(argv[2]));


 	// arithmetic operators
 	Complex addition = c1.add(c2);
 	Complex subtraction = c1.subtract(c3);
	Complex multiplication = c1.multiply(c2);
	Complex division = c1.divide(c3);

 	cout << "Real : " << c4.getReal() << endl;
 	cout << "Imaginary: " << c4.getImag() << endl;
 	cout << "First complex: ";  	c1.printComplexNumber();

 	cout << "Second complex: "; 	c2.printComplexNumber();
 	cout << "Third complex: ";  	c3.printComplexNumber();
 	cout << "Addition: ";       	addition.printComplexNumber();
 	cout << "Subtraction: " ;   	subtraction.printComplexNumber();
	cout << "Multiplication: ";   multiplication.printComplexNumber();
	cout << "Division: ";         division.printComplexNumber();
 	return 0;
}

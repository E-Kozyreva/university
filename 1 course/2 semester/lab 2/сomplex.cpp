#include <iostream> 
#include <cmath>
#include "complex data.h"
#include "operations.cpp"


int main();
double GetActualPart();
double GetImaginaryPart();
int Restart();
void GetComplex(double ActualPart, double ImaginaryPart);
int GetFunction();
void Arithmetic(double a1, double e1, double a2, double e2);


double GetActualPart() {
	double ActualPart;
	std::cout << "Enter actual part: ";
	std::cin >> ActualPart;
	return ActualPart;
}
double GetImaginaryPart() {
	double ImaginaryPart;
	std::cout << "Enter imaginary part: ";
	std::cin >> ImaginaryPart;
	return ImaginaryPart;
}
int Restart() {
	int answer = 0;
	std::cout << "Restart program?\n";
	std::cout << "1.Yes.\n2.No.\n";

	if (answer == 1 && isdigit(answer != 0)) {
		main();
	} else if (answer == 2 && isdigit(answer != 0)) {
		std::cout << "Goodbye!\n\n";
		return 0;
	} else {
		std::cout << "Wrong answer, try again!\n\n";
		Restart();
	}
	return 0;
}

void GetComplex(double ActualPart, double ImaginaryPart) {
	if (ImaginaryPart > 0) {
		std::cout << "\n" << "Your enter: ";
		std::cout << ActualPart << " + ";
		std::cout << ImaginaryPart << "i";
		std::cout << "\n\n";
	} else if (ImaginaryPart < 0) {
		std::cout << "\n" << "Your enter: ";
		std::cout << ActualPart << " - ";
		std::cout << ImaginaryPart * (-1) << "i";
		std::cout << "\n\n";
	} else {
		std::cout << "\n" << "Your enter: ";
		std::cout << ActualPart << " + ";
		std::cout << ImaginaryPart << "i";
		std::cout << "\n\n";
	}
}
int GetFunction() {
	int answer;

	std::cout << "Select one of the functions:\n";
	std::cout << "1.Arithmetic operations with the entered number.\n";
	std::cout << "2.Arithmetic operations with two numbers.\n";
	std::cout << "Your answer: ";
	std::cin >> answer;
	std::cout << "\n";

	if (answer == 1 || answer == 2) {
		return answer;
	} else {
		GetFunction();
		std::cout << "Wrong answer, try again!\n\n";
	}
	return 0;
}

void Arithmetic(double a1, double e1, double a2, double e2) {
	int answer;
	std::cout << "Select one of the functions:\n";
	std::cout << "1.Sum of complex numbers.\n";
	std::cout << "2.Difference of complex numbers.\n";
	std::cout << "3.The product of complex numbers.\n";
	std::cout << "4.Quotient of complex numbers.\n";
	std::cout << "5.Assign the value of one complex number to another.\n";
	std::cout << "6.Compare numbers.\n";
	std::cout << "7.The module of a complex number.\n";
	std::cout << "8.Raising a complex number to a positive power.\n";
	std::cout << "9.Raising a complex number to a negative power.\n";
	std::cout << "10.Raising a complex number to a fractional power.\n";
	std::cout << "11.Raising a complex number to a complex power.\n";
	std::cout << "12.Trigonometric notation of a complex number.\n";
	std::cout << "Your answer: ";
	std::cin >> answer;
	std::cout << "\n";
	TComplex data{ a1, e1, a2, e2 };

	if (answer == 1) {
		data.AdditionComplex();
	} else if (answer == 2) {
		data.SubtractionComplex();
	} else if (answer == 3) {
		data.MultiplicationComplex();
	} else if (answer == 4) {
		data.DivisionComplex();
	} else if (answer == 5) {
		data.AssignmentComplex();
	} else if (answer == 6) {
		data.ComparisonComplex();
	} else if (answer == 7) {
		data.ModuleComplex();
	} else if (answer == 8) {
		data.PowerPComplex();
	} else if (answer == 9) {
		data.PowerMComplex();
	} else if (answer == 10) {
		data.PowerDComplex();
	} else if (answer == 11) {
		data.PowerCComplex();
	} else if (answer == 12) {
		data.TrigonometricComplex();
	} else {
		std::cout << "Wrong answer, try again!\n\n";
		Arithmetic(a1, e1, a2, e2);
	}
	std::cout << "Do you want to calculate something else?\n";
	std::cout << "1.Yes.\n2.No.\n";
	std::cout << "Your answer: ";
	std::cin >> answer;
	std::cout << "\n";

	if (answer == 1) {
		Arithmetic(a1, e1, a2, e2);
	} else if (answer != 2) {
		std::cout << "Wrong answer, goodbye!\n\n";
	}
}

int main() {
	int function = 0;
	double ActualPart1 = 0, ImaginaryPart1 = 0;
	double ActualPart2 = 0, ImaginaryPart2 = 0;
	
	ActualPart1 = GetActualPart();
	ImaginaryPart1 = GetImaginaryPart();
	GetComplex(ActualPart1, ImaginaryPart1);

	function = GetFunction();

	if (function == 1) {
		ActualPart2 = ActualPart1;
		ImaginaryPart2 = ImaginaryPart1;
		Arithmetic(ActualPart1, ImaginaryPart1, ActualPart2, ImaginaryPart2);
	} else {
		ActualPart2 = GetActualPart();
		ImaginaryPart2 = GetImaginaryPart();
		GetComplex(ActualPart2, ImaginaryPart2);
		Arithmetic(ActualPart1, ImaginaryPart1, ActualPart2, ImaginaryPart2);
	}
	return 0;
}

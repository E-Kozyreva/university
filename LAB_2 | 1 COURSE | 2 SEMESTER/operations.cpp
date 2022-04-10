void TComplex::Output(double ActualPart, double ImaginaryPart) {
	if (ActualPart > 0 && ImaginaryPart > 0) {
		std::cout << ActualPart << " + " << ImaginaryPart << "i";
	} else if (ActualPart > 0 && ImaginaryPart < 0) {
		std::cout << ActualPart << " - " << ImaginaryPart * (-1) << "i";
	} else if (ActualPart < 0 && ImaginaryPart > 0) {
		std::cout << ActualPart << " + " << ImaginaryPart << "i";
	} else if (ActualPart < 0 && ImaginaryPart < 0) {
		std::cout << ActualPart << " - " << ImaginaryPart * (-1) << "i";
	} else if (ActualPart == 0 && ImaginaryPart != 0) {
		std::cout << ImaginaryPart << "i";
	} else if (ActualPart != 0 && ImaginaryPart == 0) {
		std::cout << ActualPart;
	} else if (ActualPart == 0 && ImaginaryPart == 0) {
		std::cout << 0;
	}
}

void TComplex::AdditionComplex() {
	double ActualPart = ActualPart1 + ActualPart2;
	double ImaginaryPart = ImaginaryPart1 + ImaginaryPart2;

	std::cout << "The addition of complex numbers is equal to: ";
	Output(ActualPart, ImaginaryPart);
	std::cout << "\n\n";
}
void TComplex::SubtractionComplex() {
	double ActualPart = ActualPart1 - ActualPart2;
	double ImaginaryPart = ImaginaryPart1 - ImaginaryPart2;

	std::cout << "The subtraction of complex numbers is equal to: ";
	Output(ActualPart, ImaginaryPart);
	std::cout << "\n\n";
}
void TComplex::MultiplicationComplex() {
	double ActualPart = (ActualPart1 * ActualPart2) - (ImaginaryPart1 * ImaginaryPart2);
	double ImaginaryPart = (ActualPart1 * ImaginaryPart2) + (ActualPart2 * ImaginaryPart1);

	std::cout << "The multiplication of complex numbers is equal to: ";
	Output(ActualPart, ImaginaryPart);
	std::cout << "\n\n";
}
void TComplex::DivisionComplex() {
	double a1 = (ActualPart1 * ActualPart2) + (ImaginaryPart1 * ImaginaryPart2);
	double a2 = pow(ActualPart2, 2) + pow(ImaginaryPart2, 2);
	double e1 = (ActualPart2 * ImaginaryPart1) - (ActualPart1 * ImaginaryPart2);
	double e2 = pow(ActualPart2, 2) + pow(ImaginaryPart2, 2);
	double ActualPart = a1 / a2;
	double ImaginaryPart = e1 / e2;

	std::cout << "The division of complex numbers is equal to: ";
	Output(ActualPart, ImaginaryPart);
	std::cout << "\n\n";
}
void TComplex::AssignmentComplex() {
	int answer;
	std::cout << "Select one of the function:\n";
	std::cout << "1.z1 = z2.\n2.z2 = z1.\n";
	std::cout << "Your answer: ";
	std::cin >> answer;
	std::cout << "\n";

	if (answer == 1) {
		ActualPart1 = ActualPart2;
		ImaginaryPart1 = ImaginaryPart2;
		std::cout << "z1 = ";
		Output(ActualPart1, ImaginaryPart1);
		std::cout << "\n";
		std::cout << "z2 = ";
		Output(ActualPart2, ImaginaryPart2);
		std::cout << "\n\n";
	} else if (answer == 2) {
		ActualPart2 = ActualPart1;
		ImaginaryPart2 = ImaginaryPart1;
		std::cout << "z1 = ";
		Output(ActualPart1, ImaginaryPart1);
		std::cout << "\n";
		std::cout << "z2 = ";
		Output(ActualPart2, ImaginaryPart2);
		std::cout << "\n\n";
	} else {
		std::cout << "Wrong answer, try again!\n\n";
		AssignmentComplex();
	}
}
void TComplex::ComparisonComplex() {
	if ((ActualPart1 > ActualPart2) && (ImaginaryPart1 > ImaginaryPart2)) {
		Output(ActualPart1, ImaginaryPart1);
		std::cout << " > ";
		Output(ActualPart2, ImaginaryPart2);
	} else if ((ActualPart1 < ActualPart2) && (ImaginaryPart1 < ImaginaryPart2)) {
		Output(ActualPart1, ImaginaryPart1);
		std::cout << " < ";
		Output(ActualPart2, ImaginaryPart2);
	} else if ((ActualPart1 == ActualPart2) && (ImaginaryPart1 == ImaginaryPart2)) {
		Output(ActualPart1, ImaginaryPart1);
		std::cout << " = ";
		Output(ActualPart2, ImaginaryPart2);
	}
	std::cout << "\n\n";
}


void TComplex::ModuleComplex() {
	int answer;
	std::cout << "Select one of the complex numbers:\n";
	std::cout << "1.";
	Output(ActualPart1, ImaginaryPart1);
	std::cout << ".\n";
	std::cout << "2.";
	Output(ActualPart2, ImaginaryPart2);
	std::cout << ".\n";
	std::cout << "Your answer: ";
	std::cin >> answer;
	std::cout << "\n";

	if (answer == 1) {
		double a1 = pow(ActualPart1 , 2);
		double e1 = pow(ImaginaryPart1, 2);
		double modulecomplex = sqrt(a1 + e1);
		std::cout << "Module of complex number: " << modulecomplex << "\n\n";
	} else if (answer == 2) {
		double a2 = pow(ActualPart2, 2);
		double e2 = pow(ImaginaryPart2, 2);
		double modulecomplex = sqrt(a2 + e2);
		std::cout << "Module of complex number: " << modulecomplex << "\n\n";
	} else {
		std::cout << "Wrong answer, try again!\n\n";
		ModuleComplex();
	}
}
void TComplex::PowerPComplex() {
	int answer, power;
	std::cout << "Select one of the complex numbers:\n";
	std::cout << "1.";
	Output(ActualPart1, ImaginaryPart1);
	std::cout << ".\n";
	std::cout << "2.";
	Output(ActualPart2, ImaginaryPart2);
	std::cout << ".\n";
	std::cout << "Your answer: ";
	std::cin >> answer;
	std::cout << "\n";

	if (answer == 1) {
		std::cout << "Enter a power for complex number: ";
		std::cin >> power;
		std::cout << "\n";

		double a1 = pow(ActualPart1, 2);
		double e1 = pow(ImaginaryPart1, 2);
		double modulecomplex = pow(sqrt(a1 + e1), power);
		double arc = atan(ImaginaryPart1 / ActualPart1) * power;
		std::cout << "The complex number to the raised power is equal to: ";
		Output(modulecomplex * cos(arc), sin(arc));
		std::cout << "\n\n";
	} else if (answer == 2) {
		std::cout << "Enter a power for complex number: ";
		std::cin >> power;
		std::cout << "\n";

		double a1 = pow(ActualPart2, 2);
		double e1 = pow(ImaginaryPart2, 2);
		double modulecomplex = pow(sqrt(a1 + e1), power);
		double arc = atan(ImaginaryPart2 / ActualPart2) * power;
		std::cout << "The complex number to the raised power is equal to: ";
		Output(modulecomplex * cos(arc), sin(arc));
		std::cout << "\n\n";
	} else {
		std::cout << "Wrong answer, try again!\n\n";
		PowerPComplex();
	}
}
void TComplex::PowerMComplex() {
	int answer, power;
	std::cout << "Select one of the complex numbers:\n";
	std::cout << "1.";
	Output(ActualPart1, ImaginaryPart1);
	std::cout << ".\n";
	std::cout << "2.";
	Output(ActualPart2, ImaginaryPart2);
	std::cout << ".\n";
	std::cout << "Your answer: ";
	std::cin >> answer;
	std::cout << "\n";

	if (answer == 1) {
		std::cout << "Enter a power for complex number: ";
		std::cin >> power;
		std::cout << "\n";

		double a1 = pow(ActualPart1, 2);
		double e1 = pow(ImaginaryPart1, 2);
		double modulecomplex = 1 / pow(sqrt(a1 + e1), power * (-1));
		double arc = atan(ImaginaryPart1 / ActualPart1) * power;
		std::cout << "The complex number to the raised power is equal to: ";
		Output(modulecomplex * cos(arc), sin(arc));
		std::cout << "\n\n";
	} else if (answer == 2) {
		std::cout << "Enter a power for complex number: ";
		std::cin >> power;
		std::cout << "\n";

		double a1 = pow(ActualPart2, 2);
		double e1 = pow(ImaginaryPart2, 2);
		double modulecomplex = 1 / pow(sqrt(a1 + e1), power * (-1));
		double arc = atan(ImaginaryPart2 / ActualPart2) * power;
		std::cout << "The complex number to the raised power is equal to: ";
		Output(modulecomplex * cos(arc), sin(arc));
		std::cout << "\n\n";
	} else {
		std::cout << "Wrong answer, try again!\n\n";
		PowerMComplex();
	}
}
void TComplex::PowerDComplex() {
	int answer;
	double numerator, denominator;
	std::cout << "Select one of the complex numbers:\n";
	std::cout << "1.";
	Output(ActualPart1, ImaginaryPart1);
	std::cout << ".\n";
	std::cout << "2.";
	Output(ActualPart2, ImaginaryPart2);
	std::cout << ".\n";
	std::cout << "Your answer: ";
	std::cin >> answer;
	std::cout << "\n";

	if (answer == 1) {
		std::cout << "Enter the numerator of the power: ";
		std::cin >> numerator;
		std::cout << "Enter the denominator of the power: ";
		std::cin >> denominator;
		std::cout << "\n";

		double power = numerator / denominator;
		double a1 = pow(ActualPart1, 2);
		double e1 = pow(ImaginaryPart1, 2);
		double modulecomplex = pow(sqrt(a1 + e1), power);
		double arc = atan(ImaginaryPart1 / ActualPart1) * power;
		std::cout << "The complex number to the raised power is equal to: ";
		Output(modulecomplex * cos(arc), sin(arc));
		std::cout << "\n\n";
	} else if (answer == 2) {
		std::cout << "Enter the numerator of the degree: ";
		std::cin >> numerator;
		std::cout << "Enter the denominator of the degree: ";
		std::cin >> denominator;
		std::cout << "\n";

		double power = numerator / denominator;
		double a1 = pow(ActualPart2, 2);
		double e1 = pow(ImaginaryPart2, 2);
		double modulecomplex = pow(sqrt(a1 + e1), power);
		double arc = atan(ImaginaryPart2 / ActualPart2) * power;
		std::cout << "The complex number to the raised power is equal to: ";
		Output(modulecomplex * cos(arc), sin(arc));
		std::cout << "\n\n";
	} else {
		std::cout << "Wrong answer, try again!\n\n";
		PowerPComplex();
	}
}
void TComplex::PowerCComplex() {
	double ActualPart;
	std::cout << "Enter actual part: ";
	std::cin >> ActualPart;
	double ImaginaryPart;
	std::cout << "Enter imaginary part: ";
	std::cin >> ImaginaryPart;
	std::cout << "\n";

	double a1 = pow(ActualPart1, 2);
	double e1 = pow(ImaginaryPart1, 2);
	double modulecomplex = sqrt(a1 + e1);
	int ln = int(log(modulecomplex));
	double arc = atan(ImaginaryPart1 / ActualPart1);
	std::cout << "A complex number raised to a complex power is equal to: e^(";
	Output(ActualPart, ImaginaryPart);
	std::cout << ") * (" << ln << " + (";
	std::cout << arc << " + pi * n)i)\n\n";
}
void TComplex::TrigonometricComplex() {
	int answer;
	std::cout << "Select one of the complex numbers:\n";
	std::cout << "1.";
	Output(ActualPart1, ImaginaryPart1);
	std::cout << ".\n";
	std::cout << "2.";
	Output(ActualPart2, ImaginaryPart2);
	std::cout << ".\n";
	std::cout << "Your answer: ";
	std::cin >> answer;
	std::cout << "\n";

	if (answer == 1) {
		double a1 = pow(ActualPart1, 2);
		double e1 = pow(ImaginaryPart1, 2);
		double modulecomplex =sqrt(a1 + e1);
		double arc = atan(ImaginaryPart1 / ActualPart1);
		std::cout << "The trigonometric notation of a complex number is: ";
		Output(modulecomplex * cos(arc), sin(arc));
		std::cout << "\n\n";
	}
	else if (answer == 2) {
		double a1 = pow(ActualPart2, 2);
		double e1 = pow(ImaginaryPart2, 2);
		double modulecomplex = sqrt(a1 + e1);
		double arc = atan(ImaginaryPart2 / ActualPart2);
		std::cout << "The trigonometric notation of a complex number is: ";
		Output(modulecomplex * cos(arc), sin(arc));
		std::cout << "\n\n";
	}
	else {
		std::cout << "Wrong answer, try again!\n\n";
		PowerPComplex();
	}
}

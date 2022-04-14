#include <iostream>
#include "functions.h"
#include "classes.h"

int Functions() {
	int answer;
	std::cout << "Select one of the functions:\n";
	std::cout << "1.Enter string in colsole.\n";
	std::cout << "2.Generate random strings.\n";
	std::cout << "3.Get string from file.\n";
	std::cout << "Your answer: ";
	std::cin >> answer;
	std::cout << std::endl;

	if (answer > 0 && answer < 4) {
		return answer;
	} else {
		std::cout << "Wrong answer, try again!\n\n";
		Functions();
	}
	return 0;
}
std::string GetString() {
	std::string str;
	std::cout << "Enter string: ";
	std::cin >> str;
	return str;
}
int LineOptions() {
	int answer;
	std::cout << "Select one of the options:\n";
	std::cout << "1..\n";
	std::cout << "1..\n";
	std::cout << "1..\n";
	std::cout << "1..\n";
	std::cin >> answer;
	std::cout << "\n";

	if (answer > 0 && answer < 6) {
		return answer;
	} else {
		std::cout << "Wong answer, try again!\n\n";
		LineOptions();
	}
	return 0;
}
void GetOption(int answer, std::string str1, std::string str2) {
	TStrings strings{str1, str2};

	if (answer == 1) {
		strings.AddLines();
	} else if (answer == 2) {
		strings.EquateLines();
	} else if (answer == 3) {
		strings.CompareLines();
	} else if (answer == 4) {
		strings.BoSLines();
	} else if (answer == 5) {
		strings.DublicateLine();
	} else if (answer == 6) {
		strings.FindLine();
	}
}

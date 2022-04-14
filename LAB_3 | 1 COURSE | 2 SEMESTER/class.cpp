#include <iostream>
#include "classes.h"

int TStrings::Options() {
	std::cout << "Select one of the functions:\n";
	std::cout << "1.Add lines.\n";
	std::cout << "2.Equate one line to another.\n";
	std::cout << "3.Compare lines.\n";
	std::cout << "4.Which line is bigger or smaller.\n";
	std::cout << "5.[] - something strange???\n";
	std::cout << "Your answer: ";
	std::cin >> answer;
	std::cout << "\n";

	if (answer > 0 && answer < 6) {
		return answer;
	} else {
		std::cout << "Wrong answer, try again!\n\n";
		Options();
	}
	return 0;
}
void TStrings::Restart() {}

void TStrings::AddLines() {
	std::string string = string1 + string2;
	std::cout << "Your new string is:\n";
	std::cout << string << "\n";
}
void TStrings::EquateLines() {
	std::cout << "Select one of the functions:\n";
	std::cout << "1.string 1 = string 2.\n";
	std::cout << "2.string 2 = string 1.\n";
	std::cout << "Your answer: ";
	std::cin >> answer;
	std::cout << "\n";

	if (answer == 1) {
		string1 = string2;
		std::cout << "String 1: " << string1 << "\n";
		std::cout << "String 2: " << string2 << "\n";
	} else if (answer == 2) {
		string2 = string1;
		std::cout << "String 1: " << string1 << "\n";
		std::cout << "String 2: " << string2 << "\n";
	} else {
		std::cout << "Wrong answer, try again!\n\n";
		EquateLines();
	}
}
void TStrings::CompareLines() {
	if (string1 == string2) {
		std::cout << "The lines are equal.\n";
	} else {
		std::cout << "The lines are not equal.\n";
	}
}
void TStrings::BoSLines() {
	if (string1 > string2) {
		std::cout << "The first line is larger than the second line.\n";
	} else if (string1 < string2) {
		std::cout << "The second line is larger than the first line.\n";
	} else {
		std::cout << "The lines are equal.\n";
	}
}


void TStrings::DublicateLine() {
	int count;
	std::cout << "Enter count to repeat line: ";
	std::cin >> count;
	std::cout << "\n";

	std::cout << "Select string: ";
	std::cout << "1.String 1.\n";
	std::cout << "2.String 2.\n";
	std::cout << "Your answer: ";
	std::cin >> answer;
	std::cout << "\n";

	std::string string;
	if (answer == 1) {
		for (int n = 0; n < count; n++) {
			string += string1;
		}
		std::cout << "Your string is: " << string << "\n\n";
	} else if (answer == 2) {
		for (int n = 0; n < count; n++) {
			string += string2;
		}
		std::cout << "Your string is: " << string << "\n\n";
	} else {
		std::cout << "Wrong answer, try again!\n\n";
		DublicateLine();
	}
}
void TStrings::FindLine() {
	int lenfind;
	std::string find;
	std::cout << "Enter string, which you want to find.\n";
	std::cout << "Your answer: ";
	std::cin >> find;
	lenfind = strlen(find.c_str());
	std::cout << "\n";

	std::cout << "Select string: ";
	std::cout << "1.String 1.\n";
	std::cout << "2.String 2.\n";
	std::cout << "Your answer: ";
	std::cin >> answer;
	std::cout << "\n";

	int count = 0;
	if (answer == 1) {
		int lenstring = strlen(string1.c_str());
		for (int n = 0; n < lenstring - lenfind; n++) {
			std::string slice = string1.substr(n, n + lenfind);
			if (slice == find) {
				count += 1;
			}
		}
		std::cout << "Count = " << count << "\n";
	} else if (answer == 2) {
		int lenstring = strlen(string2.c_str());
		for (int n = 0; n < lenstring - lenfind; n++) {
			std::string slice = string2.substr(n, n + lenfind);
			if (slice == find) {
				count += 1;
			}
		}
		std::cout << "Count = " << count << "\n";
	} else {
		std::cout << "Wrong answer, try again!\n\n";
		FindLine();
	}
}

TStrings::~TStrings() {};

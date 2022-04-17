#include <iostream>
#include "functions.h"
#include "classes.h"

int Functions();
std::string GetString();
int LineOptions();
void GetOption(int answer, std::string str1, std::string str2);
void Restart(int answer, std::string str1, std::string str2);


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
	std::cout << "1.Add strings.\n";
	std::cout << "2.Copy strings.\n";
	std::cout << "3.Compare strings.\n";
	std::cout << "4.Which string is bigger.\n";
	std::cout << "5.Find the index of the entered string.\n";
	std::cout << "6.Copy a string multiple times.\n";
	std::cout << "7.Find an item in string.\n";
	std::cout << "Your answer: ";
	std::cin >> answer;
	std::cout << "\n";

	if (answer > 0 && answer < 8) {
		return answer;
	} else {
		std::cout << "Wrong answer, try again!\n\n";
		LineOptions();
	}
	return 0;
}
void GetOption(int answer, std::string str1, std::string str2) {
	TStrings strings{str1, str2};

	if (answer == 1) {
		strings.AddStrings();
	} else if (answer == 2) {
		strings.EquateStrings();
	} else if (answer == 3) {
		strings.CompareStrings();
	} else if (answer == 4) {
		strings.BMString();
	} else if (answer == 5){
		strings.IndexString();
	} else if (answer == 6) {
		strings.DublicateString();
	} else if (answer == 7) {
		strings.FindString();
	}
	std::cout << "\n";
	Restart(answer, str1,str2);
}
void Restart(int answer, std::string str1, std::string str2) {
	std::cout << "Do you want to do something else?\n";
	std::cout << "1.Yes.\n2.No.\n";
	std::cout << "Your answer: ";
	std::cin >> answer;
	std::cout << "\n";

	if (answer == 1) {
		int option = LineOptions();
		GetOption(option, str1, str2);
	} else if (answer == 2) {
		std::cout << "Okay, goodbye!\n\n";
	} else {
		std::cout << "Wrong answer, try again!\n\n";
		Restart(answer, str1, str2);
	}
}

#include <iostream>
#include "classes.h"

void TStrings::AddStrings() {
	string = string1 + string2;
	std::cout << "Your new string is: ";
	std::cout << string << "\n";
}
void TStrings::EquateStrings() {
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
		EquateStrings();
	}
}
void TStrings::CompareStrings() {
	if (string1 == string2) {
		std::cout << "The strings are equal.\n";
	} else {
		std::cout << "The strings are not equal.\n";
	}
}
void TStrings::BMString() {
	if (string1 > string2) {
		std::cout << "The first string is larger than the second line.\n";
	} else if (string1 < string2) {
		std::cout << "The second string is larger than the first line.\n";
	} else {
		std::cout << "The strings are equal.\n";
	}
}
void TStrings::IndexString() {
	std::cout << "Select a string for further index search:\n";
	std::cout << "1.String 1.\n";
	std::cout << "2.String 2.\n";
	std::cout << "Your answer: ";
	std::cin >> answer;
	std::cout << "\n";

	std::string string;
	if (answer == 1) {
		std::cout << "Enter the search string: ";
		std::cin >> string;
		std::cout << "\n";
		int lenfind = strlen(string.c_str());
		int lenstr = strlen(string1.c_str());
		std::cout << "Here are the indexes. which could be found: ";
		if (lenfind == 1) {
			for (int n = 0; n < lenstr; n++) {
				if (string[0] == string1[n]) {
					std::cout << n << " ";
				}
			}
		} else {
			for (int n = 0; n < lenstr; n++) {
				std::string slice = string1.substr(n, (static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(n) + lenfind));
				if (string == slice) {
					std::cout << n;
				}
			}
		}
		std::cout << "\n";
	} else if (answer == 2) {
		std::cout << "Enter the search string: ";
		std::cin >> string;
		std::cout << "\n";
		int lenfind = strlen(string.c_str());
		int lenstr = strlen(string2.c_str());
		std::cout << "Here are the indexes. which could be found: ";
		if (lenfind == 1) {
			for (int n = 0; n < lenstr; n++) {
				if (string[0] == string2[n]) {
					std::cout << n;
				}
			}
		} else {
			for (int n = 0; n < lenstr; n++) {
				std::string slice = string2.substr(n, (static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(n) + lenfind));
				if (string == slice) {
					std::cout << n;
				}
			}
		}
		std::cout << "\n";
	} else {
		std::cout << "Wrong answer, try again!\n\n";
	}
}


void TStrings::DublicateString() {
	int count;
	std::cout << "Enter count to repeat string: ";
	std::cin >> count;
	std::cout << "\n";

	std::cout << "Select the string:\n";
	std::cout << "1.String 1.\n";
	std::cout << "2.String 2.\n";
	std::cout << "Your answer: ";
	std::cin >> answer;
	std::cout << "\n";

	if (answer == 1) {
		for (int n = 0; n < count; n++) {
			string += string1;
		}
		std::cout << "Your string is: " << string << "\n";
	} else if (answer == 2) {
		for (int n = 0; n < count; n++) {
			string += string2;
		}
		std::cout << "Your string is: " << string << "\n";
	} else {
		std::cout << "Wrong answer, try again!\n\n";
		DublicateString();
	}
}
void TStrings::FindString() {
	int lenfind;
	std::string find;
	std::cout << "Enter string, which you want to find.\n";
	std::cout << "Your answer: ";
	std::cin >> find;
	lenfind = strlen(find.c_str());
	std::cout << "\n";

	std::cout << "Select string:\n";
	std::cout << "1.String 1.\n";
	std::cout << "2.String 2.\n";
	std::cout << "Your answer: ";
	std::cin >> answer;
	std::cout << "\n";

	int count = 0;
	if (answer == 1) {
		int lenstring = strlen(string1.c_str());
		for (int n = 0; n < lenstring - lenfind; n++) {
			std::string slice = string1.substr(n, (static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(n) + lenfind));
			if (slice == find) {
				count += 1;
			}
		}
		std::cout << "The string <" << find << "> ";
		std::cout << "occurs " << count << " times.\n\n";
	} else if (answer == 2) {
		int lenstring = strlen(string2.c_str());
		for (int n = 0; n < lenstring - lenfind; n++) {
			std::string slice = string2.substr(n, static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(n) + lenfind);
			if (slice == find) {
				count += 1;
			}
		}
		std::cout << "The string <" << find << "> ";
		std::cout << "occurs " << count << " times.\n\n";
	} else {
		std::cout << "Wrong answer, try again!\n\n";
		FindString();
	}
}

TStrings::~TStrings() {};

#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include "classes.h"


int TStrings::SelectString() {
	int answer;
	std::cout << "Select a string for further index search:\n";
	std::cout << "1.String 1.\n";
	std::cout << "2.String 2.\n";
	std::cout << "Your answer: ";
	std::cin >> answer;
	std::cout << "\n";
	return answer;
}

void TStrings::AddStrings() {
	string = string1 + string2;
	std::cout << "Your new string is: ";
	std::cout << string << "\n";
	string.clear();
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
	std::string string;

	answer = SelectString();

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
				slice.clear();
			}
		}
		std::cout << "\n";
		string.clear();
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
				slice.clear();
			}
		}
		std::cout << "\n";
		string.clear();
	} else {
		std::cout << "Wrong answer, try again!\n\n";
		IndexString();
	}
}


void TStrings::DublicateString() {
	answer = SelectString();

	int count;
	std::cout << "Enter count to repeat string: ";
	std::cin >> count;
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
	answer = SelectString();

	if (answer == 1) {
		int count = 0;
		std::string find;

		std::cout << "Enter string, which you want to find.\n";
		std::cout << "Your answer: ";
		std::cin >> find;
		std::cout << "\n";

		int lenfind = strlen(find.c_str());
		int lenstr = strlen(string1.c_str());

		for (int n = 0; n < lenstr - lenfind; n++) {
			std::string slice = string1.substr(n, (static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(n) + lenfind));
			if (slice == find) {
				count += 1;
			}
			slice.clear();
		}
		std::cout << "The string <" << find << "> ";
		std::cout << "occurs " << count << " times.\n\n";
		find.clear();
	} else if (answer == 2) {
		int count = 0;
		std::string find;

		std::cout << "Enter string, which you want to find.\n";
		std::cout << "Your answer: ";
		std::cin >> find;
		std::cout << "\n";

		int lenfind = strlen(find.c_str());
		int lenstr = strlen(string2.c_str());

		for (int n = 0; n < lenstr - lenfind; n++) {
			std::string slice = string2.substr(n, static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(n) + lenfind);
			if (slice == find) {
				count += 1;
			}
			slice.clear();
		}
		std::cout << "The string <" << find << "> ";
		std::cout << "occurs " << count << " times.\n\n";
		string.clear();
	} else {
		std::cout << "Wrong answer, try again!\n\n";
		FindString();
	}
}
void TStrings::CountString() {
	answer = SelectString();

	if (answer == 1) {
		std::map<char, std::size_t> map;
		for (const auto& i : string1) {
			map[i]++;
		}
		std::cout << "The most frequent character in the string: ";
		std::cout << (*std::max_element(map.cbegin(), map.cend(), [](const auto& m1, const auto& m2) {
			return m1.second < m2.second;
			})).first << "\n";
		map.clear();
	} else if (answer == 2) {
		std::cout << "The most frequent character in the string: ";
		std::map<char, std::size_t> map;
		for (const auto& i : string2) {
			map[i]++;
		}
		std::cout << (*std::max_element(map.cbegin(), map.cend(), [](const auto& m1, const auto& m2) {
			return m1.second < m2.second;
			})).first << "\n";
		map.clear();
	} else {
		std::cout << "Wrong answer, try again!\n\n";
		CountString();
	}
}
void TStrings::SymbolsInString() {
	answer = SelectString();

	if (answer == 1) {
		std::set <char> symbols;
		int lenstr = strlen(string1.c_str());
		for (int n = 0; n < lenstr; n++) {
			symbols.insert(string1[n]);
		}
		std::cout << "Characters that are in the string: ";
		for (auto &item : symbols) {
			std::cout << item << " ";
		}
		std::cout << "\n\n";
		symbols.clear();
	} else if (answer == 2) {
		std::set <char> symbols;
		int lenstr = strlen(string2.c_str());
		for (int n = 0; n < lenstr; n++) {
			symbols.insert(string2[n]);
		}
		std::cout << "Characters that are in the string: ";
		for (auto &item : symbols) {
			std::cout << item << " ";
		}
		std::cout << "\n\n";
		symbols.clear();
	} else {
		std::cout << "Wrong answer, try again!\n\n";
		SymbolsInString();
	}
}
void TStrings::CountSymbolsInString() {
	answer = SelectString();

	if (answer == 1) {
		std::set <char> symbols;
		int lenstr = strlen(string1.c_str());
		for (int n = 0; n < lenstr; n++) {
			symbols.insert(string1[n]);
		}
		std::cout << "Characters that are in the string:\n";
		for (auto& item : symbols) {
			int count = 0;
			for (int n = 0; n < lenstr; n++) {
				if (string1[n] == item) {
					count += 1;
				}
			}
			std::cout << item << ": " << count << "\n";
		}
		std::cout << "\n";
		symbols.clear();
	} else if (answer == 2) {
		std::set <char> symbols;
		int lenstr = strlen(string2.c_str());
		for (int n = 0; n < lenstr; n++) {
			symbols.insert(string2[n]);
		}
		std::cout << "Characters that are in the string:\n";
		for (auto& item : symbols) {
			int count = 0;
			for (int n = 0; n < lenstr; n++) {
				if (string2[n] == item) {
					count += 1;
				}
			}
			std::cout << item << ": " << count << "\n";
		}
		std::cout << "\n";
		symbols.clear();
	}
	else {
		std::cout << "Wrong answer, try again!\n\n";
		CountSymbolsInString();
	}
};

TStrings::~TStrings() {
	string1.clear();
	string2.clear();
};

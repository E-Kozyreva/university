#include <iostream>
#include <string>
#include "random.h"

int GetRandomSymbol(int min, int max) {
	if (min < max) {
		int symbol = min + rand() % (max - min + 1);
		return symbol;
	} else if (max < min) {
		int symbol = max + rand() % (min - max + 1);
		return symbol;
	}
	return 0;
}
std::string GetData(int answer) {
	int min, max;
	int len;
	char mins, maxs;
	std::string string;
	if (answer == 1) {
		std::cout << "Enter min: ";
		std::cin >> mins;
		std::cout << "Enter max: ";
		std::cin >> maxs;
		std::cout << "Enter len of the string: ";
		std::cin >> len;
		std::cout << "\n";
		min = (int)mins;
		max = (int)maxs;
		for (int n = 0; n < len; n++) {
			string += (char)GetRandomSymbol(min, max);
		}
		return string;
	} else if (answer == 2) {
		std::cout << "Enter len of the string: ";
		std::cin >> len;
		std::cout << "\n";
		min = 65;
		max = 123;
		for (int n = 0; n < len; n++) {
			string += (char)GetRandomSymbol(min, max);
		}
		return string;
	}
	return string;
}
std::string GetRandom() {
	int answer;
	std::string string;
	std::cout << "Select one of the function:\n";
	std::cout << "1.Generate in the range (min | max).\n";
	std::cout << "2.Generate without range.\n";
	std::cout << "Your answer: ";
	std::cin >> answer;
	std::cout << "\n";
	if (answer == 1) {
		string = GetData(answer);
		std::cout << "Your string: ";
		std::cout << string << "\n\n";
		return string;
	} else if (answer == 2) {
		string = GetData(answer);
		std::cout << "Your string: ";
		std::cout << string << "\n\n";
		return string;
	} else {
		std::cout << "Wrong answer, try again!\n\n";
		GetRandom();
	}
	return string;
}

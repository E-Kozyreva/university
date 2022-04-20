#include <iostream>
#include <string>
#include "classes.h"
#include "functions.h"
#include "random.h"


int main() {
	int function, option;
	std::string str1, str2;

	function = Functions();

	if (function == 1) {
		str1 = GetString();
		str2 = GetString();
		std::cout << "\n";
		option = LineOptions();
		GetOption(option, str1, str2);
	} else if (function == 2) {
		str1 = GetRandom();
		str2 = GetRandom();
		option = LineOptions();
		GetOption(option, str1, str2);
	}
	return 0;
}

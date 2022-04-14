#include <iostream>
#include <string>
#include "classes.h"
#include "functions.h"


int main() {
	int function, option;
	std::string str1, str2;
	function = Functions();

	if (function == 1) {
		str1 = GetString();
		str2 = GetString();
		option = LineOptions();
		GetOption(option, str1, str2);
	}
	return 0;
}

class TTransport {
public:
	int answer;
	int SelectType() {
		std::cout << "Select type of transport:\n";
		std::cout << "1.Land.\n2.Water.\n3.Air.\n";
		std::cout << "Your answer: ";
		std::cin >> answer;
		std::cout << "\n";

		return answer;
	}
};

class TLand:public TTransport {
public:
	std::string name;
	std::string description;
	int Description() {
		name = "\nLand ";
		description = "- transportation or movement of people, animals "
			          "or goods from one place to another on land. The "
                      "two main types of land transport can be considered "
                      "railway and automobile.\n\n";
		std::cout << "Do you want to read description?\n1.Yes.\n2.No.\n";
		std::cout << "0.Exit.\n";
		std::cout << "Your answer: ";
		std::cin >> answer;
		std::cout << "\n";

		return answer;
	}
	void TypesOfTranspot() {
		std::cout << "\nSelect a transport. Enter number of transport:\n";
		std::string types[9] = {"Bus", "Taxi", "Train",
								            "Car", "Motorcycle", 
			                      "Subway", "Snowmobile", 
			                      "Trolleybus", "Tram", };
		for (int num = 1; num < 10; num++) {
			std::cout << num << "." << types[num - 1] << ".\n";
		}
	}
	int SelectTypeOfTransport() {
        std::cout << "0.Exit.\n";
		std::cout << "Your answer: ";
		std::cin >> answer;
		std::cout << "\n";

		return answer;
	}
};

class TWater:public TTransport {
public:
	std::string name;
	std::string description;
	int Description() {
		name = "\nWater ";
		description = "- a type of transport that transports cargo "
			          "and/or passengers along waterways, both natural "
			          "(oceans, seas, rivers, lakes) and artificial "
			          "(canals, reservoirs).\n\n";
		std::cout << "Do you want to read description?\n1.Yes.\n2.No.\n";
		std::cout << "0.Exit.\n";
		std::cout << "Your answer: ";
		std::cin >> answer;
		std::cout << "\n";

		return answer;
	}
	void TypesOfTranspot() {
		std::cout << "\nSelect a transport. Enter number of transport:\n";
		std::string types[6] = {"Ship", "Ferry", 
			                      "Boat", "Motor ship", 
			                      "Yacht", "Vessel", };
		for (int num = 1; num < 7; num++) {
			std::cout << num << "." << types[num - 1] << ".\n";
		}
	}
	int SelectTypeOfTransport() {
		std::cout << "0.Exit.\n";
		std::cout << "Your answer: ";
		std::cin >> answer;
		std::cout << "\n";

		return answer;
	}
};

class TAir:public TTransport {
public:
	std::string name;
	std::string description;
	int Description() {
		name = "\nAir ";
		description = "- a type of transport that transports cargo "
			          "and passengers by air with the help of aircraft: "
			          "airplanes, helicopters, etc.; helps internationalization "
			          "and globalization of all aspects of human activity.\n\n";
		std::cout << "Do you want to read description?\n1.Yes.\n2.No.\n";
		std::cout << "0.Exit.\n";
		std::cout << "Your answer: ";
		std::cin >> answer;
		std::cout << "\n";

		return answer;
	}
	void TypesOfTranspot() {
		std::cout << "\nSelect a transport. Enter number of transport:\n";
		std::string types[3] = {"Plane", "Helicopter", "Balloon"};
		for (int num = 1; num < 4; num++) {
			std::cout << num << "." << types[num - 1] << ".\n";
		}
	}
	int SelectTypeOfTransport() {
		std::cout << "0.Exit.\n";
		std::cout << "Your answer: ";
		std::cin >> answer;
		std::cout << "\n";

		return answer;
	}
};

#include <iostream>
#include <string>

class Ship:public Water {
public:
	std::string name;
	std::string description;
	void Information() {
		name = "Ship ";
		description = "- this is a large watercraft that travels"
			          "through the world's oceans and other fairly "
			          "deep waterways, transporting goods or passengers, "
			          "as well as performing specialized tasks such as defense, "
			          "research and fishing.\n\n";
		std::cout << name;
		std::cout << description;
	}
};

class Ferry:public Water {
public:
	std::string name;
	std::string description;
	void Information() {
		name = "Ferry ";
		description = "- this is a water vehicle adapted for the transportation"
			          "of people, animals, cargo, road and rail transport "
			          "between the two shores of the water surface. I.e. used "
			          "to maintain a seasonal or permanent crossing, in cases "
		              "where the construction of a permanent bridge is "
			          "impractical.\n\n";
		std::cout << name;
		std::cout << description;
	}
};

class Boat:public Water {
public:
	std::string name;
	std::string description;
	void Information() {
		name = "Boat ";
		description = "- a small vessel. In the Russian Naval "
			          "Dictionary, a boat is defined as a vessel "
			          "up to nine meters long, up to three meters "
			          "wide and with a payload capacity of up to "
			          "five tons.\n\n";
		std::cout << name;
		std::cout << description;
	}
};

class MotorShip:public Water {
public:
	std::string name;
	std::string description;
	void Information() {
		name = "Motor ship ";
		description = "- a small vessel equipped with an outboard "
			          "motor. The presence of an easily removable "
			          "outboard motor is the only qualifying feature "
			          "in the definition and distinguishes a 'motor boat' "
			          "from a 'boat' (the engine on which is installed "
			          "permanently), regardless of the power and appearance "
			          "of a small vessel (however, boats with cabins with "
			          "sleeping places, with a latrine, are widely distributed, "
			          "while designed to install several outboard motors, often "
			          "with a total capacity of several hundred hp).\n\n";
		std::cout << name;
		std::cout << description;
	}
};

class Yacht:public Water {
public:
	std::string name;
	std::string description;
	void Information() {
		name = "Yacht ";
		description = "- originally a light and fast vessel for "
			          "transporting individuals, equipped with a "
			          "deckand a cabin(cabins).In the modern sense — "
			          "any vessel intended for sports or tourist purposes "
			          "and recreation.Yachts do not include scheduled vessels "
			          "intended for commercial purposes, for the transportation "
			          "of a large number of passengers(when the main purpose is "
			          "transportation, not recreation and entertainment on board "
			          "the vessel) and other transport purposes.\n\n";
		std::cout << name;
		std::cout << description;
	}
};

class Vessel:public Water {
public:
	std::string name;
	std::string description;
	void Information() {
		name = "Vessel ";
		description = "- it is a floating engineering structure designed "
			          "to transport cargo, passengers and perform other "
			          "special tasks. The vessel consists of a hull, "
			          "superstructures.\n\n";
		std::cout << name;
		std::cout << description;
	}
};

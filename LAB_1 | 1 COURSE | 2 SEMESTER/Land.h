class TBus:public TLand {
public:
	void Information() {
		name = "Bus ";
		description = "- a trackless mechanical motor vehicle "
			            "technically designed to carry nine or "
			            "more passengers and capable of maneuvering "
			            "on the road, driven by an energy source stored "
			            "or produced from fuel stored on board (there are "
			            "battery, supercapacitor, diesel, gas-fuel buses and "
			            "fuel cell buses).\n\n";
		std::cout << name;
		std::cout << description;
	}
};

class TTaxi:public TLand {
public:
	void Information() {
		name = "Taxi ";
		description = "- a car used to transport passengers to any "
			            "specified point with the payment of the car's "
			            "fare according to a taximeter.\n\n";
		std::cout << name;
		std::cout << description;
	}
};

class TTrain:public TLand {
public:
	void Information() {
		name = "Train ";
		description = "- that is a group of interconnected railway "
			            "cars with the obligatory presence of a driving "
			            "unit — a locomotive or a motor car.\n\n";
		std::cout << name;
		std::cout << description;
	}
};

class TCar:public TLand {
public:
	void Information() {
		name = "Car ";
		description = "- a motor road and off-road vehicle used "
			            "to transport people and goods.\n\n";
		std::cout << name;
		std::cout << description;
	}
};

class TMotorcycle:public TLand {
public:
	void Information() {
		name = "Motorcycle ";
		description = "- a two-wheeled (or three-wheeled) vehicle "
			            "with or without a side trailer, having a maximum "
			            "mass of no more than 400 kg and an engine with a "
			            "volume of more than 50 cm3 in the case of an internal "
			            "combustion engine (and/or a rated power of more than "
			            "4 kW in the case of an electric motor).\n\n";
		std::cout << name;
		std::cout << description;
	}
};

class TSubway:public TLand {
public:
	void Information() {
		name = "Subway ";
		description = "- rail off-street urban public transport "
			            "with electric traction.\n\n";
		std::cout << name;
		std::cout << description;
	}
};

class TSnowmobile:public TLand {
public:
	void Information() {
		name = "Snowmobile ";
		description = "- a ski is a small tracked vehicle with "
			            "controls in the image of a motorcycle, "
			            "designed for winter trips on snow-covered "
			            "trails.\n\n";
		std::cout << name;
		std::cout << description;
	}
};

class TTrolleybus:public TLand {
public:
	void Information() {
		name = "Trolleybus ";
		description = "- a trackless mechanical vehicle (mainly "
			            "passenger, although freight and special "
			            "purpose trolleybuses are found) of a contact "
			            "type with an electric drive, receiving electric "
			            "current from an external power source (from central "
			            "power stations) through a two-wire contact network "
			            "using a rod pantograph and combining the advantages "
			            "of a tram and a bus.\n\n";
		std::cout << name;
		std::cout << description;
	}
};

class TTram:public TLand {
public:
	void Information() {
		name = "Tram ";
		description = "- ground electric railway, a type of "
			            "street and partially street public transport "
			            "for transporting passengers along specified "
			            "routes, used mainly in cities.\n\n";
		std::cout << name;
		std::cout << description;
	}
};

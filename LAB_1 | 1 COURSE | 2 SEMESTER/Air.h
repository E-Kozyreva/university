class TPlane:public TAir {
public:
	void Information() {
		name = "Plane ";
		description = "- a heavier-than-air aircraft designe "
			            "to fly in the atmosphere using a propulsion "
			            "system that creates thrust and a fixed wing relative "
			            "to other parts of the apparatus that creates lift.\n\n";
		std::cout << name;
		std::cout << description;
	}
};

class THelicopter:public TAir {
public:
	void Information() {
		name = "Helicopter ";
		description = "- a rotorcraft of vertical takeoff and landing, "
			            "in which the lifting and propulsive forces at all "
			            "stages of flight are created by one or more rotors "
			            "driven by one or more engines.\n\n";
		std::cout << name;
		std::cout << description;
	}
};

class TBalloon:public TAir {
public:
	void Information() {
		name = "Balloon ";
		description = "- an aircraft (balloon) in which a gas that is "
			            "lighter than air is used for flight. It consists "
			            "of a gas-filled shell and a basket or trailer cab "
			            "attached to it.\n\n";
		std::cout << name;
		std::cout << description;
	}
};

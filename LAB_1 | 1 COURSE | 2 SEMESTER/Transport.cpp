#include <iostream>
#include <string>
#include "Typer.h"
#include "Land.h"
#include "Water.h"
#include "Air.h"

int SelectTransport();

int LandDescription();
int LandSelect();
int LandTransport(int transport);

int WaterDescription();
int WaterSelect();
int WaterTransport(int transport);

int AirDescription();
int AirSelect();
int AirTransport(int transport);

int RestartTransport(int answer);
int RestartOrEnd(int ClassNumber);

int SelectTransport() {
	int answer;
	Transport transport;
	answer = transport.SelectType();

	if (answer > 0 && answer < 4)
		return RestartTransport(answer);
	else {
		std::cout << "Wrong answer, try again!\n\n";
		return SelectTransport();
	}
    return 0;
}

int LandDescription() {
	int answer;
	Land land;
	answer = land.Description();

	if (answer == 1) {
		std::cout << land.name;
		std::cout << land.description;
		LandSelect();
	}
	else if (answer == 2)
		LandSelect();
	else if (answer == 0)
		SelectTransport();
	else {
		std::cout << "Wrong answer, try again!\n\n";
		return LandDescription();
	}
	return 0;
}
int LandSelect() {
	int answer;
	Land land;
	land.TypesOfTranspot();
	answer = land.SelectTypeOfTransport();

	if (answer > 0 && answer < 10)
		return LandTransport(answer);
	else if (answer == 0) {
		std::cout << "Which step do you want to go back to?\n";
		std::cout << "1.Description.\n2.Transport.\n";
		std::cout << "Your answer: ";
		std::cin >> answer;
		std::cout << "\n";

		if (answer == 1)
			LandDescription();
		else if (answer == 2)
			SelectTransport();
		else {
			std::cout << "Wrong answer, try again!\n\n";
			SelectTransport();
		}
	}
	else {
		std::cout << "Wrong answer, try again!\n\n";
		return LandSelect();
	}
	return 0;
}
int LandTransport(int transport) {
	if (transport == 1) {
		Bus bus;
		bus.Information();
		RestartOrEnd(1);
	}
	else if (transport == 2) {
		Taxi taxi;
		taxi.Information();
		RestartOrEnd(1);
	}
	else if (transport == 3) {
		Train train;
		train.Information();
		RestartOrEnd(1);
	}
	else if (transport == 4) {
		Car car;
		car.Information();
		RestartOrEnd(1);
	}
	else if (transport == 5) {
		Motorcycle motorcycle;
		motorcycle.Information();
		RestartOrEnd(1);
	}
	else if (transport == 6) {
		Subway subway;
		subway.Information();
		RestartOrEnd(1);
	}
	else if (transport == 7) {
		Snowmobile snowmobile;
		snowmobile.Information();
		RestartOrEnd(1);
	}
	else if (transport == 8) {
		Trolleybus trolleybus;
		trolleybus.Information();
		RestartOrEnd(1);
	}
	else if (transport == 9) {
		Tram tram;
		tram.Information();
		RestartOrEnd(1);
	}
	return 0;
}

int WaterDescription() {
	int answer;
	Water water;
	answer = water.Description();

	if (answer == 1) {
		std::cout << water.name;
		std::cout << water.description;
		WaterSelect();
	}
	else if (answer == 2)
		WaterSelect();
	else if (answer == 0)
		SelectTransport();
	else {
		std::cout << "Wrong answer, try again!\n\n";
		return WaterDescription();
	}
	return 0;
}
int WaterSelect() {
	int answer;
	Water water;
	water.TypesOfTranspot();
	answer = water.SelectTypeOfTransport();

	if (answer > 0 && answer < 7)
		return WaterTransport(answer);
	else if (answer == 0) {
		std::cout << "Which step do you want to go back to?\n";
		std::cout << "1.Description.\n2.Transport.\n";
		std::cout << "Your answer: ";
		std::cin >> answer;
		std::cout << "\n";

		if (answer == 1)
			WaterDescription();
		else if (answer == 2)
			SelectTransport();
		else {
			std::cout << "Wrong answer, try again!\n\n";
			SelectTransport();
		}
	}
	else {
		std::cout << "Wrong answer, try again!\n\n";
		return WaterSelect();
	}
	return 0;
}
int WaterTransport(int transport) {
	if (transport == 1) {
		Ship ship;
		ship.Information();
		RestartOrEnd(2);
	}
	else if (transport == 2) {
		Ferry ferry;
		ferry.Information();
		RestartOrEnd(2);
	}
	else if (transport == 3) {
		Boat boat;
		boat.Information();
		RestartOrEnd(2);
	}
	else if (transport == 4) {
		MotorShip motorship;
		motorship.Information();
		RestartOrEnd(2);
	}
	else if (transport == 5) {
		Yacht yacht;
		yacht.Information();
		RestartOrEnd(2);
	}
	else if (transport == 6) {
		Vessel vessel;
		vessel.Information();
		RestartOrEnd(2);
	}
	return 0;
}

int AirDescription() {
	int answer;
	Air air;
	answer = air.Description();

	if (answer == 1) {
		std::cout << air.name;
		std::cout << air.description;
		AirSelect();
	}
	else if (answer == 2)
		AirSelect();
	else if (answer == 0)
		SelectTransport();
	else {
		std::cout << "Wrong answer, try again!\n\n";
		return AirDescription();
	}
	return 0;
}
int AirSelect() {
	int answer;
	Air air;
	air.TypesOfTranspot();
	answer = air.SelectTypeOfTransport();

	if (answer > 0 && answer < 4)
		return AirTransport(answer);
	else if (answer == 0) {
		std::cout << "Which step do you want to go back to?\n";
		std::cout << "1.Description.\n2.Transport.\n";
		std::cout << "Your answer: ";
		std::cin >> answer;
		std::cout << "\n";

		if (answer == 1)
			AirDescription();
		else if (answer == 2)
			SelectTransport();
		else {
			std::cout << "Wrong answer, try again!\n\n";
			return SelectTransport();
		}
	}
	else {
		std::cout << "Wrong answer, try again!\n\n";
		return AirSelect();
	}
	return 0;
}
int AirTransport(int transport) {
	if (transport == 1) {
		Plane plane;
		plane.Information();
		RestartOrEnd(3);
	}
	else if (transport == 2) {
		Helicopter helicopter;
		helicopter.Information();
		RestartOrEnd(3);
	}
	else if (transport == 3) {
		Balloon balloon;
		balloon.Information();
		RestartOrEnd(3);
	}
	return 0;
}

int RestartTransport(int answer) {
	if (answer == 1) {
		LandDescription();
	}
	else if (answer == 2) {
		WaterDescription();
	}
	else if (answer == 3) {
		AirDescription();
	}
	return 0;
}
int RestartOrEnd(int ClassNumber) {
	int answer;
	std::cout << "Select one of the functions:\n";
	std::cout << "0.Exit.\n1.Stop.\n2.Restart.\n";
	std::cout << "Your answer: ";
	std::cin >> answer;
	std::cout << "\n";

	if (answer == 0) {
		if (ClassNumber == 1)
			LandSelect();
		else if (ClassNumber == 2)
			WaterSelect();
		else if (ClassNumber == 3)
			AirSelect();
	}
	else if (answer == 1)
		return 0;
	else if (answer == 2)
		SelectTransport();
	else {
		std::cout << "Wrong answer, try again!\n\n";
		return RestartOrEnd(ClassNumber);
	}
	return 0;
}

int main() {
	SelectTransport();
    return 0;
}
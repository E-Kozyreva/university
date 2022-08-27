#include <iostream>
#include <string>
#include "Typer.h"
#include "Land.h"
#include "Water.h"
#include "Air.h"

void SelectTransport();

void LandDescription();
void LandSelect();
void LandTransport(int transport);

void WaterDescription();
void WaterSelect();
void WaterTransport(int transport);

void AirDescription();
void AirSelect();
void AirTransport(int transport);

void RestartTransport(int answer);
int RestartOrEnd(int ClassNumber);

void SelectTransport() {
	int answer;
	TTransport transport;
	answer = transport.SelectType();

	if (answer > 0 && answer < 4)
		RestartTransport(answer);
	else {
		std::cout << "Wrong answer, try again!\n\n";
		SelectTransport();
	}
}

void LandDescription() {
	int answer;
	TLand land;
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
		LandDescription();
	}
}
void LandSelect() {
	int answer;
	TLand land;
	land.TypesOfTranspot();
	answer = land.SelectTypeOfTransport();

	if (answer > 0 && answer < 10)
		LandTransport(answer);
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
		LandSelect();
	}
}
void LandTransport(int transport) {
  if (transport == 1) {
	  TBus* bus = new TBus;
		bus->Information();
		RestartOrEnd(1);
	}
	else if (transport == 2) {
		TTaxi* taxi = new TTaxi;
		taxi->Information();
		RestartOrEnd(1);
	}
	else if (transport == 3) {
		TTrain* train = new TTrain;
		train->Information();
		RestartOrEnd(1);
	}
	else if (transport == 4) {
		TCar* car = new TCar;
		car->Information();
		RestartOrEnd(1);
	}
	else if (transport == 5) {
		TMotorcycle* motorcycle = new TMotorcycle;
		motorcycle->Information();
		RestartOrEnd(1);
	}
	else if (transport == 6) {
		TSubway* subway = new TSubway;
		subway->Information();
		RestartOrEnd(1);
	}
	else if (transport == 7) {
		TSnowmobile* snowmobile = new TSnowmobile;
		snowmobile->Information();
		RestartOrEnd(1);
	}
	else if (transport == 8) {
		TTrolleybus* trolleybus = new TTrolleybus;
		trolleybus->Information();
		RestartOrEnd(1);
	}
	else if (transport == 9) {
		TTram* tram = new TTram;
		tram->Information();
		RestartOrEnd(1);
	}
}

void WaterDescription() {
	int answer;
	TWater water;
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
		WaterDescription();
	}
}
void WaterSelect() {
	int answer;
	TWater water;
	water.TypesOfTranspot();
	answer = water.SelectTypeOfTransport();

	if (answer > 0 && answer < 7)
		WaterTransport(answer);
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
		WaterSelect();
	}
}
void WaterTransport(int transport) {
	if (transport == 1) {
		TShip* ship = new TShip;
		ship->Information();
		RestartOrEnd(2);
	}
	else if (transport == 2) {
		TFerry* ferry = new TFerry;
		ferry->Information();
		RestartOrEnd(2);
	}
	else if (transport == 3) {
		TBoat* boat = new TBoat;
		boat->Information();
		RestartOrEnd(2);
	}
	else if (transport == 4) {
		TMotorShip* motorship = new TMotorShip;
		motorship->Information();
		RestartOrEnd(2);
	}
	else if (transport == 5) {
		TYacht* yacht = new TYacht;
		yacht->Information();
		RestartOrEnd(2);
	}
	else if (transport == 6) {
		TVessel* vessel = new TVessel;
		vessel->Information();
		RestartOrEnd(2);
	}
}

void AirDescription() {
	int answer;
	TAir air;
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
		AirDescription();
	}
}
void AirSelect() {
	int answer;
	TAir air;
	air.TypesOfTranspot();
	answer = air.SelectTypeOfTransport();

	if (answer > 0 && answer < 4)
		AirTransport(answer);
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
			SelectTransport();
		}
	}
	else {
		std::cout << "Wrong answer, try again!\n\n";
		AirSelect();
	}
}
void AirTransport(int transport) {
	if (transport == 1) {
		TPlane* plane = new TPlane;
		plane->Information();
		RestartOrEnd(3);
	}
	else if (transport == 2) {
		THelicopter* helicopter = new THelicopter;
		helicopter->Information();
		RestartOrEnd(3);
	}
	else if (transport == 3) {
		TBalloon* balloon = new TBalloon;
		balloon->Information();
		RestartOrEnd(3);
	}
}

void RestartTransport(int answer) {
	if (answer == 1)
		LandDescription();
	else if (answer == 2)
		WaterDescription();
	else if (answer == 3)
		AirDescription();
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
		RestartOrEnd(ClassNumber);
	}
	return 0;
}

int main() {
	SelectTransport();
	return 0;
}

#include <iostream>
#include "SetColorText.h"
#include "gotoxy.h"
class Bus {
public:
	int totalBuses = 15;
	struct Datos;
	void PedirBus();
};

struct DatosPersona {
	char nombre[50];
	char direccionFisica[50];
	char fecha[10];
	char direccionIP[50];
}datos[15];

void Bus::PedirBus() {
	system("cls");

	gotoxy(50, 1);
	std::string bienvenida = "Reservar camiones";
	SetColorText(2, bienvenida);

	std::cin.get();
}
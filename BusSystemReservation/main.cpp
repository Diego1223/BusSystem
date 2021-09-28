#include <iostream>
#include "BusSystem.h"

/*
 * @file -> Main.cpp
 * @autor -> Diego Alonso Narvaez Zapata
 * @date -> 26/09/2021
 */

 //-------------- Prototipo de funciones ------------------
void MainPage();


int main() {
	MainPage();

	std::cin.get();
	return 0;
}

// ------ Definicion de la funcion MainPage ---------
void MainPage() {
	int opcion;

	gotoxy(53, 0);
	std::cout << "Bienvenido" << '\n';

	do {
		std::cout << "\nOpciones" << '\n';
		std::cout << "1. Pedir Autobus" << '\n';
		std::cout << "2. Hacer reporte" << '\n';
		std::cout << "3. Solicitar trabajo" << '\n';
		std::cout << "=> "; std::cin >> opcion;

		if ((opcion > 3) || (opcion < 1)) {
			std::cout << "\a";
			std::cout << "\nLa opcion que ingreso no existe. Vuelve a intentarlo" << '\n';
		}
	} while ((opcion > 3) || (opcion < 1));

	switch (opcion) {
	case 1:
		Bus pedirBus;
		pedirBus.PedirBus();
		break;
	}
}
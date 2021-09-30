#include <iostream>
#include "SetColorText.h"
#include "gotoxy.h"

/*
 * Datos Generales
 * 
 * OFERTAS
 * 1. Autobus con capacidad de 15 - 25 personas
 * 2. Autobus con capacidad de 30 - 40 personas
 * 3. Autobus con capacidad de 50 - 60 personas
 * 
 *  --- No puede rentar mas de 20 horas el camion ---
 * 
 * Primera oferta
 * Para la primera oferta el monto inicial van a ser 5, 000 pesos
 * Cada hora, cuesta 2,000 pesos
 * 
 * Segunda oferta
 * Para la segunda oferta el monto inicial va a ser 8,000 pesos
 * Cada hora tiene un valor de 4,000
 * 
 * Tercera oferta 
 * Para la segunda oferta el monto inicial va a ser 11,000 pesos
 * Cada hora tiene un valor de 6, 000
 */

// ------- Clase Bus --------
class Bus {
public:
	int totalBuses = 15;
	
	struct DatosPedido;
	struct DatosPersona;
	
	void MainPage();
	void PedirBus();
	void DatosNec(int opcion);
};



//----- Declaracion de los atributos ------
struct Bus::DatosPedido {
	int capacidad;
	char fecha[10];
}datosPedido;

struct Bus::DatosPersona {
	char nombre[60];
	char tarjetaCredito[20];
}datosPersona;

void Bus::MainPage() {
	//Esta funcion cambia el titulo de la consola
	SetConsoleTitle(L"Main Page");

	int opcion;	

	system("cls");
	CentrarTexto("Bienvenido", 1);
	
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

void Bus::DatosNec(int opcion) {
	if (opcion == 1) {
		int Tiemporenta;
		float Minicial = 5000; //MontoInicial
		float Vfinal = 0; //Valor final
		char confirmar;

		system("cls");
		//Titulo
		CentrarTexto("Ingresar mas datos necesarios", 1);

		//Para poder cambiar el color del texto
		SetColorText(7, "");
		
		std::cout << "\nMonto Inicial => " << Minicial << " (Incluye una hora)\n";

		std::cout << "\nCada hora vale 2,000 pesos (varia entre la capacidad de los camiones)" << '\n';
		std::cout << "Ingrese el Tiempo de renta (Si no desea agregar mas horas, digite 0) >> ";
		std::cin >> Tiemporenta;

		if (Tiemporenta > 0) {
			Tiemporenta *= 2000;
			Vfinal = Minicial + Tiemporenta;
		}
		else {
			Vfinal = Minicial;
		}

		std::cout << "\nCoticacion => " << Vfinal << '\n';
		std::cout << "\nContinuar Y/n >> ";
		std::cin >> confirmar;

		if ((confirmar == 'Y') || (confirmar == 'y')) {
			std::cin.ignore(256, '\n');
			//Seguir con la confirmar datos (No va a ser una nueva pantalla)
			CentrarTexto("Datos", 12);

			std::cout << "\nPor favor, ingrese los siguientes datos\n";

			std::cout << "Nombre completo por apellidos => ";
			std::cin.getline(datosPersona.nombre, 60, '\n');

			std::cout << "Tarjeta de credito => ";
			std::cin.getline(datosPersona.tarjetaCredito, 20, '\n');

		}
		else {
			MainPage();
		}
		system("pause>0");
	}
}



void Bus::PedirBus() {
	system("cls");
	SetConsoleTitle(L"Ofertas");

	std::string ofertas, of1;
	int opcion = 0;

	//--- Titulo ---
	SetColorText(4, "");
	CentrarTexto("OFERTAS DISPONIBLES", 1);

	std::cout << '\n';

	//Ofertas disponibles
	gotoxy(14, 5);
	of1 = "1. Autobus con capacidad de 15 - 25 personas";
	SetColorText(7, of1);

	std::cout << '\t';
	std::cout << "2. Autobus con capacidad de 30 - 40 personas";

	gotoxy(39, 8);
	std::cout << "3. Autobus con capacidad de 50 - 60 personas";

	//---- Escojer la respuesta correcta
	SetColorText(1, "");
	CentrarTexto("Ingresa el numero de la oferta >> ", 25);
	std::cin >> opcion;
	DatosNec(opcion);
}
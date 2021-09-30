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
	
	void PedirBus();
	void DatosNec(int opcion);
};



//----- Declaracion de los atributos ------

struct Bus::DatosPedido {
	char nombre[50];
	char direccionFisica[50];
	char direccionIP[50];
}datosPedido;

struct Bus::DatosPersona {
	int capacidad;
	char fecha[10];
}datosPersona;



void Bus::DatosNec(int opcion) {
	if (opcion == 1) {
		int Tiemporenta;
		float Minicial = 5000; //MontoInicial
		float Vfinal = 0; //Valor final

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
		
		//Seguir con la confirmar datos (No va a ser una nueva pantalla)
		CentrarTexto("Confirmar datos", 9);
	

		system("pause>0");
	}
}



void Bus::PedirBus() {
	system("cls");
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
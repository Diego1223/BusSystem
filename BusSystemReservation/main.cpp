#include <iostream>
#include <Windows.h>
#include "BusSystem.h"

/*
 * @file -> main.cpp
 * @autor -> Diego Alonso Narvaez Zapata
 * @date -> 26/09/2021
 */


int main( void ) {
	//Esta funcion cambia el titulo de la consola
	SetConsoleTitle(L"Bus System Reservation");
	
	Bus system;
	system.MainPage();
	return 0;
}
#include <Windows.h>
#include <string>

/*
 * @documentation -> https://docs.microsoft.com/es-es/windows/console/console-screen-buffers#_win32_font_attributes
 *  0 = Negro       8 = Gris
 *  1 = Azul        9 = Azul claro
 *  2 = Verde
 *  3 = Aguamarina
 *  4 = Rojo
 *  5 = Purpura
 *  6 = Amarillo
 *  7 = Blanco
 *  10 -> Intencificar el color de fondo
 *
 * Uso:
 * Se tiene que crear una variable de tipo string con el texto, despues, mandar a llamar a la funcion SetColorText()
 * En los parametros ingresar la opcion y el string y el string se imprimira
 */


void SetColorText(int color, std::string str) {
	DWORD bytesWritten = 0;
	HANDLE hCon;

	hCon = GetStdHandle(STD_OUTPUT_HANDLE);

	switch (color) {
	case 0:
		SetConsoleTextAttribute(hCon, 0);
		WriteFile(hCon, str.c_str(), str.size(), &bytesWritten, NULL);
		break;

	case 1:
		SetConsoleTextAttribute(hCon, FOREGROUND_BLUE);
		WriteFile(hCon, str.c_str(), str.size(), &bytesWritten, NULL);
		break;

	case 2:
		SetConsoleTextAttribute(hCon, FOREGROUND_GREEN);
		WriteFile(hCon, str.c_str(), str.size(), &bytesWritten, NULL);
		break;

	case 3:
		SetConsoleTextAttribute(hCon, 3);
		WriteFile(hCon, str.c_str(), str.size(), &bytesWritten, NULL);
		break;

	case 4:
		SetConsoleTextAttribute(hCon, FOREGROUND_RED);
		WriteFile(hCon, str.c_str(), str.size(), &bytesWritten, NULL);
		break;

	case 5:
		SetConsoleTextAttribute(hCon, 5);
		WriteFile(hCon, str.c_str(), str.size(), &bytesWritten, NULL);
		break;

	case 6:
		SetConsoleTextAttribute(hCon, 6);
		WriteFile(hCon, str.c_str(), str.size(), &bytesWritten, NULL);
		break;

	case 7:
		SetConsoleTextAttribute(hCon, 7);
		WriteFile(hCon, str.c_str(), str.size(), &bytesWritten, NULL);
		break;

	case 8:
		SetConsoleTextAttribute(hCon, 8);
		WriteFile(hCon, str.c_str(), str.size(), &bytesWritten, NULL);
		break;

	case 9:
		SetConsoleTextAttribute(hCon, 9);
		WriteFile(hCon, str.c_str(), str.size(), &bytesWritten, NULL);
		break;

	case 10:
		SetConsoleTextAttribute(hCon, BACKGROUND_INTENSITY);
		WriteFile(hCon, str.c_str(), str.size(), &bytesWritten, NULL);
		break;
	}
}
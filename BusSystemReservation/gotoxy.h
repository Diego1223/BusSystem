#include <stdio.h>
#include <Windows.h>
#include <string.h>

void gotoxy(int x, int y) {
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon, dwPos);
}

void CentrarTexto(const char* texto, int y) {
	int size;
	size = strlen(texto);
	//El ancho de la consola es 119
	//Pero como lo estamos centrando, lo tenemos que poner en la mitad que es 59.5 (peude variar entre computadoras)
	//La y, es la fila en la que vamos a centrar el texto
	gotoxy(59.5 - (size / 2), y); printf("%s", texto);
}
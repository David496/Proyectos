#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>

using namespace std;

#define ARRIBA 72;
#define ABAJO 80;
#define IZQUIERDA 75;
#define DERECHA 77;


int x = 6, y = 6;
int xa = 10, ya = 10;
int n = 1;
int tamanio = 10;
int velocidad = 100;
int gusano[100][2];
int dir = 3;
long punt = 0;
char tecla;

void gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

void ocultar_cursor()
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 2 ;
	cci.bVisible = FALSE ;
	SetConsoleCursorInfo(hcon,&cci);
}

void mover()
{
	if (_kbhit())
	{
		tecla = _getch();
		switch (tecla)
		{
		case 72 : if (dir != 2) dir= 1 ; break;//arriba
		case 80 : if (dir != 1) dir = 2; break;//abajo
		case 75 :if (dir != 3) dir = 4; break;//izquierda
		case 77 :if (dir != 4) dir = 3; break;//derecha
		}
	}
}


void mapa() {
	for (int i = 1; i < 119; i++) {
		gotoxy(i, 0); cout<<char(205);
		gotoxy(i, 29); cout << char(205);
	}
	for (int v = 1; v < 29; v++) {
		gotoxy(0, v);  cout << char(186);
		gotoxy(119, v);  cout << char(186);
	}
	gotoxy(0, 0);    cout << char(201);
	gotoxy(0, 29);   cout << char(200);
	gotoxy(119, 0);    cout << char(187);
	gotoxy(119, 29);    cout << char(188);
}

void guardar_pos()
{
	gusano[n][0] = x;
	gusano[n][1] = y;
	n++;
	if (n == tamanio)
	{
		n = 1;
	}
}

void imprime_peronaje()
{
	for (int i = 1; i < tamanio; i++)
	{
		gotoxy(gusano[i][0], gusano[i][1]);
		cout << "*";
	}
	
}

void borrar_personaje()
{
	gotoxy(gusano[n][0], gusano[n][1]); 
	cout << " ";
}

bool game_over()
{
	if ((x == 0 || x == 119) || (y == 0 || y == 29))
	{
		return true;
	}

	for (int i = tamanio-1; i > 0; i--)
	{
		if (gusano[i][0]==x && gusano[i][1]==y)
		{
			return true;
		}

	}
	
	return false;
}

void comer()
{
	if (x == xa&&y == ya)
	{
		ya = rand() % 26 + 1;
		xa = rand() % 116 + 1;
		tamanio++;
		gotoxy(xa, ya);
		cout << char(184);
	}
}

void puntaje()
{
	gotoxy(100, 1);
	cout << "SCORE: ";
	if (x == xa&&y == ya)
	{
		punt += 100;
	}
	cout << punt;
}

int main()
{
	while (tecla!=27)
	{
		ocultar_cursor();
		mapa();

		gotoxy(xa, ya);
		cout << char(184);
		while (!game_over())
		{
			puntaje();
			borrar_personaje();
			guardar_pos();
			imprime_peronaje();
			comer();
			mover();
			mover();


			if (dir == 1) { y--; }
			if (dir == 2) { y++; }
			if (dir == 3) { x++; }
			if (dir == 4) { x--; }

			Sleep(velocidad);
		}

		mapa();
	}
	
	_getch();

	return 0;
}
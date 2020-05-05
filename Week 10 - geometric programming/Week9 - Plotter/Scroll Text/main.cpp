#include <iostream>
#include <windows.h>
#include <cmath>
#include <stdlib.h>
using namespace std;

// Written by Michelle Zhang //

//Scroller 
//Create a console application that scrolls a text message following a sine curve. 

int amp, period;
int dir, frame_spd;
bool cont = true;
void ClearScreen();
void GotoXY(int, int);
const char scroller[] = "--------------------HELLO-------IT'S-----A---------WONDERFUL-------DAY";

void GotoXY(int _iX, int _iY)
{
	COORD point;
	point.X = _iX;
	point.Y = _iY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

void ClearScreen()
{
	COORD coordScreen = { 0, 0 };
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	FillConsoleOutputCharacter(hConsole, TEXT(' '), dwConSize,
		coordScreen, &cCharsWritten);
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize,
		coordScreen, &cCharsWritten);
	SetConsoleCursorPosition(hConsole, coordScreen);
}

int main() {

	cout << "Enter amplitude: ";
	cin >> amp;
	cout << "Enter period: ";
	cin >> period;
	cout << "Enter direction 0 right 1 left:  ";
	cin >> dir;
	cout << "Enter frame speed slow(1-10)fast: ";
	cin >> frame_spd;
	
	
	
	double arr_size = sizeof(scroller) / sizeof(*scroller);




	while (cont) {
		ClearScreen();

		for (int i = 0; i < arr_size; i++) {

		}

	}


	int iTemp;
	cin >> iTemp;
	return 0; 
}
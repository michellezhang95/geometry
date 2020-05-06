#include <iostream>
#include <windows.h>
#include <cmath>
#include <stdlib.h>
using namespace std;

#define PI 3.14159265

// Written by Michelle Zhang //

//Scroller 
//Create a console application that scrolls a text message following a sine curve. 




//READ ME!!!
// begin with amplitude 2, period 1, right 0, 5 framespeed

int amp, period;
int dir, frame_spd;
float y;
int i;
bool cont = true;
void ClearScreen();
void GotoXY(int, int);
void drawScroll();
 char scroller[] = "--------------------HELLO-------IT'S-----A---------WONDERFUL-------DAY";

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
void drawScroll() {
	int arr_size = sizeof(scroller) / sizeof(*scroller);
	period = (2 * PI) / period;
	//convert to radians 
	period = period * (PI / 180);
	cout << period;
	float x2 = 0.0 ;
	int interate = 0; 
	while (cont) {
		ClearScreen();
		
		cout << endl << endl;
			for (int i = 0; i < arr_size-1; i++) {

				if (i == 0) {
					x2 = 0;
				}
				else if (i > 0) {
					x2 += (PI / 2);
					//x2 = x2 * (PI / 180);
				}

				y = amp * sin(x2 / 2);
				GotoXY(x2, y);
				cout << scroller[i];
				//shift array elements to the end of the array
				scroller[i] = scroller[i + 1];

				

			}
			Sleep(1000 / frame_spd);
		}

		
		
		
	}


	

int main() {

	cout << "Enter amplitude(2-10): ";
	cin >> amp;
	cout << "Enter period(2-6): ";
	cin >> period;
	cout << "Enter frame speed slow(1-10)fast: ";
	cin >> frame_spd;
	//convert to radians to use trig functions

	
	

	drawScroll();

	int iTemp;
	cin >> iTemp;
	return 0; 
}
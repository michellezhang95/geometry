#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;

//Written by Michelle Zhang BSE20021

//equation of a circle 
// (x - h)^2 + (y - k)^2 = r^2

//equation of an ellipse

//  x^2/a^2 + y^2/b^2 = 1

#define PI 3.14159265
// plot each (x,y) on to the graph in calc

//horizontal radius and vertical radius
int h = 0;
int k = 0;
int rx = 0;
int ry = 0;




//void drawCircle(int, int, int, );

void GotoXY(int, int);
void calc(int, int, int, int);
int main() {
	cout << "Enter the centre point of ellipse (x,y)" << endl;
	cout << "Enter the value of x: ";
	cin >> h;
	cout << "Enter the value of y: ";
	cin >> k;
	cout << "Enter the horizontal radius: ";
	cin >> rx;
	cout << "Enter the vertical radius: ";
	cin >> ry;

	calc(h, k, rx, ry);
	
	int iTemp;
	cin >> iTemp;
	return 0;

}


void calc(int h, int k, int rx, int ry) {
	//positive x
	system("cls");
	float x = 0;
	float y = ry;
	float angle = 0;
	float range = rx;

	do {
		GotoXY((int)(h + x + 0.5), (int)(k + y + 0.5));
		cout << "*";
		GotoXY((int)(h + x + 0.5), (int)(k - y + 0.5));
		cout << "*";
		GotoXY((int)(h - x + 0.5), (int)(k - y + 0.5));
		cout << "*";
		GotoXY((int)(h - x + 0.5), (int)(k + y + 0.5));
		cout << "*";

		angle += 0.5;
		x = (rx * cos(angle));
		y = (ry * sin(angle));
	} while (angle <= range);
}

		
void GotoXY(int _iX, int _iY)
{
	COORD point;
	point.X = _iX;
	point.Y = _iY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}




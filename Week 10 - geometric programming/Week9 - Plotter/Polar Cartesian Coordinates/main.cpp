#include <iostream>
#include <windows.h>
#include <cmath>
#include <stdlib.h>
// Written by Michelle Zhang BSE20021
using namespace std;
//global variables
bool type;
double r, angle;
int x, y;
string quad;
void setSystem(int);
void findQuad(double, double);
void displayCalc(int, double, double);
void drawCalc(int,int);

void drawCalc(int a, int b) {

		a += 20;
		//if y axis is negative, offset
		if (b < 0) {
			b = b * -1;
			b += 10;
		}
		else if (b > 0) {
			b = 10 - b;
		}
		cout << a << "    " << b << endl;
	// each row
	for (int i = 0; i < 20; i++) {
		//each column
		for (int j = 0; j < 40; j++) {
			//draw horizontal axis
			if (i == 9 && j != 19) {
				cout << "-";
			}
			else {
				if (j != 19 && i != 9) {
					
					if (i == b && j == a) {
						cout << "\b*";
					}
					//draw empty space
					cout << " ";
				}
				else {
					//draw vertical axis
					cout << "|";
				}
			}
			
		}
		cout << endl;
	}

}
//find the quadrant
void findQuad(double a, double b) {
	if (a >= 0 && b >= 0) {
		quad = "I";
	}
	else if (a >= 0 && b <= 0) {
		quad = "IV";
	}
	else if (a <= 0 && b >= 0) {
		quad = "II";
	}
	else if (a <= 0 && b <= 0) {
		quad = "III";
	}
	cout << "Quadrant:   " << quad << endl <<endl <<endl;
	
}

//sets type to whichever system the user chooses
void setSystem(int b) {
	if (b == 1) {
		//if true  cartesian 
		type = true;
		cout << "Enter x coordinate:  ";
		cin >> x;
		cout << "Enter y coordinate:  ";
		cin >> y;
		cout << endl;
		displayCalc(b, x, y);
	}
	else if (b == 0) {
		//if false,  polar
		type = false;
		cout << "Enter r:   ";
		cin >> r;
		cout << "Enter angle:   ";
		cin >> angle;
		cout << endl;
		displayCalc(b, r, angle);
	}

}
//displays the results of the conversion
void displayCalc(int type ,double x, double y) {
	//if cartesian, then convert to polar
	system("cls");
	cout << endl;
	if (type) {
		cout << "Cartesian:  (" << x << ", " << y << ")" << endl;
		r = sqrt((pow(x, 2) + pow(y, 2)));
		angle = atan(y / x);
		cout << "Polar:   (" << r << ", " << angle << ")" << endl;
		findQuad( x, y);


	}
	else { //if polar, then convert to cartesian
		cout << "Polar:  (" << x << ", " << y << ")" << endl;
		angle = angle * (3.14159 / 180);
		x = r * (cos(angle));
		y = r * (sin(angle));
		cout << "Cartesian:  (" << x << ", " << y << ")" << endl;
		findQuad(x, y);
	}

}
int main() {
	int input;
	cout << "Press 1 for to convert from Cartesian or Press 0 from Polar: ";
	cin >> input;
	cout << endl;
	setSystem(input);
	drawCalc(x,y);

	int iTemp;
	cin >> iTemp;
	return 0;

}
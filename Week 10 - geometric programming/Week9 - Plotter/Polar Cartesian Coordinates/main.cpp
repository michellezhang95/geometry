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
char quad;
void setSystem(int);
void findQuad(double, double);
void displayCalc(int, double, double);

//find the quadrant


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
		cout << "Quadrant:  ";

	}
	else { //if polar, then convert to cartesian
		cout << "Polar:  (" << x << ", " << y << ")" << endl;
		angle = angle * (3.14159 / 180);
		x = r * (cos(angle));
		y = r * (sin(angle));
		cout << "Cartesian:  (" << x << ", " << y << ")" << endl;
		cout << "Quadrant:   ";
	}

}
int main() {
	int input;
	cout << "Press 1 for to convert from Cartesian or Press 0 from Polar: ";
	cin >> input;
	cout << endl;
	setSystem(input);
	

	int iTemp;
	cin >> iTemp;
	return 0;

}
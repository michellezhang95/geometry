#include <iostream>
#include <windows.h>
#include <cmath>
#include <stdlib.h>
using namespace std;

//Written by Michelle Zhang BSE20021
//Create a command console prompt tool that rotates a Cartesian coordinate
//about another Cartesian coordinate by a number of degrees.

// Point Rotation
// original cartesian coordinate
// convert to polar coordinates
// rotate to new position
// convert back to cartesian
int x, y;
int x2, y2;
int x3, y3;
int angle;
char wise;
int r;
double theta;

void convert(int, int, int, int, char);


void convert(int x, int y, int x2, int y2, char wise) {
	system("cls");
	cout << "Rotate: (" << x << ", " << y << ")" << endl;
	cout << "Around: (" << x2 << ", " << y2 << ")" << endl;
	cout << "By degrees: " << angle << endl;

	r = sqrt((pow(x, 2) + pow(y, 2)));
	theta = atan(y / x);
	cout << "Result: "
}
int main() {
	cout << "Enter the coordinate you wish to rotate" << endl;
	cout << "x coordinate: ";
	cin >> x;
	cout << "y coordinate: ";
	cin >> y;

	cout << "Enter the coordinate you want to rotate around" << endl;
	cout << "x2 coordinate: ";
	cin >> x2;
	cout << "y2 coordinate: ";
	cin >> y2;

	cout << "Angles (in degrees) you wish to rotate by" << endl;
	cout << "angle: ";
	cin >> angle;

	cout << "(C)lockwise or (A)nti-clockwise?";
	cin >> wise;

	convert(x, y, x2, y2, wise);

	int iTemp;
	cin >> iTemp;
	return 0;
}
#include <iostream>
#include <windows.h>
#include <cmath>
#include <stdlib.h>
using namespace std;

//Written by Michelle Zhang BSE20021//

#define PI 3.14159265
//Create a command console prompt tool that rotates a Cartesian coordinate
//about another Cartesian coordinate by a number of degrees.

// Point Rotation
// rotate a point around something other than the origin
// 1. translate the whole system so the point of rotation is the origin
// 2. perform rotation
// 3. undo translation
int origin_x = 0;
int origin_y = 0;
int xrot, yrot;
int xaround, yaround;
int xnew, ynew;
float angle;
char wise;
int r;
double theta;

void convert(int, int, int, int, char);
void drawCalc(int, int, int, int);

void drawCalc(int a, int b, int c, int d) {
	//a and b are the rotation point coord
	//c and d are the point coord that is rotating around a and b
	a += 20;
	//if y axis is negative, offset
	if (b < 0) {
		b += 19;
	}
	else if (b > 0) {
		b = 10 - b;
	}

	c += 20;
	if (d < 0) {
		d += 19;
	}
	else if (d > 0) {
		d = 10 - b;
	}
	
	// each row
	for (int i = 0; i < 20; i++) {
		//each column
		for (int j = 0; j < 40; j++) {
			//draw horizontal axis
			if (i == 9 && j != 19) {
				if (a != 0 || c != 0) {
					cout << "-";
				}
			}
			else {
				if (j != 19 && i != 9) {

					if (i == b && j == a)   {
						cout << "\b*";
					}
					else if (i == d && j == c) {
						cout << "\bo";
					}
					//draw empty space
					cout << " ";
				}
				else {
					//draw vertical axis
					cout << ":";
				}
			}

		}
		cout << endl;
	}

}

void convert(int x, int y, int x2, int y2, char wise) {
	system("cls");
	cout << "Rotate: (" << xrot << ", " << yrot << ")" << endl;
	cout << "Around: (" << xaround << ", " << yaround << ")" << endl;
	cout << "By degrees: " << angle << endl;

	cout << endl << endl;
	cout << "after" << endl;
	drawCalc(xaround, yaround, xrot, yrot);
	
	if (wise == 'c' || wise == 'C') angle = angle * -1;

	//translate point to origin
	xrot -= xaround;
	yrot -= yaround;
	
	//c++ trig functions use radians so convert angle to radian
	angle = angle * (PI/ 180);

	 //x' = x * cos(theta) - y * sin(theta)
	//y' = x * sin(theta) + y * cos(theta)
	float c = cos(angle);
	float s = sin(angle);
	xnew = (xrot * c) - (yrot * s);
	ynew = (xrot * s) + (yrot * c);

	//translate back 
	xnew += xaround;
	ynew += yaround;
	xrot += xaround;
	yrot += yaround;
	cout << "Result: ("<< xnew << ", "<< ynew<<")" <<endl;
	drawCalc(xaround, yaround, xnew, ynew);

}
int main() {
	cout << "Enter the coordinate you wish to rotate" << endl;
	cout << "x coordinate: ";
	cin >> xrot;
	cout << "y coordinate: ";
	cin >> yrot;

	cout << "Enter the coordinate you want to rotate around" << endl;
	cout << "x2 coordinate: ";
	cin >> xaround;
	cout << "y2 coordinate: ";
	cin >> yaround;

	cout << "Angles (in degrees) you wish to rotate by" << endl;
	cout << "angle: ";
	cin >> angle;

	cout << "(C)lockwise or (A)nti-clockwise?";
	cin >> wise;

	convert(xrot, yrot, xaround, yaround, wise);

	int iTemp;
	cin >> iTemp;
	return 0;
}
#include <iostream>
#include <windows.h>
#include <cmath>
// Written by Michelle Zhang BSE20021
using namespace std;
//global variables
bool type;
double r, angle;
// this is a test to see if laptop changes show up bro
void setSystem(int);

void displayCalc(int, double, double);

//sets type to whichever system the user chooses
void setSystem(int b) {
	if (b == 1) {
		//if true return cartesian 
		type = true;
	}
	else if (b == 0) {
		//if false, return polar
		type = false;
	}

}
//displays the results of the conversion
void displayCalc(int type ,double x, double y) {
	//if cartesian, then convert to polar
	if (type) {
		r = sqrt((pow(x, 2) + pow(y, 2)));
		angle = tan(y / x);

	}
	else { //if polar, then convert to cartesian

	}

}
int main() {
	int input;
	cout << "Press 1 for Cartesian or Press 2 for Polar: ";
	cin >> input;
	cout << endl;
	setSystem(input);
	cout << "Input coordinates" << endl;




}
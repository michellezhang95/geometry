#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;
int x, y;
//horizontal radius and vertical radius
int h_radius, v_radius;
//number of angles to plot
int n_angles, angle;

double circ;


//void drawCircle(int, int, int, );
void getCircumference(int, int);

int main() {
	
	

	

	
}

void drawCircle(int x, int y, int h_radius, int v_radius) {

}

void getCircumference(int h, int v) {
	circ = 2 * 3.141592654 * sqrt((pow(h, 2) + pow(v, 2)) / 2);
	cout << circ;

}
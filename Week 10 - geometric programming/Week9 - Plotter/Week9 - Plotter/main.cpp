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
	
	
	//take in user input
	//cout << "Input centre coordinates " << endl;
	//cout << "x coordinate: ";
	//cin >> x;
	//cout << "y coordinate: ";
	//cin >> y;
	//cout << endl;
	//cout << "Input horizontal radius and vertical radius " << endl;
	//cout << "h. radius: " ;
	//cin >> h_radius;
	//cout << "v. radius: ";
	//cin >> v_radius;
	//cout << endl;
	//cout << "Input number of angles to plot: ";
	//cin >> n_angles;

	/*angle = 360 / n_angles;
	getCircumference(h_radius, v_radius);*/

	float r;

	cout << " Enter the Radius" << endl;

	cin >> r;

	float pr = 2; // pr is the aspected pixel ratio which is almost equal to 2

	for (int i = -r; i <= r; i++) // loop for horizontal movement

	{

		for (int j = -r; j <= r; j++) // loop for vertical movement

		{

			float d = ((i * pr) / r) * ((i * pr) / r) + (j / r) * (j / r); //multiplying the i variable with pr to equalize pixel-width with the height

			if (d > 0.95 && d < 1.08) // approximation

			{

				cout << "*";

			}

			else

			{

				cout << " ";

			}

		}

		cout << endl;

	}

	return 0;
	

	
}

void drawCircle(int x, int y, int h_radius, int v_radius) {

}

void getCircumference(int h, int v) {
	circ = 2 * 3.141592654 * sqrt((pow(h, 2) + pow(v, 2)) / 2);
	cout << circ;

}
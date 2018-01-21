#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>

//Initialize value for Pi
#define _USE_MATH_DEFINES
#include<math.h>

using namespace std;

int main() {

	//open a stream to write to an output file//
	ofstream outfile;
	outfile.open("ProgramData.txt");

	//Declaring all the constants//
	double w = 7.5;
	const double Te = 2 * M_PI / w;

	double a = 10.0, b = 10.0, g = 10.0, v = 0.5, T = 0;

	const double delT = Te / 1024;


	//Declaring all the variables to a starting value//
	double e = 2, tol = 1;

	double x = 0, y = 0, dx = 0, dy = 0;

	double xi = 0, yi = 0;

	//Declare period found boolean//
	bool PeriodFound1 = false;
	bool PeriodFound2 = false;

	//Initializing the 3x100 matrix to store values//
	double storage[3][100] = {};

	//Print out the head of the output file//
	outfile << "T" << setw(10) << "X" << setw(10) << "Y" << endl << endl;

	do
	{

		//Start all the calulations//
		for (double t = 0; t <= T; t += delT) {
			while (e >= tol) {

				dx = x + delT*((y + yi) / 2);
				dy = xi + delT*(a*((x + xi) / 2) -
					b*pow(((x + xi) / 2), 3) - g*((y + yi) / 2) + v*cos(t + delT / 2));
				e = pow((dx - xi), 2) + ((dy - yi), 2);

				xi = dx; yi = dy;

			}
			x = xi; y = yi;

			for (int row = 0; row < 100; row++) {
				storage[row][0] = t;
				storage[row][1] = xi;
				storage[row][2] = yi;
			}

			if PeriodFound1 = false{

				for (int row = 1; row < 100; row++) {
					for (int prevRow = 0; prevRow < row; prevRow++) {
						if (storage[row][1] == storage[prevRow][1]
							&& storage[row][2] == storage[prevRow][2]) {

							T = 2 * (storage[row][0] - storage[prevRow][0])

								//found the period for the first time//
								PeriodFound1 = true;
						}
					}
				}
			}

			if PeriodFound1 = true{

				//if period found print the values on the output file//
				outfile << t << setw(10) << xi << setw(10) << yi << endl;

				for (int row = 1; row < 100; row++) {
					for (int prevRow = 0; prevRow < row; prevRow++) {
						if (storage[row][1] == storage[prevRow][1]
							&& storage[row][2] == storage[prevRow][2]) {

							//found the period for the second time//
							PeriodFound2 = true;

						}
					}
				}

			}


		}
	} while (PeriodFound2 == flase);

}
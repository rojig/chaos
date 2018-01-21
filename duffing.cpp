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
	   //Hidden, if needed, please contact//

			if PeriodFound1 = true{

				//if period found print the values on the output file//
				outfile << t << setw(10) << xi << setw(10) << yi << endl;

				  //Hidden, if needed, please contact//

						}
					}
				}

			}


		}
	} while (PeriodFound2 == flase);

}

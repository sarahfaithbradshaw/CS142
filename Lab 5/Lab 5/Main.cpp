/*
Sarah Bradshaw, section 002, sarahfaithbradshaw@gmail.com
first iteration:
[1][0] = 0.000
[1][1] = 25.000
[1][2] = 25.000
[2][1] = 0.000
[2][2] = 0.000

second iteration:
[1][0] = 0.000
[1][1] = 31.250
[1][2] = 32.813
[2][1] = 7.813
[2][2] = 8.203

*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;

int main() {

	const int NUM_ROW = 10;
	const int NUM_COL = 10;
	size_t i;
	size_t j;
	size_t k;
	const int SET_WIDTH = 9;
	const int SET_PRECISION = 3;

	double tempDistrib[NUM_ROW][NUM_COL];

	cout << "Hotplate simulator" << endl << endl;
	cout << "Printing initial plate..." << endl;


	//initialize array
	const double TEMP_EDGE = 100.0;

	for (i = 0; i < NUM_ROW; i++)
	{
		for (j = 0; j < NUM_COL; j++)
		{
			if ((j == 0) || (j == NUM_COL - 1))
			{
				tempDistrib[i][j] = 0.0;
			}
			else if (((i == 0) || (i == NUM_ROW - 1)) && ((j != 0) && (j != NUM_COL - 1)))
			{
				tempDistrib[i][j] = TEMP_EDGE;
			}
			else
			{
				tempDistrib[i][j] = 0.0;
			}
		}
	}

	//ouputting original plate temps 
	for (i = 0; i < NUM_ROW; i++)
	{
		for (j = 0; j < NUM_COL; j++)
		{
			if (j == NUM_COL - 1)
			{
				cout << setw(SET_WIDTH) << fixed << setprecision(SET_PRECISION) << tempDistrib[i][j];
			}
			else {
				cout << setw(SET_WIDTH) << fixed << setprecision(SET_PRECISION) << tempDistrib[i][j] << ",";
			}
		}
		cout << endl;
	}

	cout << endl << endl;


	//First iteration

	cout << "Printing plate after one iteration..." << endl;

	const int NUM_NEIGHBORS = 4;
	double newTempDistrib[NUM_ROW][NUM_COL];


	for (i = 0; i < NUM_ROW; i++)
	{
		for (j = 0; j < NUM_COL; j++)
		{
			if ((i != 0) && (i != NUM_ROW - 1) && (j != 0) && (j != NUM_COL))  //center
			{
				newTempDistrib[i][j] = (tempDistrib[i][j - 1] + tempDistrib[i][j + 1] + tempDistrib[i - 1][j] + tempDistrib[i + 1][j]) / NUM_NEIGHBORS;
			}
			else // edges
			{
				newTempDistrib[i][j] = tempDistrib[i][j];
			}
		}
	}
	

	//outputting first iteration
	for (i = 0; i < NUM_ROW; i++)
	{
		for (j = 0; j < NUM_COL; j++)
		{
			if (j == NUM_COL - 1)
			{
				cout << setw(SET_WIDTH) << fixed << setprecision(SET_PRECISION) << newTempDistrib[i][j];
			}
			else
			{
				cout << setw(SET_WIDTH) << fixed << setprecision(SET_PRECISION) << newTempDistrib[i][j] << ",";
			}
		}
		cout << endl;
	}

	cout << endl << endl;


	//stabilization
	const double MIN_CHANGE = 0.1;
	double tempChange = 0.0;
	double maxChange = 99.0; // (fits loop condition)

	//copy new vals into old vals
	for (i = 0; i < NUM_ROW; i++)
	{
		for (j = 0; j < NUM_COL; j++)
		{
			tempDistrib[i][j] = newTempDistrib[i][j];
		}
	}

	while (maxChange >= MIN_CHANGE)
	{
		maxChange = 0.0;

		//iterating
		for (i = 0; i < NUM_ROW; i++)
		{
			for (j = 0; j < NUM_COL; j++)
			{
				if ((i != 0) && (i != NUM_ROW - 1) && (j != 0) && (j != NUM_COL - 1))  //center
				{
					newTempDistrib[i][j] = (tempDistrib[i][j - 1] + tempDistrib[i][j + 1] + tempDistrib[i - 1][j] + tempDistrib[i + 1][j]) / NUM_NEIGHBORS;
				}
				else // edges
				{
					newTempDistrib[i][j] = tempDistrib[i][j];
				}

				tempChange = fabs(newTempDistrib[i][j] - tempDistrib[i][j]);

				if (tempChange > maxChange)
				{
					maxChange = tempChange;
				}

			}
		}
		//copy new vals into old vals
		for (i = 0; i < NUM_ROW; i++)
		{
			for (j = 0; j < NUM_COL; j++)
			{
				tempDistrib[i][j] = newTempDistrib[i][j];
			}
		}
	}



	//outputting steady iteration

	cout << "Printing final plate..." << endl;

	for (i = 0; i < NUM_ROW; i++)
	{
		for (j = 0; j < NUM_COL; j++)
		{
			if (j == NUM_COL - 1)
			{
				cout << setw(SET_WIDTH) << fixed << setprecision(SET_PRECISION) << newTempDistrib[i][j];
			}
			else
			{
				cout << setw(SET_WIDTH) << fixed << setprecision(SET_PRECISION) << newTempDistrib[i][j] << ",";
			}
		}
		cout << endl;
	}



	//final plate file output

	cout << endl << "Outputting final plate to file \"Hotplate.csv\"..." << endl;

	ofstream outFS;

	outFS.open("Hotplate.csv");

	for (i = 0; i < NUM_ROW; i++)
	{
		for (j = 0; j < NUM_COL; j++)
		{
			if (j == NUM_COL - 1)
			{
				outFS << setw(SET_WIDTH) << fixed << setprecision(SET_PRECISION) << newTempDistrib[i][j];
			}
			else
			{
				outFS << setw(SET_WIDTH) << fixed << setprecision(SET_PRECISION) << newTempDistrib[i][j] << ",";
			}
		}
		outFS << endl;
	}

	outFS.close();



	//file input to array
	ifstream inFS;

	inFS.open("Inputplate.txt");

	for (i = 0; i < NUM_ROW; i++)
	{
		for (j = 0; j < NUM_COL; j++)
		{
			inFS >> tempDistrib[i][j];
		}
	}

	inFS.close();



	//iterating 3 times with inputted array
	const int NUM_ITERATIONS = 3;

	for (k = 0; k < NUM_ITERATIONS; k++)
	{
		for (i = 0; i < NUM_ROW; i++)
		{
			for (j = 0; j < NUM_COL; j++)
			{
				if ((i != 0) && (i != NUM_ROW - 1) && (j != 0) && (j != NUM_COL - 1))  //center
				{
					newTempDistrib[i][j] = (tempDistrib[i][j - 1] + tempDistrib[i][j + 1] + tempDistrib[i - 1][j] + tempDistrib[i + 1][j]) / NUM_NEIGHBORS;
				}
				else // edges
				{
					newTempDistrib[i][j] = tempDistrib[i][j];
				}
			}
		}
		//copy new vals into old vals
		for (i = 0; i < NUM_ROW; i++)
		{
			for (j = 0; j < NUM_COL; j++)
			{
				tempDistrib[i][j] = newTempDistrib[i][j];
			}
		}
	}

	//outputting the final final plate
	cout << endl << "Printing input plate after 3 updates..." << endl;

	for (i = 0; i < NUM_ROW; i++)
	{
		for (j = 0; j < NUM_COL; j++)
		{
			if (j == NUM_COL - 1)
			{
				cout << setw(SET_WIDTH) << fixed << setprecision(SET_PRECISION) << newTempDistrib[i][j];
			}
			else
			{
				cout << setw(SET_WIDTH) << fixed << setprecision(SET_PRECISION) << newTempDistrib[i][j] << ",";
			}
		}
		cout << endl;
	}

	system("pause");

	return 0;
}
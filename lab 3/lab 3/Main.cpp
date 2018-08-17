/*
Sarah Bradshaw, section 2, sarahfaithbradshaw@gmail.com
Test case 1: 
Input:20000, 2.50, 29000, 35, 25000, 23000, 25, 20000, Gas
Expected Output: 2857.14 gallons, $11142.86 cost, 4000.00 gallons, $13000.00 cost, 
				"** The hybrid is better than the non-hybrid when "Gas" is the user's primary objective."
Result: Passed

Test case 2:
Input: 50, 3.50, 12, 25, 15, 10, 55, 8, Total
Expected Ouptut: 10.00 gallons, $32.00 cost, 4.55 gallons, $17.91 cost
				" ** The non-hybrid is better than the hybrid when "Total" is the user's primary objective."
Result: Passed

Test case 3:
Input: 67000, 4.50, 12500, 30, 10500, 10000, 20, 8000, Total
Expected Output: 11166.70 gallons, 52250.00 cost, 16750.00 gallons, 77375.00 cost
				"** The hybrid is better than the non-hybrid when "Total" is the user's primary objective."
Result: Passed
*/


#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {

	cout << "Please enter the following:" << endl << endl;

	double milesPerYear = 0.0;
	cout << "The estimated miles driven per year: ";
	cin >> milesPerYear;

	if (milesPerYear <= 0) {
		cout << endl << "I'm sorry, you must enter a value bigger than zero. Please try again. Please enter:";
		cout << endl << "The estimated miles driven per year: ";
		cin >> milesPerYear;
	}

	double costPerGallon = 0.0;
	cout << endl << "The estimated price of a gallon of gas during the 5 years of ownership: ";
	cin >> costPerGallon;

	if (costPerGallon <= 0) {
		cout << endl << "I'm sorry, you must enter a value bigger than zero. Please try again. Please enter:";
		cout << endl << "The estimated price of a gallon of gas during the 5 years of ownership: ";
		cin >> costPerGallon;
	}

	//hybrid info

	double initialCostHybrid = 0.0;
	cout << endl << "The initial cost of a hybrid car: ";
	cin >> initialCostHybrid;

	if (initialCostHybrid <= 0) {
		cout << endl << "I'm sorry, you must enter a value bigger than zero. Please try again. Please enter:";
		cout << endl << "The initial cost of a hybrid car: ";
		cin >> initialCostHybrid;
	}

	double milesPerGallonHybrid = 0.0;
	cout << endl << "The efficiency of the hybrid car in miles per gallon: ";
	cin >> milesPerGallonHybrid;

	if (milesPerGallonHybrid <= 0) {
		cout << endl << "I'm sorry, you must enter a value bigger than zero. Please try again. Please enter:";
		cout << endl << "The efficiency of the hybrid car in miles per gallon: ";
		cin >> milesPerGallonHybrid;
	}

	double resaleHybrid = 0.0;
	cout << endl << "The estimated resale value (a dollar amount) for a hybrid after 5 years: ";
	cin >> resaleHybrid;

	if (resaleHybrid <= 0) {
		cout << endl << "I'm sorry, you must enter a value bigger than zero. Please try again. Please enter:";
		cout << endl << "The estimated resale value (a dollar amount) for a hybrid after 5 years: ";
		cin >> resaleHybrid;
	}

	//non hybrid info

	double initialCostNonHybrid = 0.0;
	cout << endl << "The initial cost of a non-hybrid car: ";
	cin >> initialCostNonHybrid;

	if (initialCostNonHybrid <= 0) {
		cout << endl << "I'm sorry, you must enter a value bigger than zero. Please try again. Please enter:";
		cout << endl << "The initial cost of a non-hybrid car: ";
		cin >> initialCostNonHybrid;
	}

	double milesPerGallonNonHybrid = 0.0;
	cout << endl << "The efficiency of the non-hybrid car in miles per gallon: ";
	cin >> milesPerGallonNonHybrid;

	if (milesPerGallonNonHybrid <= 0) {
		cout << endl << "I'm sorry, you must enter a value bigger than zero. Please try again. Please enter:";
		cout << endl << "The efficiency of the non-hybrid car in miles per gallon: ";
		cin >> milesPerGallonNonHybrid;
	}

	double resaleNonHybrid = 0.0;
	cout << endl << "The estimated resale value (a dollar amount) for a non-hybrid after 5 years: ";
	cin >> resaleNonHybrid;

	if (resaleNonHybrid <= 0) {
		cout << endl << "I'm sorry, you must enter a value bigger than zero. Please try again. Please enter:";
		cout << endl << "The estimated resale value (a dollar amount) for a non-hybrid after 5 years: ";
		cin >> resaleNonHybrid;
	}

	//user criterion

	string criterion;
	cout << endl << "The user's buying criterion, either minimized gas consumption or total cost (enter Gas or Total): ";
	cin >> criterion;


	//hybrid gas & costs

	cout << endl << "For the hybrid car:" << endl << endl;

	double gallonsHybrid = 0.0;
	int numYears = 5;
	gallonsHybrid = (milesPerYear / milesPerGallonHybrid) * numYears;

	cout << "The estimated total gallons of fuel consumed over 5 years: " << fixed << setprecision(2) << gallonsHybrid << endl;


	double fuelCostHybrid = 0.0;
	fuelCostHybrid = gallonsHybrid * costPerGallon;

	double depreciationHybrid = 0.0;
	depreciationHybrid = initialCostHybrid - resaleHybrid;

	double hybridTotalCost = 0.0;
	hybridTotalCost = fuelCostHybrid + depreciationHybrid;

	cout << "The estimated total cost of owning the car for 5 years: " << fixed << setprecision(2) << hybridTotalCost << endl << endl;

	//non hybrid gas & costs

	cout << "For the non-hybrid car:" << endl << endl;

	double gallonsNonHybrid = 0.0;
	gallonsNonHybrid = (milesPerYear / milesPerGallonNonHybrid) * numYears;

	cout << "The estimated total gallons of fuel consumed over 5 years: " << fixed << setprecision(2) << gallonsNonHybrid << endl;


	double fuelCostNonHybrid = 0.0;
	fuelCostNonHybrid = gallonsNonHybrid * costPerGallon;

	double depreciationNonHybrid = 0.0;
	depreciationNonHybrid = initialCostNonHybrid - resaleNonHybrid;

	double nonHybridTotalCost = 0.0;
	nonHybridTotalCost = fuelCostNonHybrid + depreciationNonHybrid;

	cout << "The estimated total cost of owning the car for 5 years: " << fixed << setprecision(2) << nonHybridTotalCost << endl << endl;


	//helping with the decision

	bool goalIsGas = 0;
	bool hybridGasIsBetter = 0;
	bool goalIsTotal = 0;
	bool hybridTotalIsBetter = 0;
	string betterChoice;
	string worseChoice;

	goalIsGas = (criterion == "Gas");
	hybridGasIsBetter = (gallonsNonHybrid > gallonsHybrid);

	goalIsTotal = (criterion == "Total");
	hybridTotalIsBetter = (nonHybridTotalCost > hybridTotalCost);


	if ((goalIsGas && hybridGasIsBetter) || (goalIsTotal && hybridTotalIsBetter)) {
		betterChoice = "hybrid";
		worseChoice = "non-hybrid";
		cout << "** The " << betterChoice << " car is better than the " << worseChoice << " car when \"" << criterion << "\" is the user's primary objective." << endl;
	}
	else {
		betterChoice = "non-hybrid";
		worseChoice = "hybrid";
		cout << "** The " << betterChoice << " car is better than the " << worseChoice << " car when \"" << criterion << "\" is the user's primary objective." << endl;
	}

	system("pause");
	return 0;
}
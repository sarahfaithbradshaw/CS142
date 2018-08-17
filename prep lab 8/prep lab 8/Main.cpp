#include <iostream>
#include <iomanip>
#include <string>
#include "ItemToPurchase.h"
using namespace std;


int main()
{
	ItemToPurchase item1;
	ItemToPurchase item2;
	string name;
	double price = 0.0;
	int quantity = 0;
	double item1TotalPrice = 0.0;
	double item2TotalPrice = 0.0;

	//item1
	cout << "Item 1" << endl;
	cout << "Enter the item name: ";
	getline(cin, name);
	item1.SetName(name);
	cout << endl;

	cout << "Enter the item price: ";
	cin >> price;
	item1.SetPrice(price);
	cout << endl;

	cout << "Enter the item quantity: ";
	cin >> quantity;
	item1.SetQuantity(quantity);
	cout << endl;

	//item2
	cout << "Item 2" << endl;
	cout << "Enter the item name: ";
	cin.ignore(1000, '\n');
	getline(cin, name);
	item2.SetName(name);
	cout << endl;

	cout << "Enter the item price: ";
	cin >> price;
	item2.SetPrice(price);
	cout << endl;

	cout << "Enter the item quantity: ";
	cin >> quantity;
	item2.SetQuantity(quantity);
	cout << endl;
	
	item1TotalPrice = item1.GetQuantity() * item1.GetPrice();
	item2TotalPrice = item2.GetQuantity() * item2.GetPrice();

	cout << "TOTAL COST" << endl;
	cout << fixed << setprecision(2);
	cout << item1.GetName() << " " << item1.GetQuantity() << " @ $" << item1.GetPrice() << " = $" << item1TotalPrice << endl;
	cout << item2.GetName() << " " << item2.GetQuantity() << " @ $" << item2.GetPrice() << " = $" << item2TotalPrice << endl << endl;
	cout << "Total: $" << item1TotalPrice + item2TotalPrice << endl;

	//system("pause");
	return 0;
}
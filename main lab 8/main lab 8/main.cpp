/*
Sarah Bradshaw, section 002, sarahfaithbradshaw@gmail.com

Please use one late day for this lab!

Test Case 1: adding, options, descriptions, and quit options, checking for correct layout
Input: name, date, adding some items, "descriptions", "options", "quit"
Expected Output: correct display of item's descriptions, display of menu, "Goodbye."
result: passed

Test Case 2: add, cart, remove, cart, quit; checking for correct setprecision and calculations of total cost
Input: name, date, "add", add some items with different prices and quantities, "cart", "remove" one of the items, "cart", "quit"
Expected Output: should see correct number of items and correct calculation of total cost before and after remove
result: passed

Test Case 3: change, cart, quit; checking for correct output after changing quantities
Input: name, date, "add". add some items, "cart", "change", change quantity, "cart", "quit"
Expected Output: cart before changing quantity should be different than after changing quantity
result: passed
*/

#include <iostream>
#include <limits>
#include <iomanip>
#include <string>
#include "ItemToPurchase.h"
#include "ShoppingCart.h"
using namespace std;


int main()
{
	string name;
	string date;
	string userChoice;
	string description;
	double price = 0.0;
	int quantity = 0;
	const int MAX_CHAR = 1000;
	bool inputIsValid = 0;

	cout << "Enter Customer's Name: ";
	getline(cin, name);
	cout << endl;

	cout << "Enter Today's Date: ";
	getline(cin, date);
	cout << endl;

	ShoppingCart shopperCart(name, date);



	cout << "Enter option: ";
	cin >> userChoice;
	cout << endl;

	inputIsValid = ((userChoice == "quit") || (userChoice == "add") || (userChoice == "remove") || (userChoice == "change") || (userChoice == "descriptions")
		|| (userChoice == "cart"));


	while (userChoice != "quit")
	{
		if ((userChoice == "options") || !inputIsValid)
		{
			cout << "MENU" << endl;
			cout << "add - Add item to cart" << endl;
			cout << "remove - Remove item from cart" << endl;
			cout << "change - Change item quantity" << endl;
			cout << "descriptions - Output items' descriptions" << endl;
			cout << "cart - Output shopping cart" << endl;
			cout << "options - Print the options menu" << endl;
			cout << "quit - Quit" << endl;
		}
		else if (userChoice == "quit")
		{
			break;
		}
		else if (userChoice == "cart")
		{
			shopperCart.PrintCart();
			cout << endl;
		}
		else if (userChoice == "descriptions")
		{
			shopperCart.PrintDescrips();
			cout << endl;
		}
		else if (userChoice == "add")
		{
			cout << "Enter the item name: ";
			cin.clear();
			cin.ignore(MAX_CHAR, '\n');
			getline(cin, name);
			cout << endl;

			cout << "Enter the item description: ";
			getline(cin, description);
			cout << endl;

			cout << "Enter the item price: ";
			cin >> price;
			cout << endl;

			cout << "Enter the item quantity: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> quantity;
			cout << endl;

			ItemToPurchase newItem(name, price, quantity, description);

			shopperCart.AddItemToCart(newItem);
		}
		else if (userChoice == "change")
		{
			cout << "Enter the item name: ";
			cin.clear();
			cin.ignore(MAX_CHAR, '\n');
			getline(cin, name);
			cout << endl;

			cout << "Enter the new quantity: ";
			cin >> quantity;
			cout << endl;

			shopperCart.UpdateQuantity(name, quantity);

		}
		else if (userChoice == "remove")
		{
			cout << "Enter name of the item to remove: ";
			cin.clear();
			cin.ignore(MAX_CHAR, '\n');
			getline(cin, name);

			shopperCart.RemoveItemFromCart(name);
		}

		cout << "Enter option: ";
		cin >> userChoice;
		cout << endl;
	}

	cout << "Goodbye." << endl;

	//system("pause");
	return 0;
}
#include <iostream>
#include <string>
#include <iomanip>
#include "ItemToPurchase.h"
#include "ShoppingCart.h"
using namespace std;

int foundIndexAt = 0;

ShoppingCart::ShoppingCart(string name = "none", const string& date = "January 1, 2016")
{
	customerName = name;
	dateCreated = date;
}

string ShoppingCart::GetNameCustomer() const
{
	return customerName;
}

string ShoppingCart::GetDateCreated() const 
{
	return dateCreated;
}

void ShoppingCart::AddItemToCart(ItemToPurchase item)
{
	bool isThere = 0;
	
	isThere = FindIfThere(item.GetName());
	
	if (isThere)
	{
		cout << "Item is already in cart. Nothing added." << endl;
	}
	else
	{
		cart.push_back(item);
	}
}

void ShoppingCart::RemoveItemFromCart(const string& name)
{
	bool isThere = 0;

	isThere = FindIfThere(name);

	if (isThere)
	{
		cart.erase(cart.begin() + foundIndexAt);
	}
	else
	{
		cout << "Item not found in cart. Nothing removed." << endl;
	}
}

void ShoppingCart::UpdateQuantity(const string& name, int newQuantity)
{
	bool isThere = 0;
	isThere = FindIfThere(name);
	
	if (isThere)
	{
		(cart.at(foundIndexAt)).SetQuantity(newQuantity);
	}
	else
	{
		cout << "Item not found in cart. Nothing modified." << endl;
	}
}

int ShoppingCart::GetNumItems() const
{
	int numItems = 0;

	for (size_t i = 0; i < cart.size(); i++)
	{
		numItems += (cart.at(i)).GetQuantity();
	}
	return numItems;
}

double ShoppingCart::GetTotalCost() const
{
	double totalPrice = 0.0;
	
	for (size_t i = 0; i < cart.size(); i++)
	{
		totalPrice += (cart.at(i)).GetPrice() * (cart.at(i)).GetQuantity();
	}	
	return totalPrice;
}

void ShoppingCart::PrintCart() const
{
	cout << customerName << "'s Shopping Cart - " << dateCreated << endl;

	if (GetNumItems() == 0)
	{
		cout << "Shopping cart is empty." << endl;
	}
	else 
	{
		cout << "Number of items: " << GetNumItems() << endl << endl;

		for (size_t i = 0; i < cart.size(); i++)
		{
			cout << (cart.at(i)).GetName() << " " << (cart.at(i)).GetQuantity() << " @ $" << fixed << setprecision(2) << (cart.at(i)).GetPrice() << " = $"
				<< (cart.at(i)).GetPrice() * (cart.at(i)).GetQuantity() << endl;
		}
		cout << "Total: $" << GetTotalCost() << endl;
	}
}

void ShoppingCart::PrintDescrips() const
{
	cout << customerName << "'s Shopping Cart - " << dateCreated << endl << endl;

	if (GetNumItems() == 0)
	{
		cout << "Shopping cart is empty." << endl;
	}
	else
	{
		cout << "Item Descriptions" << endl;

		for (size_t i = 0; i < cart.size(); i++)
		{
			cout << (cart.at(i)).GetName() << ": " << (cart.at(i)).GetDescrip() << endl;
		}
	}
}

bool ShoppingCart::FindIfThere(const string& name) const 
{
	bool isThere = 0;

	for (size_t i = 0; i < cart.size(); i++)
	{
		if ((cart.at(i)).GetName() == name)
		{
			isThere = true;
			foundIndexAt = i;
			break;
		}	
	}
	return isThere;
}

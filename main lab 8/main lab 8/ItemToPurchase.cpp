#include <iostream>
#include "ItemToPurchase.h"
using namespace std;


ItemToPurchase::ItemToPurchase(string name = "none", double price = 0.0, int quantity = 0, const string& description = "none")	//is this a parametrized constructor? or a default constructor?
{
	itemName = name;
	itemDescrip = description;
	itemPrice = price;
	itemQuantity = quantity;
}

void ItemToPurchase::SetName(const string& name)
{
	itemName = name;
}

string ItemToPurchase::GetName() const
{
	return itemName;
}

void ItemToPurchase::SetPrice(double price)
{
	itemPrice = price;
}

double ItemToPurchase::GetPrice() const 
{
	return itemPrice;
}

void ItemToPurchase::SetQuantity(int quantity)
{
	itemQuantity = quantity;
}

int ItemToPurchase::GetQuantity() const 
{
	return itemQuantity;
}

void ItemToPurchase::SetDescrip(const string& description)
{
	itemDescrip = description;
}

string ItemToPurchase::GetDescrip() const 
{
	return itemDescrip;
}

void ItemToPurchase::PrintPrice() const 
{
	cout << itemName << " " << itemQuantity << "@ $" << itemPrice << " = $" << itemQuantity * itemPrice << endl;
}

void ItemToPurchase::PrintDescrip() const 
{
	cout << itemName << ": " << itemDescrip << endl;
}


#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

void ItemToPurchase::SetName(string name)
{
	itemName = name;
}

string ItemToPurchase::GetName()
{
	return itemName;
}

void ItemToPurchase::SetPrice(double price)
{
	itemPrice = price;
}

double ItemToPurchase::GetPrice()
{
	return itemPrice;
}

void ItemToPurchase::SetQuantity(int quantity)
{
	itemQuantity = quantity;
}

int ItemToPurchase::GetQuantity()
{
	return itemQuantity;
}

ItemToPurchase::ItemToPurchase()
{
	itemName = "none";
	itemPrice = 0.0;
	itemQuantity = 0;
}
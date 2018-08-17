#include <iostream>
using namespace std;

#ifndef STOREITEM_H
#define STOREITEM_H

class ItemToPurchase
{
	public:
		ItemToPurchase();
		void SetName(string name);
		string GetName();
		void SetPrice(double price);
		double GetPrice();
		void SetQuantity(int quantity);
		int GetQuantity();

	private:
		string itemName;
		double itemPrice;
		int itemQuantity;
};		



#endif
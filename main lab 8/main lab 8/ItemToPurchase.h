#ifndef STOREITEM_H
#define STOREITEM_H

#include <iostream>
#include <string>
using namespace std;


class ItemToPurchase
{
public:
	ItemToPurchase(string name, double price, int quantity, const string& description);
	void SetName(const string& name);
	string GetName() const;
	void SetPrice(double price);
	double GetPrice() const;
	void SetQuantity(int quantity);
	int GetQuantity() const;
	void SetDescrip(const string& description);
	string GetDescrip() const;
	void PrintPrice() const;
	void PrintDescrip() const;

private:
	string itemName;
	double itemPrice;
	int itemQuantity;
	string itemDescrip;
};



#endif
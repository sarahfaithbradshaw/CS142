#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <vector>
#include "ItemToPurchase.h"
using namespace std;


class ShoppingCart
{
public:
	ShoppingCart(string customerName, const string& date);
	string GetNameCustomer() const;
	string GetDateCreated() const;
	void AddItemToCart(ItemToPurchase item);
	void RemoveItemFromCart(const string& name);
	void UpdateQuantity(const string& name, int newQuantity);
	int GetNumItems() const;
	double GetTotalCost() const;
	void PrintCart() const;
	void PrintDescrips() const;

private:
	bool FindIfThere(const string& name) const;
	string customerName;
	string dateCreated;
	vector<ItemToPurchase> cart;
};

#endif

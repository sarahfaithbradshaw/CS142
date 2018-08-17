#include <iostream>
#include "Bread.h"



Bread::Bread()
{
}

Bread::Bread(string type)
{
	const double BREAD_PRICE = 4.50;
	
	variety = type;
	price = BREAD_PRICE;
}

string Bread::ToString() const
{
	ostringstream outSS;

	outSS << variety << " bread" << BakedGood::ToString();

	return outSS.str();

}

double Bread::DiscountedPrice(int numGoods) const
{
	int numFree = 0;
	double tempPrice = 0.0;
	const int DISCOUNT_NUM = 3;

	tempPrice = price;
	numFree = numGoods / DISCOUNT_NUM;
	numGoods -= numFree;

	return numGoods * tempPrice;
}


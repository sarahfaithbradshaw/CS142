#include "CupCake.h"

CupCake::CupCake()
{
}

CupCake::CupCake(string goodFlavor, string goodFrosting, string color)
{
	const double CUPCAKE_PRICE = 1.95;
	const double COST_CREAM_CHEESE = 0.2;

	flavor = goodFlavor;
	frosting = goodFrosting;
	sprinkleColor = color;
	price = CUPCAKE_PRICE;

	if (frosting == "cream-cheese")
	{
		price += COST_CREAM_CHEESE;
	}
}

string CupCake::ToString() const
{
	ostringstream outSS;

	outSS << flavor << " cupcake with " << frosting << " frosting and " << sprinkleColor << " sprinkles " << BakedGood::ToString();

	return outSS.str();
}

double CupCake::DiscountedPrice(int numGoods) const
{
	const int LOWER_DISCOUNT_NUM = 2;
	const int UPPER_DISCOUNT_NUM = 4;
	const double LOWER_DISCOUNT_AMOUNT = 0.3;
	const double UPPER_DISCOUNT_AMOUNT = 0.4;
	double tempPrice = 0.0;

	tempPrice = price;

	if (numGoods >= UPPER_DISCOUNT_NUM)
	{
		tempPrice -= UPPER_DISCOUNT_AMOUNT;
	}
	else if (numGoods >= LOWER_DISCOUNT_NUM)
	{
		tempPrice -= LOWER_DISCOUNT_AMOUNT;
	}
	
	return numGoods * tempPrice;
}


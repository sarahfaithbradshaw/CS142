#include "LayerCake.h"

LayerCake::LayerCake()
{
}

LayerCake::LayerCake(string goodFlavor, string goodFrosting, int numLayers)
{
	const double LAYER_CAKE_PRICE = 9.0;
	const int ONE_LAYER = 1;
	const double COST_PER_LAYER_BEYOND_ONE = 3.0;

	flavor = goodFlavor;
	frosting = goodFrosting;
	layers = numLayers;
	price = LAYER_CAKE_PRICE;

	if (frosting == "cream-cheese")
	{
		price += layers;
	}

	if (layers > ONE_LAYER)
	{
		price += COST_PER_LAYER_BEYOND_ONE * (layers - 1);
	}
}

string LayerCake::ToString() const
{

	ostringstream outSS;

	outSS << layers << "-layer " << flavor << " cake with " << frosting << " frosting " << BakedGood::ToString();

	return outSS.str();
}

double LayerCake::DiscountedPrice(int numGoods) const
{
	const int DISCOUNT_NUM = 3;
	const double DISCOUNT_AMOUNT = 2.0;
	double tempPrice = 0.0;
	
	tempPrice = price;

	if (numGoods >= DISCOUNT_NUM)
	{
		tempPrice -= DISCOUNT_AMOUNT;
	}

	return numGoods * tempPrice;
}



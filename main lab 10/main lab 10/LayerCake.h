#ifndef LAYERCAKE_H
#define LAYERCAKE_H

#include "Cake.h"


class LayerCake : public Cake
{
public:
	LayerCake();
	LayerCake(string goodFlavor, string goodFrosting, int numLayers);
	virtual string ToString() const;
	virtual double DiscountedPrice(int numGoods) const;

private:
	int layers = 0;
	//from cake: flavor and frosting
};

#endif
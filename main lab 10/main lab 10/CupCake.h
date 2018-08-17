#ifndef CUPCAKE_H
#define CUPCAKE_H

#include "Cake.h"


class CupCake : public Cake
{
public:
	CupCake();
	CupCake(string goodFlavor, string goodFrosting, string color);
	virtual string ToString() const;
	virtual double DiscountedPrice(int numGoods) const;

private:
	string sprinkleColor;
	//from cake: flavor and frosting
};

#endif

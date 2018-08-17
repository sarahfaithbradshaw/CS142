#ifndef BREAD_H
#define BREAD_H

#include <string>
#include "BakedGood.h"


class Bread : public BakedGood
{
public:
	Bread();
	Bread(string type);
	virtual string ToString() const;
	virtual double DiscountedPrice(int numGoods) const;

private:
	string variety;
};

#endif

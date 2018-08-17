#ifndef BAKEDGOOD_H
#define BAKEDGOOD_H

#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

class BakedGood
{
public:
	BakedGood();
	virtual string ToString() const;
	virtual double DiscountedPrice(int numGoods) const = 0;
protected:
	double price = 0.0;
};

#endif

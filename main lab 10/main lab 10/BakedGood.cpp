#include "BakedGood.h"



BakedGood::BakedGood()
{
}

string BakedGood::ToString() const
{
	ostringstream outSS;

	outSS << " ($" << fixed << setprecision(2) << price << ")";

	return outSS.str();
}


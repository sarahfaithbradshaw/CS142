/*
Sarah Bradshaw, section 002, sarahfaithbradshaw@gmail.com

Use all extra late days (3 I believe) as extra credit please!

Test Case 1: testing for special cases of cream-cheese and multi-layer cake prices
Input:"Layer-cake red-velvet cream-cheese 2 1"
Expected Output: price & total price: $14.00
Result: passed

Test Case 2: testing for correct quantities of white bread added in two different places (and bread's discount case)
Input: "Bread white 3" [... other input] "Bread white 6"
Expected Output: invoice shows total of 9, price: $27.00
Result: passed

Test Case 3: testing non-discount and discount pricing for cupcakes, layer-cakes, and non-discounted bread
Input: "Bread white 2", "Cupcake vanilla chocolate red 3", "Layer-cake vanilla chocolate 2 4"
Expected Output: price: $9.00, $4.95, $40.00, total: $53.95
Result: passed!
*/


#include <iostream>
#include <sstream>
#include <vector>
#include "BakedGood.h"
#include "Bread.h"
#include "Cake.h"
#include "LayerCake.h"
#include "CupCake.h"

using namespace std;

int main()
{
	string subOrder;
	istringstream inSS;
	string goodType;
	int goodNum = 0;

	string variety;
	string flavor;
	string frosting;
	int numLayers = 0;
	string sprinkleColor;

	vector<BakedGood*> order;
	Bread* breadPtr = nullptr;
	LayerCake* layerPtr = nullptr;
	CupCake* cupPtr = nullptr;

	vector<BakedGood*> invoiceOutput;
	int counter = 0;
	vector<int> quantities;
	int totalGoods = 0;
	double totalPrice = 0.0;
	string itemDescrip;
	int quantity = 0;
	double itemPrice = 0.0;



	cout << "**Bread and Cakes Bakery**" << endl << endl;

	cout << "Enter sub-order (enter \"done\" to finish)" << endl;
	cout << "Sub-order: ";

	getline(cin, subOrder);
	//inSS.clear();
	inSS.str(subOrder);
	inSS >> goodType;

	while (goodType != "done")
	{
		if (goodType == "Bread")
		{
			inSS >> variety;
			inSS >> goodNum;

			for (int i = 0; i < goodNum; i++)
			{
				breadPtr = new Bread(variety);
				order.push_back(breadPtr);
			}
		}
		else if (goodType == "Layer-cake")
		{
			inSS >> flavor;
			inSS >> frosting;
			inSS >> numLayers;
			inSS >> goodNum;

			for (int i = 0; i < goodNum; i++)
			{
				layerPtr = new LayerCake(flavor, frosting, numLayers);
				order.push_back(layerPtr);
			}

		}
		else if (goodType == "Cupcake")
		{
			inSS >> flavor;
			inSS >> frosting;
			inSS >> sprinkleColor;
			inSS >> goodNum;

			for (int i = 0; i < goodNum; i++)
			{
				cupPtr = new CupCake(flavor, frosting, sprinkleColor);
				order.push_back(cupPtr);
			}
		}

		cout << "Sub-order: ";
		getline(cin, subOrder);
		inSS.clear();
		inSS.str(subOrder);
		inSS >> goodType;
	}

	cout << endl << endl << "Order Confirmations:" << endl;
	for (size_t i = 0; i < order.size(); i++)
	{
		cout << order.at(i)->ToString() << endl;
	}

	//new vector
	invoiceOutput = order;

	//find, count, and delete any duplicates
	for (size_t i = 0; i < invoiceOutput.size(); i++)
	{
		counter = 1;

		for (size_t j = i + 1; j < invoiceOutput.size(); j++)
		{
			if (invoiceOutput.at(i)->ToString() == invoiceOutput.at(j)->ToString())
			{
				counter++;
				invoiceOutput.erase(invoiceOutput.begin() + j);
				j--;
			}
		}
		quantities.push_back(counter);
	}


	//total price
	for (size_t i = 0; i < invoiceOutput.size(); i++)
	{
		totalPrice += invoiceOutput.at(i)->DiscountedPrice(quantities.at(i));
	}
	

	cout << endl << endl << "Invoice:" << endl;
	cout << setw(75) << left << "Baked Good" << setw(9) << "Quantity" << setw(9) << "Total" << endl;
	for (size_t i = 0; i < invoiceOutput.size(); i++)
	{
		itemDescrip = invoiceOutput.at(i)->ToString();
		quantity = quantities.at(i);
		itemPrice = invoiceOutput.at(i)->DiscountedPrice(quantities.at(i));
		
		cout << setw(75) << left << itemDescrip << setw(9) << quantity << setw(9) << fixed << setprecision(2)
			<< itemPrice << endl;
	}

	totalGoods = order.size();

	cout << setw(75) << "Totals" << setw(9) << totalGoods << setw(9) << totalPrice << endl;


	cout << "Good bye" << endl;

	system("pause");
	return 0;

}

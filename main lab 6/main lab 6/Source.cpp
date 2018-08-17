/*
Use one late day for this lab please!

Sarah Bradshaw, section 002, sarahfaithbradshaw@gmail.com
Test case 1: checked to see if menu popped up, error input
Input: 4, -1, junk, 5
Expected Ouput: nice menu followed by two invalid input messages and a goodbye
Result: passed

Test case 2: single chip drop, mult chip drop
Input: 1, 3, 2, 7, 4, 5
Expected Ouput: valid winnings and then goodbye
Result: passed

Test case 3: multiple into each drop and error handling
Input: 3, 90, 3, junk, 5, 5
Expected Ouput: valid winnings, followed by invalid prompt asking for input, followed by valid winnnings, goodbye
Result: passed
*/


#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;

const int DIV_CONSTANT = 2;
const int MAX_SLOT = 8;
const int MIN_SLOT = 0;
const int MAX_PEG = MAX_SLOT * 2;
const int PEG_NUM = 11;
const int MAX_CHAR_IN_STRING = 255;



int AChipFall(int slotNum)
{

	switch (slotNum)
	{
	case MIN_SLOT:
		++slotNum;
		break;

	case MAX_PEG:
		--slotNum;
		break;

	default:
		slotNum += (rand() % 2) * DIV_CONSTANT - 1;

		break;
	}
	return slotNum;
}


int GetNumSlot()
{
	int numSlot = 0;

	cout << endl << "Which slot do you want to drop the chip in (0-" << MAX_SLOT << ")? ";
	cin >> numSlot;

	while (!((numSlot >= MIN_SLOT) && (numSlot <= MAX_SLOT)) || cin.fail())
	{
		cin.clear();
		cin.ignore(MAX_CHAR_IN_STRING, '\n');

		cout << endl << "Invalid slot." << endl << endl;
		cout << "Which slot do you want to drop the chip in (0-" << MAX_SLOT << ")? ";
		cin >> numSlot;
	}

	return numSlot;
}


int GetChipNum()
{
	int numChips = 0;

	cout << endl << "How many chips do you want to drop(> 0)? ";
	cin >> numChips;

	while (numChips <= 0 || cin.fail())
	{
		cin.clear();
		cin.ignore(MAX_CHAR_IN_STRING, '\n');

		cout << endl << endl << "Invalid number of chips.";
		cout << "How many chips do you want to drop(> 0)? ";
		cin >> numChips;
	}

	return numChips;
}


void GetMenuOption()
{

	cout << endl << "Menu: Please select one of the following options :" << endl << endl;
	cout << "1 - Drop a single chip into one slot" << endl;
	cout << "2 - Drop multiple chips into one slot" << endl;
	cout << "3 - Drop multiple chips into each slot" << endl;
	cout << "4 - Show the options menu" << endl;
	cout << "5 - Quit the program" << endl << endl;
}


double ComputeWinnings(int slotNum)
{
	const double winningsArray[MAX_SLOT + 1] = { 100.0, 500.0, 1000.0, 0.0, 10000.0, 0.0, 1000.0, 500.0, 100.0 };
	double totalWinnings = 0.0;

	totalWinnings = winningsArray[slotNum];

	return totalWinnings;
}


void SingleChipFall()
{
	int slotNum = 0;
	double displaySlot = 0.0;

	cout << endl << "*** Drop a single chip ***" << endl;

	slotNum = GetNumSlot();

	cout << endl << "*** Dropping chip into slot " << slotNum << " ***" << endl << endl;

	slotNum *= DIV_CONSTANT;

	displaySlot = slotNum / static_cast<double>(DIV_CONSTANT);

	cout << "Path: [" << fixed << setprecision(1) << displaySlot << ", ";

	for (int i = 0; i <= PEG_NUM; i++)
	{
		slotNum = AChipFall(slotNum);

		displaySlot = slotNum / static_cast<double>(DIV_CONSTANT);

		cout << fixed << setprecision(1) << displaySlot;

		if (i != PEG_NUM)
		{
			cout << ", ";
		}
		else
		{
			cout << "]" << endl;
		}
	}
	slotNum = slotNum / DIV_CONSTANT;
	cout << "Winnings: $" << fixed << setprecision(2) << ComputeWinnings(slotNum) << endl << endl;
}


void MultChipFall(int userChipNum, int initialSlotNum, const string& outputString, const string& dollarNoDollarSign = "$")
{
	double sumWinnings = 0.0;
	int slotNum = 0;

	cout << endl;

	for (int j = 0; j < userChipNum; j++)
	{
		slotNum = initialSlotNum * DIV_CONSTANT;

		for (int i = 0; i <= PEG_NUM; i++)
		{
			slotNum = AChipFall(slotNum);
		}
		slotNum = slotNum / DIV_CONSTANT;
		sumWinnings += ComputeWinnings(slotNum);
	}
	cout << "Total winnings on " << fixed << setprecision(2) << outputString << sumWinnings << endl;
	cout << "Average winnings per chip: " << dollarNoDollarSign << fixed << setprecision(2) << sumWinnings / userChipNum << endl << endl;
}


void MultChipSimult()
{
	int userNumChips = 0;
	string displayString;
	string appendNumSlot;
	string appendChip = " chips: ";
	string noDollarSign = "";

	cout << "*** Sequentially drop multiple chips ***" << endl << endl;
	userNumChips = GetChipNum();

	for (int i = 0; i <= MAX_SLOT; i++)
	{
		displayString = "slot ";
		appendNumSlot = to_string(i);
		displayString.append(appendNumSlot + appendChip);

		MultChipFall(userNumChips, i, displayString, noDollarSign);
	}
}


int main()
{
	int userInput = 0;
	const int ONE_CHIP = 1;
	const int MULT_CHIP = 2;
	const int MULT_CHIP_SIMULT = 3;
	const int SHOW_OPTS = 4;
	const int QUIT_NOW = 5;
	const int RAND_SEED = 42;
	int numChips = 0;
	int initialSlotNum = 0;
	string stringOutput;
	string appendString;

	srand(RAND_SEED);

	cout << "Welcome to the Plinko simulator!  Enter 4 to see options." << endl << endl;

	do
	{
		cout << "Enter your selection now: " << endl;
		cin >> userInput;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(MAX_CHAR_IN_STRING, '\n');

			cout << "Invalid selection.  Enter 4 to see options." << endl << endl;
			cout << "Enter your selection now: " << endl;
			cin >> userInput;
		}

		switch (userInput)
		{
		case ONE_CHIP:
			SingleChipFall();
			break;

		case MULT_CHIP:
			cout << endl << "*** Drop multiple chips ***" << endl;

			numChips = GetChipNum();
			initialSlotNum = GetNumSlot();

			//formatting output so MultChipFall can be used again for MULT_CHIP_SIMULT
			stringOutput = to_string(numChips);
			appendString = " chips: $";
			stringOutput.append(appendString);

			MultChipFall(numChips, initialSlotNum, stringOutput);
			break;

		case MULT_CHIP_SIMULT:
			MultChipSimult();
			break;

		case SHOW_OPTS:
			GetMenuOption();
			break;

		case QUIT_NOW:
			break;

		default:
			cout << "Invalid selection.  Enter 4 to see options." << endl << endl;
			break;
		}
	} while (userInput != QUIT_NOW);

	cout << endl << "Goodbye!" << endl;
	system("pause");
	return 0;
}

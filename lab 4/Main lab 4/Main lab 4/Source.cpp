/*
Parker Hanson, Sarah Bradshaw, section 002, phanson96@gmail.com, sarahfaithbradshaw@gmail.com
Test case 1: checked to see if menu popped up
Input: 3
Expected Ouput: nice menu
Result: passed

Test case 2: invalid inputs
Input: 1, -1, 2, 9
Expected Ouput: invalid input message
Result: passed

Test case 3: single chip and multi chip
Input: 1, 1, 2, 3, 2
Expected Ouput: valid winnings
Result: passed
*/


#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main()
{
	cout << "Welcome to the Plinko simulator!  Enter 3 to see options." << endl << endl;


	int userInput = 0;
	const int ONE_CHIP = 1;
	const int MULT_CHIP = 2;
	const int SHOW_OPTS = 3;
	const int QUIT_NOW = 4;
	int slotNum = 0;
	const int MAX_PEG = 16;
	int i;
	const int PEG_NUM = 11;
	const int RAND_SEED = 42;
	double displaySlot = 0.0;
	double totalWinnings = 0.0;
	const double SMALL_PRIZE = 100.0;
	const double MED_PRIZE = 500.0;
	const double BIG_PRIZE = 1000.0;
	const double BEST_PRIZE = 10000.0;
	const double NO_PRIZE = 0.0;
	int userChipNum = 0;
	int initialSlotNum = 0;
	int j;
	const int MAX_SLOT = 8;
	const int DIV_CONSTANT = 2;

	srand(RAND_SEED);

	do
	{
		cout << "Enter your selection now: ";

		cin >> userInput;

		switch (userInput)
		{
		case ONE_CHIP:
			cout << endl << "*** Drop a single chip ***" << endl << endl;
			cout << "Which slot do you want to drop the chip in (0-8)? ";
			cin >> slotNum;

			if ((slotNum >= 0) && (slotNum <= MAX_SLOT))
			{

				cout << endl << "*** Dropping chip into slot " << slotNum << " ***" << endl;

				slotNum *= DIV_CONSTANT;

				displaySlot = slotNum / static_cast<double>(DIV_CONSTANT);

				cout << "Path: [" << fixed << setprecision(1) << displaySlot << ", ";

				for (i = 0; i <= PEG_NUM; i++)
				{
					switch (slotNum)
					{
					case 0:
						++slotNum;
						break;

					case MAX_PEG:
						--slotNum;
						break;

					default:
						slotNum += (rand() % 2) * DIV_CONSTANT - 1;

						break;
					}
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
				switch (slotNum / DIV_CONSTANT)
				{
				case 0:
				case 8:
					totalWinnings = SMALL_PRIZE;
					break;
				case 1:
				case 7:
					totalWinnings = MED_PRIZE;
					break;
				case 2:
				case 6:
					totalWinnings = BIG_PRIZE;
					break;
				case 3:
				case 5:
					totalWinnings = NO_PRIZE;
					break;
				default: //4
					totalWinnings = BEST_PRIZE;
					break;
				}

				cout << "Winnings: $" << fixed << setprecision(2) << totalWinnings << endl << endl;
			}
			else
			{
				cout << endl << "Invalid slot." << endl << endl;
			}
			break;

		case MULT_CHIP:
			totalWinnings = 0;

			cout << endl << "*** Drop multiple chips ***" << endl << endl << "How many chips do you want to drop(> 0)? ";
			cin >> userChipNum;

			if (userChipNum > 0)
			{

				cout << endl << "Which slot do you want to drop the chip in (0-8)? ";
				cin >> initialSlotNum;

				if ((initialSlotNum >= 0) && (initialSlotNum <= MAX_SLOT))
				{
					cout << endl;
					for (j = 0; j < userChipNum; ++j)
					{
						slotNum = initialSlotNum * DIV_CONSTANT;

						for (i = 0; i <= PEG_NUM; i++)
						{
							switch (slotNum)
							{
							case 0:
								++slotNum;
								break;

							case MAX_PEG:
								--slotNum;
								break;

							default:
								slotNum += (rand() % 2) * DIV_CONSTANT - 1;
								break;
							}
						}
						switch (slotNum / DIV_CONSTANT)
						{
						case 0:
						case 8:
							totalWinnings += SMALL_PRIZE;
							break;
						case 1:
						case 7:
							totalWinnings += MED_PRIZE;
							break;
						case 2:
						case 6:
							totalWinnings += BIG_PRIZE;
							break;
						case 3:
						case 5:
							totalWinnings += NO_PRIZE;
							break;
						default: //4
							totalWinnings += BEST_PRIZE;
							break;
						}
					}
					cout << "Total winnings on " << fixed << setprecision(2) << userChipNum << " chips: $" << totalWinnings << endl;
					cout << "Average winnings per chip: $" << fixed << setprecision(2) << totalWinnings / userChipNum << endl << endl;
				}
				else
				{
					cout << endl << "Invalid slot." << endl << endl;
				}
			}
			else
			{
				cout << endl << "Invalid number of chips." << endl << endl;
			}
			break;

		case SHOW_OPTS:
			cout << endl << "Menu: Please select one of the following options :" << endl << endl;
			cout << "1 - Drop a single chip into one slot" << endl;
			cout << "2 - Drop multiple chips into one slot" << endl;
			cout << "3 - Show the options menu" << endl;
			cout << "4 - Quit the program" << endl << endl;
			break;

		case QUIT_NOW:
			break;

		default:
			cout << endl << "Invalid selection.  Enter 3 to see options." << endl << endl;
			break;
		}
	} while (userInput != QUIT_NOW);

	cout << endl << "Goodbye!" << endl;
	//system("pause");
	return 0;
}
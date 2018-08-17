/*
Sarah Bradshaw, section 002, sarahfaithbradshaw@gmail.com

Use one late day for this lab please!

Test Case 1: add restaurants, display
Input: add, a, add, b, add, cat, add, dong kong, display
Expected Output: displays "a", "b"b, "cat", "dong kong", 
Result: passed

Test Case 1: cut and shuffle
Input: add, a, add, b, add, c, add, d, add, e, add, f, add, g, add, h, cut, display, shuffle, display
Expected Output:proper cutting and shuffling 
Result: passed

Test Case 1: battle
Input: a-h entered, selecting 2 every time
Expected Output: h is the winner
Result: passed

*/


#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;


const int MAX_CHAR_IN_STRING = 1000;
int indexFoundAt = 0;
const int DIV_2 = 2;


void PrintMenu();


void DisplayAllRests(const vector<string>& listOfRestaurants);


void AddRest(vector<string>& listOfRestaurants, int& numRests);


bool FindIfThere(string addOrRemoveString, vector<string>& listOfRestaurants, int& numRests);


void RemoveRest(vector<string>& listOfRestaurants, int& numRests);


void CutRests(vector<string>& listOfRestaurants, const int numRests);


void ShuffleRests(vector<string>& listOfRestaurants, const int numRests);


void RestsBattle(vector<string>& listOfRestaurants, int numRests);


bool IsPower2(const int numRests);




int main()
{
	string userChoice;
	int numRests = 0;
	vector<string> restaurantList(numRests);

	cout << "Welcome to the restaurant battle!  Enter \"options\" to see options." << endl << endl;

	do
	{
		cout << "Enter your selection: ";

		cin >> userChoice;
		cout << endl << endl;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(MAX_CHAR_IN_STRING, '\n');
			PrintMenu();
		}
		else if (userChoice == "quit")
		{
			break;
		}
		else if (userChoice == "options")
		{
			PrintMenu();
		}
		else if (userChoice == "display")
		{
			DisplayAllRests(restaurantList);
		}
		else if (userChoice == "add")
		{
			AddRest(restaurantList, numRests);
		}
		else if (userChoice == "remove")
		{
			RemoveRest(restaurantList, numRests);
		}
		else if (userChoice == "cut")
		{
			CutRests(restaurantList, numRests);
		}
		else if (userChoice == "shuffle")
		{
			ShuffleRests(restaurantList, numRests);
		}
		else if (userChoice == "battle")
		{
			RestsBattle(restaurantList, numRests);
		}
		else
		{
			cout << "Invalid Selection" << endl;

			PrintMenu();
		}
	} while (userChoice != "quit");

	
	cout << "Goodbye!";

	system("pause");
	return 0;
}




void PrintMenu()
{
	cout << endl << "Please select one of the following options:" << endl << endl;
	cout << "quit - Quit the program" << endl;
	cout << "display - Display all restaurants" << endl;
	cout << "add - Add a restaurant" << endl;
	cout << "remove - Remove a restaurant" << endl;
	cout << "cut - \"Cut\" the list of restaurants" << endl;
	cout << "shuffle - \"Shuffle\" the list of restaurants" << endl;
	cout << "battle - Begin the tournament" << endl;
	cout << "options - Print the options menu" << endl << endl;
}


void DisplayAllRests(const vector<string>& listOfRestaurants)
{
	cout << "Here are the current restaurants :" << endl;

	for (size_t i = 0; i < listOfRestaurants.size(); i++)
	{
		cout << "\t" << "\"" << listOfRestaurants.at(i) << "\"" << endl << endl;
	}
}


void AddRest(vector<string>& listOfRestaurants, int& numRests)
{
	string restToAdd;
	bool isThere;

	cout << "What is the name of the restaurant you want to add?" << endl;
	
	cin.clear();
	cin.ignore(MAX_CHAR_IN_STRING, '\n');
	getline(cin, restToAdd);

	isThere = FindIfThere(restToAdd, listOfRestaurants, numRests);

	if (isThere)
	{
		cout << "That restaurant is already on the list, you can not add it again." << endl << endl;
	}
	else if (!isThere)
	{
		numRests++;
		listOfRestaurants.push_back(restToAdd);
		cout << restToAdd << " has been added." << endl << endl;
	}
}


bool FindIfThere(const string addOrRemoveString, vector<string>& listOfRestaurants, int& numRests)
{
	bool isThere = 0;

	if (listOfRestaurants.size() == 0)
	{
		isThere = false;
		return isThere;
	}
	else
	{
		for (int i = 0; i < numRests; i++)
		{
			if (listOfRestaurants.at(i) == addOrRemoveString)	
			{
				isThere = true;
				indexFoundAt = i;
				return isThere;
				break;
			}
		}
	}
	return isThere;
}


void RemoveRest(vector<string>& listOfRestaurants, int& numRests)
{
	string restToRemove;
	bool isThere;

	cout << "What is the name of the restaurant you want to remove?" << endl;
	
	cin.clear();
	cin.ignore(MAX_CHAR_IN_STRING, '\n');
	getline(cin, restToRemove);

	isThere = FindIfThere(restToRemove, listOfRestaurants, numRests);

	if (isThere)
	{
		numRests--;
		listOfRestaurants.erase(listOfRestaurants.begin() + indexFoundAt);
		cout << restToRemove << " has been removed." << endl << endl;
	}
	else if (!isThere)
	{
		cout << "That restaurant is not on the list, you can not remove it." << endl << endl;
	}
}


void CutRests(vector<string>& listOfRestaurants, const int numRests)
{
	int cutNum = 0;
	int leftNum = 0;

	vector<string> cutListOfRestaurants(numRests);


	cout << "How many restaurants should be taken from the top and put on the bottom? ";
	cin >> cutNum;

	while ((cutNum < 0) || (cutNum > numRests) || cin.fail())
	{
		cin.clear();
		cin.ignore(MAX_CHAR_IN_STRING, '\n');

		cout << endl << "The cut number must be between 0 and " << numRests << endl << endl;
		cout << endl << "How many restaurants should be taken from the top and put on the bottom? ";
		cin >> cutNum;
	}
	
	cout << endl << endl;

	leftNum = numRests - cutNum;

	for (int i = 0; i < numRests; i++)
	{

		if (i < leftNum) 
		{
			cutListOfRestaurants.at(i) = listOfRestaurants.at(i + cutNum);
		}
		else
		{
			cutListOfRestaurants.at(i) = listOfRestaurants.at(i - leftNum);
		}
	}
	listOfRestaurants = cutListOfRestaurants;
}


void ShuffleRests(vector<string>& listOfRestaurants, const int numRests)
{
	vector<string> firstHalfVector(numRests / DIV_2);
	vector<string> secondHalfVector(numRests / DIV_2);
	vector<string> shuffledVector(numRests);
	bool numRestsIsPowerOf2 = 0;

	numRestsIsPowerOf2 = IsPower2(numRests);

	if (!numRestsIsPowerOf2)
	{
		cout << "The current tournament size (" << listOfRestaurants.size() << ") is not a power of two (2, 4, 8...)." << endl;

		cout << "A shuffle is not possible. Please add or remove restaurants." << endl;
	}
	else
	{
		for (int i = 0; i < numRests / DIV_2; i++)
		{
			firstHalfVector.at(i) = listOfRestaurants.at(i);
		}
		for (int i = 0; i < numRests / DIV_2; i++)
		{
			secondHalfVector.at(i) = listOfRestaurants.at(i + numRests / 2);
		}
		for (int i = 0; i < numRests; i++)
		{
			if (i % DIV_2 == 0) //i is even -- use second half of vect
			{
				shuffledVector.at(i) = secondHalfVector.at(i / DIV_2);
			}
			else if (i % DIV_2 != 0) //i is odd -- use first half of vect
			{
				shuffledVector.at(i) = firstHalfVector.at(i / DIV_2);
			}
		}
		listOfRestaurants = shuffledVector;
	}
}


void RestsBattle(vector<string>& listOfRestaurants, int numRests)
{
	vector<string> survivingRests;
	string rest0;
	string rest1;

	const int NUM_OPPONENT = 2;
	const int FIRST_CHOICE = 1;
	const int SECOND_CHOICE = 2;

	int numRound = 0;
	int restChoice;
	int startVal = 0;

	bool numRestIsPowerOf2 = 0;


	numRestIsPowerOf2 = IsPower2(numRests);


	if (!numRestIsPowerOf2)	
	{
		cout << "The current tournament size(" << numRests << ") is not a power of two(2, 4, 8...)." << endl;
		cout << "A battle is not possible. Please add or remove restaurants." << endl << endl;
	}
	else
	{
		for (size_t i = 0; i < sqrt(numRests); i++)	//rounds
		{
			startVal = 0;

			numRound = i + 1;
			cout << "Round: " << numRound << endl;

			for (size_t j = 0; j < listOfRestaurants.size() / DIV_2; j++)	//matches
			{
				for (int k = startVal; k < startVal + NUM_OPPONENT; k++) //selects opponents
				{
					if (k == startVal)
					{
						rest0 = listOfRestaurants.at(k);
					}
					else if (k != startVal)
					{
						rest1 = listOfRestaurants.at(k);
					}
				}

				cout << "Type \"1\" if you prefer " << rest0 << " or" << endl;
				cout << "Type \"2\" if you prefer " << rest1 << endl;
				cout << "Choice: ";
				cin >> restChoice;


				while ((restChoice != FIRST_CHOICE) && (restChoice != SECOND_CHOICE) || cin.fail())
				{
					cin.clear();
					cin.ignore(MAX_CHAR_IN_STRING, '\n');

					cout << "Invalid choice" << endl;
					cout << "Type \"1\" if you prefer " << rest0 <<" or" << endl;
					cout << "Type \"2\" if you prefer " << rest1 << endl;
					cout << "Choice: ";
					cin >> restChoice;
				}

				if (restChoice == FIRST_CHOICE)	//rest0
				{
					survivingRests.push_back(listOfRestaurants.at(startVal));
				}
				else if (restChoice == SECOND_CHOICE) //rest1
				{
					survivingRests.push_back(listOfRestaurants.at(startVal + 1));
				}

				cout << endl << endl;

				startVal += NUM_OPPONENT;
			}

			listOfRestaurants.resize(survivingRests.size());
			listOfRestaurants = survivingRests;
			survivingRests.clear();
		}

		cout << "The winning restaurant is " << listOfRestaurants.at(0) << "." << endl << endl;

	}
}


bool IsPower2(const int numRests)
{
	static_cast<double>(numRests);

		if (floor(log2(numRests)) == ceil(log2(numRests)))
		{
			return true;
		}
		else
		{
			return false;
		}
}
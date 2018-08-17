#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {

	string inputString;
	bool commaIsThere = 0;
	istringstream inSS;
	string firstWord;
	string secondWord;
	string null;
	//ostringstream outSS;

	cout << "Enter input string: ";
	getline(cin, inputString);
	cout << endl;

	while (inputString != "q")
	{
		commaIsThere = false;

		while (commaIsThere == false)
		{
			for (size_t i = 0; i < inputString.size(); i++)
			{
				if (inputString.at(i) == ',')
				{
					commaIsThere = true;
					break;
				}
			}

			if (commaIsThere == false)
			{
				cout << "Error: No comma in string" << endl;

				cout << "Enter input string: ";
				getline(cin, inputString);
				cout << endl;

				if (inputString == "q")
				{
					break;
				}
			}

		}

		//search through string to replace comma with space
		for (size_t i = 0; i < inputString.size(); i++)
		{
			if (inputString.at(i) == ',')
			{
				inputString.replace(i, 1, " ");
			}
		}

		inSS.clear();
		inSS.str(inputString);
		inSS >> firstWord;
		inSS >> secondWord;


		cout << "First word: " << firstWord << endl;
		cout << "Second word: " << secondWord << endl << endl << endl;

		cout << "Enter input string: ";
		getline(cin, inputString);
		cout << endl;
	}

	system("pause");
	return 0;
}

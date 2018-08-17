#include <iostream>
#include <string>
using namespace std;

//function declarations
char PrintMenu(string& userString);
int GetNumOfNonWSCharacters(const string userString);
int  GetNumOfWords(const string userString);
int FindText(const string& userString, const string& findString);
void ReplaceExclamation(string& periodString);
void  ShortenSpace(string& shortenedString);

char menuChoice;

int main()
{
	string userString;

	cout << "Enter a sample text: ";
	getline(cin, userString);

	cout << endl << endl << "You entered: " << userString << endl;

	PrintMenu(userString);
	while (menuChoice != 'q')
	{
		PrintMenu(userString);
	}

	system("pause");
	return 0;
}

char PrintMenu(string& userString)
{

	cout << "MENU" << endl;
	cout << "c - Number of non-whitespace characters" << endl;
	cout << "w - Number of words" << endl;
	cout << "f - Find text" << endl;
	cout << "r - Replace all !'s" << endl;
	cout << "s - Shorten spaces" << endl;
	cout << "q - Quit" << endl << endl;
	cout << "Choose an option: " << endl;

	cin >> menuChoice;

	while ((menuChoice != 'c') && (menuChoice != 'w') && (menuChoice != 'f') && (menuChoice != 'r') && (menuChoice != 's') && (menuChoice != 'q'))
	{
		cout << "MENU" << endl;
		cout << "c - Number of non-whitespace characters" << endl;
		cout << "w - Number of words" << endl;
		cout << "f - Find text" << endl;
		cout << "r - Replace all !'s" << endl;
		cout << "s - Shorten spaces" << endl;
		cout << "q - Quit" << endl << endl;
		cout << "Choose an option: " << endl;
		cin >> menuChoice;
	}


	if (menuChoice == 'c')
	{
		cout << "Number of non-whitespace characters: " << GetNumOfNonWSCharacters(userString) << endl << endl;
	}

	else if (menuChoice == 'w')
	{
		cout << "Number of words: " << GetNumOfWords(userString) << endl << endl;

	}

	else if (menuChoice == 'f')
	{
		string stringFind;
		cin.clear();
		cin.ignore(20, '\n');
		cout << "Enter a word or phrase to be found: " << endl;
		getline(cin, stringFind);

		cout << "\"" << stringFind << "\"" << " instances: " << FindText(userString, stringFind) << endl;
	}
	else if (menuChoice == 'r')
	{
		cout << "Edited text: ";
		ReplaceExclamation(userString);
		cout << userString << endl << endl;
	}
	else if (menuChoice == 's')
	{
		ShortenSpace(userString);
		cout << "Edited text: " << userString << endl;
	}
	return menuChoice;
}

int GetNumOfNonWSCharacters(const string userString)
{
	int numCharNotWhiteSpace = 0;
	for (size_t i = 0; i < userString.size(); i++)
	{
		if (!isspace(userString.at(i)))
		{
			numCharNotWhiteSpace += 1;
		}
	}

	return numCharNotWhiteSpace;
}

int  GetNumOfWords(const string userString)
{
	int numWords = 1;									// to acount for no space at end and bc there's always one word
	for (size_t i = 0; i < userString.size(); i++)
	{
		if (isspace(userString.at(i)) && !isspace(userString.at(i + 1)))
		{
			numWords += 1;
		}
	}
	return numWords;
}

int FindText(const string& userString, const string& findString)
{
	int numInstance = 0;
	int indx = 0;
	string editedString;

	editedString = userString;

	while (editedString.find(findString) != string::npos)
	{
		numInstance++;
		indx = editedString.find(findString);
		editedString = editedString.substr(indx + findString.length(), (editedString.length() - 1));

	}

	return numInstance;
}

void ReplaceExclamation(string& periodString)
{ 
	for (size_t i = 0; i < periodString.size(); i++)
	{
		if (periodString.at(i) == '!')
		{
			periodString.at(i) = '.';
		}
	}
}

void  ShortenSpace(string& shortenedString)
{
	for (size_t i = 0; i < shortenedString.size(); i++)
	{
		if (isspace(shortenedString.at(i)) && !isalpha(shortenedString.at(i + 1)))
		{
			shortenedString.erase(i, 1);
		}
	}
}
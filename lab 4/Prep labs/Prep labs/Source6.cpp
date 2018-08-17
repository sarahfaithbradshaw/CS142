#include <iostream>
#include <string>
using namespace std;

//Returns the number of spaces in usrStr
int GetNumOfSpaces(const string usrStr) {
	int sumSpaces = 0;
	for (size_t i = 0; i < usrStr.size(); i++) {
		if (isspace(usrStr.at(i))) {
			sumSpaces += 1;
		}
	}
	return sumSpaces;
}

void OutputWithoutWhitespace(const string usrStr) {
	for (size_t i = 0; i < usrStr.size(); i++) {
		if (!isspace(usrStr.at(i))) {
			cout << usrStr.at(i);
		}
	}
}

int main() {
	string usrStr;

	cout << "Enter a sentence or phrase: ";
	getline(cin, usrStr);
	cout << endl << "You entered: " << usrStr << endl;

	cout << endl << "Number of spaces: " << GetNumOfSpaces(usrStr) << endl;
	cout << "String with no whitespace: ";
	OutputWithoutWhitespace(usrStr);
	cout << endl;

	system("pause");
	return 0;
}
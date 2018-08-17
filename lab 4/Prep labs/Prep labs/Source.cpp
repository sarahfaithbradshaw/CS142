//Use one late day on this prep lab please!

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

	const int NUM_ELEMENTS = 5;
	vector<int> jerseyNum(NUM_ELEMENTS);
	vector<int> ratingNum(NUM_ELEMENTS);
	unsigned int i;
	string userChoice;
	unsigned int addJersey;
	unsigned int addRate;
	unsigned int delJersey;
	unsigned int updateJersey;
	unsigned int updateRate;
	unsigned int minRat;

	for (i = 0; i < NUM_ELEMENTS; ++i) {
		cout << "Enter player " << i + 1 << "'s jersey number: ";
		cin >> jerseyNum.at(i);

		cout << endl << "Enter player " << i + 1 << "'s rating: ";
		cin >> ratingNum.at(i);
		cout << endl << endl;
	}

	//roster
	cout << "ROSTER" << endl;

	for (i = 0; i < NUM_ELEMENTS; ++i) {
		cout << "Player " << i + 1 << " -- Jersey number: " << jerseyNum.at(i) << ", Rating: " << ratingNum.at(i) << endl;
	}

	// menu

	cout << endl << "MENU" << endl;
	cout << "a - Add player" << endl;
	cout << "d - Remove player" << endl;
	cout << "u - Update player rating" << endl;
	cout << "r - Output players above a rating" << endl;
	cout << "o - Output roster" << endl;
	cout << "q - Quit" << endl << endl;
	cout << "Choose an option :";
	cin >> userChoice;
	cout << endl;

	while (userChoice != "q") {


		if (userChoice == "o") {
			cout << "ROSTER" << endl;
			for (i = 0; i < jerseyNum.size(); ++i) {
				cout << "Player " << i + 1 << " -- Jersey number: " << jerseyNum.at(i) << ", Rating: " << ratingNum.at(i) << endl;
			}
		}

		if (userChoice == "a") {
			cout << "Enter another player's jersey number: ";
			cin >> addJersey;
			jerseyNum.push_back(addJersey);

			cout << endl << "Enter another player's rating: ";
			cin >> addRate;
			ratingNum.push_back(addRate);
		}

		if (userChoice == "d") {
			cout << "Enter a jersey number: ";
			cin >> delJersey;

			for (i = 0; i < jerseyNum.size(); ++i) {
				if (jerseyNum.at(i) == delJersey) {
					jerseyNum.erase(jerseyNum.begin() + i);
					ratingNum.erase(ratingNum.begin() + i);
				}
			}
		}

		if (userChoice == "u") {
			cout << "Enter a jersey number: ";
			cin >> updateJersey;
			for (i = 0; i < jerseyNum.size(); ++i) {
				if (updateJersey == jerseyNum.at(i)) {
					cout << endl << "Enter a new rating for player: ";
					cin >> updateRate;
					ratingNum.at(i) = updateRate;
				}
			}
		}

		if (userChoice == "r") {
			cout << "Enter a rating: ";
			cin >> minRat;
			cout << endl << "ABOVE " << minRat << endl;

			for (i = 0; i < ratingNum.size(); ++i) {
				if (ratingNum.at(i) > minRat) {
					cout << "Player " << i + 1 << " -- Jersey number: " << jerseyNum.at(i) << ", Rating: " << ratingNum.at(i) << " " << endl;
				}
			}
		}
		if (userChoice == "q") {
			break;
		}

		cout << endl << "MENU" << endl;
		cout << "a - Add player" << endl;
		cout << "d - Remove player" << endl;
		cout << "u - Update player rating" << endl;
		cout << "r - Output players above a rating" << endl;
		cout << "o - Output roster" << endl;
		cout << "q - Quit" << endl << endl;
		cout << "Choose an option :";
		cin >> userChoice;
		cout << endl << endl;
	}



	system("pause");
	return 0;
}
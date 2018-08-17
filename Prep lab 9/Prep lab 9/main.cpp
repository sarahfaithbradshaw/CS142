#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

class Student {
public:
	Student(string name = "not intialized", double GPA = 0.0);
	void SetName(string studentName);
	void SetGPA(double personName);
	string ToString() const;
private:
	string name;
	double GPA;
};

Student::Student(string initialName, double initialGPA)
{
	name = initialName;
	GPA = initialGPA;
}

void Student::SetName(string inputName)
{
	name = inputName;
}

void Student::SetGPA(double newGPA)
{
	GPA = newGPA;
}

string Student::ToString() const
{
	ostringstream outSS;

	outSS << name << " has a GPA of " << fixed << setprecision(1) << GPA;
		
	return outSS.str();
}


int main() {
	vector<Student*> studentsPtr;
	Student* currPtr = nullptr;
	string userInput;
	string name;
	double GPA = 0.0;
	int dropIndex = 0;


	do
	{
		cout << "Enter Option: ";
		cin >> userInput;

		if (userInput == "add")
		{
			cout << "Student name: ";
			cin >> name;
			cout << endl;

			cout << name << "'s GPA: ";
			cin >> GPA;
			cout << endl << endl;

			currPtr = new Student(name, GPA);		//this says hey we want a memory location for this student obj, point to it using currPtr
			studentsPtr.push_back(currPtr);			//adds the pointer to the new student obj to the pointer vector
				
		}
		else if (userInput == "drop")
		{
			cout << "Index of student to drop: ";
			cin >> dropIndex;

			delete studentsPtr.at(dropIndex);		//deletes the memory location
			studentsPtr.erase(studentsPtr.begin() + dropIndex);	//deletes the actual pointer to that memory location

		}
		else if (userInput == "print")
		{
			for (size_t i = 0; i < studentsPtr.size(); i++)
			{
				cout << i << ": " << studentsPtr.at(i)->ToString() << endl;		//take this pointer, dereference it for me, and then print that student's info out
			}
			cout << endl;
		}
		else if (userInput == "quit")
		{
			break;
		}
	} while (userInput != "quit");

	return 0;
}
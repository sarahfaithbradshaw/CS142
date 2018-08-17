#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student {
public:
	Student(string initialName = "No Name") {
		name = initialName;
	}

	// Enter definition for a virtual ToStr member function here.
	virtual void ToString()
	{
		cout << name << " is an undergraduate student." << endl;
	}


protected:
	string name;
};

class GradStudent : public Student {
public:

	// Enter definition for a paramteriezed contructor function here that sets both data members.
	GradStudent(string theirName = "No Name", string areaResearch = "none")
	{
		name = theirName;
		researchArea = areaResearch;
	}

	// Enter definition for a virtual ToStr member function here.
	virtual void ToString()
	{
		cout << name << " is a graduate student researching the area of " << researchArea << "." << endl;
	}

private:
	string researchArea;
};

int main() {
	string usrOption;
	string inpName;
	string inpResearch;
	vector<Student*> classMembers;
	Student* studentPtr = nullptr;
	GradStudent* gradPtr = nullptr;

	do {
		cout << "Option: ";
		cin >> usrOption;
		cout << endl;
		if (usrOption == "print") {

			// Enter code here to print each member pointed to from classMembers using their respective ToStr member functions.	
			for (size_t i = 0; i < classMembers.size(); i++)
			{
				classMembers.at(i)->ToString();
			}
		}

		else if (usrOption == "add") {
			cout << "Name: ";
			cin >> inpName;
			cout << endl;
			cout << "If grad student enter a one word research area, else enter \"NO\": ";
			cin >> inpResearch;
			cout << endl;

			// Enter code here to create new objects (using new) for either a Student or a GradStudent
			// and add the pointer to the classMember vector.			
			if (inpResearch == "NO")
			{
				studentPtr = new Student(inpName);
				classMembers.push_back(studentPtr);
			}
			else
			{
				gradPtr = new GradStudent(inpName, inpResearch);
				classMembers.push_back(gradPtr);
			}
		}
	} while (usrOption != "quit");


system("pause");
return 0;
}
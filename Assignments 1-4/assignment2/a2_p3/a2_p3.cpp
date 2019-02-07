#include <iostream>
#include <string>

using namespace std;

class Employee
{
protected:
	string name;
	int idNumbe;
	string department;
	string position;
public:
	Employee()
	{
		name = "";
		idNumbe = 0;
		department = "";
		position = "";
	}
	Employee(string name2, int idNumbe2)
	{
		name = name2;
		idNumbe = idNumbe2;
		department = "";
		position = "";
	}
	Employee(string name1, int idNumbe1, string department1, string position1)
	{
		name = name1;
		idNumbe = idNumbe1;
		department = department1;
		position = position1;
	}
	void setName(string);
	void setID(int);
	void setDepartment(string);
	void setPosition(string);
	string getName();
	int getID();
	string getDepartment();
	string getPosition();
};

void Employee::setName(string n)
{
	name = n;
}

void Employee::setID(int id)
{
	idNumbe = id;
}

void Employee::setDepartment(string d)
{
	department = d;
}

void Employee::setPosition(string p)
{
	position = p;
}

string Employee::getName()
{
	return name;
}

int Employee::getID()
{
	return idNumbe;
}

string Employee::getDepartment()
{
	return department;
}

string Employee::getPosition()
{
	return position;
}




int main()
{
	string name1, name2, name3;
	int id1, id2, id3;
	string dep1, dep2, dep3;
	string pos1, pos2, pos3;

	Employee e1;
	Employee e2;
	Employee e3;

	
	cout << "Please enter name of first employee. ";
	getline(cin, name1);
	e1.setName(name1);
	cout << "Please first employee id number. ";
	cin >> id1;
	cin.ignore(1000, 10);
	e1.setID(id1);
	cout << "Please enter first employee department. ";
	getline(cin, dep1);
	e1.setDepartment(dep1);
	cout << "Please enter first employee position. "; 
	getline(cin, pos1);
	e1.setPosition(pos1);
	cout << endl;

	cout << "Please enter name of second employee. ";
	getline(cin, name2);
	e1.setName(name2);
	cout << "Please second employee id number. ";
	cin >> id2;
	cin.ignore(1000, 10);
	e1.setID(id2);
	cout << "Please enter second employee department. ";
	getline(cin, dep2);
	e1.setDepartment(dep2);
	cout << "Please enter second employee position. ";
	getline(cin, pos2);
	e1.setPosition(pos2);
	cout << endl;

	cout << "Please enter name of third employee. ";
	getline(cin, name3);
	e1.setName(name3);
	cout << "Please third employee id number. ";
	cin >> id3;
	cin.ignore(1000, 10);
	e1.setID(id3);
	cout << "Please enter third employee department. ";
	getline(cin, dep3);
	e1.setDepartment(dep3);
	cout << "Please enter third employee position. ";
	getline(cin, pos3);
	e1.setPosition(pos3);
	cout << endl;

	cout << e1.getName() << "   " << e1.getID() << "   " << e1.getDepartment() << "   " << e1.getPosition(); 
	cout << e2.getName() << "   " << e2.getID() << "   " << e2.getDepartment() << "   " << e2.getPosition();
	cout << e3.getName() << "   " << e3.getID() << "   " << e3.getDepartment() << "   " << e3.getPosition();
	return 0;
}
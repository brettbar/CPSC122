#include <iostream>
#include <string>

using namespace std;

class Date {
private :
	int month;
	int day;
	int year;
public :
	void input_values() {
		
		// Asks for the month, day and year and refuses out of range answers. 
		cout << "Enter the month number: ";
		cin >> month;
		while (month > 12 || month < 1) {
			cout << "Pick a number in an appropriate range of 1-12. " << endl;
			cin >> month;
		}
		cout << endl; 

		cout << "Enter the day number: ";
		cin >> day;
		cout << endl;
		while (day > 31 || day < 1) {
			cout << "Pick a number in an appropriate range of 1-31. " << endl;
			cin >> day;
		}

		cout << "Enter the year number: ";
		cin >> year;
		cout << endl;
	}
	// This function actually outputs the dates in the correct formats.
	void output_value() {
		cout << month << "/" << day << "/" << year << endl;
		string monthName;
		if (month == 1) {
			monthName = "January";
		}
		else if (month == 2) {
			monthName = "February";
		}
		else if (month == 3) {
			monthName = "March";
		}
		else if (month == 4) {
			monthName = "April";
		}
		else if (month == 5) {
			monthName = "May";
		}
		else if (month == 6) {
			monthName = "June";
		}
		else if (month == 7) {
			monthName = "July";
		}
		else if (month == 8) {
			monthName = "August";
		}
		else if (month == 9) {
			monthName = "September";
		}
		else if (month == 10) {
			monthName = "October";
		}
		else if (month == 11) {
			monthName = "November";
		}
		else if (month == 12) {
			monthName = "December";
		} 
		else {
			cout << "Unacceptable input " << endl;
		}
		cout << monthName << " " << day << ", " << year << endl;
		cout << day << " " << monthName << " " << year << endl;
	}	
};

int main() {
	Date d;
	d.input_values();
	d.output_value();
	return 0;
}
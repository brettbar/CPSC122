#include <iostream>
#include <string>
#include <fstream>


using namespace std;

struct Info 
{
	string divisionName;
	int quarter;
	double sales1;
	double sales2;
	double sales3;
	double sales4;
};

void form()
{
	Info East;
	Info West;
	Info North;
	Info South;

	East.divisionName = "East";
	West.divisionName = "West";
	North.divisionName = "North";
	South.divisionName = "South"; 

/////////////////////////////////////////////////////////////
	cout << "Enter the quarter 1 sales for East Division. "; 
	cin >> East.sales1; 
	while (East.sales1 < 0)
	{
		cout << "No negative numbers."; 
		cin >> East.sales1;
	}

	cout << "Enter the quarter 2 sales for East Division. ";
	cin >> East.sales2;
	while (East.sales2 < 0)
	{
		cout << "No negative numbers.";
		cin >> East.sales2;
	}

	cout << "Enter the quarter 3 sales for East Division. ";
	cin >> East.sales3;
	while (East.sales3 < 0)
	{
		cout << "No negative numbers.";
		cin >> East.sales3;
	}

	cout << "Enter the quarter 4 sales for East Division. ";
	cin >> East.sales4;
	while (East.sales4 < 0)
	{
		cout << "No negative numbers.";
		cin >> East.sales4;
	}
/////////////////////////////////////////////////////////////
	cout << "Enter the quarter 1 sales for West Division. ";
	cin >> West.sales1;
	while (West.sales1 < 0)
	{
		cout << "No negative numbers.";
		cin >> West.sales1;
	}

	cout << "Enter the quarter 2 sales for West Division. ";
	cin >> West.sales2;
	while (West.sales2 < 0)
	{
		cout << "No negative numbers.";
		cin >> West.sales2;
	}

	cout << "Enter the quarter 3 sales for West Division. ";
	cin >> West.sales3;
	while (West.sales3 < 0)
	{
		cout << "No negative numbers.";
		cin >> West.sales3;
	}

	cout << "Enter the quarter 4 sales for West Division. ";
	cin >> West.sales4;
	while (West.sales4 < 0)
	{
		cout << "No negative numbers.";
		cin >> West.sales4;
	}
////////////////////////////////////////////////////////////////
	cout << "Enter the quarter 1 sales for North Division. ";
	cin >> North.sales1;
	while (North.sales1 < 0)
	{
		cout << "No negative numbers.";
		cin >> North.sales1;
	}

	cout << "Enter the quarter 2 sales for North Division. ";
	cin >> North.sales2;
	while (North.sales2 < 0)
	{
		cout << "No negative numbers.";
		cin >> North.sales2;
	}

	cout << "Enter the quarter 3 sales for North Division. ";
	cin >> North.sales3;
	while (North.sales3 < 0)
	{
		cout << "No negative numbers.";
		cin >> North.sales3;
	}

	cout << "Enter the quarter 4 sales for North Division. ";
	cin >> North.sales4;
	while (North.sales4 < 0)
	{
		cout << "No negative numbers.";
		cin >> North.sales4;
	}
///////////////////////////////////////////////////////////////////
	cout << "Enter the quarter 1 sales for South Division. ";
	cin >> South.sales1;
	while (South.sales1 < 0)
	{
		cout << "No negative numbers.";
		cin >> South.sales1;
	}

	cout << "Enter the quarter 2 sales for South Division. ";
	cin >> South.sales2;
	while (South.sales2 < 0)
	{
		cout << "No negative numbers.";
		cin >> South.sales2;
	}

	cout << "Enter the quarter 3 sales for South Division. ";
	cin >> South.sales3;
	while (South.sales3 < 0)
	{
		cout << "No negative numbers.";
		cin >> South.sales3;
	}

	cout << "Enter the quarter 4 sales for South Division. ";
	cin >> South.sales4;
	while (South.sales4 < 0)
	{
		cout << "No negative numbers.";
		cin >> South.sales4;
	}
	print(East, West, North, South);
}

void print(Info East, Info West, Info North, Info South)
{
	ofstream file; 
	file.open("Quarterly Sales");
	file << "Sales for East Division.\n";
	file << "Quarter 1: " << East.sales1 << " Quarter 2: " << East.sales2 << " Quarter 3: " << East.sales3 << " Quarter 4: " << East.sales4; 

	file << "Sales for East Division.\n";
	file << "Quarter 1: " << West.sales1 << " Quarter 2: " << West.sales2 << " Quarter 3: " << West.sales3 << " Quarter 4: " << West.sales4;

	file << "Sales for East Division.\n";
	file << "Quarter 1: " << North.sales1 << " Quarter 2: " << North.sales2 << " Quarter 3: " << North.sales3 << " Quarter 4: " << North.sales4;

	file << "Sales for East Division.\n";
	file << "Quarter 1: " << South.sales1 << " Quarter 2: " << South.sales2 << " Quarter 3: " << South.sales3 << " Quarter 4: " << South.sales4;

	file.close(); 
}

int main()
{
	form();
	return 0;
}

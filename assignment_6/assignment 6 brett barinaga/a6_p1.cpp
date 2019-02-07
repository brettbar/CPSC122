 /*
Problem 1
Brett Barinaga
12/3/2017
*/


#include <iostream>

using namespace std;

int function(int);

int main()
{
	int x = 10;
	cout << function(x) << endl;
	return 0;
}
int function(int num)
{
	if (num <= 0)
		return 0;
	else
		return function(num - 1) + num; // Assuming this is suppoed to have a minus after num, it was  blank in the assignment which would yield an error
} 


// This program returns 55 as the output.

#include <iostream>
#include <string>

using namespace std;

void function(string, int, int);

int main()
{
	string mystr = "Hello";
	cout << mystr << endl;
	function(mystr, 0, mystr.size());
	return 0;
}
void function(string str, int pos, int size)
{
	if (pos < size)
	{
		function(str, pos + 1, size);
		cout << str[pos];
	}
}

// This program outputs Hello
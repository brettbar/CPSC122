#include <iostream>

using namespace std;

int sum(int, int);

int main()
{
	int xNum = 5;
	int yNum = 4;
	int *x = &xNum;
	int *y = &yNum; 

	cout << sum(x, y) << endl;


	system("pause");
	return 0;
}

int sum(int *a, int *b)
{
	int sum = *a + *b;
	return sum;
}


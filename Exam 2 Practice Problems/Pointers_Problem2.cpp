#include <iostream>

using namespace std;

int doSomething(int *x, int *y)
{
	int temp = *x;
	*x = *y * 10;
	*y = temp * 10;
	return *x + *y;
}

int main()
{
	int a = 4;
	int b = 3;
	cout << doSomething(&a,&b);
	return 0;
}


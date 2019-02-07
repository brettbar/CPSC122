#include <iostream>
#include <fstream>

using namespace std;
S
struct QueueNode
{
	char value;
	QueueNode* next;
};

int main()
{
	DynCharQueue Q1;
	DynCharQueue Q2;

	ifstream F1("file1.txt");
	ifstream F2("file2.txt");

	while(!F1.eof())
	{
		F1 >> x;
		Q1.enqueue(x);
	}
	do 
	{
		Q1.dequeue(v1);
		Q2.dequeue(v2);
		if(v1 != v2)
		{
			cout <<"not equal";
			return 0;
		}
		while (v1 == v2);
		cout << "Equal";
		return 0;
	}
}
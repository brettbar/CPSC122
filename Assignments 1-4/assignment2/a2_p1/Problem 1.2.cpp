#include <iostream>
using namespace std;
class DumbBell;
{
	// Should to state if this int is public, private, or protected.
	int weight;
public:
	void setWeight(int); 
};
void setWeight(int w) // This method should be inside the class DumbBell
{
	weight = w;	// This weight isnt defined because of the lack of a protected or private variable in the class dumbell
}
int main()
{
	DumbBell bar;	
	DumbBell(200); // if you are trying to set the weight, you would do bar.setWeight(200);
	cout << "The weight is " << bar.weight << endl;
	
	return 0;
}

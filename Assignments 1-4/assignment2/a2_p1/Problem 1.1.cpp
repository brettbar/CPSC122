#include <iostream>


// Original version

// Assuming we want this class to work on its own, we need to either define the setCenter and setRadius methods, or inherit a class which does.
class Circle : // missing an inheritance class call
{
	private				 // Private should have a colon after it.
		double centerX; 
		double centerY;
		double radius;
	public				// Public should have a colon after it.
		setCenter(double, double); 
		setRadius(double);
} // There should be a semi colon at the end of this class.

// Corrected version

class Circle : public someClassThatWeWantToInherit
{
private:
	double centerX;
	double centerY;
	double radius;
public:
	setCenter(double centerX, double centerY);
	setRadius(double radius);
};
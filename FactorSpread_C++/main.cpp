#include "FactorSpread.h"

int main()
{
	// Object of the factor
	FactorSpread myField;

	// print the graph
	std::cout << "Before: " << std::endl;
	myField.print_field();

	// Try factor spread
	std::cout << "After: " << std::endl;
	myField.orlandoSpread(2, 2);
	myField.treeSpread(1, 2);
	myField.xSpread(2, 2);

	myField.print_field();



	return 0;
}
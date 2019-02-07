#include "FactorSpread.h"

int main()
{
	// Object of the factor
	FactorSpread myField(6, 5, 32867);

	// print the graph
	std::cout << "Before: " << std::endl;
	myField.print_field();

	// Try factor spread
	std::cout << "After: " << std::endl;
	myField.spread(2, 2);
	myField.print_field();



	return 0;
}
#include "FactorSpread.h"

int main()
{
	// Variables
	int c, r, s;
	int column = 0;
	int factor = 0;
	int input;
	char ynsel;

	std::cout << "Enter column size: ";
	std::cin >> c;
	std::cin.ignore();
	std::cout << "Enter Row size: ";
	std::cin >> r;
	std::cin.ignore();
	std::cout << "Enter seed (0 for random): ";
	std::cin >> s;
	std::cin.ignore();

	// Initialise object
	FactorSpread myField(r, c, s);
	myField.print_field();

	do
	{
		std::cout << "\n\n\n\nEnter row to factor: ";
		std::cin >> column;
		std::cin.ignore();

		std::cout << "Enter Factor to calculate: ";
		std::cin >> factor;
		std::cin.ignore();

		std::cout << "Enter factor to try:" << std::endl;
		std::cout << "0: Orlando Factor\n1: Tree Factor\n2: X Factor\n> ";
		std::cin >> input;
		std::cin.ignore();

		switch (input)
		{
			case 0:
				myField.orlandoSpread(column - 1, factor);
				break;

			case 1:
				myField.treeSpread(column - 1, factor);
				break;

			case 2:
				myField.xSpread(column - 1, factor);
				break;
		
			default:
				std::cout << "Invalid Input " << std::endl;
				break;
		}

		myField.print_field();

		std::cout << "\n\n Enter again? [y/n] ";
		std::cin >> ynsel;
		std::cin.ignore();

		

	}
	while(ynsel == 'y');


	return 0;

}
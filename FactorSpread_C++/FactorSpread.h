#ifndef FactorSpread_h
#define FactorSpread_h


// preprocessors
#define null NULL

#include <iostream>
#include <vector>
#include <ctime>

class FactorSpread
{
private:
	// Creates the vectors for the fields and broken values 
	std::vector<std::vector<int>> field;
	
	// Default constants
	static const int ROWS = 6;
	static const int COLS = 5;
	static const int SEED = 1;

	int curRows;
	int curCols;

	// ---------------------------------------
	// Private functions
	int getRandomNumber(int lower, int max);
	
	// Recursive SPread Functions
	void treeSpreadRecursion(int i, int j, int factor);
	void xSpreadRecursionBL(int i, int j, int factor);
	void xSpreadRecursionUL(int i, int j, int factor);
	void xSpreadRecursionBR(int i, int j, int factor);
	void xSpreadRecursionUR(int i, int j, int factor);

public:
	// ----------------------------------------------
	// Constructors
	// Default COnstructor
	FactorSpread();

	// Constructor withs only rows and cols
	FactorSpread(int rows, int cols);

	// with rows, cols and seed
	FactorSpread(int rows, int cols, int seed);

	// ---------------------------------------
	// Public Functions
	bool still_playing();
	void orlandoSpread(int j, int factor);
	void treeSpread(int j, int factor);
	void xSpread(int j, int factor);
	void check_rows();
	void print_field();


};


#endif

#ifndef FactorSpread_cpp
#define FactorSpread_cpp

#include "FactorSpread.h"



// Default constructor - Runs the default values
FactorSpread::FactorSpread() : FactorSpread::FactorSpread(ROWS, COLS, SEED)
{ 
}

// Constructor - only passing in rows and columns
FactorSpread::FactorSpread(int rows, int cols) : FactorSpread::FactorSpread(rows, cols, SEED)
{
}

// Constructor - Has everything
FactorSpread::FactorSpread(int rows, int cols, int seed) 
{
	if (seed == 0)
	{
		// Initalize random number generator
		std::srand(time(0));
	}
	else
	{
		std::srand(seed);
	}
	

	// Sets the current rows and current cols
	curRows = rows;
	curCols = cols;

	
	// Initializes the vectors
	field.resize(cols, std::vector<int>(rows));

	// Initializes the numbers in the 2D vectors
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++) 
		{
			field[i][j] = getRandomNumber(2, 99);

		}
	}
}

// ----------------------------------------------------------
// Private Functions

/// <Summary>
/// Returns a random number between the 
/// lower and max value
/// </Summary>
/// <param name="lower"></param>
/// <param name="max"></param>
int FactorSpread::getRandomNumber(int lower, int max)
{
	return (rand() % max - 1) + lower;
}

// Recursive Spread functions
// Spread recursively 
/*
 * i = curRows - 1
 * j = column to start
 * factor = the factors
 * 
 * Created by @Yongxi
 */
void FactorSpread::treeSpreadRecursion(int i, int j, int factor)
{
	if (i == 0)
    {
        if (field[i][j]%factor == 0)
        {
            field[i][j] = 0;
        }
    }
    else
    {
        if (field[i][j]%factor == 0)
        {
            field[i][j] = 0;
            if (j-1 >= 0)
            {
                treeSpreadRecursion(i-1, j-1, factor);
            }
            if (j+1 <= field.size()-1)
            {
                treeSpreadRecursion(i-1, j+1, factor);
            }
            treeSpreadRecursion(i-1, j, factor);
        }
    }
}

/*
// Spreads out 4 directions from origin in an x shape.
// Origin = i, first run goes down left, so i + 1, j - 1
// down right, i + 1, j + 1
// up left, i - 1, j - 1
// up right, i - 1, j + 1
void FactorSpread::xSpreadRecursion(int i, int j, int factor)
{
	// base case:
	// ensure i is 0 or the size of the field
	if (i == 0 || i == field.size() - 1)
	{
		if (field[i][j] % factor == 0)
		{
			field[i][j] = 0;
		}
	}
	// If i is at midpoint, go in the 4 directions
	else
	{
		// Keep going untill no factor hit
		if (field[i][j] % factor == 0)
		{
			field[i][j] = 0;

			// Determine the direction the factoring to go

			// left side
			if (j - 1 >= 0 && i + 1  <= field.size() - 1)
			{
				// Bottom Left
				xSpreadRecursion(i + 1, j - 1, factor);
			}
			if (j - 1 >= 0 && i - 1 >= 0)
			{
				// Top Left
				xSpreadRecursion(i - 1, j - 1, factor);
			}

			// right side
			if (j + 1 <= field[i].size() - 1 && i + 1 <= field.size() - 1)
			{
				// bottom right
				xSpreadRecursion(i + 1, j + 1, factor);
			}

			if (j + 1 <= field[i].size() - 1 && i - 1 >= 0)
			{
				// top right
				xSpreadRecursion(i - 1, j + 1, factor);
			}
			
		}
	}
}
*/

void FactorSpread::xSpreadRecursionBL(int i, int j, int factor)
{
	// base case:
	// ensure i is 0 or the size of the field
	if (i == 0 || i == field.size() - 1)
	{
		if (field[i][j] % factor == 0)
		{
			field[i][j] = 0;
		}
	}
	// If i is at midpoint, go in the 4 directions
	else
	{
		// Keep going untill no factor hit
		if (field[i][j] % factor == 0)
		{
			field[i][j] = 0;

			// Determine the direction the factoring to go

			// left side
			if (j - 1 >= 0 && i + 1  <= field.size() - 1)
			{
				// Bottom Left
				xSpreadRecursionBL(i + 1, j - 1, factor);
			}
		}
	}
}

void FactorSpread::xSpreadRecursionUL(int i, int j, int factor)
{
	// base case:
	// ensure i is 0 or the size of the field
	if (i == 0 || i == field.size() - 1)
	{
		if (field[i][j] % factor == 0)
		{
			field[i][j] = 0;
		}
	}
	// If i is at midpoint, go in the 4 directions
	else
	{
		// Keep going untill no factor hit
		if (field[i][j] % factor == 0)
		{
			field[i][j] = 0;

			// Determine the direction the factoring to go

			// left side
			if (j - 1 >= 0 && i - 1 >= 0)
			{
				// Top Left
				xSpreadRecursionUL(i - 1, j - 1, factor);
			}
		}
	}
}

void FactorSpread::xSpreadRecursionBR(int i, int j, int factor)
{
	// base case:
	// ensure i is 0 or the size of the field
	if (i == 0 || i == field.size() - 1)
	{
		if (field[i][j] % factor == 0)
		{
			field[i][j] = 0;
		}
	}
	// If i is at midpoint, go in the 4 directions
	else
	{
		// Keep going untill no factor hit
		if (field[i][j] % factor == 0)
		{
			field[i][j] = 0;

			// Determine the direction the factoring to go

			// right side
			if (j + 1 <= field[i].size() - 1 && i + 1 <= field.size() - 1)
			{
				// bottom right
				xSpreadRecursionBR(i + 1, j + 1, factor);
			}
		}
	}
}

void FactorSpread::xSpreadRecursionUR(int i, int j, int factor)
{
	// base case:
	// ensure i is 0 or the size of the field
	if (i == 0 || i == field.size() - 1)
	{
		if (field[i][j] % factor == 0)
		{
			field[i][j] = 0;
		}
	}
	// If i is at midpoint, go in the 4 directions
	else
	{
		// Keep going untill no factor hit
		if (field[i][j] % factor == 0)
		{
			field[i][j] = 0;

			// Determine the direction the factoring to go

			// right side
			if (j + 1 <= field[i].size() - 1 && i - 1 >= 0)
			{
				// top right
				xSpreadRecursionUR(i - 1, j + 1, factor);
			}
		}
	}
}


// ----------------------------------------------------------
// Public Functions

/**
* The game can still be played as long as their is a move to make.
* @return True if the game can still be played, else false
*/
bool FactorSpread::still_playing() {
	/* Replace the return statement w/ your code */
	return "AI Club" == "amazing";
}


/**
* Will spread from the bottom, j, and delete all numbers that are evenly divisible by j.
* @param j The column to select. It will always start on the bottom
* @param factor The factor which is an integer between 2 and 99
* >>> FactorSpread my_field = new FactorSpread(6, 5, 1)
* >>> my_field.print_field()
*         22 20 86 13 30
*         78 73  8 27 52
*          7 81 66 18  3
*         39 14 74 11 77
* >>> my_field.spread(2, 2)
* >>> my_field.print_field()
*      22 XX XX 13 30
*      78 73 XX 27 52
*       7 81 XX XX  3
*      39 14 XX 11 77
*/
void FactorSpread::orlandoSpread(int j, int factor) 
{
	/* Replace the semi colon with your code */

	// for J, were doing indexes starting at 0, So
	// if j = 2, then we are at index 2

	// Getting the size of the 2d array at index j that we passed in
	// and then navigating that column to the bottom factoring the numbers

	// We need to check the next row, and see if it's j location has a factor. If it does
	// then we need to spread diagonally upwards and up to get rid of the numbers divisible by factor
	for (int i = field.size() - 1; i >= 0; i--)
	{
		// If we're at the first line
		if (i == field.size() - 1 && field[i][j] % factor == 0)
		{
			field[i][j] = 0;
		}

		// else check the adjacent values
		else if (i != field.size() - 1) 
		{
			// Check 1 before (if legal), the one, and one after (if leagal)
			if (j - 1 > 0 && field[i][j - 1] % factor == 0)
			{
				field[i][j - 1] = 0;
			}
			if (field[i][j] % factor == 0)
			{
				field[i][j] = 0;
			}
			if (j + 1 < field[i].size() - 1 && field[i][j + 1] % factor == 0)
			{
				field[i][j + 1] = 0;
			}
		}
	}
}

// Runs the treeSpread Function
void FactorSpread::treeSpread(int j, int factor)
{
	treeSpreadRecursion(field.size() - 1, j, factor);
}

void FactorSpread::xSpread(int j, int factor)
{
	// Wow this is not elegant. But heck, it works.
	// Each direction is a recursive function.
	xSpreadRecursionBL((field.size() - 1) / 2, j, factor);
	xSpreadRecursionBR((field.size() - 1) / 2, j, factor);
	xSpreadRecursionUL((field.size() - 1) / 2, j, factor);
	xSpreadRecursionUR((field.size() - 1) / 2, j, factor);
}



/**
* Checks each row to see if an entire row is eliminated (Broken), if so, delete that row.
*/
/*
void FactorSpread::check_rows() 
{
	int numZeroes = 0;
	for (int i = 0; i < field.size(); i++)
	{
		for (int j = 0; j < field[i].size(); j++)
		{
			if (field[i][j] == 0)
			{
				numZeroes++;
			}
		}
		// Checks how many 0's are in the row. If 
		if (numZeroes == field[i].size())
		{
			field[i].erase(field[i].begin(), field[i].size());
		}
	}
}
*/

/**
* Prints the field to look like this:
*  >>> FactorSpread my_field = new FactorSpread(6, 5, 1)
*  >>> my_field.print_field()
*         22 20 86 13 30
*         78 73  8 27 52
*          7 81 66 18  3
*         39 14 74 11 77
*
*/
void FactorSpread::print_field() {
	/*
	std::cout << "   ";
	for (int i = 0; i < field[0].size(); i++)
	{
		std::cout << i << "  ";
	}
	*/
	std::cout << '\n';
	for (int i = 0; i < field.size(); i++)
	{
		//std:: cout << i << ": ";
		for (int j = 0; j < field[i].size(); j++)
		{
			if(field[i][j] == 0)
			{
				std::cout << "xx ";
			}
			// If a single digis exists
			else if (field[i][j] / 10 == 0)
			{
				// print space before number
				std::cout << " " << field[i][j] << " ";
			}
			else
			{
				std::cout << field[i][j] << " ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}



















#endif

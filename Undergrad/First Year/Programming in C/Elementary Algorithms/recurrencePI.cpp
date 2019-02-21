// Display an aproximation for PI after the recurrences formulas:
// pi[0][1] = 4/1; 
// pi[0][2] = 4/1 - 4/3;
// pi[0][3] = 4/1 - 4/3 + 4/5;
// pi[0][4] = 4/1 - 4/3 + 4/5 - 4/7;
// pi[i][j] = (pi[i - 1][j] + pi[i-1][j+1]) / 2, for i, j >= 1;
// After that calculate pi[10][10] = 3.141592653 with exactly 9 digits.

#include "stdafx.h"
#include <iostream>
#include <iomanip>

int main()
{
	std::cout << "Aproximation for PI using recurrences formulas: " << std::endl;
	double pi[21][21];
	pi[0][1] = 4.0 / 1.0;

	double patru = 4.0;           
	int i, j;
	for (i = 2; i <= 20; i++)
	{
		patru = -patru;
		pi[0][i] = pi[0][i - 1] + patru / (2.0*i - 1.0); // the general formula; 
                                                     //pi[0][2] = pi[0][1] - 4.0 / (2.0 * 2 - 1.0 ) 
  }
  
	std::cout << "0: " << std::endl;                  // the initial aproximations
	for (i = 1; i <= 20; i++)
	  std::cout << std::setprecision(10) << pi[0][i] << "\n";
	 std::cout << std::endl;
	 std::cout << " \n";

	for (i = 1; i <= 10; i++)
	{
		for (j = 1; j <= 20 - i; j++)
			pi[i][j] = 0.5*(pi[i - 1][j] + pi[i - 1][j + 1]);
		
    std::cout << i << " : " << std::endl;           // the i aproximations
		for (j = 1; j <= 20 - i; j++)
			std::cout << std::setprecision(10) << pi[i][j] << " \n";
		  std::cout << std::endl;
	}
  
	std::cout << "The best aproximation for PI is: " << std::setprecision(10) << pi[10][10] << ".\n";
	return 0;
}

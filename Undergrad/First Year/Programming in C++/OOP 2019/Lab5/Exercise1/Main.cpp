#include <stdio.h>
#include <iostream>
#include "Test.h"

#define AFISEAZA(var) std::cout << ##var << " ";

#define X_DIN_T t.Get_x()

#define Y_DIN_T t.Get_y()

#define ESTE_DIFERIT_DE !=

#define MAI_MARE_DECAT >

#define MINUS - 

#define DACA(var1, var2, var3) if(var1)\
{var2; } else {var3; }

#define SFARSIT_CAT_TIMP }

#define CAT_TIMP(var1) while(var1){

int main()
{

	Test t;

	t.Set_x(18);

	t.Set_y(24);

	AFISEAZA(t.Get_x() + t.Get_y());

	CAT_TIMP(X_DIN_T ESTE_DIFERIT_DE Y_DIN_T)

		DACA(X_DIN_T MAI_MARE_DECAT Y_DIN_T, t.Set_x(X_DIN_T MINUS Y_DIN_T), t.Set_y(Y_DIN_T MINUS X_DIN_T));

	SFARSIT_CAT_TIMP

	AFISEAZA(X_DIN_T);

	std::cin.get();
	return 0;

}
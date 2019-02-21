#include <iostream>
#include "StrVector.h"
using namespace std;

void main()
{
	StrVector v = { "Test" , "for" , "C++" };
	auto it = v.GetIterator();
	auto count = v.GetCount();
	for (auto index = 0; index < count; index++, it++)
		// va afisa cele 3 texte
		printf("%s\n", *it); 
	for (auto element : v)
		// va afisa deasemenea cele 3 texte
		printf("%s\n", element); 
}
#pragma once

class StrVector
{
private:
	char * sir;
	unsigned int AllocatedSize; // how much memory
	unsigned int Size;			// number of letters



public:
	StrVector();					// constructor1;
	StrVector(const char * text);	// constructor2;
	~StrVector();					// destructor;
	unsigned int GetIterator() const;
	unsigned int GetCount() const;
};
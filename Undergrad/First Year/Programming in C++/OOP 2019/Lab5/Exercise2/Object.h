#pragma once

class Object
{
public:
	int x;

public:
	Object(int x)
	{
		this->x = x;
	}

	Object()
	{
		this->x = 0;
	}

	Object(const Object & obj)
	{
		x = obj.x;
	}
};

bool operator==(Object lhs, Object rhs)
{
	return lhs.x == rhs.x;
}

bool operator<(Object lhs, Object rhs)
{
	return lhs.x < rhs.x;
}

bool operator>(Object lhs, Object rhs)
{
	return lhs.x > rhs.x;
}
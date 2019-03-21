#pragma once

#define ABC class
#define CREATE(var) void Set_##var(int value) { this->var = value; }\
int Get_##var() { return this->var; }

#define INIT(var) var(0)

ABC Test
{

 int x, y, z;

#define AAA public
AAA:

 Test() : INIT(x), INIT(y), INIT(z) {}

 CREATE(x)
 CREATE(y)
 CREATE(z)

};
#include "Identify.hpp"
class D:public Base
{};
int main()
{
	//Base *base = generate();
	Base *base = new D;
	identify(base);
	identify(*base);
	delete base;
	return (0);
}
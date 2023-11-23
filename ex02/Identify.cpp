#include "Identify.hpp"

Base *	generate(void)
{
	Base *ret;

	srand(time(NULL));
	switch (rand() % 3)
	{
		case 0:
			ret = new A;
			break;
		case 1:
			ret = new B;
			break;
		case 2:
			ret = new C;
			break;
	}
	return (ret);
}
x

void	identify(Base* p)
{
	std::cout << "Pointer: ";
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void	identify(Base& p)
{
	std::cout << "Reference: ";
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (std::bad_cast &bc)
	{
		try
		{
			B &b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "B" << std::endl;
		}
		catch (std::bad_cast &bc)
		{
			try
			{
				C &c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "C" << std::endl;
			}
			catch (std::bad_cast &bc)
			{
				std::cout << "Unknown" << std::endl;
			}
		}
	}
}
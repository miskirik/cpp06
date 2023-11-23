#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <cerrno>
#include <cstring>

class ScalarConverter
{
	public:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &instance);
		ScalarConverter &operator=(ScalarConverter const &rhs);
		~ScalarConverter(void);
		static void convert(std::string str);
		static bool checkInput(std::string str);
		static void toChar(std::string str);
		static void toInt(std::string str);
		static void toFloat(std::string str);
		static void toDouble(std::string str);
};

#endif

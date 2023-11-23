#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void){}

ScalarConverter::ScalarConverter(ScalarConverter const &instance)
{
	*this = instance;
}

ScalarConverter &	ScalarConverter::operator=(ScalarConverter const &rhs)
{
	(void)rhs;
	return *this;
}

ScalarConverter::~ScalarConverter(void){}

void ScalarConverter::convert(std::string str)
{
    bool check = false;
    check = ScalarConverter::checkInput(str);
    if(check == false)
    {
        std::cout << "Wrong input" << std::endl;
        return ;
    }
    toChar(str);
    toInt(str);
    toFloat(str);
    toDouble(str);
}

int count_u(std::string s, char c) {
  int count = 0;

  for (size_t i = 0; i < s.size(); i++)
    if (s[i] == c) count++;

  return count;
}

bool ScalarConverter::checkInput(std::string str)
{
    if(str.find('-') != std::string::npos || str.find('+') != std::string::npos)
        if(count_u(str, '-') > 1 || count_u(str, '+') > 1)
            return false;

    if(str.find('.') != std::string::npos)
        if(count_u(str, '.') > 1)
            return false;
    
    if(str.find('f') != std::string::npos && str.length() > 1)
        if(count_u(str, 'f') > 2)
            return false;

    if(str != "nan" && str != "nanf" && str != "inf" && str != "inff" && str != "+inf" && str != "+inff" && str != "-inf" && str != "-inff" && str.length() != 1)
        if(str.find_first_not_of("0123456789.+-f") != std::string::npos)
            return false;
        
    return true;
}

void ScalarConverter::toChar(std::string str)
{
    char c;
        
    std::cout << "char: ";
        
        if(str == "nan" || str == "nanf" || str == "inf" || str == "inff" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff")
        {
            std::cout << "impossible" << std::endl;
            return ;
        }
        if(isprint(str[0]) == true && isdigit(str[0]) == false)
        {
            c = str[0];
            if(c < 32 || c > 126)
                std::cout << "Non displayable" << std::endl;
            else
                std::cout << "'" << c << "'" << std::endl;
        }
        else
        {
            c = static_cast<char>(std::stoi(str));
            if(c < 32 || c > 126)
                std::cout << "Non displayable" << std::endl;
            else
                std::cout << "'" << c << "'" << std::endl;
        }
}

void ScalarConverter::toInt(std::string str)
{
    int i = 0;
     std::cout << "int: ";
        if(str == "nan" || str == "nanf" || str == "inf" || str == "inff" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff")
        {
            std::cout << "impossible" << std::endl;
            return ;
        }
        if(isprint(str[0]) == true && isdigit(str[0]) == false)
        {
            i = str[0];
            std::cout << i << std::endl;
        }
        else
        {
            i = static_cast<int>(std::stoi(str));
            std::cout << i << std::endl;
        }
}

void ScalarConverter::toFloat(std::string str)
{
    float f;
    std::cout << "float: ";
        if(str == "nan" || str == "inf" || str == "+inf" || str == "-inf" )
        {
            std::cout << str << "f" << std::endl;
            return ;
        }
        else if (str == "nanf" || str == "inff" || str == "+inff" || str == "-inff")
        {
            std::cout << str << std::endl;
            return ;
        }
        if(isprint(str[0]) == true && isdigit(str[0]) == false)
        {
            f = str[0];
            std::cout << std::fixed << std::setprecision(1)  << f << "f" << std::endl;
        }
        else
        {
            f = static_cast<float>(std::stof(str));
            std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
        }
}

void ScalarConverter::toDouble(std::string str)
{
    double d;
    std::cout << "double: ";
        if(str == "nan" || str == "inf" || str == "+inf" || str == "-inf" )
        {
            std::cout << str << std::endl;
            return ;
        }
        else if (str == "nanf" || str == "inff" || str == "+inff" || str == "-inff")
        {
            std::cout << str.substr(0, str.length() - 1) << std::endl;
            return ;
        }
        if(isprint(str[0]) == true && isdigit(str[0]) == false)
        {
            d = str[0];
            std::cout << std::fixed << std::setprecision(1)  << d << std::endl;
        }
        else
        {
            d = static_cast<double>(std::stod(str));
            std::cout << std::setprecision(1) << d << std::endl;
        }
    
}

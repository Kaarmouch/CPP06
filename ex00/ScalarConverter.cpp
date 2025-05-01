#include "SclarConvert.hpp"
#include <ctype>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&src) {(void)src;}
ScalarConverter::~ScalarConverter() {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter&src) {(void)src; return *this;}
static int isInt()

static int	getType(std::string& lit)
{
	if (lit.find('.') == string::npos)
	{
		if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff")
			return 4;
		if (lit.lenth == 1 && !isdigit(lit[0]))
			return 0;
		if (isInt(lit))
			return 1;
	}
	if (lif.find('.') != string::npos)
	{
		if (isFloat(lif))
			return 2;
		if (isDouble(lif))
			return 3;
	}
	return 2319;

}
static void charOut(std::string& lit) {std::cout << "Char input" <<std::endl;}
static void intOut(std::string& lit) {std::cout << "Int input" <<std::endl;}
static void floatOut(std::string& lit) {std::cout << "Float input" << std::endl;}
static void doubleOut(std::string& lit) {std::cout << "Double input" << std::endl;}
static void specialOut(std::string& lit) {std::cout << "Special input" << std::endl;}
static void errOut() {std::cout << "ERROR input" << std::endl;}

static void	ScalarConvert::convert(std::string& lit)
{
	int	type = getType(lit);
	if (type == 0)
		charOut(lit);
	else if (type == 1)
		intOut(lit);
	else if (type == 2)
		floatOut(lit);
	else if (type == 3)
		doubleOut(lit);
	else if (type == 4)
		specialOut(lit);
	else
		errOut();
}

#include "ScalarConverter.hpp"
#include "Out.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&src) {(void)src;}
ScalarConverter::~ScalarConverter() {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter&src) {(void)src; return *this;}

static int	isInt(std::string& lit)
{
	int	i = 0;

	if (lit[i] == '-' || lit[i] == '+')
		i++;
	while (lit[i] >= '0' && lit[i] <= '9' && i < 12)
		i++;
	if (lit[i])
		return 0;
	return 1;
}

static int      isFloat(std::string& lit)
{
        int     i = 0;
	int	flag = 0;

        if (lit[i] == '-' || lit[i] == '+')
                i++;
        while (lit[i] >= '0' && lit[i] <= '9')
	{
                i++;
		if (lit[i] == '.') { 
			i++; 
			flag++;
		}
		if (flag == 2) {
			return 0;
		}
	}
	if (lit[i] != 'f' || lit[i+1])
		return 0;
        return 1;
}

static int      isDouble(std::string& lit)
{
        int     i = 0;
        int     flag = 0;

        if (lit[i] == '-' || lit[i] == '+')
                i++;
        while (lit[i] >= '0' && lit[i] <= '9')
        {
                i++;
                if (lit[i] == '.') {
                        i++;
                        flag++;
                }
                if (flag == 2) {
                        return 0;
                }
        }
        if (lit[i])
                return 0;
        return 1;
}

static int	getType(std::string& lit)
{
	if (lit.find('.') == std::string::npos)
	{
		if (lit == "nan" || lit == "nanf" || lit == "+inf" || lit == "+inff" || lit == "-inf" || lit == "-inff")
			return 3;
		if (lit.length() == 1 && isalpha(lit[0]))
			return 0;
		if (isInt(lit))
			return 1;
	}
	if (lit.find('.') != std::string::npos && (isDouble(lit) || isFloat(lit)))
			return 2;
	return -1;

}

void	ScalarConverter::convert(std::string& lit)
{
	int	type = getType(lit);
	if (type == 0)
		charOut(lit);
	else if (type == 1)
		intOut(lit);
	else if (type == 2)
		floatOut(lit);
	else if (type == 3)
		specialOut(lit);
	else
		errOut();
}

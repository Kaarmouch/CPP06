#include "Out.hpp"
#include <iomanip>

void charOut(std::string& lit) 
{
	char	c = lit[0];

	if (isprint(c))
		std::cout << "char: " << c <<std::endl;
	else
		std::cout << "char : Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) <<std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void intOut(std::string& lit)
{
	long	l = std::atol(lit.c_str());
	std::cout<< l << std::endl;
	if (l >= 1 && l <= 126)
	{
		if (isprint(l))
			std::cout << "char: " << static_cast<char>(l) <<std::endl;
		else
			std::cout << "char : Non displayable" << std::endl;
	}
	else
		std:: cout << "char : impossible" << std::endl;
	if (l >= -2147483648 && l <= 2147483647)
                std::cout << "int: " << static_cast<int>(l) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << static_cast<float>(l) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(l) << ".0" << std::endl;
}

void floatOut(std::string& lit) 
{
	float   f = std::atof(lit.c_str());
	double	d = static_cast<double>(f);
        if (d >= 1 && d <= 126)
        {
                if (isprint(d))
                        std::cout << "char: " << static_cast<char>(d) <<std::endl;
                else
                        std::cout << "char : Non displayable" << std::endl;
        }
        else
                std:: cout << "char : impossible" << std::endl;
        if (d >= -2147483648 && d <= 2147483647)
                std::cout << "int: " << static_cast<int>(d) << std::endl;
        else
                std::cout << "int: impossible" << std::endl;
	std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: "<< d << std::endl;
}
void specialOut(std::string& lit) 
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (lit != "nanf" && lit != "-inff" && lit != "+inff")
		std::cout << "float: "+ lit + "f" << std::endl;
	else	
		std::cout << "float: "+ lit << std::endl;
	if (lit == "nanf" || lit == "-inff" || lit == "+inff")
		lit.erase(lit.length() - 1);
	std::cout << "double: "+ lit << std::endl;


}
void errOut() {std::cout << "ERROR input" << std::endl;}

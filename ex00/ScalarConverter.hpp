#pragma once

#include <string>
#include <iostream>
#include <algorithm>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter&);
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter&);
	public:
		static void convert(std::string& lit);
};

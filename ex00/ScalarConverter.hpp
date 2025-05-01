#pragma once

#include <string>
#include <iostream>

class ScalarConverter
{
	private:
		ScalarConverter(void);
	public:
		static void convert(std::string& lit);
}

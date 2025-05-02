#pragma once

#include <iostream>

#include <stdint.h>

struct Data 
{
	int id;
	std::string name;
};



class Serializer 
{
	private:
		Serializer(void);
		Serializer(const Serializer& );
		Serializer& operator=(const Serializer& );
		~Serializer(void);
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

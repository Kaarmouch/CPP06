#include "Serializer.hpp"

int main() 
{
	Data d;
	d.id = 000;
	d.name = "Jesus";

	uintptr_t raw = Serializer::serialize(&d);
	Data* ptr = Serializer::deserialize(raw);

	std::cout << "Original pointer : " << &d << std::endl;
	std::cout << "Deserialized ptr : " << ptr << std::endl;
	std::cout << "Same address?     " << (ptr == &d ? "yes" : "no") << std::endl;

	std::cout << "Data->id   = " << ptr->id << std::endl;
	std::cout << "Data->name = " << ptr->name << std::endl;

	return 0;
}

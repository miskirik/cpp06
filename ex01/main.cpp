#include "Data.hpp"

int main()
{
	Data *data = new Data;
	data->s1 = "Hello World!";

	std::cout << "data address: " << data << std::endl;
	uintptr_t raw = Serializer::serialize(data);
	std::cout << "raw address: " << raw << std::endl;
	std::cout << "raw hex: " << std::hex << raw << std::endl;
	Data *data2 = Serializer::deserialize(raw);
	std::cout << "data2 address: " << data2 << std::endl;
	std::cout << data2->s1 << std::endl;
	delete data;
	return 0;
}
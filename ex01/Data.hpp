#ifndef DATA_HPP
# define DATA_HPP

# include <iomanip>
# include <iostream>

typedef struct Data
{
	std::string s1;
} Data;

class Serializer
{
	public:
		Serializer();
		Serializer(Serializer const &instance);
		Serializer &operator=(Serializer const &rhs);
		~Serializer();
		
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};

#endif
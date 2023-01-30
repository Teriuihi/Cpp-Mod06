#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>
#include "Data.hpp"

class Serializer {
public:
	Serializer();
	~Serializer();
	uintptr_t serialize(Data* ptr);
	Data* deserialize(uintptr_t raw);
};


#endif

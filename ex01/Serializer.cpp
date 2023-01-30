#include "Serializer.hpp"

Serializer::Serializer() {
}

Serializer::~Serializer() {

}

uintptr_t Serializer::serialize(Data *ptr) {
	return (uintptr_t) (void*) ptr;
}

Data *Serializer::deserialize(uintptr_t raw) {
	return (Data *) (void *) raw;
}

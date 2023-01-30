#include <iostream>
#include "Serializer.hpp"

int main() {
	Data *data = new Data();
	std::cout << data->getRandomData() << std::endl;
	std::cout << data << std::endl;
	Data *d = Serializer().deserialize(Serializer().serialize(data));
	std::cout << d << std::endl;
	std::cout << "pointers are the same: " << (d == data ? "true" : "false") << std::endl;
	std::cout << d->getRandomData() << "\n" << data->getRandomData() << std::endl;
	std::cout << "data is the same: " << (d->getRandomData() == data->getRandomData()
				? "true" : "false") << std::endl;
}
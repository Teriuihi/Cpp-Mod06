#include <cstdlib>
#include "Data.hpp"

Data::Data(int randomData) : randomData(randomData) {
}

Data::Data() {
	randomData = std::rand();
}

Data::Data(Data const &data) {
	*this = data;
}

Data &Data::operator=(const Data &data) {
	this->randomData = data.randomData;
	return *this;
}

int Data::getRandomData() const {
	return randomData;
}

Data::~Data() {

}


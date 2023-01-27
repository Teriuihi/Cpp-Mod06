#include "Converter.hpp"
#include <iostream>
#include <numeric>
#include <cmath>

void Converter::convert(Type type, char *input) {
	this->nanInf = false;
	switch (type) {
		case Char:
			fromChar(*input);
			break;
		case Int:
			if (toDouble(input) != toInt(input)) {
				convert(Double, input);
				return;
			}
			fromInt(toInt(input));
			break;
		case Float:
			fromFloat(toFloat(input));
			break;
		case Double:
			fromDouble(toDouble(input));
			break;
	}
	print();
}

float Converter::toFloat(char *input) {
	return static_cast<float>(std::atof(input));
}

int Converter::toInt(char *input) {
	return std::atoi(input);
}

double Converter::toDouble(char *input) {
	return std::atof(input);
}

void Converter::fromFloat(float input) {
	this->c = static_cast<char>(input);
	this->i = static_cast<int>(input);
	this->f = input;
	this->d = static_cast<double>(input);
	this->nanInf = isinf(input);
}

void Converter::fromInt(int input) {
	this->c = static_cast<char>(input);
	this->i = input;
	this->f = static_cast<float>(input);
	this->d = static_cast<double>(input);
}

void Converter::fromDouble(double input) {
	this->c = static_cast<char>(input);
	this->i = static_cast<int>(input);
	this->f = static_cast<float>(input);
	this->d = input;
	this->nanInf = isinf(input);
}

void Converter::fromChar(char input) {
	this->c = input;
	this->i = static_cast<int>(input);
	this->f = static_cast<float>(input);
	this->d = static_cast<double>(input);
}

void Converter::print() {
	if (this->d > std::numeric_limits<int>::max() || this->d < std::numeric_limits<int>::min())
		this->nanInf = true;
	if (this->nanInf) {
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
	} else {
		if (this->i > std::numeric_limits<char>::max() ||
				this->i < std::numeric_limits<char>::min() ||
				!std::isprint(this->c))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: " << this->c << std::endl;
		std::cout << "int: " << this->i << std::endl;
	}
	std::cout << "float: " << this->f << "f" << std::endl;
	std::cout << "double: " << this->d << ((isNanInf(this->d) && this->d == this->i)
		? ".0" : "") << std::endl;
}

bool Converter::isNanInf(double input) {
	return (std::isnan(input) || std::isinf(input));
}

bool Converter::isNanInf(float input) {
	return (std::isnan(input) || std::isinf(input));
}
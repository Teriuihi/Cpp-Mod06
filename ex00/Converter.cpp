#include "Converter.hpp"

void Converter::convert(Type type, char *input) {
	switch (type) {
		case Char:
			fromChar(*input);
			break;
		case Int:
			fromInt(toInt(input));
			break;
		case Float:
			fromFloat(toFloat(input));
			break;
		case Double:
			fromDouble(toDouble(input));
			break;
	}
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
	std::cout << "char: " << static_cast<char>(input) << std::endl;
	std::cout << "int: " << static_cast<int>(input) << std::endl;
	std::cout << "float: " << input << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(input) << std::endl;
}

void Converter::fromInt(int input) {
	std::cout << "char: " << static_cast<char>(input) << std::endl;
	std::cout << "int: " << input << std::endl;
	std::cout << "float: " << static_cast<float >(input) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(input) << std::endl;
}

void Converter::fromDouble(double input) {
	std::cout << "char: " << static_cast<char>(input) << std::endl;
	std::cout << "int: " << static_cast<int>(input) << std::endl;
	std::cout << "float: " << static_cast<float >(input) << "f" << std::endl;
	std::cout << "double: " << input << std::endl;
}

void Converter::fromChar(char input) {
	std::cout << "char: " << input << std::endl;
	std::cout << "int: " << static_cast<int>(input) << std::endl;
	std::cout << "float: " << static_cast<float >(input) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(input) << std::endl;
}

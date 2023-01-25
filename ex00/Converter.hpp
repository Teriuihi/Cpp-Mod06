#ifndef CONVERTER_HPP
#define CONVERTER_HPP
#include "Type.hpp"
#include <iostream>

class Converter {
private:
	float toFloat(char input[]);
	int toInt(char input[]);
	double toDouble(char input[]);
	void fromFloat(float input);
	void fromInt(int input);
	void fromDouble(double input);
	void fromChar(char input);
public:
	void convert(Type type, char input[]);
};

#endif
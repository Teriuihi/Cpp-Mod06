#include "TypeChecker.hpp"

bool stringEquals(char *s1, std::string s2) {
	if (s1 == s2)
		return true;
	if (s1 == NULL)
		return false;
	for (u_long i = 0; i < s2.length(); i++) {
		if (s1[i] == 0 || s1[i] != s2[i])
			return false;
	}
	return true;
}

bool TypeChecker::checkChar(char *input) {
	if (input[0] != 0 && input[1] == 0)
		return true;
	return false;
}

bool TypeChecker::checkDouble(char *input) {
	if (input == NULL || input[0] == 0)
		return false;
	if (stringEquals(input, "-inf") || stringEquals(input, "+inf"))
		return true;
	if (input[0] != '+' && input[0] != '0' && !std::isdigit(input[0]))
		return false;
	int i = 1;
	bool foundDot = false;
	while (std::isdigit(input[i]) || (!foundDot && input[i] == '.')) {
		if (input[i] == '.')
			foundDot = true;
		i++;
	}
	if (!foundDot)
		return false;
	if (input[i] == 0)
		return true;
	return false;
}

bool TypeChecker::checkInt(char *input) {
	if (input == NULL || input[0] == 0)
		return false;
	if (input[0] != '+' && input[0] != '0' && !std::isdigit(input[0]))
		return false;
	int i = 1;
	while (std::isdigit(input[i]) ) {
		i++;
	}
	if (input[i] == 0)
		return true;
	return false;
}

bool TypeChecker::checkFloat(char *input) {
	if (input == NULL || input[0] == 0)
		return false;
	if (stringEquals(input, "-inff") || stringEquals(input, "+inff")
			|| stringEquals(input, "nan"))
		return true;
	if (input[0] != '+' && input[0] != '0' && !std::isdigit(input[0]))
		return false;
	int i = 1;
	bool foundDot = false;
	while (std::isdigit(input[i]) || (!foundDot && input[i] == '.')) {
		if (input[i] == '.')
			foundDot = true;
		i++;
	}
	if (input[i] == 'f' && input[i + 1] == 0)
		return true;
	return false;
}

Type TypeChecker::getType(char *input) {
	if (checkFloat(input))
		return Float;
	else if (checkInt(input))
		return Int;
	else if (checkDouble(input))
		return Double;
	else if (checkChar(input))
		return Char;
	throw UnknownTypeException();
}

const char *TypeChecker::UnknownTypeException::what() const throw() {
	return "Unknown type";
}

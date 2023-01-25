#ifndef TYPECHECKER_HPP
#define TYPECHECKER_HPP
#include <iostream>
#include "Type.hpp"

class TypeChecker {
private:
	bool checkFloat(char input[]);
	bool checkInt(char input[]);
	bool checkDouble(char input[]);
	bool checkChar(char input[]);
public:
	Type getType(char input[]);
	class UnknownTypeException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};


};


#endif

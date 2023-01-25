#ifndef TYPECHECKER_HPP
#define TYPECHECKER_HPP
#include <iostream>

class TypeChecker {
public:
	enum Type {Char, Int, Float, Double};
private:
	Type type;
	bool checkChar(char input[]);
	bool checkInt(char input[]);
	bool checkDouble(char input[]);
	bool checkFloat(char input[]);
public:
	Type getType(char input[]);
	class UnknownTypeException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};


};


#endif

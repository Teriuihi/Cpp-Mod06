#include <iostream>

void printChar(int i) {
	std::string a = "a";
	a[0] = i;
	std::cout << "char: ";
	if (std::isprint(i)) {
		std::cout << a;
	} else {
		std::cout << "Non displayable" ;
	}
	std::cout << std::endl;
}

int main(int len, char **args) {
	if (len != 2) {
		std::cout << "Please include a parameter with data to convert" << std::endl;
		return 0;
	}

	printChar(std::atoi(args[1]));
}
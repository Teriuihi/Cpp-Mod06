#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"


Base::~Base() {

}

Base *Base::generate() {
	Base *p;
	srand(time(NULL));
	switch (rand() % 3) {
		case 0:
			p = new A();
			break;
		case 1:
			p =  new B();
			break;
		case 2:
			p = new C();
			break;
		default:
			p = NULL;
			std::cout << "Unable to generate class" << std::endl;
	}
	return p;
}

void Base::identify(Base *p) {
	if (A* a = dynamic_cast<A*>(p)) {
		std::cout << "A" << std::endl;
	} else if (B* b = dynamic_cast<B*>(p)) {
		std::cout << "B" << std::endl;
	} else if (C* c = dynamic_cast<C*>(p)) {
		std::cout << "C" << std::endl;
	} else {
		std::cout << "Unable to find base class" << std::endl;
	}
}

void Base::identify(Base &p) {
	try {
		A &a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		(void)a;
	} catch (std::exception &e) {
		try {
			B &b = dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
			(void)b;
		} catch (std::exception &e) {
			try {
				C &c = dynamic_cast<C &>(p);
				std::cout << "C" << std::endl;
				(void)c;
			} catch (std::exception &e) {
				std::cout << "Unable to find base class" << std::endl;
			}
		}
	}
}
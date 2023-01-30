#include "Base.hpp"

int main() {
	Base* b = Base().generate();
	b->identify(b);
	b->identify(*b);
	return 0;
}
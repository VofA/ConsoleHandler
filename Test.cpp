#include "Color.hpp"
#include "Style.hpp"
#include <iostream>

Style css;

int main() {
	css.setFontColor(Color::BLACK, Color::WHITE);
	std::cout << "Hello World!";
	return 0;
}

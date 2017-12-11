#include "Color.hpp"
#include "Style.hpp"
#include "DoubleBuffering.hpp"
#include <iostream>

Style css;
DoubleBuffering db;

int main() {
	db.changePixel(5, 5, '^', Color::RED, Color::BLACK);
	db.draw();
	system("pause");
	return 0;
}

#include "Color.hpp"
#include "DoubleBuffering.hpp"
#include <iostream>

DoubleBuffering db;

int main() {
	db.init(10, 10);

	db.changePixel(5, 5, '$', Color::BLACK, Color::WHITE);

	db.draw();

	system("pause");
	return 0;
}

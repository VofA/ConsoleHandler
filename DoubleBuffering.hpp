#ifndef HPP_DOUBLEBUFFERING
#define HPP_DOUBLEBUFFERING

#include <vector>
#include <iostream>
#include "Color.hpp"
#include "Style.hpp"

class DoubleBuffering {
public:
	void draw();
	void init(int height, int width);
	void changePixel(int x, int y, char symbol = ' ', int foregroundColor = Color::WHITE, int backgroundColor = Color::BLACK);
protected:
private:
	void setCursorPosition(int x = 0, int y = 0);

	struct Pixel {
		int foregroundColor = Color::WHITE;
		int backgroundColor = Color::BLACK;
		char symbol = ' ';
	};

	Style style;

	std::vector<std::vector<Pixel>> onScreenBuffer;
	std::vector<std::vector<Pixel>> newScreenBuffer;
};

#endif

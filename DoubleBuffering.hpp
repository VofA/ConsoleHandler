#ifndef HPP_DOUBLE_BUFFERING
#define HPP_DOUBLE_BUFFERING

#include <vector>
#include <iostream>
#include "Color.hpp"
#include "Style.hpp"

struct Pixel {
	Theme theme;
	char symbol = ' ';
};

class DoubleBuffering {
public:
	void draw();
	void init(int height, int width);
	void clear(Theme theme = themeEmpty);
	void changePixel(unsigned int x, unsigned int y, char symbol = ' ', Theme theme = themeEmpty);
protected:
private:
	void setCursorPosition(int x = 0, int y = 0);

	const static Theme themeEmpty;
	std::vector<std::vector<Pixel>> onScreenBuffer;
	std::vector<std::vector<Pixel>> newScreenBuffer;
};

#endif
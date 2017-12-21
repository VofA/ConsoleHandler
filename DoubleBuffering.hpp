#ifndef HPP_DOUBLE_BUFFERING
#define HPP_DOUBLE_BUFFERING

#include <vector>
#include <iostream>
#include "Color.hpp"
#include "Style.hpp"

struct Pixel {
	Style::Theme theme;
	char symbol = ' ';
};

class DoubleBuffering {
public:
	void draw();
	void init(int height, int width);
	void clear(Style::Theme theme = themeEmpty);
	void changePixel(unsigned int x, unsigned int y, char symbol = ' ', Style::Theme theme = themeEmpty);
protected:
private:
	void setCursorPosition(int x = 0, int y = 0);

	const static Style::Theme themeEmpty;
	std::vector<std::vector<Pixel>> onScreenBuffer;
	std::vector<std::vector<Pixel>> newScreenBuffer;
};

#endif
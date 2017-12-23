#ifndef HPP_DOUBLE_BUFFERING
#define HPP_DOUBLE_BUFFERING

#include <io.h>
#include <vector>
#include <iostream>
#include "Color.hpp"
#include "Style.hpp"

class DoubleBuffering {
public:
	void init(unsigned int height, unsigned int width);
	void clear(Style::Theme theme = Style::create());
	void changePixel(unsigned int x, unsigned int y, wchar_t symbol = ' ', Style::Theme theme = Style::create());

protected:
	void draw();
	void hideCursor(bool status = true);

private:
	struct Pixel {
		Style::Theme theme;
		wchar_t symbol = ' ';
	};

	void setCursorPosition(unsigned int x = 0, unsigned int y = 0);

	std::vector<std::vector<Pixel>> onScreenBuffer;
	std::vector<std::vector<Pixel>> newScreenBuffer;

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
};

#endif
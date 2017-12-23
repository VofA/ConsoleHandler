#ifndef HPP_GRAPHICS
#define HPP_GRAPHICS

#include "DoubleBuffering.hpp"



class Graphics : public DoubleBuffering {
public:
	struct Point {
		unsigned int x = 0;
		unsigned int y = 0;
	};

	struct Area {
		Point first;
		Point second;
	};

	void fill(Area area, wchar_t symbol = ' ', Style::Theme theme = Style::create());
	void writeText(unsigned int x, unsigned int y, std::wstring text, unsigned int length, Style::Theme theme = Style::create());
};

#endif
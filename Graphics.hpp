#ifndef HPP_GRAPHICS
#define HPP_GRAPHICS

#include "DoubleBuffering.hpp"

struct Point {
	int x = 0;
	int y = 0;
};

struct Area {
	Point first;
	Point second;
};

class Graphics : public DoubleBuffering {
public:
	void fill(Area area, char symbol = ' ', Theme theme = themeEmpty);
	void writeText(int x, int y, std::string text, int length, Theme theme = themeEmpty);
protected:
private:
	const static Theme themeEmpty;
};

#endif
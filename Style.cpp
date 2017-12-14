#include "Style.hpp"

struct Theme Style::create(unsigned short foreground, unsigned short background) {
	struct Theme theme;

	theme.foreground = foreground;
	theme.background = background;

	return theme;
}

void Style::select(struct Theme theme) {
	unsigned short color = theme.background * 0x10 + theme.foreground;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
#include "Style.hpp"

Style::Theme Style::create(unsigned short foreground, unsigned short background) {
	Style::Theme theme;

	theme.foreground = foreground;
	theme.background = background;

	return theme;
}

void Style::select(Style::Theme theme) {
	unsigned short color = theme.background * 0x10 + theme.foreground;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
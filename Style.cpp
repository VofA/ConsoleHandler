#include "Style.hpp"

void Style::setForegroundColor(int foregroundColor) {
	setFontColor(foregroundColor, currentBackgroundColor);
}

void Style::setBackgroundColor(int backgroundColor) {
	setFontColor(currentForegroundColor, backgroundColor);
}

void Style::setFontColor(int foregroundColor, int backgroundColor) {
	int fontColor = backgroundColor * 0x10 + foregroundColor;

	SetConsoleTextAttribute(Console, fontColor);
}

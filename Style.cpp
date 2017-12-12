#include "Style.hpp"

void Style::getForegroundColor(int foregroundColor) {
	getColor(foregroundColor, currentBackgroundColor);
}

void Style::getBackgroundColor(int backgroundColor) {
	getColor(currentForegroundColor, backgroundColor);
}

void Style::getColor(int foregroundColor, int backgroundColor) {
	currentForegroundColor = foregroundColor;
	currentBackgroundColor = backgroundColor;
	
	int color = backgroundColor * 0x10 + foregroundColor;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void Style::getDefaultColor() {
	getColor(defaultForegroundColor, defaultBackgroundColor);
}

void Style::setDefaultColor(int foregroundColor, int backgroundColor) {
	defaultForegroundColor = foregroundColor;
	defaultBackgroundColor = backgroundColor;
}

void Style::setDefaultForegroundColor(int foregroundColor) {
	defaultForegroundColor = foregroundColor;
}

void Style::setDefaultBackgroundColor(int backgroundColor) {
	defaultBackgroundColor = backgroundColor;
}

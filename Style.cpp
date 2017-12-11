#include "Style.hpp"

void getForegroundColor(int foregroundColor) {
	getColor(foregroundColor, currentBackgroundColor);
}

void getBackgroundColor(int backgroundColor) {
	getColor(currentForegroundColor, backgroundColor);
}

void getColor(int foregroundColor, int backgroundColor) {
	currentForegroundColor = foregroundColor
	currentBackgroundColor = backgroundColor;
	
	int color = backgroundColor * 0x10 + foregroundColor;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void getDefaultColor() {
	getColor(defaultForegroundColor, defaultBackgroundColor);
}

void setDefaultColor(int foregroundColor, int backgroundColor) {
	defaultForegroundColor = foregroundColor;
	defaultBackgroundColor = backgroundColor;
}

void setDefaultForegroundColor(int foregroundColor) {
	defaultForegroundColor = foregroundColor;
}

void setDefaultBackgroundColor(int backgroundColor) {
	defaultBackgroundColor = backgroundColor;
}

#include "DoubleBuffering.hpp"

void DoubleBuffering::draw() {
	for (int y = 0; y < onScreenBuffer.size(); ++y) {
		for (int x = 0; x < onScreenBuffer[y].size(); ++x) {
			bool edited = false;

			if (onScreenBuffer[y][x].foregroundColor != newScreenBuffer[y][x].foregroundColor) {
				style.getForegroundColor(newScreenBuffer[y][x].foregroundColor);
				edited = true;
			}

			if (onScreenBuffer[y][x].backgroundColor != newScreenBuffer[y][x].backgroundColor) {
				style.getBackgroundColor(newScreenBuffer[y][x].backgroundColor);
				edited = true;
			}
			if (onScreenBuffer[y][x].symbol != newScreenBuffer[y][x].symbol || edited) {
				setCursorPosition(x, y);
				std::cout << newScreenBuffer[y][x].symbol;
			}

			onScreenBuffer[y][x] = newScreenBuffer[y][x];
		}
	}
	setCursorPosition();
}

void DoubleBuffering::init(int height, int width) {
	Pixel emptyPixel;

	onScreenBuffer.resize(height);
	newScreenBuffer.resize(height);

	for (int y = 0; y < height; y++) {
		onScreenBuffer[y].resize(width);
		newScreenBuffer[y].resize(width);

		for (int x = 0; x < width; x++) {
			onScreenBuffer[y][x] = emptyPixel;
			newScreenBuffer[y][x] = emptyPixel;
		}
	}
}

void DoubleBuffering::changePixel(int x, int y, char symbol, int foregroundColor, int backgroundColor) {
	newScreenBuffer[y][x].symbol = symbol;
	newScreenBuffer[y][x].foregroundColor = foregroundColor;
	newScreenBuffer[y][x].backgroundColor = backgroundColor;
}

void DoubleBuffering::setCursorPosition(int x, int y) {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {short(x), short(y)});
}

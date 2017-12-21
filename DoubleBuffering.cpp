#include "DoubleBuffering.hpp"

void DoubleBuffering::draw() {
	for (unsigned int y = 0; y < onScreenBuffer.size(); ++y) {
		for (unsigned int x = 0; x < onScreenBuffer[y].size(); ++x) {
			if (onScreenBuffer[y][x].theme.foreground != newScreenBuffer[y][x].theme.foreground ||
				onScreenBuffer[y][x].theme.background != newScreenBuffer[y][x].theme.background ||
				onScreenBuffer[y][x].symbol != newScreenBuffer[y][x].symbol) {

				setCursorPosition(x, y);
				Style::select(newScreenBuffer[y][x].theme);
				std::cout << newScreenBuffer[y][x].symbol;
			}

			onScreenBuffer[y][x] = newScreenBuffer[y][x];
		}
	}
	setCursorPosition();
}

void DoubleBuffering::init(int height, int width) {
	Pixel pixelEmpty;

	onScreenBuffer.resize(height);
	newScreenBuffer.resize(height);

	for (int y = 0; y < height; y++) {
		onScreenBuffer[y].resize(width);
		newScreenBuffer[y].resize(width);

		for (int x = 0; x < width; x++) {
			onScreenBuffer[y][x] = pixelEmpty;
			newScreenBuffer[y][x] = pixelEmpty;
		}
	}
}

void DoubleBuffering::clear(Style::Theme theme) {
	Pixel pixel;
	pixel.theme = theme;

	for (unsigned int y = 0; y < newScreenBuffer.size(); y++) {
		for (unsigned int x = 0; x < newScreenBuffer[y].size(); x++) {
			newScreenBuffer[y][x] = pixel;
		}
	}
}

void DoubleBuffering::changePixel(unsigned int x, unsigned int y, char symbol, Style::Theme theme) {
	if (y >= 0 && y < newScreenBuffer.size() && x >= 0 && x < newScreenBuffer[y].size()) {
		newScreenBuffer[y][x].symbol = symbol;
		newScreenBuffer[y][x].theme = theme;
	}
}

void DoubleBuffering::setCursorPosition(int x, int y) {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD { short(x), short(y) });
}
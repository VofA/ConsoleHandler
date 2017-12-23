#include "DoubleBuffering.hpp"

void DoubleBuffering::init(unsigned int height, unsigned int width) {
	Pixel pixelEmpty;

	onScreenBuffer.resize(height);
	newScreenBuffer.resize(height);

	for (unsigned int y = 0; y < height; ++y) {
		onScreenBuffer[y].resize(width);
		newScreenBuffer[y].resize(width);

		for (unsigned int x = 0; x < width; ++x) {
			onScreenBuffer[y][x] = pixelEmpty;
			newScreenBuffer[y][x] = pixelEmpty;
		}
	}

	hideCursor();
}

void DoubleBuffering::clear(Style::Theme theme) {
	Pixel pixel;

	pixel.theme = theme;

	for (unsigned int y = 0; y < newScreenBuffer.size(); ++y) {
		for (unsigned int x = 0; x < newScreenBuffer[y].size(); ++x) {
			newScreenBuffer[y][x] = pixel;
		}
	}
}

void DoubleBuffering::changePixel(unsigned int x, unsigned int y, wchar_t symbol, Style::Theme theme) {
	if (y < 0 || y >= newScreenBuffer.size()) {
		return;
	}

	if (x < 0 || x >= newScreenBuffer[y].size()) {
		return;
	}

	newScreenBuffer[y][x].symbol = symbol;
	newScreenBuffer[y][x].theme = theme;
}

void DoubleBuffering::draw() {
	for (unsigned int y = 0; y < newScreenBuffer.size(); ++y) {
		for (unsigned int x = 0; x < newScreenBuffer[y].size(); ++x) {
			if (onScreenBuffer[y][x].theme.foreground != newScreenBuffer[y][x].theme.foreground ||
				onScreenBuffer[y][x].theme.background != newScreenBuffer[y][x].theme.background ||
				onScreenBuffer[y][x].symbol != newScreenBuffer[y][x].symbol) {

				setCursorPosition(x, y);
				Style::select(newScreenBuffer[y][x].theme);
				std::wcout << newScreenBuffer[y][x].symbol;

				onScreenBuffer[y][x] = newScreenBuffer[y][x];
			}
		}
	}
}

void DoubleBuffering::hideCursor(bool status) {
	CONSOLE_CURSOR_INFO consoleInfo;

	GetConsoleCursorInfo(handle, &consoleInfo);
	consoleInfo.bVisible = !status;

	SetConsoleCursorInfo(handle, &consoleInfo);
}

void DoubleBuffering::setCursorPosition(unsigned int x, unsigned int y) {
	SetConsoleCursorPosition(handle, COORD { short(x), short(y) });
}
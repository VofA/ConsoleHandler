#include "Graphics.hpp"

void Graphics::fill(Area area, char symbol, Theme theme) {
	for (int y = area.first.y; y < area.second.y; y++) {
		for (int x = area.first.x; x < area.second.x; x++) {
			changePixel(x, y, symbol, theme);
		}
	}
}

void Graphics::writeText(int x, int y, std::string text, int length, Theme theme) {
	for (int ix = 0; ix < text.size(); ix++) {
		changePixel(ix + x, y, text[ix], theme);
	}

	for (int ix = text.size(); ix < length; ix++) {
		changePixel(ix + x, y, ' ', theme);
	}
}
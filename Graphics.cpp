#include "Graphics.hpp"

void Graphics::fill(Area area, char symbol, Style::Theme theme) {
	for (int y = area.first.y; y < area.second.y; y++) {
		for (int x = area.first.x; x < area.second.x; x++) {
			changePixel(x, y, symbol, theme);
		}
	}
}

void Graphics::writeText(int x, int y, std::string text, unsigned int length, Style::Theme theme) {
	for (unsigned int ix = 0; ix < text.size(); ix++) {
		changePixel(ix + x, y, text[ix], theme);
	}

	for (unsigned int ix = (unsigned int)text.size(); ix < length; ix++) {
		changePixel(ix + x, y, ' ', theme);
	}
}
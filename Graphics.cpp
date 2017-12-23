#include "Graphics.hpp"

void Graphics::fill(Graphics::Area area, wchar_t symbol, Style::Theme theme) {
	for (unsigned int y = area.first.y; y < area.second.y; ++y) {
		for (unsigned int x = area.first.x; x < area.second.x; ++x) {
			changePixel(x, y, symbol, theme);
		}
	}
}

void Graphics::writeText(unsigned int x, unsigned int y, std::wstring text, unsigned int length, Style::Theme theme) {
	for (unsigned int relativeX = 0; relativeX < length; ++relativeX) {
		changePixel(x + relativeX, y, ' ', theme);
	}

	for (unsigned int relativeX = 0; relativeX < text.size(); ++relativeX) {
		changePixel(x + relativeX, y, text[relativeX], theme);
	}
}
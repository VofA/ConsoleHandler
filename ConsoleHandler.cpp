#include "ConsoleHandler.hpp"

void ConsoleHandler::init(int height, int width) {
	_COORD consoleSizes = { short(width), short(height) };
	_SMALL_RECT window = { 0, 0, short(consoleSizes.X - 1), short(consoleSizes.Y - 1) };

	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), consoleSizes);
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, &window);
	
	graphics.init(height, width);
}

void ConsoleHandler::setTitle(std::string title) {
	SetConsoleTitle((LPCSTR)title.c_str());
}
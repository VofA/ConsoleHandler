#include "ConsoleHandler.hpp"

#include <iostream>
#include <windows.h>

void ConsoleHandler::init(int height, int width) {
	_COORD consoleSizes = { short(width), short(height) };
	_SMALL_RECT window = { 0, 0, short(consoleSizes.X - 1), short(consoleSizes.Y - 1) };

	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), consoleSizes);
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, &window);
	
	graphics.init(height, width);
}

void ConsoleHandler::setTitle(const std::string &title) {
	SetConsoleTitleA((LPCSTR)title.c_str());
}

void ConsoleHandler::registerHandlerCallback(void(*function)(int)) {
	handlerCallback = function;
}

void ConsoleHandler::registerKeyCallback(int keyCode) {
	keys.push_back(keyCode);
}

void ConsoleHandler::mainLoop() {
	while (true) {
		for (size_t i = 0; i < keys.size(); i++) {
			if (GetKeyState(keys[i]) & 0x8000) {
				handlerCallback(keys[i]);
			}
		}

		graphics.draw();

		Sleep(1);
	}
}
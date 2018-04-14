#include "ConsoleHandler.hpp"
#include <thread>

ConsoleHandler ch;

void handler(int key) {
	switch (key) {
	case ConsoleHandler::KEY_CODE_W:
		ch.setTitle(L"CALLBACK SUCCESS - W");
		break;
	case ConsoleHandler::KEY_CODE_A:
		ch.setTitle(L"CALLBACK SUCCESS - A");
		break;
	case ConsoleHandler::KEY_CODE_S:
		ch.setTitle(L"CALLBACK SUCCESS - S");
		break;
	case ConsoleHandler::KEY_CODE_D:
		ch.setTitle(L"CALLBACK SUCCESS - D");
		break;
	default:
		ch.setTitle(L"CALLBACK SUCCESS");
		break;
	}
}

int main() {
	ch.init(30, 60);

	ch.setTitle(L"SUPER TERMINAL");

	ch.registerHandlerCallback(handler);
	ch.registerKeyCallback(ConsoleHandler::KEY_CODE_W);
	ch.registerKeyCallback(ConsoleHandler::KEY_CODE_A);
	ch.registerKeyCallback(ConsoleHandler::KEY_CODE_S);
	ch.registerKeyCallback(ConsoleHandler::KEY_CODE_D);

	ch.clear(Style::create(Color::WHITE, Color::WHITE));
	ch.changePixel(5, 5, '$', Style::create(Color::BLACK, Color::WHITE));

	ch.writeText(20, 2, L"Hello World!", 30, Style::create(Color::LIGHTBLUE, Color::BLACK));

	Graphics::Area area;
	area.first.x = 6;
	area.first.y = 6;
	area.second.x = 10;
	area.second.y = 10;

	ch.fill(area, '#', Style::create(Color::LIGHTRED, Color::LIGHTRED));

	ch.writeText(0, 20, L"│┌┐└┘├┤┬┴┼═║╒╓╔╕╖╗╘╙╚╛╜╝╞╟╠╡╢╣╤╥╦╧╨╩╪╫╬", 30, Style::create(Color::LIGHTBLUE, Color::BLACK));
	ch.writeText(0, 21, L"English", 30, Style::create(Color::LIGHTBLUE, Color::BLACK));
	ch.writeText(0, 22, L"Русский", 30, Style::create(Color::LIGHTBLUE, Color::BLACK));
	ch.writeText(0, 23, L"Ελληνικά", 30, Style::create(Color::LIGHTBLUE, Color::BLACK));
	ch.writeText(0, 24, L"Español", 30, Style::create(Color::LIGHTBLUE, Color::BLACK));

	ch.mainLoop();

	return 0;
}

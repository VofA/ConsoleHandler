#include "ConsoleHandler.hpp"

ConsoleHandler ch;

void handler(int key) {
	switch (key)
	{
	case ConsoleHandler::KEY_CODE_W:
		ch.setTitle("CALLBACK SUCCESS - W");
		break;
	case ConsoleHandler::KEY_CODE_A:
		ch.setTitle("CALLBACK SUCCESS - A");
		break;
	case ConsoleHandler::KEY_CODE_S:
		ch.setTitle("CALLBACK SUCCESS - S");
		break;
	case ConsoleHandler::KEY_CODE_D:
		ch.setTitle("CALLBACK SUCCESS - D");
		break;
	default:
		ch.setTitle("CALLBACK SUCCESS");
		break;
	}
}

void mainLoop() {
	ch.mainLoop();
}

int main() {
	ch.init(30, 60);

	ch.setTitle("SUPER TERMINAL");

	ch.registerHandlerCallback(handler);
	ch.registerKeyCallback(ConsoleHandler::KEY_CODE_W);
	ch.registerKeyCallback(ConsoleHandler::KEY_CODE_A);
	ch.registerKeyCallback(ConsoleHandler::KEY_CODE_S);
	ch.registerKeyCallback(ConsoleHandler::KEY_CODE_D);

	ch.graphics.clear(Style::create(Color::WHITE, Color::WHITE));
	ch.graphics.changePixel(5, 5, '$', Style::create(Color::BLACK, Color::WHITE));

	ch.graphics.writeText(20, 2, "Hello World!", 30, Style::create(Color::LIGHTBLUE, Color::BLACK));

	Area area;
	area.first.x = 6;
	area.first.y = 6;
	area.second.x = 10;
	area.second.y = 10;

	ch.graphics.fill(area, '#', Style::create(Color::LIGHTRED, Color::LIGHTRED));

	std::thread threadMainLoop(mainLoop);
	threadMainLoop.join();

	system("pause");
	return 0;
}
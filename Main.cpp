#include "ConsoleHandler.hpp"

int main() {
	ConsoleHandler ch;

	ch.init(30, 60);
	ch.setTitle("SUPER TERMINAL");

	ch.graphics.clear(Style::create(Color::WHITE, Color::WHITE));
	ch.graphics.changePixel(5, 5, '$', Style::create(Color::BLACK, Color::WHITE));

	ch.graphics.writeText(20, 2, "Hello World!", 30, Style::create(Color::LIGHTBLUE, Color::BLACK));

	Area area;
	area.first.x = 6;
	area.first.y = 6;
	area.second.x = 10;
	area.second.y = 10;

	ch.graphics.fill(area, '#', Style::create(Color::LIGHTRED, Color::LIGHTRED));
	
	ch.graphics.draw();

	system("pause");
	return 0;
}

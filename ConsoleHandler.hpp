#ifndef HPP_CONSOLE_HANDLER
#define HPP_CONSOLE_HANDLER

#include "Graphics.hpp"
#include <string>

class ConsoleHandler {
public:
	void init(int height, int width);
	void setTitle(std::string title);

	Graphics graphics;
protected:
private:
	int height;
	int width;
};

#endif
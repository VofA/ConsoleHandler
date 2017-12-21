#ifndef HPP_STYLE
#define HPP_STYLE

#include <windows.h>
#include "Color.hpp"



class Style {
public:
	struct Theme {
		int foreground = Color::BLACK;
		int background = Color::BLACK;
	};

	Theme static create(unsigned short foreground, unsigned short background);
	void static select(Theme theme);

private:
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
};

#endif
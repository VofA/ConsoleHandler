#ifndef HPP_STYLE
#define HPP_STYLE

#include <windows.h>
#include "Color.hpp"

class Style {
public:
	struct Theme {
		unsigned short foreground = Color::BLACK;
		unsigned short background = Color::BLACK;
	};

	static Theme create(unsigned short foreground = Color::BLACK, unsigned short background = Color::BLACK);
	static void select(Theme theme);
};

#endif
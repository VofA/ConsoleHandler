#ifndef HPP_STYLE
#define HPP_STYLE

#include <windows.h>
#include "Color.hpp"

struct Theme {
	int foreground = Color::BLACK;
	int background = Color::BLACK;
};

class Style {
public:
	struct Theme static create(unsigned short foreground, unsigned short background);
	void static select(struct Theme theme);
protected:
private:
};

#endif
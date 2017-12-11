#ifndef HPP_STYLE
#define HPP_STYLE

#include "Color.hpp"

class Style {
public:
	void setForegroundColor(int foregroundColor);
	void setBackgroundColor(int backgroundColor);
	void setFontColor(int foregroundColor, int backgroundColor);
protected:
private:
	int currentBackgroundColor = Color::BLACK;
	int currentForegroundColor = Color::WHITE;
};

#endif

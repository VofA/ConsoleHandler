#ifndef HPP_STYLE
#define HPP_STYLE

#include <windows.h>
#include "Color.hpp"

class Style {
public:
	void getForegroundColor(int foregroundColor);
	void getBackgroundColor(int backgroundColor);
	void getColor(int foregroundColor, int backgroundColor);
	void getDefaultColor();

	void setDefaultColor(int foregroundColor, int backgroundColor);
	void setDefaultForegroundColor(int foregroundColor);
	void setDefaultBackgroundColor(int backgroundColor);

protected:
private:
	int currentBackgroundColor = Color::BLACK;
	int currentForegroundColor = Color::WHITE;

	int defaultBackgroundColor = Color::BLACK;
	int defaultForegroundColor = Color::WHITE;
};

#endif

#ifndef HPP_CONSOLE_HANDLER
#define HPP_CONSOLE_HANDLER

#include <io.h>
#include <string>
#include <vector>
#include <fcntl.h>
#include <iostream>
#include <windows.h>
#include "Graphics.hpp"

class ConsoleHandler : public Graphics {
public:
	void init(unsigned int height, unsigned int width);

	void initWindow();

	void setTitle(const std::wstring &title);

	void registerHandlerCallback(void(*function)(int));
	void registerKeyCallback(int keyCode);

	void mainLoop();
	
	const static int KEY_CODE_0 = 0x30;
	const static int KEY_CODE_1 = 0x31;
	const static int KEY_CODE_2 = 0x32;
	const static int KEY_CODE_3 = 0x33;
	const static int KEY_CODE_4 = 0x34;
	const static int KEY_CODE_5 = 0x35;
	const static int KEY_CODE_6 = 0x36;
	const static int KEY_CODE_7 = 0x37;
	const static int KEY_CODE_8 = 0x38;
	const static int KEY_CODE_9 = 0x39;
	const static int KEY_CODE_A = 0x41;
	const static int KEY_CODE_B = 0x42;
	const static int KEY_CODE_C = 0x43;
	const static int KEY_CODE_D = 0x44;
	const static int KEY_CODE_E = 0x45;
	const static int KEY_CODE_F = 0x46;
	const static int KEY_CODE_G = 0x47;
	const static int KEY_CODE_H = 0x48;
	const static int KEY_CODE_I = 0x49;
	const static int KEY_CODE_J = 0x4A;
	const static int KEY_CODE_K = 0x4B;
	const static int KEY_CODE_L = 0x4C;
	const static int KEY_CODE_M = 0x4D;
	const static int KEY_CODE_N = 0x4E;
	const static int KEY_CODE_O = 0x4F;
	const static int KEY_CODE_P = 0x50;
	const static int KEY_CODE_Q = 0x51;
	const static int KEY_CODE_R = 0x52;
	const static int KEY_CODE_S = 0x53;
	const static int KEY_CODE_T = 0x54;
	const static int KEY_CODE_U = 0x55;
	const static int KEY_CODE_V = 0x56;
	const static int KEY_CODE_W = 0x57;
	const static int KEY_CODE_X = 0x58;
	const static int KEY_CODE_Y = 0x59;
	const static int KEY_CODE_Z = 0x5A;
	const static int KEY_CODE_SPACE = 0x20;

private:
	std::vector<int> keys;

	void(*handlerCallback)(int);
	
	unsigned int _height;
	unsigned int _width;
};

#endif

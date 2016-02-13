#include <iostream>
#include "Screen.h"
#include <Math.h>
#include <SDL.h>

using namespace std;
using namespace mac;

int main() {

	Screen screen;

	if (!screen.init()) {
		cout << "Error initializing SDL" << flush;
	}

	while (true) {

		int elapsed = SDL_GetTicks();
		unsigned char green = (unsigned char) (1 + sin(elapsed * 0.0001) * 128);
		unsigned char red = (unsigned char) (1 + sin(elapsed * 0.0002) * 128);
		unsigned char blue = (unsigned char) (1 + sin(elapsed * 0.0003) * 128);

		for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
			for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
				screen.setPixel(x, y, red, green, blue);
			}
		}

		screen.screenUpdate();

		if (!screen.processEvents()) {
			break;
		}
	}

	screen.close();

	return 0;
}

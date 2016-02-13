#include <iostream>
#include "Screen.h"
#include <SDL.h>

using namespace std;
using namespace mac;

int main() {

	Screen screen;

	if (!screen.init()) {
		cout << "Error initializing SDL" << flush;
	}

	while (true) {

		for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
			for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
				screen.setPixel(x, y, 128, 0, 255);
			}
		}

		screen.setPixel(400, 300, 255, 255, 255);

		screen.screenUpdate();

		if (!screen.processEvents()) {
			break;
		}
	}

	screen.close();

	return 0;
}

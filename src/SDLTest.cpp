#include <iostream>
#include "Screen.h"
#include "Swarm.h"
#include <Math.h>
#include <SDL.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
using namespace mac;

int main() {

	srand(time(NULL));

	Screen screen;
	Swarm swarm;

	if (!screen.init()) {
		cout << "Error initializing SDL" << flush;
	}

	while (true) {

		const Particle* const pParticles = swarm.getParticles();

		int elapsed = SDL_GetTicks();

		unsigned char green = (unsigned char) (1 + sin(elapsed * 0.0001) * 128);
		unsigned char red = (unsigned char) (1 + sin(elapsed * 0.0002) * 128);
		unsigned char blue = (unsigned char) (1 + sin(elapsed * 0.0003) * 128);

		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
			int y = (particle.m_y + 1) * Screen::SCREEN_HEIGHT / 2;

			screen.setPixel(x, y, red, green, blue);
		}

		screen.screenUpdate();

		if (!screen.processEvents()) {
			break;
		}
	}

	screen.close();

	return 0;
}

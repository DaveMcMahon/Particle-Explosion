#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL.h>
#include <iostream>
using namespace std;

namespace mac {

class Screen {

private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	SDL_Texture* m_texture;
	Uint32* m_buffer;

public:
	Screen();
	virtual ~Screen();
	bool init();
	void close();
	bool processEvents();
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	void screenUpdate();

	const static int SCREEN_WIDTH = 800;
	const static int SCREEN_HEIGHT = 600;

};

}

#endif

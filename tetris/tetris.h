#ifndef TETRIS_TETRIS
	#define TETRIS_TETRIS

	#include <allegro5/allegro.h>
	#include <allegro5/allegro_primitives.h>

	#include "block.h"
	#include "shape.h"
	#include "util.h"

	class Tetris {
		int _screenWidth;
		int _screenHeight;
		ALLEGRO_EVENT_QUEUE *_timerQueue;
		ALLEGRO_EVENT_QUEUE *_keyboardQueue;

		Shape *_shape;

		bool _left;
		bool _right;
		bool _up;
		bool _down;

	public:
		Tetris(int screenWidth, int screenHeight, ALLEGRO_EVENT_QUEUE *timerQueue);
		~Tetris();

		bool update(unsigned int ticks);
		void render();
	};
#endif

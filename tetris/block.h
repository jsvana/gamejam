#ifndef TETRIS_BLOCK
	#define TETRIS_BLOCK

	#include <allegro5/allegro.h>
	#include <allegro5/allegro_primitives.h>

	#include "util.h"

	class Block {
		Point _position;
		float _size;

		Rectangle _bounds;

	public:
		Block(float x, float y);

		bool update(unsigned int ticks);
		void render();

		void setPosition(float x, float y);
		Point getPosition() { return _position; }

		float size() { return _size; }

		void move(int direction);
	};
#endif

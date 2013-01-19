#ifndef TETRIS_SHAPE
	#define TETRIS_SHAPE

	#include <allegro5/allegro.h>
	#include <allegro5/allegro_primitives.h>
	#include <vector>
	#include <iostream>

	#include "block.h"
	#include "util.h"

	class Shape {
		Rectangle _container;
		int _type;
		Rectangle _bounds;

		std::vector<Block *> _blocks;

	public:
		Shape(int type, Rectangle bounds);
		~Shape();

		bool update(unsigned int ticks);
		void render();

		void rotate();

		void move(int direction);
	};
#endif

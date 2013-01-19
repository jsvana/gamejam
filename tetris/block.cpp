#include "block.h"

Block::Block(float x, float y) {
	_position.setX(x);
	_position.setY(y);

	_size = 16;
}

bool Block::update(unsigned int ticks) {
	if (ticks % 4000 == 0) {
		_position.setY(_position.getY() + _size);
	}

	return true;
}

void Block::render() {
	al_draw_filled_rectangle(_position.getX(), _position.getY(),
		_position.getX() + _size, _position.getY() + _size,
		al_map_rgb(255, 255, 255));
	al_draw_rectangle(_position.getX() + 2, _position.getY() + 2,
		_position.getX() + _size - 1, _position.getY() + _size - 1,
		al_map_rgb(0, 0, 0) , 1);
}

void Block::setPosition(float x, float y) {
	_position.setX(x);
	_position.setY(y);
}

void Block::move(int direction) {
	if (direction == TETRIS_LEFT && _position.getX() > 0) {
		_position.setX(_position.getX() - _size);
	} else if (direction == TETRIS_RIGHT) {
		_position.setX(_position.getX() + _size);
	} else if (direction == TETRIS_DOWN) {
		_position.setY(_position.getY() + _size);
	}
}

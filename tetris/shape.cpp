#include "shape.h"

Shape::Shape(int type, Rectangle bounds) {
	_type = type;
	_bounds = bounds;
	_container.setX(0);
	_container.setY(0);

	switch (type) {
		case TETRIS_SHAPE_I:
			for (int i = 0; i < 4; i++) {
				Block *block = new Block(16 * i, 0);
				_blocks.push_back(block);
			}

			_container.setW(4 * 16);
			_container.setH(16);
			break;
	}
}

Shape::~Shape() {
	for (Block *block : _blocks) {
		delete block;
	}
}

bool Shape::update(unsigned int ticks) {
	if (ticks % 4000 == 0
		&& _container.getY() + _container.getH() < _bounds.getH()) {
		for (Block *block : _blocks) {
			block->move(TETRIS_DOWN);
		}

		_container.setY(_container.getY() + 16);
	}

	return true;
}

void Shape::render() {
	for (Block *block : _blocks) {
		block->render();
	}

	al_draw_rectangle(_container.getX(), _container.getY(),
		_container.getX() + _container.getW(),
		_container.getY() + _container.getH(), al_map_rgb(255, 255, 0), 1);
}

void Shape::rotate() {
	switch (_type) {
		case TETRIS_SHAPE_I:
			Block *third = _blocks.at(2);
			float thirdX = third->getPosition().getX();
			float thirdY = third->getPosition().getY();

			for (Block *block : _blocks) {
				float x = block->getPosition().getX() - thirdX;
				float y = block->getPosition().getY() - thirdY;
				x += thirdY;
				y += thirdX;

				block->setPosition(y, x);
			}

			Block *one = _blocks.at(0);
			_container.setX(one->getPosition().getX());
			_container.setY(one->getPosition().getY());

			if (one->getPosition().getX() < third->getPosition().getX()) {
				_container.setW(64);
				_container.setH(16);
			} else {
				_container.setW(16);
				_container.setH(64);
			}
			break;
	}
}

void Shape::move(int direction) {
	if (direction == TETRIS_LEFT && _container.getX() > 0) {
		for (Block *block : _blocks) {
			block->move(direction);
		}

		_container.setX(_container.getX() - 16);
	} else if (direction == TETRIS_RIGHT
		&& _container.getX() + _container.getW() < _bounds.getW()) {
		for (Block *block : _blocks) {
			block->move(direction);
		}

		_container.setX(_container.getX() + 16);
	} else if (direction == TETRIS_DOWN
		&& _container.getY() + _container.getH() < _bounds.getH()) {
		for (Block *block : _blocks) {
			block->move(direction);
		}

		_container.setY(_container.getY() + 16);
	}
}

#include "tetris.h"

Tetris::Tetris(int screenWidth, int screenHeight, ALLEGRO_EVENT_QUEUE *timerQueue) {
	_screenWidth = screenWidth;
	_screenHeight = screenHeight;
	_timerQueue = timerQueue;

	Rectangle bounds(0, 0, _screenWidth - 16 * 5, _screenHeight);
	_shape = new Shape(TETRIS_SHAPE_I, bounds);

  _keyboardQueue = al_create_event_queue();
  al_register_event_source(_keyboardQueue, al_get_keyboard_event_source());

  _left = false;
  _right = false;
  _down = false;
  _up = false;
}

Tetris::~Tetris() {
	delete _shape;
	al_destroy_event_queue(_keyboardQueue);
}

bool Tetris::update(unsigned int ticks) {
  while (!al_is_event_queue_empty(_keyboardQueue)) {
		ALLEGRO_EVENT event;
		al_wait_for_event(_keyboardQueue, &event);

		if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (event.keyboard.keycode) {
				case ALLEGRO_KEY_LEFT:
					_left = true;
					break;
				case ALLEGRO_KEY_RIGHT:
					_right = true;
					break;
				case ALLEGRO_KEY_UP:
					_up = true;
					break;
				case ALLEGRO_KEY_DOWN:
					_down = true;
					break;
				case ALLEGRO_KEY_ESCAPE:
					return false;
			}
		} else if (event.type == ALLEGRO_EVENT_KEY_UP) {
			switch (event.keyboard.keycode) {
				case ALLEGRO_KEY_LEFT:
					_left = false;
					break;
				case ALLEGRO_KEY_RIGHT:
					_right = false;
					break;
				case ALLEGRO_KEY_UP:
					_up = false;
					break;
				case ALLEGRO_KEY_DOWN:
					_down = false;
					break;
			}
		}
	}

	if (ticks % 500 == 0) {
		if (_left) {
			_shape->move(TETRIS_LEFT);
		} else if (_right) {
			_shape->move(TETRIS_RIGHT);
		}

		if (_up) {
			_shape->rotate();
		}

		if (_down) {
			_shape->move(TETRIS_DOWN);
		}
	}

  _shape->update(ticks);

	return true;
}

void Tetris::render() {
	_shape->render();

	al_draw_line(160, 0, 160, 320, al_map_rgb(255, 255, 255), 1);

	al_flip_display();
  al_clear_to_color(al_map_rgb(0, 0, 0));
}

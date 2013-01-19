#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "tetris.h"

#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 320
#define FPS 2.0

int main(int argc, char *argv[]) {
  ALLEGRO_DISPLAY *display;
  unsigned int ticks = 0;

  if (!al_init()) {
    std::cerr << "[ERROR] Error initializing Allegro" << std::endl;
  }

  display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);

  if (!display) {
    std::cerr << "[ERROR] Error creating Allegro display" << std::endl;
  }

  al_install_audio();
  al_install_keyboard();

  al_init_primitives_addon();
  al_init_acodec_addon();
  al_init_font_addon();
  al_init_ttf_addon();
  al_init_image_addon();

  al_reserve_samples(10);

  srand(time(NULL));

  ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);
  ALLEGRO_EVENT_QUEUE *timerQueue = al_create_event_queue();
  al_register_event_source(timerQueue, al_get_timer_event_source(timer));

  al_start_timer(timer);

  Tetris *game = new Tetris(SCREEN_WIDTH, SCREEN_HEIGHT, timerQueue);

  while (game->update(ticks)) {
    game->render();

    ++ticks;
  }

  delete game;

  al_destroy_display(display);
  al_destroy_timer(timer);
  al_destroy_event_queue(timerQueue);

  return 0;
}

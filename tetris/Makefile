CXX = clang++
PROG = tetris
OBJS = main.o tetris.o block.o shape.o
LIBS = allegro-5.0 allegro_main-5.0 allegro_dialog-5.0 allegro_ttf-5.0 \
	allegro_image-5.0 allegro_font-5.0 allegro_primitives-5.0 allegro_audio-5.0 \
	allegro_acodec-5.0
CFLAGS = -ggdb -stdlib=libc++ -std=c++0x $(shell pkg-config --cflags ${LIBS})
LDFLAGS = $(shell pkg-config --libs ${LIBS})

all: ${PROG}

${PROG}: ${OBJS}
		${CXX} ${CFLAGS} -o $@ $+ ${LDFLAGS}

%.o: %.cpp
		${CXX} ${CFLAGS} -c $< -o $@

%.d: %.cpp
	@set -e; rm -f $@; \
		${CXX} -M ${CFLAGS} $< > $@.$$$$; \
		sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
		rm -f $@.$$$$

-include ${OBJS:.o=.d}

clean:
	rm -f ${OBJS} ${PROG} ${OBJS:.o=.d}

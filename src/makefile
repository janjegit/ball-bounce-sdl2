IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
BINDIR=bin
LDIR =../lib

$(shell mkdir -p $(ODIR))
$(shell mkdir -p $(BINDIR))

LIBS=`sdl2-config --libs --cflags` -ggdb3 -O0 --std=c99 -Wall -lSDL2_image -lm

_DEPS = types.h renderer.h input.h vector.h texture.h gameobj.h update.h cleanup.h init.h font.h sprite.h animation.h animation_table.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o renderer.o input.o vector.o texture.o gameobj.o update.o cleanup.o init.o font.o sprite.o animation.o animation_table.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BINDIR)/game: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ $(BINDIR)/game 

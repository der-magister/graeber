SRC = daten/gfx/sprites.c daten/gfx/tiles.c daten/lvldaten/l1.c daten/lvldaten/l2.c daten/lvldaten/l3.c daten/lvldaten/l4.c daten/lvldaten/l5.c daten/lvldaten/l6.c daten/lvldaten/l7.c daten/lvldaten/l8.c daten/lvldaten/l9.c daten/lvldaten/l10.c daten/gfx/hudgui.c daten/intro-1.c daten/intro-2.c daten/intro-3.c daten/gameover.c daten/win.c graber.c init.c player.c engine.c items.c hud.c gegner.c lvlstatus.c lvl.c intro.c

BIN = graber.gb

#SIZE=medium
SIZE=small

GBDK_Home=c:\\apps\\gbdk

LIB = $(GBDK_Home)\\lib\\$(SIZE)\\rgbds\\gbz80\\gbz80.lib $(GBDK_Home)\\lib\\$(SIZE)\\rgbds\\gb\\gb.lib
CRT0 = $(GBDK_Home)\\lib\\$(SIZE)\\rgbds\\gb\\crt0.o

OBJ = $(SRC:.c=.o)

CC = $(GBDK_Home)\\bin\\sdcc -mgbz80 --asm=rgbds -I $(GBDK_Home)\\include -I $(GBDK_Home)\\include\\asm

all: $(BIN)

clean:
	del $(OBJ)
	del *.asm
	del daten/gfx/*.asm
	del *.map
	del *.sym

%.o: %.s

$(BIN): $(OBJ)
	$(CC) $(CRT0) $(OBJ) $(LIB)
	move a.gb $(BIN)
	rgbfix -p -v -tgraber $(BIN) 
	
$(LIB): $(LIBOBJ)
	xlib $@ a $(LIBOBJ)

%.o: %.c
	$(CC) -c $<

%.o: %.asm
	rgbasm -o$@ $<

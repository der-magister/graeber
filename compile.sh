#!/bin/bash

date

echo "Lösche alte Objektdateien..."

rm -rf obj/*.o

echo "Kompiliere..."

### daten

#sprites und tiles
/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -c -o obj/sprites.o daten/gfx/sprites.c
/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -c -o obj/tiles.o daten/gfx/tiles.c

#level
/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -c -o obj/l1.o daten/lvldaten/l1.c
/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -c -o obj/l2.o daten/lvldaten/l2.c
/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -c -o obj/l3.o daten/lvldaten/l3.c
/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -c -o obj/l4.o daten/lvldaten/l4.c
/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -c -o obj/l5.o daten/lvldaten/l5.c
/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -c -o obj/l6.o daten/lvldaten/l6.c
/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -c -o obj/l7.o daten/lvldaten/l7.c
/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -c -o obj/l8.o daten/lvldaten/l8.c
/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -c -o obj/l9.o daten/lvldaten/l9.c
/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -c -o obj/l10.o daten/lvldaten/l10.c

#other
/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -c -o obj/gameover.o daten/gameover.c
/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -c -o obj/intro-1.o daten/intro-1.c
/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -c -o obj/intro-2.o daten/intro-2.c
/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -c -o obj/intro-3.o daten/intro-3.c
/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -c -o obj/win.o daten/win.c

#hud
/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -Wf-bo1 -c -o obj/hudgui.o daten/gfx/hudgui.c

#main
/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -Wa-l -Wl-m -Wl-j -c -o obj/verlies.o graeber.c
/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -c -o obj/engine.o engine.c
/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -c -o obj/init.o init.c
/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -c -o obj/intro.o intro.c
/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -c -o obj/lvl.o lvl.c
/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -c -o obj/lvlstatus.o lvlstatus.c
/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -Wf-bo1 -c -o obj/hud.o hud.c
/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -Wf-bo1 -c -o obj/items.o items.c
/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -Wf-bo1 -c -o obj/player.o player.c
/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -Wf-bo2 -c -o obj/gegner.o gegner.c


cd obj/

obj=$(ls | grep [.][o])

echo "Erstelle Rom..."

/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -Wl-yt0x019 -Wl-yo4 -o ../graeber.gb $obj

date


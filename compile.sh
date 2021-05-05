#!/bin/bash

date

echo "Lösche alte Objektdateien..."

if [ -d obj ] 
then
	rm -rf obj/*.o
	rm -rf obj/*.sym
	rm -rf obj/*.map
	rm -rf obj/*.lst
	rm -rf obj/*.noi
	rm -rf obj/*.ihx
	rm -rf *.gb

else
	mkdir obj/
fi

echo "Kompiliere..."

### daten

#sprites und tiles
/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -c -o obj/sprites.o daten/gfx/sprites.c
/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -c -o obj/tiles.o daten/gfx/tiles.c

#level
/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -c -o obj/l1.o daten/lvldaten/lvldat.c

#other
/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -c -o obj/gameover.o daten/gameover.c
/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -c -o obj/introdat.o daten/introdat.c
/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -c -o obj/win.o daten/win.c

#hud
/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -Wf-bo1 -c -o obj/hudgui.o daten/gfx/hudgui.c

### main
/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -Wa-l -Wl-m -Wl-j -c -o obj/graeber.o graeber.c
/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -c -o obj/globals.o globals.c
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

/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -Wl-yt0x019 -Wl-yo4 -Wm-yn"GRAEBER" -o graeber.gb $obj

romusage graeber.map

mv graeber.gb ../graeber.gb

cd ..

date


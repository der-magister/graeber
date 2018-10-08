//   Graber
//
//   Copyright (C) 2018 Heiko Wolf
//
//   This program is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License As published by
//   the Free Software Foundation; either version 2 of the License, or
//   (at your option) any later version.
//
//   This program is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY Or FITNESS For A PARTICULAR PURPOSE.  See the
//   GNU General Public License For more details.
//
//   You should have received a copy of the GNU General Public License along
//   With this program; if not, write to the Free Software Foundation, Inc.,
//   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//
//   Kontakt: magister@skywave-2000.de

#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#include "c:\\apps\\gbdk\\include\\asm\\gbz80\\types.h"
#include "c:\\apps\\gbdk\\include\\gb\\gb.h"

#define FALSE 0
#define TRUE 1
#define NORTH 1
#define SOUTH 2
#define WEST 3
#define EAST 4

#define MOVE_HORIZONT 1
#define MOVE_VERTICAL 2
#define MOVE_STACHEL 3

#define MOVE_NORTH 1
#define MOVE_SOUTH 2
#define MOVE_WEST 3
#define MOVE_EAST 4
#define MOVE_UP 5
#define MOVE_DOWN 6

///
extern UINT8 v_gameover;

extern UINT8 v_movetimer;
extern UINT8 v_angriffstimer;

///Lebenspunkte Spieler
extern INT8 v_slp;    

///maximale Lebenspunkte Spieler                                          
extern INT8 v_smlp;

///XK-Koordinate Spieler                                           
extern UINT8 v_sxk;

///YK-Koordinate Spieler
extern UINT8 v_syk;

///zusammengerechnete Kartenkoordinate Spieler
extern UINT8 v_smk;

///X-Mapkoordinate Spieler
extern UINT8 v_smxk; 

///Y-Mapkoordinate Spieler
extern UINT8 v_smyk;

///Bewegungsrichtung Spieler
extern UINT8 v_sri;

///Gold Spieler
extern UINT8 v_sgo;

///maximales Gold Spieler
extern UINT8 v_smgo;

extern UINT8 v_sangriff;

///Haltbarkeit des Pickel
extern UINT8 v_shalt;

///max. Haltbarkeit Pickel
extern UINT8 v_smhalt;

extern UINT8 v_sschlaege;

extern UINT8 v_edelstein;

extern UINT8 v_timer;
extern UINT8 v_tick;

extern unsigned char v_lvldat [241];
extern unsigned char v_tile [1];

extern UINT8 v_i;

extern UINT8 v_lvl;
extern UINT8 v_aktion;

extern UINT8 v_gxk [4];        //Koordinate X
extern UINT8 v_gyk [4];        //Koordinate Y
extern UINT8 v_gflag [4];      //Flag 1 - horizontale, 2 - vertikale Bewegung, 0 - nicht aktiv
extern INT8 v_glp [4];         //Lebenspunkte 
extern UINT8 v_gtp [4];        //Gegnertrefferpunkte
extern UINT8 v_gmk [4];        //Koordinate auf Map
extern UINT8 v_gri [4];        //Bewegungsrichtung
extern UINT8 v_gftile [4];
extern UINT8 v_gltile [4];
extern UINT8 v_trefferlooptime;
extern UINT8 v_gegnerlooptime;
extern UINT8 v_kampf;
extern volatile UINT8 v_j;
extern UINT8 v_mg;             //maximale Gegner
extern UINT8 v_stref;
extern UINT8 v_gspeed;

extern UINT8 v_quit;

#endif

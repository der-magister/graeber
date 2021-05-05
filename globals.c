//   Graeber
//
//   Copyright (C) 2018-2021 Heiko Wolf
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
//   Kontakt: projekte@kabelmail.net

#include "globals.h"

UINT8 v_gameover;
UINT8 v_movetimer;
UINT8 v_angriffstimer;
UINT8 v_tick;
UINT8 v_quit;

INT8 v_slp;
INT8 v_smlp;
UINT8 v_sxk;
UINT8 v_syk;
UINT8 v_smk;
UINT8 v_sri;
UINT8 v_sangriff;
UINT8 v_smxk;
UINT8 v_smyk;
UINT8 v_sgo;
UINT8 v_smgo;
UINT8 v_shalt;
UINT8 v_smhalt;
UINT8 v_sschlaege;
UINT8 v_edelstein;

unsigned char v_lvldat [241];
unsigned char v_tile [1];
UINT8 v_i;

UINT8 v_gxk [6];        //Koordinate X
UINT8 v_gyk [6];        //Koordinate Y
UINT8 v_gflag [6];      //Flag 1 - horizontale, 2 - vertikale Bewegung, 0 - nicht aktiv
INT8 v_glp [6];         //Lebenspunkte 
UINT8 v_gtp [6];        //Gegnertrefferpunkte
UINT8 v_gmk [6];        //Koordinate auf Map
UINT8 v_gri [6];        //Bewegungsrichtung
UINT8 v_gftile [6];
UINT8 v_gltile [6];
UINT8 v_trefferlooptime;
UINT8 v_gegnerlooptime;
UINT8 v_kampf;
UINT8 v_j;
UINT8 v_mg;             //maximale Gegner
UINT8 v_stref;
UINT8 v_gspeed;

UINT8 v_timer;
UINT8 v_lvl;
UINT8 v_aktion;


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
//   Kontakt: projekte@kabelmail.net

#include "globals.h"
#include "init.h"
#include "player.h"
#include "hud.h"
#include "gegner.h"
#include "lvlstatus.h"
#include "intro.h"

#include "daten/gameover.h"
#include "daten/win.h"


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
volatile UINT8 v_j;
UINT8 v_mg;             //maximale Gegner
UINT8 v_stref;
UINT8 v_gspeed;

UINT8 v_timer;
UINT8 v_lvl;
UINT8 v_aktion;

void main ()
{
  p_init (); v_quit = FALSE;
  p_intro ();

  while (v_quit == FALSE)
  {
    p_init2 ();
    v_gameover = FALSE; v_movetimer = 0; v_angriffstimer = 0; v_tick = 0; v_gegnerlooptime = 0;

    while (v_gameover == FALSE)
    {
      if ((v_gegnerlooptime == v_gspeed) && (v_kampf == TRUE))
      {
        p_gegner_move_horizontal ();
        p_gegner_move_vertikal ();
        p_gegner_stachel ();
     
        v_gegnerlooptime = 0;
      }

      if (v_movetimer == 6)
      {
        if (joypad () & J_UP) p_player_moveNorth ();
        if (joypad () & J_DOWN) p_player_moveSouth ();
        if (joypad () & J_LEFT) p_player_moveWest ();
        if (joypad () & J_RIGHT) p_player_moveEast ();
        v_movetimer = 0;
      }

      if ((joypad () & J_A) && (v_sangriff == FALSE))
      {
        p_lvl_whichLvL ();

        if (v_aktion == FALSE) { p_player_angriff (); }
      }

      v_aktion = FALSE;

      if (v_angriffstimer == 8)
      {
        move_sprite (1, 0, 0);
        v_sangriff = FALSE;
      }

      v_movetimer++;
      v_tick++;
      if (v_sangriff == TRUE) v_angriffstimer++;
      if (v_kampf == TRUE) v_gegnerlooptime++;

      if (v_tick == 60) 
      {
        v_timer--;
        v_tick = 0;
      }

      if ((v_slp <= 0) || (v_timer <= 0) || (v_shalt <= 0))
      { 
        HIDE_SPRITES;
        set_sprite_tile (0, 0);
        set_bkg_tiles (0, 0, 20, 18, gameover);
        p_gegner_stop ();
        move_sprite (0, 0, 0);
        move_sprite (1, 0, 0);
        waitpad (J_START);
        v_gameover = TRUE;
      }

      if (v_edelstein == 1)
      {
        HIDE_SPRITES;
        set_sprite_tile (0, 0);
        set_bkg_tiles (0, 0, 20, 18, win);
        p_gegner_stop ();
        move_sprite (0, 0, 0);
        move_sprite (1, 0, 0);
        waitpad (J_START);
        v_gameover = TRUE;
      }


      p_gegner_kolision ();
      p_hud_show ();

      wait_vbl_done ();
    }
  }
}

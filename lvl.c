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

#include "lvl.h"
#include "engine.h"

#include "player.h"
#include "gegner.h"

#include "daten/lvldaten/l2.h"
#include "daten/lvldaten/l3.h"
#include "daten/lvldaten/l4.h"
#include "daten/lvldaten/l5.h"
#include "daten/lvldaten/l6.h"
#include "daten/lvldaten/l7.h"
#include "daten/lvldaten/l8.h"
#include "daten/lvldaten/l9.h"
#include "daten/lvldaten/l10.h"


void p_lvl1 () NONBANKED
{
  if ((v_sxk == 152) && (v_syk == 64))
  {
    p_engine_changeLvl (2, l2);
    p_player_setSprite (16, 64, 1, 6);

    v_mg = 1; v_gspeed = 30;
    p_gegner_set (1, 2, 3, 104, 88, MOVE_HORIZONT, MOVE_WEST, 1, 1);
  }
}

void p_lvl2 () NONBANKED
{
  if ((v_sxk == 88) && (v_syk == 96))
  {
    p_engine_changeLvl (3, l3);
    p_player_setSprite (88, 24, 10, 1);

    v_mg = 1; v_gspeed = 30;
    p_gegner_set (1, 4, 4, 72, 96, MOVE_HORIZONT, MOVE_EAST, 125, 2);
  }
}

void p_lvl3 () NONBANKED
{
  if ((v_sxk == 88) && (v_syk == 96))
  {
    p_engine_changeLvl (4, l4);
    p_player_setSprite (88, 24, 10, 1);

    v_mg = 2; v_gspeed = 15;
    p_gegner_set (1, 4 , 4, 96, 48, MOVE_HORIZONT, MOVE_WEST, 125, 2);
    p_gegner_set (2, 4 , 4, 64, 64, MOVE_HORIZONT, MOVE_EAST, 125, 2);
  }
}

void p_lvl4 () NONBANKED
{
  if ((v_sxk == 80) && (v_syk == 56))
  {
    p_engine_changeLvl (5, l5);
    p_player_setSprite (80, 56, 9, 5);

    v_mg = 2; v_gspeed = 25;
    p_gegner_set (1, 2, 3, 128, 64, MOVE_HORIZONT, MOVE_EAST, 1, 1);
    p_gegner_set (2, 4, 4, 16, 96, MOVE_VERTICAL, MOVE_NORTH, 125, 2);
  }
}

void p_lvl5 () NONBANKED
{
  if ((v_sxk == 16) && (v_syk == 56))
  {
    p_engine_changeLvl (6, l6);
    p_player_setSprite (16, 56, 1, 5);

  }
}

void p_lvl6 () NONBANKED
{
  if ((v_sxk == 72) && (v_syk == 96))
  {
    p_engine_changeLvl (7, l7);
    p_player_setSprite (72, 96, 8, 10);

    v_mg = 2; v_gspeed = 30;
    p_gegner_set (1, 6, 5, 112, 96, MOVE_STACHEL, MOVE_UP, 125, 2);
    p_gegner_set (2, 6, 5, 72, 32, MOVE_STACHEL, MOVE_UP, 125, 2);
  }
}

void p_lvl7 () NONBANKED
{
  if ((v_sxk == 72) && (v_syk == 24))
  {
    p_engine_changeLvl (8, l8);
    p_player_setSprite (72, 24, 8, 1);

    v_mg = 1; v_gspeed = 15;
    p_gegner_set (1, 4, 4, 72, 96, MOVE_VERTICAL, MOVE_NORTH, 125, 2);
  }
}

void p_lvl8 () NONBANKED
{
  if ((v_sxk == 16) && (v_syk == 96))
  {
    p_engine_changeLvl (9, l9);
    p_player_setSprite (16, 96, 1, 10);

    v_mg = 2; v_gspeed = 25;
    p_gegner_set (1, 4, 4, 24, 48, MOVE_VERTICAL, MOVE_SOUTH, 125, 2);
     p_gegner_set (2, 6, 5, 144, 56, MOVE_STACHEL, MOVE_UP, 125, 2);
  }
}

void p_lvl9 () NONBANKED
{
  if ((v_sxk == 152) && (v_syk == 56))
  {
    p_engine_changeLvl (10, l10);
    p_player_setSprite (152, 56, 18, 5);
  }
}

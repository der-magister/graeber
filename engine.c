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

#include "engine.h"
#include "gegner.h"

void p_engine_drawMap (unsigned char *lvldat) NONBANKED
{
  for (v_i = 0; v_i <= 241; v_i++)
  {
    v_lvldat [v_i] = lvldat [v_i];
  }

  set_bkg_tiles (0, 0, 20, 12, v_lvldat);
}

void p_engine_changeLvl (UINT8 lvl, unsigned char *lvldat) NONBANKED
{
  DISPLAY_OFF;
  p_gegner_stop ();
  delay (150);
  v_aktion = TRUE;
  v_lvl = lvl;
  p_engine_drawMap (lvldat);
  DISPLAY_ON;
}

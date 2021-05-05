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

#include "init.h"
#include "player.h"
#include "engine.h"
#include "hud.h"
#include "gegner.h"

#include "daten/gfx/sprites.h"
#include "daten/gfx/tiles.h"
#include "daten/lvldaten/lvldat.h"
#include "daten/introdat.h"

void p_init (void) __nonbanked
{
        HIDE_SPRITES;
        HIDE_BKG;
        HIDE_WIN;
        SPRITES_8x8;
        set_sprite_data (0, 7, sprites);
        set_bkg_data (0, 54, tiles);
}

void p_init2 (void) __nonbanked
{
        SHOW_SPRITES;
        SHOW_BKG;

        set_bkg_tiles (0, 0, 20, 18, intro3);
        waitpad (J_START);

        v_timer = 150; v_lvl = 1; v_sangriff = FALSE; v_aktion = FALSE;

        p_player_init ();
        p_hud_init ();

        p_engine_drawMap (l1);

        p_player_setSprite (16, 64, 1, 6);
        v_mg = 1; v_gspeed = 40;
        p_gegner_set (1, 2, 3, 136, 64, MOVE_HORIZONT, MOVE_WEST, 1, 1);
}

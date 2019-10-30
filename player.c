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

#pragma bank=1

#include "player.h"
#include "engine.h"
#include "items.h"

void p_player_init () BANKED
{
  v_slp = 3; v_smlp = 3; v_sxk = 16; v_syk = 16; v_sgo = 0; v_smgo = 250; v_edelstein = 0;

  v_shalt = 5; v_smhalt = 5;

  set_sprite_tile (0, 0);
  set_sprite_tile (1, 1);
}

void p_player_setSprite (UINT8 xk, UINT8 yk, UINT8 v_mxk, UINT8 v_myk) BANKED
{
  v_sxk = xk;
  v_syk = yk;
  v_smxk = v_mxk;
  v_smyk = v_myk;

  v_smk = ((v_sxk - 8) / 8) + 20 * ((v_syk - 16) / 8);

  move_sprite (0, v_sxk, v_syk); 
}

void p_player_moveNorth () BANKED
{
  v_sri = NORTH;
  if ((v_lvldat [v_smk - 20] != 3) &&
      (v_lvldat [v_smk - 20] != 2) &&
      (v_lvldat [v_smk - 20] != 6) &&
      (v_lvldat [v_smk - 20] != 7))
  {
    p_player_setSprite (v_sxk, v_syk - 8, v_smxk, v_smyk - 1);

    p_items_sammleGold ();
    p_items_sammleHerz ();
    p_items_sammlePickel ();
    p_item_sammleEdelstein ();
  }
}

void p_player_moveSouth () BANKED
{
  v_sri = SOUTH;
  if ((v_lvldat [v_smk + 20] != 3) &&
     (v_lvldat [v_smk + 20] != 2) &&
     (v_lvldat [v_smk + 20] != 6) &&
     (v_lvldat [v_smk + 20] != 7))
  {
    p_player_setSprite (v_sxk, v_syk + 8, v_smxk, v_smyk + 1);

    p_items_sammleGold ();
    p_items_sammleHerz ();
    p_items_sammlePickel ();
    p_item_sammleEdelstein ();
  }
}

void p_player_moveWest () BANKED
{
  v_sri = WEST;
  if ((v_lvldat [v_smk - 1] != 3) &&
     (v_lvldat [v_smk - 1] != 2) &&
     (v_lvldat [v_smk - 1] != 6) &&
     (v_lvldat [v_smk - 1] != 7))
  {
    p_player_setSprite (v_sxk - 8, v_syk, v_smxk - 1, v_smyk);

    p_items_sammleGold ();
    p_items_sammleHerz ();
    p_items_sammlePickel ();
    p_item_sammleEdelstein ();
  }
}

void p_player_moveEast () BANKED
{
  v_sri = EAST;
  if ((v_lvldat [v_smk + 1] != 3) &&
     (v_lvldat [v_smk + 1] != 2)  &&
     (v_lvldat [v_smk + 1] != 6) &&
     (v_lvldat [v_smk + 1] != 7))
  {
    p_player_setSprite (v_sxk + 8, v_syk, v_smxk + 1, v_smyk);

    p_items_sammleGold ();
    p_items_sammleHerz ();
    p_items_sammlePickel ();
    p_item_sammleEdelstein ();
  }
}

void p_player_angriff () BANKED
{
  if (v_sri == NORTH)
  {
    move_sprite (1, v_sxk, v_syk - 8);

    if (v_lvldat [v_smk - 20] == 3)
    {
      v_tile [0] = 1;    
      set_bkg_tiles (v_smxk, v_smyk - 1, 1, 1, v_tile);
      v_lvldat [v_smk - 20] = 1;
      v_sschlaege++;
    }
    else if (v_lvldat [v_smk - 20] == 2)
    {
      v_tile [0] = 7;    
      set_bkg_tiles (v_smxk, v_smyk - 1, 1, 1, v_tile);
      v_lvldat [v_smk - 20] = 7;
       v_sschlaege++;
    }
    else if (v_lvldat [v_smk - 20] == 7)
    {
      v_tile [0] = 1;    
      set_bkg_tiles (v_smxk, v_smyk - 1, 1, 1, v_tile);
      v_lvldat [v_smk - 20] = 1;
      v_sschlaege++;
    }
  }  
  else if (v_sri == SOUTH)
  {
    move_sprite (1, v_sxk, v_syk + 8);

    if (v_lvldat [v_smk + 20] == 3)
    {
      v_tile [0] = 1;    
      set_bkg_tiles (v_smxk, v_smyk + 1, 1, 1, v_tile);
      v_lvldat [v_smk + 20] = 1;
    }
    else if (v_lvldat [v_smk + 20] == 2)
    {
      v_tile [0] = 7;    
      set_bkg_tiles (v_smxk, v_smyk + 1, 1, 1, v_tile);
      v_lvldat [v_smk + 20] = 7;
      v_sschlaege++;
    }
    else if (v_lvldat [v_smk + 20] == 7)
    {
      v_tile [0] = 1;    
      set_bkg_tiles (v_smxk, v_smyk + 1, 1, 1, v_tile);
      v_lvldat [v_smk + 20] = 1;
      v_sschlaege++;
    }
  }
  else if (v_sri == WEST)
  {
    move_sprite (1, v_sxk - 8, v_syk);

    if (v_lvldat [v_smk - 1] == 3)
    {
      v_tile [0] = 1;    
      set_bkg_tiles (v_smxk - 1, v_smyk, 1, 1, v_tile);
      v_lvldat [v_smk - 1] = 1; v_sschlaege++;
    }
    else if (v_lvldat [v_smk - 1] == 2)
    {
      v_tile [0] = 7;    
      set_bkg_tiles (v_smxk - 1, v_smyk, 1, 1, v_tile);
      v_lvldat [v_smk - 1] = 7; v_sschlaege++;
    }
    else if (v_lvldat [v_smk - 1] == 7)
    {
      v_tile [0] = 1;    
      set_bkg_tiles (v_smxk - 1, v_smyk, 1, 1, v_tile);
      v_lvldat [v_smk - 1] = 1; v_sschlaege++;
    }
  }
  else if (v_sri == EAST)
  {
    move_sprite (1, v_sxk + 8, v_syk);

    if (v_lvldat [v_smk + 1] == 3)
    {
      v_tile [0] = 1;    
      set_bkg_tiles (v_smxk + 1, v_smyk, 1, 1, v_tile);
      v_lvldat [v_smk + 1] = 1; v_sschlaege++;
    }
    else if (v_lvldat [v_smk + 1] == 2)
    {
      v_tile [0] = 7;    
      set_bkg_tiles (v_smxk + 1, v_smyk, 1, 1, v_tile);
      v_lvldat [v_smk + 1] = 7; v_sschlaege++;
    }
    else if (v_lvldat [v_smk + 1] == 7)
    {
      v_tile [0] = 1;    
      set_bkg_tiles (v_smxk + 1, v_smyk, 1, 1, v_tile);
      v_lvldat [v_smk + 1] = 1; v_sschlaege++;
    }
  }

  v_sangriff = TRUE;  
  v_angriffstimer = 0;

  if (v_sschlaege == 25)
  {
    v_shalt--;
    v_sschlaege = 0;  
  }
}

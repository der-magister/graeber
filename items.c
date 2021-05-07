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

#include "items.h"

///Gold einsammeln
void p_items_sammleGold (void) __banked
{ 
        if ((v_lvldat [v_smk] == 5) && (v_sgo != v_smgo))
        {
                ++v_sgo;
                v_lvldat [v_smk] = 1;
                v_tile [0] = 1;
                
                set_bkg_tiles (v_smxk, v_smyk, 1, 1, v_tile);
        }
}

//Herz einsammeln
void p_items_sammleHerz (void) __banked
{
        if ((v_lvldat [v_smk] == 20) && (v_slp != v_smlp)) {
                ++v_slp;
                v_lvldat [v_smk] = 1;
                v_tile [0] = 1;
                set_bkg_tiles (v_smxk, v_smyk, 1, 1, v_tile);
        }
}

//Haltbarkeit des Pickels erhöhen
void p_items_sammlePickel (void) __banked
{
        if ((v_lvldat [v_smk] == 21) && (v_shalt != v_smhalt)) {
                ++v_shalt;
                v_lvldat [v_smk] = 1;
                v_tile [0] = 1;
                set_bkg_tiles (v_smxk, v_smyk, 1, 1, v_tile);
        }
}

//Delestein einsammeln
void p_item_sammleEdelstein (void) __banked 
{
        if ((v_lvldat [v_smk] == 52) && (v_lvl == 10)) {
                v_lvldat [v_smk] = 1;
                v_tile [0] = 1;
                set_bkg_tiles (v_smxk, v_smyk, 1, 1, v_tile);
                v_edelstein = 1;
        }
}


void p_item (void) __banked
{
        p_items_sammleGold ();
        p_items_sammleHerz ();
        p_items_sammlePickel ();
        p_item_sammleEdelstein ();
} 

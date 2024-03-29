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

//#pragma bank=1

#include "hud.h"
#include "daten/gfx/hudgui.h"

///wandelt Variablenwert in Anzeigewert um
void p_hud_umwandlung (UINT8 v_wert, UINT8 mxk, UINT8 myk) __banked
{
        UINT8 l_nr [1];
  
        if (v_wert == 0) l_nr [0] = 17;
  
        for (v_i = 1; v_i != 10; ++v_i) {
                if (v_wert == v_i) l_nr [0] = 7 + v_i;
        }
        set_bkg_tiles (mxk, myk, 1, 1, l_nr); 
}

///zeigt aktuelle Spielerlebenspunkte an
void p_hud_showLP (void) __banked
{
        p_hud_umwandlung (v_slp, 3, 13);
}

///zeigt maximale Spielerlebenspunkte an
void p_hud_showMLP (void) __banked
{
        p_hud_umwandlung (v_smlp, 5, 13);
}

void p_hud_showGO (void) __banked
{
        p_hud_umwandlung (v_sgo % 10, 18, 13);
        p_hud_umwandlung ((v_sgo / 10) % 10, 17, 13);
        p_hud_umwandlung (((v_sgo / 10)/10) % 10, 16, 13);
}

void p_hud_showTimer (void) __banked
{
        p_hud_umwandlung (v_timer % 10, 18, 15);
        p_hud_umwandlung ((v_timer / 10) % 10, 17, 15);
        p_hud_umwandlung (((v_timer / 10)/10) % 10, 16, 15);
}

void p_hud_showhalt (void) __banked
{
        p_hud_umwandlung (v_shalt, 3, 15);
}

void p_hud_showmhalt (void) __banked
{
        p_hud_umwandlung (v_smhalt, 5, 15);
}

void p_hud_showXYK (void) __banked
{
        p_hud_umwandlung (v_sxk % 10, 8, 14);
        p_hud_umwandlung ((v_sxk / 10) % 10, 7, 14);
        p_hud_umwandlung (((v_sxk / 10) / 10) % 10, 6, 14);
  
        p_hud_umwandlung (v_syk % 10, 12, 14);
        p_hud_umwandlung ((v_syk / 10) % 10, 11, 14);
        p_hud_umwandlung (((v_syk / 10) / 10) % 10, 10, 14);
}

void p_hud_show (void) __banked
{
        p_hud_showLP ();
        p_hud_showMLP ();
        p_hud_showGO ();
        p_hud_showTimer ();
        p_hud_showhalt ();
        p_hud_showmhalt ();
        //p_hud_showXYK ();
}

void p_hud_init (void) __banked
{
        set_bkg_tiles (0, 12, 20, 16, hudgui);
        p_hud_show ();
}

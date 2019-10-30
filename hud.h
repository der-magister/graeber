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

#ifndef _HUD_H_
#define _HUD_H_

#include "globals.h"

void p_hud_umwandlung (UINT8 v_wert, UINT8 mxk, UINT8 myk) BANKED;
void p_hud_init () BANKED;
void p_hud_showLP () BANKED;
void p_hud_showMLP () BANKED;
void p_hud_showGO () BANKED;
void p_hud_show () BANKED;
void p_hud_showTimer () BANKED;
void p_hud_showhalt () BANKED;
void p_hud_showmhalt () BANKED;
void p_hud_showXYK () BANKED;

#endif

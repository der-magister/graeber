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

#ifndef _HUD_H_
#define _HUD_H_

#include "globals.h"

void p_hud_umwandlung (UINT8 v_wert, UINT8 mxk, UINT8 myk) __banked;
void p_hud_init (void) __banked;
void p_hud_showLP (void) __banked;
void p_hud_showMLP (void) __banked;
void p_hud_showGO (void) __banked;
void p_hud_show (void) __banked;
void p_hud_showTimer (void) __banked;
void p_hud_showhalt (void) __banked;
void p_hud_showmhalt (void) __banked;
void p_hud_showXYK (void) __banked;

#endif

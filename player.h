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
//   Kontakt: magister@skywave-2000.de

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "globals.h"

void p_player_init () BANKED;
void p_player_setSprite (UINT8 xk, UINT8 yk, UINT8 v_mxk, UINT8 v_myk) BANKED;
void p_player_moveNorth () BANKED;
void p_player_moveSouth () BANKED;
void p_player_moveWest () BANKED;
void p_player_moveEast () BANKED;
void p_player_angriff () BANKED;

#endif

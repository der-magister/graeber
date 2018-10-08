//   Verlies - ein Adventure im Retrodesign
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

#ifndef _GEGNER_H_
#define _GEGNER_H_

#include "globals.h"

void p_gegner_move_horizontal () BANKED;
void p_gegner_move_vertikal () BANKED;
void p_gegner_stop () BANKED;
void p_gegner_kolision () BANKED;
void p_gegner_stachel () BANKED;
void p_gegner_set (UINT8 v_sprinr, UINT8 v_sprftile, UINT8 v_sprltile, UINT8 v_sprx, UINT8 v_spry, 
                   UINT8 v_sprflag, UINT8 v_sprri, UINT8 v_sprlp, UINT8 v_sprtp) BANKED;
                   
#endif

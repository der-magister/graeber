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

#include "intro.h"

#include "daten/introdat.h"

void p_intro (void) __nonbanked
{
	  SHOW_SPRITES;
	  SHOW_BKG;

	  set_bkg_tiles (0, 0, 20, 18, intro1);
	  //delay (2500);
	  //set_bkg_tiles (0, 0, 20, 18, intro2);
	  delay (2500);
}

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

#include "lvlstatus.h"
#include "lvl.h"

void p_lvl_whichLvL () NONBANKED
{
  if (v_lvl == 1) p_lvl1 ();
  else if (v_lvl == 2) p_lvl2 ();
  else if (v_lvl == 3) p_lvl3 ();
  else if (v_lvl == 4) p_lvl4 ();
  else if (v_lvl == 5) p_lvl5 ();
  else if (v_lvl == 6) p_lvl6 ();
  else if (v_lvl == 7) p_lvl7 ();
  else if (v_lvl == 8) p_lvl8 ();
  else if (v_lvl == 9) p_lvl9 ();
  //else if (v_lvl == 10) p_lvl10 ();
}

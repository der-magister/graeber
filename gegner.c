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

//#pragma bank=2

#include "player.h"
#include "gegner.h"
#include "hud.h"

///horizontale Bewegungsroutine Gegner
void p_gegner_move_horizontal (void) __banked
{
  for (v_i = 1; v_i <= v_mg; ++v_i) 
  {
    if (v_gflag [v_i] == 1) 
    {
      v_gmk [v_i] = ((v_gxk [v_i] - 8) / 8) + 20 * ((v_gyk [v_i] - 16) / 8);

      if (v_gri [v_i] == 4)
      {
        set_sprite_tile (9 + v_i, v_gltile [v_i]);
        
        //bei bevorstehende Kolision Richtungswechsel
        if  ((v_lvldat [v_gmk [v_i] + 1] == 6) ||
             (v_lvldat [v_gmk [v_i] + 1] == 2) ||
             (v_lvldat [v_gmk [v_i] + 1] == 7) ||
             (v_lvldat [v_gmk [v_i] + 1] == 3))
        { 
          v_gri [v_i] = 3; 
        }
        else
        {
          v_gxk [v_i] = v_gxk [v_i] + 8;
        }
      }
      if (v_gri [v_i] == 3)
      {
        set_sprite_tile (9 + v_i, v_gftile [v_i]);
      
        if ((v_lvldat [v_gmk [v_i] - 1] == 6) ||
            (v_lvldat [v_gmk [v_i] - 1] == 2) ||
            (v_lvldat [v_gmk [v_i] - 1] == 7) ||
            (v_lvldat [v_gmk [v_i] - 1] == 3))
        {
          v_gri [v_i] = 4;
        }
        else
        {
          v_gxk [v_i] = v_gxk [v_i] - 8;
        }
      }
    }
    if (v_gflag [v_i] == 1) move_sprite (9 + v_i, v_gxk [v_i], v_gyk [v_i]);
  }
}

///Gegner die sich vertikal bewegen
void p_gegner_move_vertikal (void) __banked
{
  for (v_i = 1; v_i <= v_mg; v_i++) 
  {
    if (v_gflag [v_i] == 2)
    {
      v_gmk [v_i] = ((v_gxk [v_i] - 8) / 8) + 20 * ((v_gyk [v_i] - 16) / 8);

      if (v_gri [v_i] == 1)
      {
        set_sprite_tile (9 + v_i, v_gltile [v_i]);
      
        //bei bevorstehende Kolision Richtungswechsel
        if  ((v_lvldat [v_gmk [v_i] - 20] == 6) ||
             (v_lvldat [v_gmk [v_i] - 20] == 2) ||
             (v_lvldat [v_gmk [v_i] - 20] == 7) ||
             (v_lvldat [v_gmk [v_i] - 20] == 3))
        {
          v_gri [v_i] = 2; 
        }
        else
        {
          v_gyk [v_i] = v_gyk [v_i] - 8;
        }
      }
      if (v_gri [v_i] == 2)
      {
        set_sprite_tile (9 + v_i, v_gftile [v_i]);
      
        if ((v_lvldat [v_gmk [v_i] + 20] == 6) ||
            (v_lvldat [v_gmk [v_i] + 20] == 2) ||
            (v_lvldat [v_gmk [v_i] + 20] == 7) ||
            (v_lvldat [v_gmk [v_i] + 20] == 3))
        {
          v_gri [v_i] = 1;
        }
        else
        {
          v_gyk [v_i] = v_gyk [v_i] + 8;
        }     
      }
    }
    if (v_gflag [v_i] == 2) move_sprite (9 + v_i, v_gxk [v_i], v_gyk [v_i]);
  }
}

void p_gegner_stop (void) __banked
{
  v_kampf = FALSE;
  
  for (v_i = 1; v_i <= 5; v_i++) 
  {
    v_gflag [v_i] = 0;
      
    v_gxk [v_i] = 0; v_gyk [v_i] = 0;
    v_gmk [v_i] = 0;

    move_sprite (9 + v_i, 0, 0);
  }
}

///Kolision mit Spieler
void p_gegner_kolision (void) __banked
{
  for (v_j = 1; v_j <= v_mg; v_j++)
  {
    v_gmk [v_j] = ((v_gxk [v_j] - 8) / 8) + 20 * ((v_gyk [v_j] - 16) / 8);

    if (((v_gflag [v_j] <= 2) &&  (v_gflag [v_j] > 0)) && (v_smk == v_gmk [v_j])) 
    { 
      v_slp = v_slp - v_gtp [v_j]; v_trefferlooptime = 0;
      v_gegnerlooptime = v_gspeed - 1;
        
      p_hud_showLP ();
        
        ///Gegner kommt vom Süden
        if (v_gri [v_j] == 1) 
        {
          v_gri [v_j] = 2;
          
          if ((v_lvldat [v_smk - 20] != 6) &&
              (v_lvldat [v_smk - 20] != 2) &&
              (v_lvldat [v_smk - 20] != 7) &&
              (v_lvldat [v_smk - 20] != 3)) 
          {
            p_player_setSprite (v_sxk, v_syk - 8, v_smxk, v_smyk - 1);
          }
          else if ((v_lvldat [v_smk + 1] != 6) &&
                  (v_lvldat [v_smk + 1] != 2) &&
                  (v_lvldat [v_smk + 1] != 7) &&
                  (v_lvldat [v_smk + 1] != 3))
          {
            p_player_setSprite (v_sxk + 8, v_syk, v_smxk + 1, v_smyk);
          }
          else if ((v_lvldat [v_smk - 1] != 6) &&
                  (v_lvldat [v_smk - 1] != 2) &&
                  (v_lvldat [v_smk - 1] != 7) &&
                  (v_lvldat [v_smk - 1] != 3))
          {
            p_player_setSprite (v_sxk - 8, v_syk, v_smxk - 1, v_smyk);
          }  
        }
        
        //Gegner kommt vom Norden
        else if (v_gri [v_j] == 2) 
        {
          v_gri [v_j] = 1;
          
          if ((v_lvldat [v_smk + 20] != 6) &&
              (v_lvldat [v_smk + 20] != 2) &&
              (v_lvldat [v_smk + 20] != 7) &&
              (v_lvldat [v_smk + 20] != 3))
          {
            p_player_setSprite (v_sxk, v_syk + 8, v_smxk, v_smyk + 1);
          }
          else  if ((v_lvldat [v_smk + 1] != 6) &&
                    (v_lvldat [v_smk + 1] != 2) &&
                    (v_lvldat [v_smk + 1] != 7) &&
                    (v_lvldat [v_smk + 1] != 3))
          {
            p_player_setSprite (v_sxk + 8, v_syk, v_smxk + 1, v_smyk);
          }
          else if ((v_lvldat [v_smk - 1] != 6) &&
                  (v_lvldat [v_smk - 1] != 2) &&
                  (v_lvldat [v_smk - 1] != 7) &&
                  (v_lvldat [v_smk - 1] != 3))
          {
            p_player_setSprite (v_sxk - 8, v_syk, v_smxk - 1, v_smyk);
          }
        }
        
        //Gegner kommt vom Osten
        else if (v_gri [v_j] == 3) 
        {
          v_gri [v_j] = 4;
          
          if ((v_lvldat [v_smk - 1] != 6) &&
              (v_lvldat [v_smk - 1] != 2) &&
              (v_lvldat [v_smk - 1] != 7) &&
              (v_lvldat [v_smk - 1] != 3))
          {
            p_player_setSprite (v_sxk - 8, v_syk, v_smxk - 1, v_smyk);
          }
          else if ((v_lvldat [v_smk - 20] != 6) &&
                   (v_lvldat [v_smk - 20] != 2) &&
                  (v_lvldat [v_smk - 20] != 7) &&
                  (v_lvldat [v_smk - 20] != 3)) 
          {
            p_player_setSprite (v_sxk, v_syk - 8, v_smxk, v_smyk - 1);
          }
          else if ((v_lvldat [v_smk + 20] != 6) &&
                  (v_lvldat [v_smk + 20] != 2) &&
                  (v_lvldat [v_smk + 20] != 7) &&
                  (v_lvldat [v_smk + 20] != 3))
          {
            p_player_setSprite (v_sxk, v_syk + 8, v_smxk, v_smyk + 1);
          }
          
        }
        
        //Gegner kommt vom Westen
        else if (v_gri [v_j] == 4) 
        {
          v_gri [v_j] = 3;
          
          if ((v_lvldat [v_smk - 20] != 6) &&
              (v_lvldat [v_smk - 20] != 2) &&
              (v_lvldat [v_smk - 20] != 7) &&
              (v_lvldat [v_smk - 20] != 3)) 
          {
            p_player_setSprite (v_sxk, v_syk - 8, v_smxk, v_smyk - 1);
          }
          else if ((v_lvldat [v_smk + 1] != 6) &&
                  (v_lvldat [v_smk + 1] != 2) &&
                  (v_lvldat [v_smk + 1] != 7) &&
                  (v_lvldat [v_smk + 1] != 3))
          {
            p_player_setSprite (v_sxk + 8, v_syk, v_smxk + 1, v_smyk);
          }
          else if ((v_lvldat [v_smk + 20] != 6) &&
                  (v_lvldat [v_smk + 20] != 2) &&
                  (v_lvldat [v_smk + 20] != 7) &&
                  (v_lvldat [v_smk + 20] != 3))
          {
            p_player_setSprite (v_sxk, v_syk + 8, v_smxk, v_smyk + 1);
          }
        }
    }
    else if ((v_gflag [v_j] == 3) && (v_smk == v_gmk [v_j]))
    {
      if (v_gri [v_j] == 6)
      {
        v_slp = v_slp - v_gtp [v_j]; v_trefferlooptime = 0;
        v_gegnerlooptime = v_gspeed - 1; 
      }
    }
  }
}


//Setz Gegner (Nr, 1. Tile, 2. Tile, XK, YK, Flag, Richtung, LP, TP)
void p_gegner_set (UINT8 v_sprinr, UINT8 v_sprftile, UINT8 v_sprltile, UINT8 v_sprx, UINT8 v_spry, 
                   UINT8 v_sprflag, UINT8 v_sprri, UINT8 v_sprlp, UINT8 v_sprtp) __banked
{
          v_gtp [v_sprinr] = v_sprtp; v_glp [v_sprinr] = v_sprlp; v_gxk [v_sprinr] = v_sprx; 
          v_gyk [v_sprinr] = v_spry; v_gflag [v_sprinr] = v_sprflag; v_gri [v_sprinr] = v_sprri;
          v_gftile [v_sprinr] = v_sprftile; v_gltile [v_sprinr] = v_sprltile;
          
          v_kampf = TRUE;
          
          v_gegnerlooptime = v_gspeed - 1;
          
          if (v_sprri == 1) set_sprite_tile  (9 + v_sprinr, v_gftile [v_sprinr]);
          if (v_sprri == 2) set_sprite_tile  (9 + v_sprinr, v_gltile [v_sprinr]);
          if (v_sprri == 3) set_sprite_tile  (9 + v_sprinr, v_gftile [v_sprinr]);
          if (v_sprri == 4) set_sprite_tile  (9 + v_sprinr, v_gltile [v_sprinr]);
          if (v_sprri == 5) set_sprite_tile  (9 + v_sprinr, v_gftile [v_sprinr]);
          if (v_sprri == 6) set_sprite_tile  (9 + v_sprinr, v_gltile [v_sprinr]);

          move_sprite (9 + v_sprinr, v_gxk [v_sprinr], v_gyk [v_sprinr]);
}

///Stachelbewegung Gegner
void p_gegner_stachel (void) __banked
{
  for (v_i = 1; v_i <= v_mg; ++v_i) 
  {
    if (v_gflag [v_i] == 3)
    {
      v_gmk [v_i] = ((v_gxk [v_i] - 8) / 8) + 20 * ((v_gyk [v_i] - 16) / 8);

      if (v_gri [v_i] == 5)
      {
        set_sprite_tile (9 + v_i, v_gltile [v_i]);
        v_gri [v_i] = 6; 
      }
      else if (v_gri [v_i] == 6)
      {
        set_sprite_tile (9 + v_i, v_gftile [v_i]);
        v_gri [v_i] = 5;
      }
    }
  }
}

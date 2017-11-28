/*
** tekline.c for  in /home/le-mau_f/Desktop/wolf3d
** 
** Made by Zouz Le Maux
** Login   <le-mau_f@epitech.net>
** 
** Started on  Sat May 28 00:32:45 2016 Zouz Le Maux
** Last update Sun Jun  5 16:20:01 2016 Zouz Le Maux
*/

#include <lapin.h>
#include "struct.h"
#include "ft.h"

static void		init_val(t_bunny_position *pos,
			 float *tot,
                         t_bunny_position *tmp_pos)
{
  tmp_pos->x = pos->x;
  tmp_pos->y = pos->y;
  tot[0] = (float)((pos + 1)->x - pos->x);
  tot[1] = (float)((pos + 1)->y - pos->y);
  tot[3] = 0;
  if (tot[0] != 0)
    tot[2] = tot[1] / tot[0];
}

void			tekline(t_bunny_pixelarray *pix,
                                 t_bunny_position *pos,
                                 t_color *color)
{
  float			tot[4];
  t_bunny_position	tmp_pos;

  init_val(pos, tot, &tmp_pos);
  if (tot[0] == 0)
    {
      while (tmp_pos.y != (pos + 1)->y)
        {
          tmp_pos.y = (tot[1] > 0) ? tmp_pos.y + 1 : tmp_pos.y - 1;
          tekpixel(pix, &tmp_pos, color);
        }
      return ;
    }
  while (tmp_pos.x != (pos + 1)->x)
    {
      tekpixel(pix, &tmp_pos, color);
      tot[3] = tot[3] + tot[2];
      while (tot[3] < -1 || tot[3] >= 1)
        {
          tekpixel(pix, &tmp_pos, color);
          tmp_pos.y = (tot[1] >= 0) ? tmp_pos.y + 1 : tmp_pos.y - 1;
          tot[3] = (tot[3] > 0) ? tot[3] - 1 : tot[3] + 1;
        }
      tmp_pos.x = (tot[0] > 0) ? tmp_pos.x + 1 : tmp_pos.x - 1;
    }
}

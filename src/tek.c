/*
** tek.c for  in /home/fabian/rendu/lib_lapin/wolf3d/src
** 
** Made by Zouz
** Login   <fabian@epitech.net>
** 
** Started on  Tue May 24 08:47:01 2016 Zouz
** Last update Sun Jun  5 16:19:36 2016 Zouz Le Maux
*/

#include <lapin.h>
#include "struct.h"

void		tekpixel(t_bunny_pixelarray *pix,
                         t_bunny_position *pos,
                         t_color *color)
{
  unsigned int	*pic;

  pic = pix->pixels;
  if (pos->x <= pix->clipable.buffer.width &&
      pos->x >= 0 &&
      pos->y >= 0 &&
      pos->y < pix->clipable.buffer.height)
    pic[pos->y * pix->clipable.buffer.width + pos->x] =
      color->full;
}

void			putsqr(t_bunny_pixelarray *pix,
                               t_bunny_position *pos,
                               unsigned int color,
			       t_map *map)
{
  t_color		tmp;
  int			i;
  int			j;

  tmp.full = color;
  i = pos->x;
  j = pos->y;
  while (pos->y < (j + map->bloc_size_y))
    {
      pos->x = i;
      while (pos->x < (i + map->bloc_size_x))
        {
          tekpixel(pix, pos, &tmp);
          ++pos->x;
        }
      ++pos->y;
    }
}

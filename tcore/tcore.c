/*
** putplayer.c for  in /home/le-mau_f/Desktop/wolf3d/src
** 
** Made by Zouz Le Maux
** Login   <le-mau_f@epitech.eu>
** 
** Started on  Thu May 26 11:59:00 2016 Zouz Le Maux
** Last update Sun Jun  5 19:07:35 2016 Zouz Le Maux
*/

#include <lapin.h>
#include <math.h>

void		go(t_bunny_position *curpos, double angle,
		   t_bunny_position *newpos, int move)
{
  newpos->x = cos(angle) * move + curpos->x;
  newpos->y = sin(angle) * move + curpos->y;
}

double		vecnorm(t_bunny_position *coord0,
			t_bunny_position *coord1)
{
  return (sqrt(((coord1->x - coord0->x) *
		(coord1->x - coord0->x))
	       + ((coord1->y - coord0->y) *
		  (coord1->y - coord0->y))));
}

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


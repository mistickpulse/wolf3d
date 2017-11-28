/*
** environment.c for  in /home/le-mau_f/Desktop/wolf3d/src
** 
** Made by Zouz Le Maux
** Login   <le-mau_f@epitech.net>
** 
** Started on  Mon May 30 17:54:10 2016 Zouz Le Maux
** Last update Sun Jun  5 16:04:59 2016 Zouz Le Maux
*/

#include <lapin.h>
#include "ft.h"
#include "struct.h"
#include "macro.h"

static void			fill(t_wolf *wolf,
				     t_bunny_position *pos,
				     t_bunny_position *ref_pos,
				     t_color *color)
{
  while (pos->y != ref_pos->y)
    {
      pos->x = 0;
      while (pos->x != ref_pos->x)
	{
	  tekpixel(wolf->graph->pix, pos, color);
	  ++pos->x;
	}
      ++pos->y;
    }
}

static void			draw_sky(t_wolf *wolf)
{
  t_bunny_position	pos;
  t_bunny_position	ref_pos;
  t_color		color;

  color.full = SKY_COLOR;
  ref_pos.x = WIN_SIZE_X;
  ref_pos.y = (WIN_SIZE_Y / 2);
  pos.y = 0;
  pos.x = 0;
  fill(wolf, &pos, &ref_pos, &color);
}

static void			draw_floor(t_wolf *wolf)
{
  t_bunny_position	pos;
  t_bunny_position	ref_pos;
  t_color		color;

  color.full = FLOOR_COLOR;
  ref_pos.x = WIN_SIZE_X;
  ref_pos.y = WIN_SIZE_Y;
  pos.x = 0;
  pos.y = (WIN_SIZE_Y / 2);
  fill(wolf, &pos, &ref_pos, &color);
}

void			draw_environment(t_wolf *wolf)
{
  draw_sky(wolf);
  draw_floor(wolf);
}

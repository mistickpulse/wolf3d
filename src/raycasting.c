/*
** raycasting.c for  in /home/le-mau_f/Desktop/wolf3d/src
** 
** Made by Zouz Le Maux
** Login   <le-mau_f@epitech.net>
** 
** Started on  Fri Jun  3 00:41:27 2016 Zouz Le Maux
** Last update Sat Jun  4 17:34:59 2016 Zouz Le Maux
*/

#include <lapin.h>
#include "struct.h"
#include "macro.h"
#include "ft.h"

void			draw(t_wolf *wolf, int x, int dist)
{
  t_bunny_position	pos;
  t_color		color;
  int			size_wall;
  int			endline;

  color.full = YELLOW;
  size_wall = WIN_SIZE_Y / 2 / dist;
  pos.x = x;
  pos.y = -size_wall / 2 + WIN_SIZE_Y / 2;
  endline = size_wall / 2 + WIN_SIZE_Y / 2;
  if (pos.y < 0)
    size_wall = 0;
  if (endline > WIN_SIZE_Y)
    endline = WIN_SIZE_Y - 1;
  while (pos.y < endline)
    {
      tekpixel(wolf->graph->pix, &pos, &color);
      ++pos.y;
    }
}

int			to_hit(t_wolf *wolf, double angle)
{
  t_bunny_position	curr_pos;
  t_bunny_position	new_pos;
  int			dist;

  dist = 0;
  curr_pos.x = wolf->camera_pos->camera_pos.x;
  curr_pos.y = wolf->camera_pos->camera_pos.y;
  while (wolf->map->data[curr_pos.y / wolf->map->bloc_size_y]
	 [curr_pos.x / wolf->map->bloc_size_x] != 1)
    {
      go(&curr_pos, angle, &new_pos, STEP_HIT);
      if ((new_pos.x / wolf->map->bloc_size_x) > 0 &&
          (new_pos.x / wolf->map->bloc_size_x) < wolf->map->width &&
          (new_pos.y / wolf->map->bloc_size_y) > 0 &&
          (new_pos.y / wolf->map->bloc_size_y) < wolf->map->height)
	{
	  curr_pos.x = new_pos.x;
	  curr_pos.y = new_pos.y;
	}
      else
	{
	  if (dist == 0)
	    dist = 1;
	  break;
	}
      ++dist;
    }
  return (dist);
}

void		raycasting(t_wolf *wolf)
{
  int		x;
  int		dist;
  double	field;
  double	angle;

  angle = wolf->camera_pos->camera_angle / 2;
  field = CAMERA_FIELD_R / WIN_SIZE_X;
  x = 0;
  while (x < WIN_SIZE_X)
    {
      dist = to_hit(wolf, angle);
      draw(wolf, x, dist);
      angle += field;
      ++x;
    }
}

/*
** putplayer.c for  in /home/le-mau_f/Desktop/wolf3d/src
** 
** Made by Zouz Le Maux
** Login   <le-mau_f@epitech.eu>
** 
** Started on  Thu May 26 11:59:00 2016 Zouz Le Maux
** Last update Sun Jun  5 16:18:59 2016 Zouz Le Maux
*/

#include <lapin.h>
#include <math.h>
#include "struct.h"
#include "ft.h"

void		go(t_bunny_position *curpos, double angle,
		   t_bunny_position *newpos, int move)
{
  newpos->x = cos(angle) * move + curpos->x;
  newpos->y = sin(angle) * move + curpos->y;
}

int		init_camera_pos(t_wolf *wolf)
{
  wolf->camera_pos->camera_pos.x =
    ((wolf->map->player.pos_x * wolf->map->bloc_size_x)
     + (wolf->map->bloc_size_x / 2));
  wolf->camera_pos->camera_pos.y =
    ((wolf->map->player.pos_y * wolf->map->bloc_size_y)
     + (wolf->map->bloc_size_y / 2));
  if (wolf->map->data[wolf->map->player.pos_y][wolf->map->player.pos_x] != 0)
    return (-1);
  return (0);
}

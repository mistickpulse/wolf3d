/*
** mouvement.c for  in /home/le-mau_f/Desktop/wolf3d/src
** 
** Made by Zouz Le Maux
** Login   <le-mau_f@epitech.net>
** 
** Started on  Tue May 31 16:51:31 2016 Zouz Le Maux
** Last update Sun Jun  5 16:17:01 2016 Zouz Le Maux
*/

#include <lapin.h>
#include <math.h>
#include "struct.h"
#include "macro.h"
#include "ft.h"

static void		mouv_2(t_bunny_keysym key, t_wolf *wolf)
{
  if (key == BKS_RIGHT)
    {
      wolf->camera_pos->camera_angle += 0.1;
      wolf->map->player.angle += 0.1;
    }
  if (key == BKS_LEFT)
    {
      wolf->camera_pos->camera_angle -= 0.1;
      wolf->map->player.angle -= 0.1;
    }
}

void			mouvement(t_bunny_keysym key, t_wolf *wolf)
{  
  t_bunny_position	newpos;

  if (key == BKS_UP || key == BKS_DOWN)
    {
      if (key == BKS_UP)
	go(&wolf->camera_pos->camera_pos,
	   wolf->map->player.angle + M_PI, &newpos, STEPE);
      else if (key == BKS_DOWN)
	go(&wolf->camera_pos->camera_pos, wolf->map->player.angle,
	   &newpos, STEPE);
      if ((newpos.x / wolf->map->bloc_size_x) > 0 &&
	  (newpos.x / wolf->map->bloc_size_x) < wolf->map->width &&
	  (newpos.y / wolf->map->bloc_size_y) > 0 &&
	  (newpos.y / wolf->map->bloc_size_y) < wolf->map->height)
	{
	  wolf->camera_pos->camera_pos.x = newpos.x;
	  wolf->camera_pos->camera_pos.y = newpos.y;
	}
    }
  mouv_2(key, wolf);
}

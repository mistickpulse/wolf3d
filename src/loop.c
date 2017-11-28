/*
** loop.c for  in /home/le-mau_f/Desktop/wolf3d/src
** 
** Made by Zouz Le Maux
** Login   <le-mau_f@epitech.net>
** 
** Started on  Thu May 26 03:57:56 2016 Zouz Le Maux
** Last update Sun Jun  5 16:14:54 2016 Zouz Le Maux
*/

#include <stdio.h>
#include <lapin.h>
#include "ft.h"
#include "struct.h"
#include "macro.h"

static void		get_wiew(t_wolf *wolf)
{
  t_bunny_position	tmp[2];
  t_color		color;

  color.full = RED;
  tmp[0].x = wolf->camera_pos->camera_pos.x;
  tmp[0].y = wolf->camera_pos->camera_pos.y;
  go(&wolf->camera_pos->camera_pos,
     wolf->camera_pos->camera_angle + wiew, &(tmp[1]), STEPE);
  tekline(wolf->graph->pix, tmp, &color);
  go(&wolf->camera_pos->camera_pos,
     wolf->camera_pos->camera_angle - wiew, &(tmp[1]), STEPE);
  tekline(wolf->graph->pix, tmp, &color);
}

static void		tmp(t_wolf *wolf)
{
  t_bunny_position	pos[2];
  t_color		col[2];

  col[0].full = RED;
  col[1].full = BLUE;
  pos[0].x = wolf->camera_pos->camera_pos.x;
  pos[0].y = wolf->camera_pos->camera_pos.y;
  go(&(pos[0]), wolf->camera_pos->camera_angle, &(pos[1]), STEPE);
  tekline(wolf->graph->pix, pos, &(col[1]));
  get_wiew(wolf);
}

static void		set_pos(t_wolf *wolf)
{
  wolf->map->data[wolf->map->player.pos_y][wolf->map->player.pos_x] = 0;
  wolf->map->player.pos_x =
    wolf->camera_pos->camera_pos.x / wolf->map->bloc_size_x;
  wolf->map->player.pos_y =
    wolf->camera_pos->camera_pos.y / wolf->map->bloc_size_y;
  wolf->map->data[wolf->map->player.pos_y][wolf->map->player.pos_x] = 2;
}

t_bunny_response	loop(void *data)
{
  t_wolf		*wolf;

  wolf = (t_wolf *)data;
  tmp(wolf);
  set_pos(wolf);
  draw_environment(wolf);
  raycasting(wolf);
  //mini_map(wolf);
  bunny_blit(&wolf->graph->win->buffer,
	     &wolf->graph->pix->clipable, NULL);
  bunny_display(wolf->graph->win);
  return (GO_ON);
}

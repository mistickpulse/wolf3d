/*
** wolf3d.c for  in /home/fabian/rendu/lib_lapin/wolf3d/src
** 
** Made by Zouz
** Login   <fabian@epitech.net>
** 
** Started on  Mon May 23 22:47:52 2016 Zouz
** Last update Sun Jun  5 16:15:06 2016 Zouz Le Maux
*/

#include <unistd.h>
#include <stdio.h>
#include <lapin.h>
#include "struct.h"
#include "macro.h"
#include "ft.h"

int			mini_map(t_wolf *wolf)
{
  t_bunny_position   	pos;
  int			i;
  int			j;

  j = 0;
  while (j < wolf->map->height)
    {
      i = 0;
      while (i < wolf->map->width)
	{
	  pos.x = (wolf->map->bloc_size_x * i);
	  pos.y = (wolf->map->bloc_size_y * j);
	  if (wolf->map->data[j][i] == 1)
	    putsqr(wolf->graph->pix, &pos, WHITE, wolf->map);
	  else if (wolf->map->data[j][i] == 0)
	    putsqr(wolf->graph->pix, &pos, BLACK, wolf->map);
	  ++i;
	}
      ++j;
    }
  return (0);
}

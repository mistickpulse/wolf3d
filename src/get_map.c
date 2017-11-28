/*
** get_map.c for  in /home/fabian/rendu/lib_lapin/wolf3d/src
** 
** Made by Zouz
** Login   <fabian@epitech.net>
** 
** Started on  Wed May 18 17:33:00 2016 Zouz
** Last update mar. nov. 28 22:18:30 2017 ROTARU Iulian
*/

#include "lapin.h"
#include <stdlib.h>
#include "struct.h"
#include "macro.h"
#include "ft.h"

static int		get_mapdef(t_bunny_ini *ini, t_map *map)
{
  if (((map->name = bunny_ini_get_field(ini, LVL, F_NAME, 0)) == NULL) ||
  ((map->height = my_constgetnbr(bunny_ini_get_field(ini, LVL, F_HEIGHT, 0))) == -1) ||
  ((map->width = my_constgetnbr(bunny_ini_get_field(ini, LVL, F_WIDTH, 0))) == -1))
    return (-1);
  return (0);
}

static int		get_player_pos(t_bunny_ini *ini, t_map *map)
{
  if ((((map->player.pos_x = my_constgetnbr(bunny_ini_get_field(ini, LVL, F_START_POS, 0))) == -1) ||
  ((map->player.pos_y = my_constgetnbr(bunny_ini_get_field(ini, LVL, F_START_POS, 1))) == -1)
  (map->player.angle = my_getfloat(bunny_ini_get_field(ini, LVL, F_START_POS, 2))) == -1))
    return (-1);
  return (0);
}

static int		get_map_info(t_bunny_ini *ini, t_map *map)
{
  if ((map->tile_size = my_constgetnbr(bunny_ini_get_field(ini, LVL, F_TILE_SIZE, 0))) == -1)
    return (-1);
  return (0);
}

int		**malloc_tab(t_map *map)
{
  int			i;
  int			**tmp_map;

  if ((tmp_map =
       bunny_malloc(sizeof(int *) * (map->height + 1))) == NULL)
    return (NULL);
  i = 0;
  while (i < map->height)
    {
      if ((tmp_map[i] =
	   bunny_malloc(sizeof(int) * (map->width + 1))) == NULL)
	return (NULL);
      ++i;
    }
  return (tmp_map);
}

t_map			*get_map(const char *path)
{
  t_bunny_ini		*ini;
  t_map			*map;

  if (((map = bunny_malloc(sizeof(t_map))) == NULL) ||
    ((ini = bunny_load_ini(path)) == NULL) ||
    ((get_mapdef(ini, map)) == -1) ||
    ((get_map_info(ini, map)) == -1) ||
    ((get_map_cor(ini, map)) == -1) ||
    ((get_player_pos(ini, map)) == -1))
    return (NULL);
  return (map);
}

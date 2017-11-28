/*
** get_map_2.c for  in /home/le-mau_f/Desktop/wolf3d/src
** 
** Made by Zouz Le Maux
** Login   <le-mau_f@epitech.net>
** 
** Started on  Sun Jun  5 16:07:08 2016 Zouz Le Maux
** Last update mar. nov. 28 22:13:43 2017 ROTARU Iulian
*/

#include <lapin.h>
#include "struct.h"
#include "ft.h"
#include "macro.h"

int              get_map_cor(t_bunny_ini *ini, t_map *map)
{
  int                   i;
  int                   j;
  int                   glob_count;

  if ((map->data = malloc_tab(map)) == NULL)
    return (-1);
  map->map_size = map->width * map->height;
  j = 0;
  glob_count = 0;
  while (j < map->height)
    {
      i = 0;
      while (i < map->width)
        {
          if ((map->data[j][i] =
               my_constgetnbr(bunny_ini_get_field(ini, LVL, F_DATA, glob_count))) == -1)
            return (-1);
          ++i;
          ++glob_count;
        }
      ++j;
    }
  return (0);
}

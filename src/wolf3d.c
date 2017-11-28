/*
** wolf3d.c for  in /home/le-mau_f/Desktop/wolf3d/src
** 
** Made by Zouz Le Maux
** Login   <le-mau_f@epitech.net>
** 
** Started on  Thu May 26 03:41:49 2016 Zouz Le Maux
** Last update Sun Jun  5 18:59:09 2016 Zouz Le Maux
*/

#include <unistd.h>
#include <lapin.h>
#include "ft.h"
#include "macro.h"
#include "struct.h"

static void		clean_map(t_wolf *wolf)
{
  int			i;

  i = 0;
  while (i < wolf->map->height)
    {
      bunny_free(wolf->map->data[i]);
      ++i;
    }
  bunny_free(wolf->map->data);
}

static void		clean_all(t_wolf *wolf)
{
  clean_map(wolf);
  bunny_free(wolf->map);
  bunny_free(wolf->camera_pos);
  bunny_free(wolf->ray);
}


static int		init(t_wolf *wolf, const char *path)
{
  if ((wolf->map = get_map(path)) == NULL)
    return (-1);
  if ((wolf->camera_pos = bunny_malloc(sizeof(t_camera_pos))) == NULL)
    return (-1);
  wolf->camera_pos->camera_angle = wolf->map->player.angle;
  if ((wolf->graph->pix =
       bunny_new_pixelarray(WIN_SIZE_X, WIN_SIZE_Y)) == NULL)
    return (-1);
  if ((wolf->graph->win =
       bunny_start(WIN_SIZE_X, WIN_SIZE_Y, 1, wolf->map->name)) == NULL)
    return (-1);
  wolf->map->bloc_size_x = WIN_SIZE_X / wolf->map->width;
  wolf->map->bloc_size_y = WIN_SIZE_Y / wolf->map->height;
  if ((init_camera_pos(wolf)) == -1)
    return (-1);
  if ((wolf->ray = bunny_malloc(sizeof(t_raycast))) == NULL)
    return (-1);
  wolf->ray->posx =
    wolf->camera_pos->camera_pos.x / wolf->map->bloc_size_x;
  wolf->ray->posy =
    wolf->camera_pos->camera_pos.y / wolf->map->bloc_size_y;
  bunny_set_loop_main_function(loop);
  bunny_set_key_response(keyboard);
  return (0);
}

int		wolf3d(t_wolf *wolf, const char *path)
{
  t_bunny_music	*music;

  if ((music = bunny_malloc(sizeof(*music))) == NULL)
    return (-1);
  if ((init(wolf, path)) != 0)
    return (-1);
  if ((music = bunny_load_music("./son/son.ogg")) == NULL)
    return (-1);
  write(2, "Ryuu-ga, Wa-ga-te-ki-wo, Ku-ra-u\n", 33);
  bunny_sound_play(&music->sound);
  bunny_loop(wolf->graph->win, FPS, wolf);
  bunny_stop(wolf->graph->win);
  bunny_delete_sound(&music->sound);
  bunny_delete_clipable(&wolf->graph->pix->clipable);
  clean_all(wolf);
  return (0);
}

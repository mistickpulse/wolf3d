/*
** struct.h for  in /home/fabian/rendu/lib_lapin/wolf3d/include
** 
** Made by Zouz
** Login   <fabian@epitech.net>
** 
** Started on  Tue May 17 17:52:22 2016 Zouz
** Last update Sun Jun  5 17:26:15 2016 Zouz Le Maux
*/

#ifndef STRUCT_H_
# define STRUCT_H_

#include <lapin.h>

typedef struct		s_draw
{
  double       		linehigh;
  double       		startline;
  double       		endline;
}			t_draw;

typedef struct		s_vector
{
  double       		dirx;
  double       		diry;
  double       		planex;
  double       		planey;
  double		sidedistx;
  double		sidedisty;
  double		deltadistx;
  double		deltadisty;
  double		perpwalldist;
}			t_vector;

typedef struct		s_raycast
{
  double		camerax;
  double		raydirx;
  double		raydiry;
  t_vector		vector;
  t_draw		draw;
  double       		stepx;
  double       		stepy;
  double       		hit;
  double       		side;
  double		rayposx;
  double		rayposy;
  double		posx;
  double		posy;
  int			mapx;
  int			mapy;
}			t_raycast;

typedef struct		s_camera_pos
{
  t_bunny_position	camera_pos;
  double		camera_angle;
}			t_camera_pos;

typedef struct		s_player_pos
{
  int			pos_x;
  int			pos_y;
  double       		angle;
}			t_player_pos;

typedef struct		s_graph
{
  t_bunny_pixelarray	*pix;
  t_bunny_window	*win;
}			t_graph;

typedef struct 		s_map
{
  int			**data;
  const char		*name;
  int			tile_size;
  int			width;
  int			height;
  int			map_size;
  int       		bloc_size_x;
  int       		bloc_size_y;
  t_player_pos		player;
}			t_map;

typedef struct		s_wolf
{
  t_map			*map;
  t_camera_pos		*camera_pos;
  t_graph		*graph;
  t_raycast		*ray;
}			t_wolf;

#endif /* !STRUCT_H_ */

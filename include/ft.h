/*
** ft.h for  in /home/fabian/rendu/lib_lapin/wolf3d/include
** 
** Made by Zouz
** Login   <fabian@epitech.net>
** 
** Started on  Wed May 18 19:11:42 2016 Zouz
** Last update Sun Jun  5 16:11:08 2016 Zouz Le Maux
*/

#ifndef FT_H_
#define FT_H_

#include <lapin.h>
#include "struct.h"

int			**malloc_tab(t_map *);
int			get_map_cor(t_bunny_ini *, t_map *);
void			mouvement(t_bunny_keysym, t_wolf *);
void			raycasting(t_wolf *);
void			draw_environment(t_wolf *);
void			putsqr(t_bunny_pixelarray *,
			       t_bunny_position *,
			       unsigned int ,
			       t_map *);
void			tekpixel(t_bunny_pixelarray *,
				 t_bunny_position *,
				 t_color *);
void			go(t_bunny_position *, double,
			   t_bunny_position *, int);
void			tekline(t_bunny_pixelarray *, t_bunny_position *, t_color *);
char			*my_strdup(const char *);
t_map			*get_map(const char *);
int			my_getnbr(char *);
int			my_strlen(char *);
int			my_strcpy(char *, char *);
int			my_constgetnbr(const char *);
int			wolf3d(t_wolf *, const char *);
int			mini_map(t_wolf *);
int			init_camera_pos(t_wolf *);
double			my_getfloat(const char *);
t_bunny_response 	loop(void *);
t_bunny_response	keyboard(t_bunny_event_state,
				 t_bunny_keysym,
				 void *);

#endif /* !FT_H_*/

/*
** keyboard.c for  in /home/le-mau_f/Desktop/wolf3d/src
** 
** Made by Zouz Le Maux
** Login   <le-mau_f@epitech.net>
** 
** Started on  Thu May 26 03:44:07 2016 Zouz Le Maux
** Last update Sun Jun  5 16:13:02 2016 Zouz Le Maux
*/

#include <lapin.h>
#include <math.h>
#include "macro.h"
#include "struct.h"
#include "ft.h"

static t_bunny_response		set_mouv(t_bunny_keysym key,
					 t_wolf *wolf)
{
  if (key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  mouvement(key, wolf);
  return (GO_ON);
}

t_bunny_response		keyboard(UNUSED t_bunny_event_state stat,
				 t_bunny_keysym key,
				 void *data)
{
  t_wolf			*wolf;

  wolf = (t_wolf *)data;
  if ((set_mouv(key, wolf)) == EXIT_ON_SUCCESS)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

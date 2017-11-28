/*
** main.c for  in /home/fabian/rendu/lib_lapin/wolf3d
** 
** Made by Zouz
** Login   <fabian@epitech.net>
** 
** Started on  Wed May 18 19:04:59 2016 Zouz
** Last update Sun Jun  5 17:36:35 2016 Zouz Le Maux
*/

#include <lapin.h>
#include <stdio.h>
#include <unistd.h>
#include "struct.h"
#include "ft.h"

int		main(int ac, char **av)
{
  t_wolf	wolf;

  bunny_set_maximum_ram(20971520);
  if (ac != 2)
    return (-1);
  if ((wolf3d(&wolf, av[1])) != 0)
    {
      write(2, "Ryuu-ga, Wa-ga-te-ki-wo, Ku-ra-u\n", 33);
      return (-1);
    }
  bunny_set_memory_check(true);
  return (0);
}

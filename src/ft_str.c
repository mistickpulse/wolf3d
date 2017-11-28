/*
** ft_str.c for  in /home/fabian/rendu/lib_lapin/wolf3d
** 
** Made by Zouz
** Login   <fabian@epitech.net>
** 
** Started on  Wed May 18 21:26:25 2016 Zouz
** Last update mar. nov. 28 22:13:28 2017 ROTARU Iulian
*/

#include <lapin.h>

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  if (!str)
    return (-1);
  while (str[i])
    ++i;
  return (i);
}

char		*my_strcpy(char *dest, char *src)
{
  while ((*src)++ && (*dest)++)
    *dest = *src;
  *dest = 0;
  return (dest);
}

char		*my_strdup(char *str)
{
  char		*ret;

  if ((ret = bunny_malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  if ((ret = my_strcpy(ret, str)) == NULL)
    return (NULL);
  return (ret);
}

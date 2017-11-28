/*
** my_getfloat.c for  in /home/fabian/rendu/lib_lapin/wolf3d
** 
** Made by Zouz
** Login   <fabian@epitech.net>
** 
** Started on  Mon May 23 20:01:03 2016 Zouz
** Last update Mon May 23 20:03:10 2016 Zouz
*/

#include <stdio.h>

double		get_dec(const char *str, int i)
{
  double       	flag;
  float       	res_2;

  res_2 = 0;
  flag = 1;
  ++i;
  while (str[i])
    {
      flag = flag / 10;
      if (str[i] >= '0' && str[i] <= '9')
	res_2 = res_2 * 10 + (str[i] - '0');
      ++i;
    }
  return (res_2 * flag);
}

double		my_getfloat(const char *str)
{
  int		i;
  double       	res;

  res = 0;
  i = 0;
  while (str[i])
    {
      if (str[i] == '.')
	{
	  res += get_dec(str, i);
	  break ;
	}
      else if (str[i] >= '0' && str[i] <= '9')
	res = res * 10 + (str[i] - '0');
      ++i;
    }
  return (res);
}

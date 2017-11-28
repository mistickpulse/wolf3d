/*
** my_getnbr.c for  in /home/le-mau_f/rendu/Piscine_C_J04
** 
** Made by Zouz Le Maux
** Login   <le-mau_f@epitech.net>
** 
** Started on  Sun Mar  6 11:33:03 2016 Zouz Le Maux
** Last update Sun Jun  5 16:18:29 2016 Zouz Le Maux
*/

int	my_count_neg(char *str)
{
  int 	count;
  int 	i;

  i = 0;
  count = 0;
  while (str[i])
    {
      if (str[i] == '-')
	{
	  count = count + 1;
	}
      i = i + 1;
    }
  if ((count % 2) == 0)
    return (0);
  else
    return (1);
}

int	my_getnbr(char *str)
{
  int	temoin_1;
  int	i;
  int	nbr;

  nbr = 0;
  i = 0;
  temoin_1 = my_count_neg(str);
  if (str != 0)
    {
      while (str[i] != '\0')
	{
	  if (str[i] > '9' && str[i] < '0' && str[i] != '-' && str[i] != '+')
	      return (nbr);
	  else if (str[i] != '-' && str[i] != '+')
	    nbr = (nbr * 10) + (str[i] - '0');
	  i = i + 1;
	}
      if (temoin_1 == 0)
	  return (nbr);
      else
	return (-nbr);
    }
  return (0);
}

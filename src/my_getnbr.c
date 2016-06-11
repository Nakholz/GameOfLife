/*
** my_getnbr.c in /home/nakholz/rendu/Github/GameOflife/src
** 
** Made by Arnholz Martin
** Login : arnhol_m
** 
** Started on  Tue Jun  9 14:39:52 2015 Martin Arnholz
** Last update Sat Jun 11 19:39:44 2016 
*/

#include "../include/my.h"

int	my_getnbr(char *str)
{
  int   i;
  int   cpt;
  int   nb;
  int   res;
  int   a;

  cpt = 1;
  i = 0;
  res = 0;
  while (str[i] != 0 && (str[i] < '0' || str[i] > '9'))
    i = i + 1;
  nb = i;
  while (str[i] != 0 && str[i] >= '0' && str[i] <= '9')
    i = i + 1;
  i--;
  while (i >= nb){
    a = str[i] - '0';
    res = res + (a * cpt);
    cpt = cpt * 10;
    i = i - 1;
  }
  if (nb > 0 && str[nb - 1] == '-')
    res = -res;
  return (res);
}

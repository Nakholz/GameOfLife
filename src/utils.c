/*
** utils.c in /home/nakholz/rendu/Github/GameOflife/src
** 
** Made by Arnholz Martin
** Login : arnhol_m
** 
** Started on  Tue Jun  9 14:43:38 2015 Martin Arnholz
** Last update Wed May 18 13:50:11 2016 
*/

#include <unistd.h>
#include "../include/my.h"

void	my_putchar(char c)
{
  write(1 ,&c ,1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}

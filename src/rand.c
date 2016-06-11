/*
** rand.c in /home/nakholz/rendu/Github/GameOflife/src
** 
** Made by Arnholz Martin
** Login : arnhol_m
**
** Started on  Tue Jun  9 14:41:02 2015 Martin Arnholz
** Last update Sat Jun 11 19:39:58 2016 
*/

#include <time.h>
#include <stdlib.h>
#include "../include/my.h"

char    **my_rand_star(int star, char **tab, char **av)
{
  int   i;
  int   j;

  srand(time(0));
  while (star > 0){
    i = rand() % my_getnbr(av[1]);
    if (i == 0)
      i++;
    j = rand() % my_getnbr(av[2]);
    if (j == 0)
      j++;
    if (tab[j][i] == '*')
      star++;
    else
      tab[j][i] = '*';
    star--;
  }
  return (tab);
}

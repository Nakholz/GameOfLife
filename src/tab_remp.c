/*
** tab_remp.c in /home/nakholz/rendu/Github/GameOflife/src
** 
** Made by Arnholz Martin
** Login : arnhol_m
** 
** Started on  Tue Jun  9 14:42:25 2015 Martin Arnholz
** Last update Sat Jun 11 19:40:26 2016 
*/

#include <unistd.h>
#include <stdlib.h>
#include "../include/my.h"

char    **my_tab_remp3(char **tab, char **av, int i)
{
  int   a;

  a = 1;
  tab[i][0] = '+';
  while (a < my_getnbr(av[1]) + 1)
    {
      tab[i][a] = '-';
      a++;
    }
  tab[i][a] = '+';
  a++;
  tab[i][a] = 0;
  return (tab);
}

char    **my_tab_remp2(char **tab, char **av)
{
  int   a;
  int   i;

  a = 0;
  i = 1;
  while (i < my_getnbr(av[2]) + 1){
      a = 0;
      while (a < my_getnbr(av[1]) + 2){
	if (a == 0)
	  tab[i][a] = '|';
	else
            tab[i][a] = ' ';
	a++;
      }
      a--;
      tab[i][a] = '|';
      tab[i][a + 1] = 0;
      i++;
  }
  tab = my_tab_remp3(tab, av, i);
  return (tab);
}

char    **my_tab_remp(char **av, int x)
{
  char  **tab;
  int   a;

  a = 1;
  if ((tab = malloc(sizeof(char*) * my_getnbr(av[2]) + 100)) == NULL)
    my_exit(1);
  while (x < my_getnbr(av[2]) + 3){
    if ((tab[x] = malloc(sizeof(char) * my_getnbr(av[1]) + 100)) == NULL)
      my_exit(1);
    x++;
  }
  tab[0][0] = '+';
  while (a < my_getnbr(av[1]) + 1){
    tab[0][a] = '-';
    a++;
  }
  tab[0][a] = '+';
  a++;
  tab[0][a] = 0;
  tab = my_tab_remp2(tab, av);
  return (tab);
}

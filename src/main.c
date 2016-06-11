/*
** main.c in /home/nakholz/rendu/Github/GameOflife/src
** 
** Made by Arnholz Martin
** Login : arnhol_m
** 
** Started on  Tue Jun  9 14:39:01 2015 Martin Arnholz
** Last update Sat Jun 11 19:39:22 2016 
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"

void    my_exit(int i)
{
  if (i == 0){
    my_putstr("Wrong argument value\n");
    exit(0);
  }
  if (i == 1){
    my_putstr("Malloc error\n");
    exit(0);
  }
  if (i == 2){
    my_putstr("Please, enter a >0 number\n");
    exit(0);
  }
}

void    my_pars_args2(char **av)
{
  int   i;
  
  i = 0;
  while (av[3][i]){
    if (av[3][i] > '9' || av[3][i] < '0'){
	my_putstr("Wrong argument value\n");
	exit(0);
    }
    i++;
  }
}

void    my_pars_args(char **av, int i)
{
  while (av[1][i]){
    if (av[1][i] > '9' || av[1][i] < '0'){
      my_putstr("Wrong argument value\n");
      exit(0);
    }
    i++;
  }
  i = 0;
  while (av[2][i]){
    if (av[2][i] > '9' || av[2][i] < '0'){
      my_putstr("Wrong argument value\n");
      exit(0);
    }
    i++;
  }
  my_pars_args2(av);
}

int     main(int ac, char **av)
{
  char  **tab;

  if (ac != 4){
    my_putstr("wrong parameter number\n");
    my_putstr("usage : lenght hight cell number\n");
    return (0);
  }
  if ((my_getnbr(av[1]) * my_getnbr(av[2])) < my_getnbr(av[3])){
    my_putstr("please enter a correct amount of cell (too big)\n");
    return (0);
  }
  my_pars_args(av, 0);
  if ((tab = my_tab_remp(av, 0)) == NULL)
    return (0);
  tab[my_getnbr(av[2]) + 2] = NULL;
  tab = my_rand_star(my_getnbr(av[3]), tab, av);
  print_tab(tab);
  algo(tab, av);
  return (0);
}

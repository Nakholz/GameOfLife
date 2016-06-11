/*
** algo.c in /home/nakholz/rendu/Github/GameOflife/src
** 
** Made by Arnholz Martin
** Login : arnhol_m
** 
** Started on  Tue Jun  9 14:37:03 2015 Martin Arnholz
** Last update Sat Jun 11 19:42:35 2016 
*/
 
#include <stdlib.h>
#include <unistd.h>
#include "../include/my.h"

void    print_tab(char **tab)
{
  int   a;

  a = 0;
  while (tab[a] != NULL){
    my_putstr(tab[a]);
    my_putchar('\n');
    a++;
  }
}

int     check_nei(char **tab, int a, int b, char **av)
{
  int   save;

  save = 0;
  if (a == 0 || b == 0 || a == my_getnbr(av[2]) + 1
      || b == my_getnbr(av[1]) + 1)
    return (0);
  if (tab[a - 1][b - 1] == '*' || (tab[a - 1][b] == '*'))
    save++;
  if (tab[a - 1][b + 1] == '*' || (tab[a][b - 1] == '*'))
    save++;
  if (tab[a][b] == '*' || (tab[a][b + 1] == '*'))
    save++;
  if (tab[a + 1][b - 1] == '*' || (tab[a + 1][b] == '*'))
    save++;
  if (tab[a + 1][b + 1] == '*')
    save++;
  return (save);
}

int     my_check_buff(char *buff)
{
  int   ret;

  ret = 0;
  if (buff[0] == '\0')
    my_exit(2);
  while (buff[ret]){
    if (buff[ret] > '9' || buff[ret] < '0')
      my_exit(2);
    ret++;
  }
  ret = my_getnbr(buff);
  return (ret);
}

char    **parser(char **tab, int a, int b, char **av)
{
  a = 0;
  while (tab[a] != NULL){
      b = 0;
      while (tab[a][b]){
          if (check_nei(tab, a, b, av) == 3)
            tab[a][b] = '*';
          else if (tab[a][b] == '*'){
	    if (check_nei(tab, a, b, av) <= 1)
	      tab[a][b] = ' ';
	    else if (check_nei(tab, a, b, av) >= 4
		       || check_nei(tab, a, b, av) <= 8)
                tab[a][b] = ' ';
            }
          b++;
        }
      a++;
    }
  usleep(1000000);
  system("clear");
  print_tab(tab);
  return (tab);
}

void    algo(char **tab, char **av)
{
  int   a;
  char  *buff;
  int   ret;

  a = 0;
  if ((buff = malloc(sizeof(char) * 4096)) == NULL)
    my_exit(1);
  while (42){
      if ((ret = read(0, buff, 4096)) != 0){
          buff[ret - 1] = 0;
          ret = my_check_buff(buff);
      }
      while (ret > 0){
	tab = parser(tab, a, 0, av);
	ret--;
      }
  }
}

/*
** my.h in /home/nakholz/rendu/Github/GameOflife/include
** 
** Made by Arnholz Martin
** Login : arnhol_m
** 
** Started on  Tue Jun  9 14:29:40 2015 Martin Arnholz
** Last update Wed May 18 13:48:03 2016 
*/

#ifndef MY_H_
#define MY_H_

void	print_tab(char **tab);
int	check_nei(char **tab, int a, int b, char **av);
void	algo(char **tab, char **av);
void	my_exit(int i);
void	my_pars_args(char **av, int i);
char    **my_tab_remp3(char **tab, char **av, int i);                                                             
char    **my_tab_remp2(char **tab, char **av);                                                                    
char    **my_tab_remp(char **av, int x);                                                                          
int     my_getnbr(char *str);                                                                                     
char    **my_rand_star(int star, char **tab, char **av);                                                          
void    my_putchar(char c);                                                                                       
void    my_putstr(char *str);

#endif


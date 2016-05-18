##
## Makefile in /home/nakholz/rendu/Github/GameOflife
## 
## Made by Arnholz Martin
## Login : arnhol_m
## 
## Started on  Tue Jun  9 14:32:15 2015 Martin Arnholz
## Last update Wed May 18 13:50:43 2016 
##

CC	= gcc

RM	= rm -rf

SRCS	= src/algo.c \
	  src/main.c \
	  src/my_getnbr.c \
	  src/rand.c \
	  src/tab_remp.c \
	  src/utils.c

CFLAGS	= -W -Wall -Wextra

OBJS	= $(SRCS:.c=.o)

NAME	= game_of_life

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

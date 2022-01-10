##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =       lib/my/my_putchar.c \
      lib/my/my_put_nbr.c \
      lib/my/my_putstr.c \
      lib/my/my_printf.c \
	  lib/my/my_strlen.c \

OBJ = my_printf.o \
	  my_put_nbr.o \
	  my_putchar.o \
	  my_putstr.o \
	  my_strlen.o \

NAME = libmy.a

NAME2 = my_ls

all: compil_lib compile_my_ls

compile_my_ls: 
	gcc -o $(NAME2) my_ls.c -Iinclude -L. -lmy

compil_lib:
	gcc -c $(SRC) -Iinclude -Llib/my
	ar rc $(NAME) $(OBJ)

clean:
	rm $(OBJ)
	rm my_ls

fclean:	clean
	rm -f $(NAME)

re:	 fclean all

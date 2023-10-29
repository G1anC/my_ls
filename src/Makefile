##
## EPITECH PROJECT, 2023
## my_ls
## File description:
## Makefile
##

NAME	=	my_ls

SRC		=	lib/my_printf/flag_maj.c \
			lib/my_printf/flag_num_de_base.c \
			lib/my_printf/flag_num.c \
			lib/my_printf/flag_strings.c \
			lib/my_printf/flag_supp.c \
			lib/my_printf/my_printf.c \
			lib/my_printf/my_put_nbr.c \
			lib/my_printf/my_putchar.c \
			lib/my_printf/my_put_float.c \
			lib/exit_error.c \
			lib/is_existing.c \
			lib/is_printable.c \
			lib/my_arrlen.c \
			lib/my_getnbr.c \
			lib/my_putstr.c \
			lib/my_str_to_word_array.c \
			lib/my_strlen.c \
			lib/my_strcat.c \
			lib/arrlen.c \
			lib/my_revstr.c \
			lib/my_revarr.c \
			lib/my_strcmp.c \
			lib/my_strcpy.c \
			lib/my_strdup.c \
			lib/my_strncat.c \
			lib/my_strncmp.c \
			lib/my_strncpy.c \
			lib/putarray.c \
			lib/split_string.c \
			main.c \
			src/error_handling.c \
			src/init.c \
			src/tools.c \
			src/ls/ls_l.c \
			src/ls/multiple.c \
			src/ls/single.c

OBJ		 =	$(SRC:.c=.o)

all: $(OBJ)
	gcc -g -o $(NAME) $(SRC)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f vgcore.*

re:	fclean all

.PHONY:	all clean fclean re

cs: fclean
	coding-style . .
	
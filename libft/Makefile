# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdiedra <sdiedra@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/02 20:55:48 by sdiedra           #+#    #+#              #
#    Updated: 2019/07/07 14:44:36 by sdiedra          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
SRCS	=	ft_atoi.c ft_isalpha.c ft_isascii.c ft_tolower.c ft_toupper.c \
			ft_isprint.c ft_isalnum.c ft_isdigit.c ft_strcmp.c ft_strlen.c \
			ft_memset.c ft_bzero.c ft_memcpy.c ft_strncmp.c ft_strcat.c \
			ft_strncat.c ft_strlcat.c ft_strcpy.c ft_strncpy.c ft_strchr.c\
			ft_strrchr.c ft_memchr.c ft_memcmp.c ft_memmove.c ft_memccpy.c\
			ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
			ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
			ft_strnequ.c ft_itoa.c ft_strtrim.c ft_strjoin.c ft_strsub.c \
			ft_strsplit.c ft_strnstr.c ft_strstr.c ft_strdup.c\
			ft_putchar.c ft_putstr.c ft_putchar_fd.c ft_putstr_fd.c \
			ft_putnbr.c ft_putnbr_fd.c ft_putendl.c ft_putendl_fd.c \
			ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
			ft_lstmap.c ft_sort_str_arr.c ft_print_str_arr.c ft_vector_init.c \
			ft_vector_free.c ft_vector_get.c ft_vector_add.c ft_vector_resize.c \
			ft_vector_delete.c ft_realloc.c ft_concat_str_arr.c get_next_line.c\
			join_lines.c ft_strndup.c ft_sqrt.c
PRINF_PATH	=	./ft_printf/
SC_PRINTF	=	chars.c create_spec.c dispatch.c dispatcher.c flags.c flags1.c \
				ft_printf.c ftoa.c itoa.c handle_char.c handle_int.c pointer.c \
				print_sp.c util.c util1.c utiltoa.c width.c ft_cage.c
OBJ		=	$(SRCS:.c=.o)
SRC_PF	=	$(addprefix $(PRINF_PATH), $(SC_PRINTF))
OBJ_PF	=	$(SC_PRINTF:.c=.o)
CC		=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@gcc $(CC) -c $(SRCS) $(SRC_PF)
	@ar rcs $(NAME) $(OBJ) $(OBJ_PF)

clean:
	@rm -f $(OBJ) $(OBJ_PF)

fclean: clean
	@rm -f $(NAME)

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 16:04:32 by chrhuang          #+#    #+#              #
#    Updated: 2019/06/24 12:03:37 by chrhuang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -I ./includes/

RM		=	rm -f

SRCS	=	ft_memset.c			\
			ft_bzero.c			\
			ft_memcpy.c			\
			ft_memccpy.c		\
			ft_memmove.c		\
			ft_memchr.c			\
			ft_memcmp.c			\
			ft_memalloc.c		\
			ft_memdel.c			\
			ft_strlen.c 		\
			ft_strdup.c			\
			ft_strcpy.c			\
			ft_strncpy.c		\
			ft_strcat.c			\
			ft_strncat.c		\
			ft_strlcat.c		\
			ft_strchr.c			\
			ft_strrchr.c		\
			ft_strstr.c			\
			ft_strnstr.c		\
			ft_strcmp.c			\
			ft_strncmp.c		\
			ft_atoi.c			\
			ft_isalpha.c		\
			ft_isdigit.c		\
			ft_isalnum.c		\
			ft_isascii.c		\
			ft_isprint.c		\
			ft_toupper.c		\
			ft_tolower.c		\
			ft_strnew.c			\
			ft_strdel.c			\
			ft_strclr.c			\
			ft_striter.c		\
			ft_striteri.c		\
			ft_strmap.c			\
			ft_strmapi.c		\
			ft_strequ.c			\
			ft_strnequ.c		\
			ft_strsub.c			\
			ft_strjoin.c		\
			ft_strtrim.c		\
			ft_strsplit.c		\
			ft_itoa.c			\
			ft_putchar.c		\
			ft_putstr.c			\
			ft_putendl.c		\
			ft_putnbr.c			\
			ft_putchar_fd.c		\
			ft_putstr_fd.c		\
			ft_putendl_fd.c		\
			ft_putnbr_fd.c		\
			ft_lstnew.c			\
			ft_lstdelone.c		\
			ft_lstdel.c			\
			ft_lstadd.c			\
			ft_lstiter.c		\
			ft_lstmap.c			\
			ft_puterr.c			\
			ft_print_tab_char.c	\
			ft_print_tab_int.c	\
			ft_tabnew.c			\
			ft_tablen.c			\
			ft_lstlen.c			\
			ft_putnbr_base.c	\
			ft_swap.c			\
			ft_atoi_base.c		\
			ft_convert_base.c	\
			ft_strjoin_free.c	\
			get_next_line.c		\
			ft_atoi_ptr.c		\
			ft_intlen.c			\
			ft_revstr.c			\
			ft_isinteger.c		\
			ft_isnumber.c		\
			ft_isspace.c

OBJS	=	$(SRCS:.c=.o)

$(NAME):	$(OBJS)
	@ar rc $@ $?
	@echo "libft build"

%.o:	%.c
	@$(CC) -o $@ -c $^ $(CFLAGS)

all: $(NAME)

clean:
	@$(RM) $(OBJS)
	@echo "libft clean"

fclean: clean
	@$(RM) $(NAME)
	@echo "libft.a clean"

re: fclean all

.PHONY: all clean fclean re

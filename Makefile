# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/14 10:21:11 by chrhuang          #+#    #+#              #
#    Updated: 2019/06/25 12:37:24 by chrhuang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT			=	libft/libft.a
CC				=	gcc
INC_DIR			=	include
LIBFT_INC_DIR	+=	libft/includes
CFLAGS			+=	-I $(INC_DIR)
CFLAGS			+=	-I $(LIBFT_INC_DIR)
CFLAGS			+=	-Wall -Wextra -Werror
RM				=	rm -f

#~~~~~~~~~~~~~~~CHECKER~~~~~~~~~~~~~~~#

CHECKER			=	checker
SRCDIR_CHECKER	=	srcs/$(CHECKER)
OBJ_CHECKER     =   $(SRC_CHECKER:.c=.o)
SRC_CHECKER		=	$(SRCDIR_CHECKER)/checker.c			\
					$(SRCDIR_CHECKER)/check_arg.c		\
					$(SRCDIR_CHECKER)/checker_loop.c	\
					$(SRCDIR_CHECKER)/free_env.c		\
					$(SRCDIR_CHECKER)/do_sa_sb_ss.c		\
					$(SRCDIR_CHECKER)/do_pa_pb.c		\
					$(SRCDIR_CHECKER)/do_ra_rb_rr.c		\
					$(SRCDIR_CHECKER)/do_rra_rrb_rrr.c	\
					$(SRCDIR_CHECKER)/is_sorted.c

#~~~~~~~~~~~~~~PUSH_SWAP~~~~~~~~~~~~~~#

PUSH_SWAP		=	push_swap
SRCDIR_PUSH_SWAP=	srcs/$(PUSH_SWAP)
OBJ_PUSH_SWAP	=	$(SRC_PUSH_SWAP:.c=.o)
SRC_PUSH_SWAP	=	$(SRCDIR_PUSH_SWAP)/push_swap.c		\
					$(SRCDIR_PUSH_SWAP)/new_elem.c		\
					$(SRCDIR_PUSH_SWAP)/free_env.c		\
					$(SRCDIR_PUSH_SWAP)/check_arg.c		\
					$(SRCDIR_PUSH_SWAP)/action.c		\
					$(SRCDIR_PUSH_SWAP)/print_action.c	\
					$(SRCDIR_PUSH_SWAP)/do_sa_sb_ss.c	\
					$(SRCDIR_PUSH_SWAP)/do_pa_pb.c		\
					$(SRCDIR_PUSH_SWAP)/do_ra_rb_rr.c	\
					$(SRCDIR_PUSH_SWAP)/do_rra_rrb_rrr.c\
					$(SRCDIR_PUSH_SWAP)/search_min_max.c\
					$(SRCDIR_PUSH_SWAP)/choose_algo.c	\
					$(SRCDIR_PUSH_SWAP)/little_sort.c	\
					$(SRCDIR_PUSH_SWAP)/is_sorted.c		\
					$(SRCDIR_PUSH_SWAP)/chunk_sort.c	\
					$(SRCDIR_PUSH_SWAP)/chunk_init.c	\
					$(SRCDIR_PUSH_SWAP)/search_rotate.c	\
					$(SRCDIR_PUSH_SWAP)/rotate_list.c

all: $(LIBFT) $(CHECKER) $(PUSH_SWAP)

$(LIBFT):
	make -C libft

$(CHECKER): $(LIBFT) $(OBJ_CHECKER)
	$(CC) -o checker $(OBJ_CHECKER) $(LIBFT)

$(PUSH_SWAP): $(LIBFT) $(OBJ_PUSH_SWAP)
	$(CC) -o push_swap $(OBJ_PUSH_SWAP) $(LIBFT)

%.o: &.c
	@$(CC) -c $@ $? $(CFLAGS)

clean:
	$(RM) $(OBJ_CHECKER) $(OBJ_PUSH_SWAP)
	make -C libft clean

fclean: clean
	$(RM) ./checker ./push_swap
	make -C libft fclean

re : fclean all

.PHONY: all clean fclean re

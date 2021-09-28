# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lverkart <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/16 14:17:30 by lverkart          #+#    #+#              #
#    Updated: 2021/04/16 14:17:33 by lverkart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECK_NAME		=	checker

PUSH_NAME		=	push_swap

FLAGS			=	-Wall -Wextra -Werror

INC				=	-Iincludes/ -I$(LIB_DIR)

CHECK_SRC_NAME	=	ft_checker_ps.c \
					ft_trans_move.c	preparation_ps.c	ft_eval_pr.c \
					ft_five_ps.c	ft_create_way.c		ft_big_ps.c \
					ft_filter.c		ft_start_filter.c	ft_trans_comands.c \
					ft_trans_comands_two.c	ft_problem_ps.c	check_utilus.c 

CHECK_OBJ_NAME	=	$(CHECK_SRC_NAME:.c=.o)
CHECK_OBJ		=	$(addprefix $(OBJ_DIR),$(CHECK_OBJ_NAME))

PUSH_SRC_NAME	=	push_swap.c \
					ft_trans_move.c	preparation_ps.c	ft_eval_pr.c \
					ft_five_ps.c	ft_create_way.c		ft_big_ps.c \
					ft_filter.c		ft_start_filter.c	ft_trans_comands.c \
					ft_trans_comands_two.c	ft_problem_ps.c	check_utilus.c 

PUSH_OBJ_NAME	=	$(PUSH_SRC_NAME:.c=.o)
PUSH_OBJ		=	$(addprefix $(OBJ_DIR),$(PUSH_OBJ_NAME))

LIB_DIR			=	libft/
SRC_DIR			=	srcs/
OBJ_DIR			=	objs/

all				:	$(CHECK_NAME) $(PUSH_NAME)

$(CHECK_NAME)	:	$(CHECK_OBJ)
	@make -C $(LIB_DIR) --silent
	@gcc -o $(CHECK_NAME) $(CHECK_OBJ) -L $(LIB_DIR) -lft

$(PUSH_NAME)	:	$(PUSH_OBJ)
	@make -C $(LIB_DIR) --silent
	@gcc -o $(PUSH_NAME) $(PUSH_OBJ) -L $(LIB_DIR) -lft

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(FLAGS) -o $@ -c $< $(INC)

clean			:
	@make -C $(LIB_DIR) clean  --silent
	@rm -f $(CHECK_OBJ) $(PUSH_OBJ)

fclean			:	clean
	@make -C $(LIB_DIR) fclean  --silent
	@rm -f $(CHECK_NAME) $(PUSH_NAME)
	@rmdir $(OBJ_DIR)

re				:	fclean all

.PHONY			:	all clean fclean re

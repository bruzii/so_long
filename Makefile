# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgervais <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 17:59:56 by bgervais          #+#    #+#              #
#    Updated: 2023/01/06 16:35:03 by bgervais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

NAME_B = so_long_bonus

SRC = src/ft_parcing_2.c src/main.c src/ft_parcing.c src/fill_map.c src/ft_handle_press.c src/ft_maj.c src/ft_algo_map.c

SRC_BONUS = src_bonus/ft_parcing_bonus2.c src_bonus/main.c src/bonus.c src_bonus/ft_parcing_bonus.c src_bonus/ft_handle_press.c src_bonus/ft_maj.c src_bonus/ft_algo_map.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

LIB_PATH = ./libft

MLX_PATH = ./mlx

LIB = -Llibft -lft

MLX = -Lmlx -lmlx

MLX_REQUIRES = -lXext -lX11 -lz

MATH = -lm

INCLUDES = ./includes

CFLAGS = -Werror -Wextra -Wall -I$(INCLUDES) -I$(MLX_PATH)  -g3

all :	$(NAME)

bonus :	$(NAME_B)

$(OBJ) :	%.o: %.c
			@ $(CC) $(CFLAGS) -c $< -o $@

$(OBJ_BONUS) :	%.o: %.c
			@ $(CC) $(CFLAGS) -c $< -o $@

$(NAME) :	$(OBJ)
			@ $(MAKE) -s -C $(MLX_PATH)
			@ $(MAKE) -s -C $(LIB_PATH)
			@ $(CC) $(CFLAGS) $(OBJ) $(MLX) $(MLX_REQUIRES) $(LIB) $(MATH) -o $(NAME)
			@ echo "\e[33m\e[1m\tMake\e[0m [🗿] : \e[1mDone ! ✅"

$(NAME_B) :		$(OBJ_BONUS)
			@ $(MAKE) -s -C $(MLX_PATH)
			@ $(MAKE) -s -C $(LIB_PATH)
			@ $(CC) $(CFLAGS) $(OBJ_BONUS) $(MLX) $(MLX_REQUIRES) $(LIB) $(MATH) -o $(NAME_B)
			@ echo "\e[33m\e[1m\tMake\e[0m [🗿] : \e[1mBonus ! 🏆"
				
clean :
		@ $(MAKE) -s clean -C $(LIB_PATH)
		@ rm -f $(OBJ) $(OBJ_BONUS) @
		@echo "\e[33m\e[1m\tMake\e[0m [🗿] : \e[1mRemove binary files .. 🧹"

fclean : clean
		@ $(MAKE) -s fclean -C $(LIB_PATH)
		@ rm -f $(NAME) $(NAME_B)
		@echo "\e[33m\e[1m\tMake\e[0m [🗿] : \e[1mRemove executable .. 🗑️"

re : 
	@echo "\e[33m\e[1m\tMake\e[0m [🗿] : \e[1mRecompile .. 🔄"
	@ $(MAKE) -s fclean $(NAME)

.PHONY: all clean fclean re

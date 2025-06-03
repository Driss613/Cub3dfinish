# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drabarza <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/27 00:45:11 by drabarza          #+#    #+#              #
#    Updated: 2025/06/02 13:57:26 by drabarza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[3;32m
GREENS = \033[7;32m
YELLOW = \033[3;33m
RED = \033[3;31m
NC = \033[0m

NAME = cub3D
CC = cc
FLAGS = -I./MLX42/include -Wall -Werror -Wextra -g

MLXFLAGS = -Iinclude -L./MLX42/build \
		   -lmlx42 -ldl -pthread -lm -Ofast \
		   -L/opt/homebrew/opt/glfw/lib -lglfw \
		   -I/opt/homebrew/opt/glfw/include

SRC =	Get_Next_Line/get_next_line.c \
		Get_Next_Line/get_next_line_utils.c\
		src/Mandatory/main.c \
		src/Mandatory/parsing/parsing.c \
		src/Mandatory/parsing/parsing_args.c \
		src/Mandatory/parsing/parsing_file.c \
		src/Mandatory/parsing/parsing_textures.c \
		src/Mandatory/parsing/color.c \
		src/Mandatory/parsing/parsing_map.c \
		src/Mandatory/parsing/map_validation.c \
		src/Mandatory/parsing/flood_fill.c \
		src/Mandatory/utils/utils_1.c \
		src/Mandatory/utils/utils_2.c \
		src/Mandatory/utils/ft_atoi.c \
		src/Mandatory/game/game.c \
		src/Mandatory/game/init_img.c \
		src/Mandatory/game/hooks.c \
		src/Mandatory/game/move.c \
		src/Mandatory/game/movement_vector.c \
		src/Mandatory/game/camera.c \
		src/Mandatory/game/raycasting.c \
		src/Mandatory/game/render_utils.c \
		src/Mandatory/game/texture_utils.c \
		src/Mandatory/game/texture_math.c \
		src/Mandatory/game/utils_game.c \
		src/Mandatory/init_free.c

SRC_BONUS =	Get_Next_Line/get_next_line.c \
		Get_Next_Line/get_next_line_utils.c\
		src/Bonus/main_bonus.c \
		src/Bonus/parsing/parsing_bonus.c \
		src/Bonus/parsing/parsing_args_bonus.c \
		src/Bonus/parsing/parsing_file_bonus.c \
		src/Bonus/parsing/parsing_textures_bonus.c \
		src/Bonus/parsing/color_bonus.c \
		src/Bonus/parsing/parsing_map_bonus.c \
		src/Bonus/parsing/map_validation_bonus.c \
		src/Bonus/parsing/flood_fill_bonus.c \
		src/Bonus/utils/utils_1_bonus.c \
		src/Bonus/utils/utils_2_bonus.c \
		src/Bonus/utils/ft_atoi_bonus.c \
		src/Bonus/game/game_bonus.c \
		src/Bonus/game/init_img_bonus.c \
		src/Bonus/game/hooks_bonus.c \
		src/Bonus/game/move_bonus.c \
		src/Bonus/game/movement_vector_bonus.c \
		src/Bonus/game/camera_bonus.c \
		src/Bonus/game/cursor_move_bonus.c \
		src/Bonus/game/raycasting_bonus.c \
		src/Bonus/game/render_utils_bonus.c \
		src/Bonus/game/texture_utils_bonus.c \
		src/Bonus/game/texture_math_bonus.c \
		src/Bonus/game/minimap_bonus.c \
		src/Bonus/game/utils_game_bonus.c \
		src/Bonus/init_free_bonus.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
CURRENT_DATE = $(shell date +"%d/%m/%Y %H:%M:%S")
MAKEFLAGS += -s

all: header mlx_build $(NAME)

bonus : header mlx_build $(NAME)_bonus

$(NAME) : $(OBJ)
	@${CC} ${FLAGS} $(OBJ) $(MLXFLAGS) -o $@

header:
	@clear
	@echo "${GREEN} ██████╗██╗   ██╗██████╗ ██████╗ ██████╗"
	@echo "██╔════╝██║   ██║██╔══██╗╚════██╗██╔══██╗"
	@echo "██║     ██║   ██║██████╔╝ █████╔╝██║  ██║"
	@echo "██║     ██║   ██║██╔══██╗ ╚═══██╗██║  ██║"
	@echo "╚██████╗╚██████╔╝██████╔╝██████╔╝██████╔╝"
	@echo " ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝"
	@echo "Compilation in progress...${NC}"

mlx_build:
	@cd MLX42 && cmake -B build
	@cd MLX42 && cmake --build build -j4

%.o : %.c
	@${CC} ${FLAGS} -c $< -o $@
	@echo "${CURRENT_DATE} ${GREENS}[CMD]${NC}${GREEN} - $(basename $<)${NC}"

$(NAME)_bonus : $(OBJ_BONUS)
	@${CC} ${FLAGS} $(OBJ_BONUS) $(MLXFLAGS) -o $@

clean:
	@echo "${RED}Cleaning object files...${NC}"
	@rm -f ${OBJ} ${OBJ_BONUS}
	@echo "${RED}Cleaning completed.${NC}"

fclean: clean
	@rm -f ${NAME} $(NAME)_bonus

re: fclean all

.PHONY: all clean fclean re header mlx_build bonus

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/24 09:37:05 by ljudd             #+#    #+#              #
#    Updated: 2025/06/05 16:14:50 by ljudd            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -MMD -MP
NAME			= fractol
INCLUDES		= -Imlx -Ilibft -Iincludes

# Sources
SRC_PATH		= src/
SRC				= fractol.c \
					color.c \
					init.c \
					render.c \
					fractals_set/mandelbrot.c \
					fractals_set/julia.c \
					fractals_set/burning_ship.c \
					fractals_set/manowar.c \
					fractals_set/phoenix.c \
					hook/key_hook.c \
					hook/mouse_hook.c \
					parser/parser_core.c \
					parser/parser_color.c \
					messages/message_core.c \
					messages/message_key.c \
					messages/message_mouse.c
SOURCES			= $(addprefix $(SRC_PATH), $(SRC))

# Objects
OBJ_PATH		= obj/
OBJ				= $(SRC:.c=.o)
OBJECTS			= $(addprefix $(OBJ_PATH), $(OBJ))
DEP				= $(SRC:.c=.d)
DEPS			= $(addprefix $(OBJ_PATH), $(DEP))

# mlx
MLX				= libmlx.a
MLX_FLAGS		= -Lmlx -lmlx -lXext -lX11 -lm -lz
MLX_DIR			= ./mlx

# libft
LIBFT			= libft.a
LIBFT_FLAGS		= -Llibft -lft
LIBFT_DIR		= ./libft

# Colors for display
RED				= \e[31m
GREEN			= \e[32m
YELLOW			= \e[33m
BLUE			= \e[34m
MAGENTA			= \e[35m
CYAN			= \e[36m
RESET			= \e[m

all: $(MLX) $(LIBFT) $(NAME)

$(NAME): $(OBJECTS)
	@printf "$(BLUE)%s$(RESET): $(YELLOW)Building $(NAME)...$(RESET)\n" $(NAME)
	@$(CC) $(CFLAGS) $(OBJECTS) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $(NAME)
	@printf "$(BLUE)%s$(RESET): $(GREEN)Successfully built $(NAME)$(RESET)\n" $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c | $(OBJ_PATH)
	@printf "$(BLUE)%s$(RESET): $(MAGENTA)Compiling$(RESET) $<\n" $(NAME)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)
	@mkdir $(OBJ_PATH)fractals_set/
	@mkdir $(OBJ_PATH)hook/
	@mkdir $(OBJ_PATH)parser/
	@mkdir $(OBJ_PATH)messages/

$(MLX):
	@make -C $(MLX_DIR) all --no-print-directory

$(LIBFT):
	@make -C $(LIBFT_DIR) all --no-print-directory

clean:
	@printf "$(BLUE)%s$(RESET): $(RED)Cleaning object files...$(RESET)\n" $(NAME)
	@rm -rf obj
	@make -C $(MLX_DIR) clean --no-print-directory
	@make -C $(LIBFT_DIR) clean --no-print-directory

fclean: clean
	@printf "$(BLUE)%s$(RESET): $(RED)Full clean...$(RESET)\n" $(NAME)
	@rm -f $(NAME)
	@rm -f $(MLX_DIR)/$(MLX)
	@make -C $(LIBFT_DIR) fclean --no-print-directory

re: fclean all

bonus: all

-include $(DEPS)

.PHONY: all clean fclean re bonus $(MLX)
.DELETE_ON_ERROR:

NAME = cub3D
HDR = cub3d.h
SRC = src/main.c \
      src/draw_utils.c src/init_mlx.c \
      src/init_game.c src/raycasting.c \
      src/raycasting2.c src/render.c \
      src/events.c src/movement.c src/minimap.c src/minimap2.c src/utils.c \
      parsing/start_parsing.c parsing/map_utils.c parsing/read_process_line.c \
      parsing/parsing_map.c parsing/parsing_player.c parsing/parsing_textures.c \
      parsing/parse_single_line.c parsing/parsing_handler.c parsing/parsing_color.c \
      utils/clean_utils.c

OBJS := $(SRC:%.c=obj/%.o)
CC = cc
LIBFT = includes/libft
CFLAGS = -Wall -Wextra -Werror -g -O2 -Iincludes -I$(LIBFT)

ifeq ($(shell uname), Darwin)
    LFLAGS = -L./minilibx_macos -lmlx -framework OpenGL -framework Appkit
else
    LFLAGS = -L./minilibx-linux -lmlx_Linux -lX11 -lXext -lXrender -lGL -lm
endif

all: libft.a $(NAME)

$(NAME): $(OBJS) libft.a
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -lft -o $(NAME) $(LFLAGS)
	@echo "\n\033[1;38;2;50;255;50mCub3D Compiled Successfully! 🎮🚀\033[0m\n"

obj/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

libft.a:
	@make -C $(LIBFT) --no-print-directory

clean:
	@rm -rf obj
	@make -C $(LIBFT) clean --no-print-directory

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT) fclean --no-print-directory
	@echo "\n\033[1;38;2;255;50;50mDeleting EVERYTHING! 🚮🚮🚮\033[0m\n"
    
re: fclean all

.PHONY: all clean fclean re libft.a

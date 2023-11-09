NAME =		cub3D

CC =		cc
CFLAGS =	-Wall -Wextra -Werror
INCLUDE = 	-I includes \
			-I libft/includes \
			-I mlx
LIB =		-Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit

RM =		rm -rf
BUILD_LIBFT = make -C libft $@

SRCS_RT_DIR =	srcs/

SRCS_DIR =		map \
				rendering \
				get_next_line \
				utils

CFILES =		main.c \
				\
				mlxset.c \
				initalize_setting.c \
				initialize_map_texture.c \
				move_player.c \
				move_direction.c \
				event_handler.c \
				\
				rendering.c \
				raycasting.c \
				fill_screen_data.c \
				\
				check_map.c \
				check_wall.c \
				create_map.c \
				parse_map.c \
				parse_rgb.c \
				split_file.c \
				\
				get_next_line.c \
				get_next_line_utils.c 

CFILES :=		$(addprefix $(SRCS_RT_DIR), $(CFILES))

SRCS = 			$(notdir $(CFILES))

OBJS_DIR = 		objs/
OBJS = 			$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

VPATH = 		$(SRCS_RT_DIR) \
				$(addprefix $(SRCS_RT_DIR), $(SRCS_DIR))

$(OBJS_DIR)%o: %c
	$(CC) $(CFLAGS) ${INCLUDE} -c $< -o $@

$(NAME): make_mandatory

all: $(NAME)

bonus: all

make_mandatory: $(OBJS)
	$(BUILD_LIBFT)
	$(CC) $(CFLAGS) $(LIB) $^ -o $(NAME)
	touch $@

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	$(RM) make_mandatory make_bonus
	$(BUILD_LIBFT)

fclean: clean
	$(RM) $(NAME)
	$(BUILD_LIBFT)

re: 
	make fclean
	make all

.PHONY: all clean fclean re bonus

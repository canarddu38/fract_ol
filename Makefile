NAME					= fract_ol
OBJ_DIR					= obj

# cc *.c minilibx-linux/*.a libft/libft.a -Ilibft -lXext -lX11 -lm -Iminilibx-linux -o3 -o fract_ol

LIBFT_PATH				= libft
MLX_PATH				= minilibx-linux
MLX						= $(MLX_PATH)/libmlx.a
LIBFT					= $(LIBFT_PATH)/libft.a
CFLAGS					= -Wall -Werror -Wextra -I$(LIBFT_PATH) -I$(MLX_PATH) -MMD -MP
C_FILES					= main.c \
						  burning_ship.c \
						  colors.c \
						  complex.c \
						  fractals_db.c \
						  julia.c

O_FILES					= $(patsubst %.c, %.o, $(C_FILES))
D_FILES					= $(O_FILES:.o=.d)

all: $(NAME)
bonus: $(BONUS_DONE)

$(MLX):
	$(MAKE) -C $(MLX_PATH) all

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH) all

$(NAME): $(LIBFT) $(OBJ_DIR) $(O_FILES)
	$(CC) $(CFLAGS) -o $@ $(O_FILES) $(MLX) $(LIBFT) -lXext -lX11 -lm

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	rm -rf $(O_FILES) $(D_FILES)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(D_FILES)
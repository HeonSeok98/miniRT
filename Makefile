NAME = miniRT
CC = cc
CFLAGS = -Wall -Werror -Wextra
MLX = -L./mlx -lmlx -framework OpenGL -framework AppKit
OBJS_DIR = object
BOBJS_DIR = object
SRCS = $(wildcard Mandatory/*.c)
BSRCS = $(wildcard Bonus/*.c)
OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))
BOBJS = $(addprefix $(BOBJS_DIR)/, $(notdir $(BSRCS:.c=.o)))
LIB_NAME = libft.a
LIB_OBJS = $(LIB_SRC:.c=.o)
MLX_DIR = mlx
MLX_PATH = $(MLX_DIR)/libmlx.dylib

MK_DIR = @mkdir -p

LIB_DIR = libft
LIB_PATH = $(LIB_DIR)/libft.a

ifdef WITH_BONUS
	OBJECTS = $(BOBJS)
	NAME = miniRT_bonus
else
	OBJECTS = $(OBJS)
endif

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(MAKE) -C $(LIB_DIR)
	$(MAKE) -C $(MLX_DIR)
	cp ./mlx/libmlx.dylib ./
	$(CC) -o $@ $(OBJECTS) $(MLX) $(LIB_PATH) $(MLX_PATH)

$(OBJS_DIR)/%.o : Mandatory/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -Imlx -Ilibft -IInclude -c $< -o $@

$(BOBJS_DIR)/%.o : Bonus/%.c | $(BOBJS_DIR)
	$(CC) $(CFLAGS) -Imlx -Ilibft -IInclude -c $< -o $@

$(OBJS_DIR):
	$(MK_DIR) $(OBJS_DIR)

clean :
	make -C ./libft clean
	make -C $(MLX_DIR) clean
	rm -rf $(OBJS_DIR)
	rm -f ./mlx/*.swiftsourceinfo
	rm -f $(OBJS) $(BOBJS)

fclean : clean
	make -C ./libft fclean
	rm -f libmlx.dylib
	rm -f miniRT_bonus
	rm -f $(NAME)

re: fclean all

bonus : $(BOBJS)
	$(MAKE) WITH_BONUS=1 all

.PHONY: all clean fclean re bonus

# SOURCES
SRCS = srcs/color_utils.c \
		srcs/drawer.c \
		srcs/fractals.c \
		srcs/hooks.c \
		srcs/image.c \
		srcs/main.c \
		srcs/number_utils.c \
		srcs/workspace.c \

# OTHER VARS
NAME	= fractol

# COMPILATION
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
LFLAGS	= -Lminilibx -lmlx -framework OpenGL -framework AppKit -Llibft -lft
IFLAGS	= -Iincludes
FLAGS	= $(CFLAGS) $(LFLAGS) $(IFLAGS)

# COLORS
RED		= \033[0;31m
GREEN	= \033[0;32m
NC		= \033[0m

# MESSAGES
OK		= $(GREEN)✓ OK$(NC)
KO		= $(RED)⨯ KO$(NC)

$(NAME):
	@echo "== making $(NAME) =="
	@make -C libft
	@echo "libft compiled: $(OK)"
	@make -C minilibx
	@echo "minilibx compiled: $(OK)"
	@$(CC) $(FLAGS) -o $(NAME) $(SRCS)
	@echo "$(NAME): $(OK)"

all: $(NAME)

clean:
	@make -C libft fclean
	@echo "libft cleaned: $(OK)"

fclean: clean
	@rm -f $(NAME)
	@echo "removed $(NAME): $(OK)"

re: fclean all

.PHONY: all clean fclean re

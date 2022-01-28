# SOURCES
SRCS	= srcs/checks.c \
		srcs/colors.c \
		srcs/events.c \
		srcs/fractals.c \
		srcs/main.c \
		srcs/maths/absolute.c \
		srcs/maths/range.c \
		srcs/maths/rotate.c \
		srcs/xutils.c \

OBJS	= $(SRCS:.c=.o)

# COMPILATION
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -O3
INCS	= -Iincludes -Iminilibx -Ilibft
LIBS	= -Lminilibx -lmlx -Llibft -lft
OPTS	= -framework OpenGL -framework AppKit
C_OPTS	= $(CFLAGS) $(INCS)
BIN_OPT	= $(LIBS) $(OPTS) $(INCS)

# OTHER
NAME	= fractol
SHELL	= zsh

# COLORS
BG_RD	= \033[48;2;237;66;69m
BG_GR	= \033[48;2;0;194;60m
BG_BL	= \033[48;2;88;101;242m
FG_WH	= \033[38;2;255;255;255m
FG_BK	= \033[38;2;0;0;0m
BOLD	= \033[1m
NOCOL	= \033[0m

# CHARS
TICK	= ✓
PEN		= ✐
CROSS	= 𐄂

# MESSAGES
VALID	= $(BOLD)$(FG_WH)$(BG_GR) $(TICK)
INFO	= $(BOLD)$(FG_WH)$(BG_BL) $(PEN)
DEL		= $(BOLD)$(FG_WH)$(BG_RD) $(CROSS)

.c.o:
	@make -sC minilibx
	@make -sC libft
	@$(CC) $(C_OPTS) -c $< -o $@
	@echo -n "\033[1000D\033[2K$(INFO) $(notdir $@) $(NOCOL)"

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[1000D\033[2K$(INFO) Object files compiled $(NOCOL)"
	@$(CC) $(BIN_OPT) $^ -o $@
	@echo "$(VALID) $@ $(NOCOL)"

clean:
	@make -sC libft clean
	@echo "$(DEL) libft cleaned $(NOCOL)"
	@make -sC minilibx clean
	@echo "$(DEL) minilibx cleaned $(NOCOL)"
	@rm -f $(OBJS)
	@echo "$(DEL) $(words $(OBJS)) obj files $(NOCOL)"

fclean: clean
	@rm -f $(NAME)
	@make -sC libft fclean
	@echo "$(DEL) $(NAME) binary $(NOCOL)"

re: fclean all

.PHONY: all clean fclean re

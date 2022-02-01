# SOURCES
SRCS	= srcs/ft_atoi.c \
		srcs/ft_atol.c \
		srcs/ft_bzero.c \
		srcs/ft_calloc.c \
		srcs/ft_isalnum.c \
		srcs/ft_isalpha.c \
		srcs/ft_isascii.c \
		srcs/ft_isdigit.c \
		srcs/ft_isprint.c \
		srcs/ft_isspace.c \
		srcs/ft_itoa.c \
		srcs/ft_lstadd_back.c \
		srcs/ft_lstadd_front.c \
		srcs/ft_lstclear.c \
		srcs/ft_lstdelone.c \
		srcs/ft_lstiter.c \
		srcs/ft_lstlast.c \
		srcs/ft_lstmap.c \
		srcs/ft_lstnew.c \
		srcs/ft_lstsize.c \
		srcs/ft_memchr.c \
		srcs/ft_memcmp.c \
		srcs/ft_memcpy.c \
		srcs/ft_memmove.c \
		srcs/ft_memset.c \
		srcs/ft_putchar_fd.c \
		srcs/ft_putendl_fd.c \
		srcs/ft_putnbr_fd.c \
		srcs/ft_putstr_fd.c \
		srcs/ft_split.c \
		srcs/ft_strchr.c \
		srcs/ft_strdup.c \
		srcs/ft_striteri.c \
		srcs/ft_strjoin.c \
		srcs/ft_strlcat.c \
		srcs/ft_strlcpy.c \
		srcs/ft_strlen.c \
		srcs/ft_strmapi.c \
		srcs/ft_strncmp.c \
		srcs/ft_strnstr.c \
		srcs/ft_strrchr.c \
		srcs/ft_strtrim.c \
		srcs/ft_substr.c \
		srcs/ft_tolower.c \
		srcs/ft_toupper.c \

OBJS	= $(SRCS:.c=.o)

# COMPILATION
CC		= gcc
AR		= ar
CFLAGS	= -Wall -Wextra -Werror -O3
INCS	= -Iincludes
FLAGS	= $(CFLAGS) $(INCS)

# OTHER
NAME	= libft.a
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
	@$(CC) $(FLAGS) -c $< -o $@
	@echo -n "\033[1000D\033[2K$(INFO) $(notdir $@) $(NOCOL)"

$(NAME): $(OBJS)
	@$(AR) rcus $@ $(OBJS)
	@echo "\033[1000D\033[2K$(VALID) libft compiled $(NOCOL)"

all: $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

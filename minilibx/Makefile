NOM  = libmlx.a
SRC  = mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC += mlx_png.c mlx_mouse.m
OBJ1 = $(SRC:.c=.o)
OBJ  = $(OBJ1:.m=.o)

CFLAGS += -O2
CFLAGS += -DSTRINGPUTX11
CFLAGS += -Wno-deprecated-declarations

all: $(NOM)

$(NOM):	$(OBJ)
	@ar -rc $(NOM) $(OBJ)
	@ranlib $(NOM)
	@echo "\033[1m\033[48;2;0;194;60m\033[38;2;255;255;255m ✓ minilibx compiled \033[0m"

clean:
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app

re: clean all

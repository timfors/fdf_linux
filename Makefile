NAME 				= fdf
LIBFT_NAME			= libft.a
MINILIBX_NAME			= libmlx.a

HEADER_DIR			= includes/
HEADER				= fdf.h key_codes.h

SRC_DIR				= source/
SRC 				= main.c object.c object_draw.c object_calc.c draw_line.c point.c parse.c vector.c render.c key_press.c key_release.c close.c utils.c
OBJ_DIR				= objects/
OBJ 				= $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

LIBFT_DIR			= libft/
LIBFT				= $(LIBFT_DIR)$(LIBFT_NAME)

MINILIBX_DIR			= mlx/
MINILIBX			= $(MINILIBX_DIR)$(MINILIBX_NAME)

FLAGS 				= -Werror -Wall -Wextra
LIBS				= -Lmlx -lmlx -Llibft -lft -lX11 -lm -lz -lXext


all : $(OBJ_DIR) $(MINILIBX) $(LIBFT) $(NAME) 

$(OBJ_DIR)	:
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o	: $(SRC_DIR)%.c $(HEADER_DIR)*.h
	gcc $(FLAGS) -I $(MINILIBX_DIR) -I $(HEADER_DIR) -I$(LIBFT_DIR)  -O3 -c $< -o $@

$(NAME) : $(OBJ) 
	gcc -g -o $@ $^ $(LIBS) $(LDFLAGS)

$(LIBFT)	:
	$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX)	:
	$(MAKE) -C $(MINILIBX_DIR)
	#cp $(MINILIBX_DIR)*.h $(HEADER_DIR)

fclean	: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm $(NAME)

clean	:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MINILIBX_DIR)
	rm -rf $(OBJ_DIR)

re : fclean all

.PHONY : all clean fclean re 

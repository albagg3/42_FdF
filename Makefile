NAME = fdf 
CC = gcc
LIBFT_DIR = lib/libft_src
CFLAGS = -Wall -Wextra -Werror -g3
INC_DIR = inc
OBJ_DIR = obj/
SRC_DIR = src/
MINILIBX_DIR = lib/minilibx_macos/
FSANITIZE	:= -fsanitize=address -g3
MINILIBXCC	= -I mlx -L $(MINILIBX_DIR) -lmlx
OPENGL = -framework OpenGL -framework AppKit
SRC_FILES	=	read_map get_next_line errors main key_codes

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
DEPS 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))

RM = rm -f

 

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
		mkdir -p $(OBJ_DIR)
		$(CC) -I $(INC_DIR)  -c $(CFLAGS) -MMD $< -o $@

all: makelib
	@$(MAKE) $(NAME)

makelib:
		@$(MAKE) -C $(LIBFT_DIR)
		@$(MAKE) -C $(MINILIBX_DIR)

-include $(DEPS)
$(NAME) :	$(LIBFT_DIR)/libft.a $(MINILIBX_DIR)libmlx.a $(OBJ)
		make -sC $(LIBFT_DIR)
		make -sC $(MINILIBX_DIR)
		$(CC) $(CFLAGS) $(FSANITIZE) $(OBJ) $(LIBFT_DIR)/libft.a $(MINILIBXCC) $(OPENGL) -o $(NAME)



clean:
		$(RM) -r $(OBJ_DIR) $(DEPS)
		$(RM) $(LIBFT_DIR)/libft.a
		@make clean -C $(LIBFT_DIR)
		$(RM) $(MINILIBX_DIR)libmlx.a
		@make clean -C $(MINILIBX_DIR)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY : all clean re fclean makelibft

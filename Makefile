NAME = fdf 
CC = gcc
LIBFT_DIR = lib/libft_src
CFLAGS = -Wall -Wextra -Werror
INC_DIR = inc
OBJ_DIR = obj/
SRC_DIR = src/
MINILIBX_DIR = lib/minilibx_macos/
MINILIBXCC	= -I mlx -L $(MINILIBX_DIR) -lmlx
OPENGL = -framework OpenGL -framework AppKit
SRC_FILES	=	main

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
DEPS 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))

RM = rm -f

 

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
		mkdir -p $(OBJ_DIR)
		$(CC)   -c $(CFLAGS) -MMD $< -o $@

all: makelib
	@$(MAKE) $(NAME)

makelib:
		@$(MAKE) -C $(LIBFT_DIR)
		@$(MAKE) -C $(MINILIBX_DIR)

-include $(DEPS)
$(NAME) :	$(LIBFT_DIR)/libft.a $(MINILIBX_DIR)libmlx.a $(OBJ)
		make -sC $(LIBFT_DIR)
		make -sC $(MINILIBX_DIR)
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT_DIR)/libft.a $(MINILIBXCC) $(OPENGL) -o $(NAME)



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

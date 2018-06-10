NAME = fractol
SRC = fractol.c source_two.c source_three.c source_four.c source_five.c source_six.c
OBJ = fractol.o source_two.o source_three.o source_four.o source_five.o source_six.o
REM = rm -rf
FLAGS =  -c -Wall -Werror -Wextra
LINC = -I libft/includes
GINC = -I graphlib/includes
LSINC = -L libft/ -lft
GSINC = -L graphlib/ 
MLX = -lmlx -framework OpenGl -framework AppKit

.PHONY : all clean fclean re


all: $(NAME)

$(NAME): ${OBJ} libft/libft.a graphlib/graphlib.a
	gcc $(FLAGS) $(SRC)
	gcc -O3 -o $(NAME) $(LINC) $(LSINC) $(OBJ) $(GINC) $(MLX) $(GSINC) libft/libft.a graphlib/graphlib.a

%.o: %.c fractol.h
	gcc $< $(FLAGS) -o $@

libft/libft.a:
	make -C libft/

graphlib/graphlib.a:
	make -C graphlib/

clean:
	make clean -C libft/
	make clean -C graphlib/
	$(REM) $(OBJ)
	$(REM) *~

fclean: clean
	make fclean -C libft/
	make fclean -C graphlib/
	$(REM) $(OBJ) $(NAME)
	$(REM) *~

re: fclean all
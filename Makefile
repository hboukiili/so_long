src = *.c ./printf/*.c ./get_next_line/*.c ./function/*.c
so_long = so_long
FLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit
CC = cc

all : so_long
	
$(so_long): $(src)	
	@$(CC) $(FLAGS) $(src) -o so_long
	@tput setaf 2; echo "So_long IS READY"

clean :
	@rm -f so_long
	@tput setaf 1; echo "CLEAN COMPLET"

fclean : clean

re: fclean all
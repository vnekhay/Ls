NAME = ft_ls

SRC= 	src/fill_files.c \
        src/ft_strjoin_path.c \
        src/ls_begin.c \
        src/parser.c \
        src/print_files.c \
        src/print_for_l.c \
        src/quicksort_ascii.c \
        src/quicksort_time.c \


OBJECT = $(SRC:.c=.o)

HEADER = includes

all: $(NAME)

$(NAME): $(OBJECT)
	make -C libft/
	make -C ft_printf/
	gcc -Wall -Wextra -Werror $(OBJECT) -Iincludes -Llibft -lft -Lft_printf -lftprintf -o $(NAME)

%.o:%.c $(HEADER)
	gcc -Wall -Wextra -Werror -o $@ -c $< -Iincludes

clean:
	make -C libft/ clean
	make -C ft_printf/ clean
	rm -f $(OBJECT)

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean
	make -C ft_printf/ fclean 

re: fclean all

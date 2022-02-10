
NAME =	libstr.a

SRCS =	ft_str_init.c ft_str_clear.c ft_str_copy.c \
			str_utils.c ft_str_append.c \
			ft_str_pop.c ft_str_substr.c \
			ft_str_find.c ft_str_erase.c ft_str_compare.c \
			ft_str_compare_nchar.c ft_str_paste.c \

OBJ = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c ft_string.h Makefile
	$(CC)  $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

re: fclean all

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

.PHONY: clean fclean re all
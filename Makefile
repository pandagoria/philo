
NAME = philo

SRCS = main.c utils.c init.c monitor_philos.c \

OBJ = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror -pthread

all: $(NAME)

%.o: %.c philo.h Makefile
	$(CC)  $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FLAGS) -o $(NAME)

re: fclean all

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

.PHONY: clean fclean re all
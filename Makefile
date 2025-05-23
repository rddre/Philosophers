NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = src/philosophers.c\
		src/parsing/parsing.c src/exit/free_exit.c\
		src/philo_routine/philo.c\
		utils/print.c utils/utils.c
OBJ = $(SRC:.c=.o)

# Règles
all: $(NAME)
	@echo "✅ Compilation terminée."

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@rm -f $(OBJ)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
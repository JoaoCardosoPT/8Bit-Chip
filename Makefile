CC = gcc
NAME := chip
CFLAGS = -Wextra -Werror -Wall

SOURCE := main.c $(wildcard src/files/*.c)
INCLUDES := -Iincludes

all: $(NAME)

$(NAME): $(SOURCE)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(SOURCE)

clean: 
	rm -f $(NAME)

fclean: clean
re: fclean all

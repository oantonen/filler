NAME = oantonen.filler

BONUS = visualizer

SRCS = main.c scan_for_sizes.c put_piece.c checking_down.c small_algorithm.c \
small_algorithm_up.c algo_for_m_up.c algo_for_b_down.c algo_for_b_up.c 

SRC = $(addprefix project/,$(SRCS))

HEADERS = libft/includes

OBJ =  $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I $(HEADERS)

all: create_lib $(NAME)

create_lib:
	@make -C libft

$(NAME): $(OBJ)
	@gcc -o $(NAME) $(OBJ) -L libft/ -lft libft/libftprintf.a
	@echo "Let's start the battle"

%.o: %.c
	@$(CC) -c $(CFLAGS) -o $@ $< -I$(HEADERS)

bonus:
	gcc $(CFLAGS) bonus/visual.c -o $(BONUS) -L libft/ -lft libft/libftprintf.a

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) $(BONUS)

re: fclean all

.PHONY: all test clean bonus

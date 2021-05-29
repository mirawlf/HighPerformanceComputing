PUSH_SWAP = push_swap
CHECKER = checker
MAKE = make
LIB = ./libft/libft.a
FLAGS = -Wall -Wextra -Werror

SRC_PUSH_SWAP = ./src/ft_error.c ./src/ft_stack.c ./src/ft_validation.c \
				./src/px.c ./src/rrx.c ./src/sx.c ./src/is_sorted.c \
			    ./src/sort_stacks.c ./src/sorting_algorythm.c ./src/rx.c \
			    ./src/ft_push_swap.c ./src/rotations.c ./src/extra_functions.c \
			    ./src/cleaner.c

SRC_CHECKER = ./src/ft_error.c ./src/ft_stack.c ./src/ft_validation.c ./src/px.c \
			          ./src/rrx.c ./src/rx.c ./src/sx.c ./src/is_sorted.c \
			          ./src/ft_checker.c ./src/cleaner.c
HEADER = ./includes/ft_push_swap.h
LIB = ./libft/libft.a

OBJ_PS = $(SRC_PUSH_SWAP:.c=.o)

OBJ_CK = $(SRC_CHECKER:.c=.o)

all: $(CHECKER) $(PUSH_SWAP)

%.o: %.c
	    gcc $(FLAGS) -c -o $@ $< -g

$(PUSH_SWAP): $(LIB) $(OBJ_PS)
	    gcc $(FLAGS) -I $(HEADER) $(LIB) -o $(PUSH_SWAP) $(SRC_PUSH_SWAP) -g

$(CHECKER): $(LIB) $(OBJ_CK)
	    gcc $(FLAGS) -I $(HEADER)  $(LIB) -o $(CHECKER) $(SRC_CHECKER) -g

$(LIB):
	    $(MAKE) -C ./libft/

clean:
	    $(MAKE) clean -C ./libft
		rm -f $(OBJ_PS)
		rm -f $(OBJ_CK)

fclean: clean
	    $(MAKE) fclean -C ./libft
		rm -f $(PUSH_SWAP)
		rm -f $(CHECKER)

re: fclean all

CC = cc
CFLAGS =-Wall -Wextra -Werror
G = $(shell tput setaf 2)
R = $(shell tput setaf 1)
Y = $(shell tput setaf 3)
DONE = Done
SRCS = ./parse_args/check_is_num.c \
       ./parse_args/fetch_args.c \
	   ./parse_args/convert_int.c \
	   ./parse_args/check_sorted.c \
	   ./src/init_stack.c \
	   ./src/print_stack.c \
	   ./src/index.c \
	   ./src/moves/sa.c \
	   ./src/moves/sb.c \
	   ./src/moves/ss.c \
	   ./src/moves/pa.c \
	   ./src/moves/pb.c \
	   ./src/moves/ra.c \
	   ./src/moves/rb.c \
	   ./src/moves/rr.c \
	   ./src/moves/rra.c \
	   ./src/moves/rrb.c \
	   ./src/moves/rrr.c \
	   ./src/sort/tiny_sort.c \
	   ./src/sort/sort4.c \
	   ./src/sort/sort5.c \
	   ./src/sort/sort100.c \
	   ./src/sort/sort500.c \
       ./utils/ft_strlen.c \
	   ./utils/free_stack.c \
	   ./utils/ft_split.c \
	   ./utils/args_join.c \
	   ./utils/args_dup.c \
	   ./utils/ft_strdup.c \
	   ./utils/ft_atoi.c \
	   ./utils/check_dup.c \
	   ./utils/ft_max.c \
	   ./utils/ft_min.c \
       ./main.c
OBJECTS = $(SRCS:.c=.o)
NAME = push_swap

all: $(NAME)
	@echo $(G) "ALL functions are done!"

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

%.o: %.c
	@echo $(Y) Compiling: $< ... Done!
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo $(R) Cleaned
	@rm -f $(OBJECTS)

fclean: clean
	@echo $(R) Fully Cleaned
	@rm -f $(NAME)

re: fclean all

.PHONY: clean re all fclean

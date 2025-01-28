CC = cc
CFLAGS =-Wall -Wextra -Werror
G = $(shell tput setaf 2)
R = $(shell tput setaf 1)
Y = $(shell tput setaf 3)
DONE = Done
SRCS = ./Mandatory/parse_args/check_is_num.c \
       ./Mandatory/parse_args/fetch_args.c \
	   ./Mandatory/parse_args/convert_int.c \
	   ./Mandatory/parse_args/check_sorted.c \
	   ./Mandatory/src/init_stack.c \
	   ./Mandatory/src/index.c \
	   ./Mandatory/src/moves/sa.c \
	   ./Mandatory/src/moves/sb.c \
	   ./Mandatory/src/moves/ss.c \
	   ./Mandatory/src/moves/pa.c \
	   ./Mandatory/src/moves/pb.c \
	   ./Mandatory/src/moves/ra.c \
	   ./Mandatory/src/moves/rb.c \
	   ./Mandatory/src/moves/rr.c \
	   ./Mandatory/src/moves/rra.c \
	   ./Mandatory/src/moves/rrb.c \
	   ./Mandatory/src/moves/rrr.c \
	   ./Mandatory/src/sort/tiny_sort.c \
	   ./Mandatory/src/sort/sort4.c \
	   ./Mandatory/src/sort/sort5.c \
	   ./Mandatory/src/sort/sort100.c \
	   ./Mandatory/src/sort/sort500.c \
       ./Mandatory/utils/ft_strlen.c \
	   ./Mandatory/utils/free_stack.c \
	   ./Mandatory/utils/ft_split.c \
	   ./Mandatory/utils/args_join.c \
	   ./Mandatory/utils/args_dup.c \
	   ./Mandatory/utils/ft_strdup.c \
	   ./Mandatory/utils/ft_atoi.c \
	   ./Mandatory/utils/check_dup.c \
	   ./Mandatory/utils/ft_max.c \
	   ./Mandatory/utils/ft_min.c \
       ./Mandatory/main.c
BON =	./Bonus/parse_args/check_is_num.c \
       ./Bonus/parse_args/fetch_args.c \
	   ./Bonus/parse_args/convert_int.c \
	   ./Bonus/parse_args/check_sorted.c \
	   ./Bonus/src/init_stack.c \
	   ./Bonus/src/check_stack_sort.c \
	   ./Bonus/src/moves/sa.c \
	   ./Bonus/src/moves/sb.c \
	   ./Bonus/src/moves/ss.c \
	   ./Bonus/src/moves/pa.c \
	   ./Bonus/src/moves/pb.c \
	   ./Bonus/src/moves/ra.c \
	   ./Bonus/src/moves/rb.c \
	   ./Bonus/src/moves/rr.c \
	   ./Bonus/src/moves/rra.c \
	   ./Bonus/src/moves/rrb.c \
	   ./Bonus/src/moves/rrr.c \
       ./Bonus/utils/ft_strlen.c \
	   ./Bonus/utils/free_stack.c \
	   ./Bonus/utils/ft_split.c \
	   ./Bonus/utils/args_join.c \
	   ./Bonus/utils/args_dup.c \
	   ./Bonus/utils/ft_strdup.c \
	   ./Bonus/utils/ft_atoi.c \
	   ./Bonus/utils/check_dup.c \
	   ./Bonus/utils/ft_strcmp.c \
	   ./Bonus/get_next_line/get_next_line.c \
	   ./Bonus/get_next_line/get_next_line_utils.c \
       ./Bonus/main.c
OBJECTS = $(SRCS:.c=.o)
OBJ_BONUS = $(BON:.c=.o)
NAME = push_swap
NAME_BONUS = checker

all: $(NAME)
	@echo $(G) "ALL functions are done!"

bonus : $(NAME_BONUS)
	@echo $(G) "ALL functions are done!"

$(NAME_BONUS) : $(OBJ_BONUS)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS)

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

Mandatory/%.o: Mandatory/%.c ./Mandatory/push_swap.h
	@echo $(Y) Compiling: $< ... Done!
	@$(CC) $(CFLAGS) -c $< -o $@

Bonus/%.o: Bonus/%.c ./Bonus/push_swap_bonus.h
	@echo $(Y) Compiling: $< ... Done!
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo $(R) Cleaned
	@rm -f $(OBJECTS) $(OBJ_BONUS)

fclean: clean
	@echo $(R) Fully Cleaned
	@rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: clean re all fclean

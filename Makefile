NAME	= pipex

# SOURCES
_SRC	= main.c

SRCS	= $(addprefix src/, $(_SRC))
OBJS	= $(SRCS:.c=.o)

# COMPILER
CC		= clang-13
CFLAGS	= -Wall -Wextra -Werror

INCL	= -I ./includes -I ./lib/libft
LIBS	= -L ./lib/libft -lft

# RULES
%.o: %.c includes/$(NAME).h
	$(CC) $(CFLAGS) $(INCL) -c $< -o $@

$(NAME): $(OBJS)
	@make -s -C ./lib/libft bonus
	$(CC) $(CFLAGS) -o $(NAME) $(INCL) $(OBJS) $(LIBS)

all: $(NAME)

clean:
	make -s -C ./lib/libft clean
	rm -f $(OBJS)

fclean:
	make -s -C ./lib/libft fclean
	rm -f $(OBJS) $(NAME)

re: fclean all
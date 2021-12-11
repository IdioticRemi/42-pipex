NAME	= pipex

# SOURCES
_SRC	= main.c

SRCS	= $(addprefix src/, $(_SRC))
OBJS	= $(SRCS:.c=.o)

_BSRC	= bonus.c

BSRCS	= $(addprefix src/, $(_BSRC))
BOBJS	= $(BSRCS:.c=.o)

# COMPILER
UNAME	= $(shell uname)

ifeq ($(UNAME), Linux)
CC		= clang-13
endif
ifeq ($(UNAME), Darwin)
CC		= clang
endif

CFLAGS	= -Wall -Wextra -Werror

INCL	= -I ./includes -I ./lib/libft
LIBS	= -L ./lib/libft -lft

# RULES
%.o: %.c includes/$(NAME).h
	$(CC) $(CFLAGS) $(INCL) -c $< -o $@

$(NAME): $(OBJS) $(BOBJS)
	@make -s -C ./lib/libft bonus
	$(CC) $(CFLAGS) -o $(NAME) $(INCL) $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) -o $(NAME)_bonus $(INCL) $(BOBJS) $(LIBS)

all: $(NAME)

clean:
	make -s -C ./lib/libft clean
	rm -f $(OBJS)

fclean:
	make -s -C ./lib/libft fclean
	rm -f $(OBJS) $(NAME)

re: fclean all

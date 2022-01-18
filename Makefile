NAME	= pipex

# SOURCES
_SRC	= main.c

SRCS	= $(addprefix src/, $(_SRC))
OBJS	= $(SRCS:.c=.o)

_BSRC	= bonus.c

BSRCS	= $(addprefix src/, $(_BSRC))
BOBJS	= $(BSRCS:.c=.o)

# COMPILER
CC		= clang
CFLAGS	= -Wall -Wextra -Werror -O3

INCL	= -I ./includes -I ./lib/libft
LIBS	= -L ./lib/libft -lft

# FORMAT
FG_MAGE	= \033[0;35m
FG_CYAN	= \033[0;36m
FG_WHIT	= \033[0;37m
FG_GREE	= \033[0;32m

C_BUILD	= $(FG_WHIT)[ PIPEX ]$(FG_WHIT) $(FG_CYAN)Starting build process.\n$(FG_WHIT)
C_AR	= $(FG_WHIT)[ PIPEX ]$(FG_WHIT) $(FG_GREE)Built '$(NAME)'.\n$(FG_WHIT)
C_AR_B	= $(FG_WHIT)[ PIPEX ]$(FG_WHIT) $(FG_GREE)Built '$(NAME)_bonus'.\n$(FG_WHIT)
C_CLEAN	= $(FG_WHIT)[ PIPEX ]$(FG_WHIT) $(FG_MAGE)Build objects cleaned.\n$(FG_WHIT)
C_FCLEA	= $(FG_WHIT)[ PIPEX ]$(FG_WHIT) $(FG_MAGE)Library was cleaned.\n$(FG_WHIT)

# RULES
%.o: %.c includes/$(NAME).h
	@$(CC) $(CFLAGS) $(INCL) -c $< -o $@
	@printf "."

log:
	@printf "$(C_BUILD)"

$(NAME): log $(OBJS) $(BOBJS)
	@printf " [$(words $(OBJS) $(BOBJS))]\n"
	@make -s -C ./lib/libft all
	@$(CC) $(CFLAGS) -o $(NAME) $(INCL) $(OBJS) $(LIBS)
	@printf "$(C_AR)"
	@$(CC) $(CFLAGS) -o $(NAME)_bonus $(INCL) $(BOBJS) $(LIBS)
	@printf "$(C_AR_B)"

all: $(NAME)

clean:
	@make -s -C ./lib/libft clean
	@rm -f $(OBJS) $(BOBJS)
	@printf "$(C_CLEAN)"

fclean:
	@make -s -C ./lib/libft fclean
	@rm -f $(OBJS) $(BOBJS) $(NAME)
	@printf "$(C_FCLEA)"

re: fclean all

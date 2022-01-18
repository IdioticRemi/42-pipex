# LIB NAME

NAME	= libft.a

# SOURCES

SRC	= \
	ft_memset ft_memcpy ft_memmove ft_memchr ft_memcmp ft_bzero \
	ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint \
	ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd \
	ft_strchr ft_strrchr ft_strncmp ft_strnstr \
	ft_substr ft_strjoin ft_strtrim ft_split\
	ft_strlen ft_strlcpy ft_strlcat \
	ft_strmapi ft_striteri \
	ft_toupper ft_tolower \
	ft_strdup ft_calloc \
	ft_atoi ft_itoa \
	ft_lstnew ft_lstadd_front ft_lstadd_back \
	ft_lstdelone ft_lstclear \
	ft_lstsize ft_lstlast \
	ft_lstiter ft_lstmap \
	ft_pathjoin ft_afree

SRCS	= $(addsuffix .c, $(SRC))
OBJS	= $(SRCS:.c=.o)

# COMMANDS

CC		= clang
RM		= rm -f
AR		= ar rc
RN		= ranlib

CFLAGS	= -Wall -Werror -Wextra -O3

# FORMAT

FG_MAGE	= \033[0;35m
FG_CYAN	= \033[0;36m
FG_WHIT	= \033[0;37m
FG_GREE	= \033[0;32m

C_BUILD	= $(FG_WHIT)[ LIBFT ]$(FG_WHIT) $(FG_CYAN)Starting build process.\n$(FG_WHIT)
C_AR	= $(FG_WHIT)[ LIBFT ]$(FG_WHIT) $(FG_GREE)Built '$(NAME)'.\n$(FG_WHIT)
C_CLEAN	= $(FG_WHIT)[ LIBFT ]$(FG_WHIT) $(FG_MAGE)Build objects cleaned.\n$(FG_WHIT)
C_FCLEA	= $(FG_WHIT)[ LIBFT ]$(FG_WHIT) $(FG_MAGE)Library was cleaned.\n$(FG_WHIT)

# RULES

%.o: %.c libft.h
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "."

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@$(RN) $(NAME)
	@printf " [$(words $(OBJS))]\n"
	@printf "$(C_AR)"

log:
	@printf "$(C_BUILD)"

all: log $(NAME)

clean:
	@$(RM) $(OBJS)
	@printf "$(C_CLEAN)"

fclean:
	@$(RM) $(NAME) $(OBJS)
	@printf "$(C_FCLEA)"

re: fclean all

# LIB NAME

NAME	= libft.a

# SOURCES

SRC	= \
	ft_memset ft_memcpy ft_memmove ft_memchr ft_memcmp ft_bzero \
	ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint \
	ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd \
	ft_strchr ft_strrchr ft_strichr ft_strncmp ft_strnstr \
	ft_substr ft_strjoin ft_strtrim ft_split\
	ft_strlen ft_strlcpy ft_strlcat \
	ft_strmapi ft_striteri \
	ft_toupper ft_tolower \
	ft_strdup ft_calloc \
	ft_atoi ft_itoa \
	ft_pathjoin

SRCS	= $(addsuffix .c, $(SRC))
OBJS	= $(SRCS:.c=.o)

B_SRC	= \
	ft_lstnew ft_lstadd_front ft_lstadd_back \
	ft_lstdelone ft_lstclear \
	ft_lstsize ft_lstlast \
	ft_lstiter ft_lstmap

B_SRCS	= $(addsuffix .c, $(B_SRC))
B_OBJS	= $(B_SRCS:.c=.o)

# COMMANDS

CC		= gcc
RM		= rm -f
AR		= ar rc
RN		= ranlib

CFLAGS	= -Wall -Werror -Wextra

# FORMAT

FG_MAGE	= \033[0;35m
FG_CYAN	= \033[0;36m
FG_WHIT	= \033[0;37m
FG_GREE	= \033[0;32m

C_RESET	= \033[0m

C_BUILD	= $(FG_WHIT)     [ BUILD ]$(RESET)
C_BIN	= $(FG_CYAN)%20s$(RESET)
C_BOUT	= $(FG_CYAN)%20s$(RESET)
C_AR	= $(FG_WHIT)        [ AR ]$(RESET) $(FG_MAGE)$(NAME) has been packed.$(RESET)
C_AR_BO	= $(FG_WHIT)        [ AR ]$(RESET) $(FG_MAGE)$(NAME) has been packed with bonuses.$(RESET)
C_CLEAN	= $(FG_WHIT)     [ CLEAN ]$(RESET) $(FG_GREE)Every .o has been removed.$(RESET)
C_FCLEA	= $(FG_WHIT)    [ FCLEAN ]$(RESET) $(FG_GREE)$(NAME) was removed.$(RESET)

# RULES

%.o: %.c libft.h
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(C_BUILD)$(C_BIN)$(C_BOUT)\n" "$<" "$@"

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@$(RN) $(NAME)
	@printf "$(C_AR)\n"

bonus: $(NAME) $(B_OBJS)
	@$(AR) $(NAME) $(OBJS) $(B_OBJS)
	@$(RN) $(NAME)
	@printf "$(C_AR_BO)\n"

all: $(NAME)

clean:
	@$(RM) $(OBJS) $(B_OBJS)
	@printf "$(C_CLEAN)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(C_FCLEA)\n"

re: fclean all

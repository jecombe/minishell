FOLDERO = objs

MKDIR = mkdir -p $(FOLDERO)

.PHONY: all re clean fclean

NAME = minishell

CC = gcc

CC_FLAGS = -Wall -Wextra -Werror

HEAD = -I

LIB_DIR = ./libft/

LIB = libft.a

SOURCES = srcs

FILES = main.c \
		path.c \
		prompt.c \
		builtin.c \
		tools.c \
		env.c \
		cd.c \
		fork.c \
		str_to_tab.c \
		quote.c \
		epure.c \
		ft_free.c \
		pwd.c \
		tools2.c\
		ft_split.c\
		ft_strsplit2.c \
		ft_split_quote.c \
		tools3.c \
		tools4.c \
		tools_env.c \
		tools_env_2.c \
		tild.c \
		dollar.c

END=\x1b[0m
BOLD=\x1b[1m
UNDER=\x1b[4m
REV=\x1b[7m

GREY=\x1b[30m
RED=\x1b[31m
GREEN=\x1b[32m
YELLOW=\x1b[33m
BLUE=\x1b[34m
PURPLE=\x1b[35m
CYAN=\x1b[36m
WHITE=\x1b[37m


BGREY=\x1b[40m
BRED=\x1b[41m
BGREEN=\x1b[42m
BYELLOW=\x1b[43mm
BBLUE=\x1b[44m
BCYAN=\x1b[46m
BPURPLE=\x1b[45m
BWHITE=\x1b[47m



FOBJS = $(FILES:.c=.o)

OBJS = $(addprefix $(FOLDERO)/,$(FOBJS))

all: $(NAME)


$(NAME): $(LIB) $(OBJS)
	@gcc -o $(NAME) $(OBJS) $(LIB_DIR)$)$(LIB)
	@echo "\033[1;35m ==========> COMPILING $(NAME)"
	@echo "\033[1;32m ==========[ MINISHELL SUCCESSFULLY CREATED ]=========="
	@printf "$(ASCII_ART)"

$(LIB):
	@cd $(LIB_DIR) && $(MAKE)

$(FOLDERO)/%.o: $(SOURCES)/%.c
	@mkdir $(FOLDERO) 2> /dev/null || true
	@$(CC) $(HEAD) $(CC_FLAGS) -o $@ -c $<
	@echo "\033[1;34m$@ ==> CREATED"

clean:
	@cd $(LIB_DIR) && $(MAKE) $@
	@/bin/rm -f $(OBJS)
	@echo "\033[1;31m$(OBJS) ==> DELETED"
	@echo "\033[1;31m objs ==> DELETED"

fclean: clean
	@cd $(LIB_DIR) && /bin/rm -f $(LIB)
	@/bin/rm -f $(NAME)
	@rm -rf objs
	@echo "\033[1;31m$(LIB) ==> DELETED"
	@echo "\033[1;31m$(NAME) ==> DELETED"
	@echo "\033[1;31m objs ==> DELETED"

re: fclean all

NAME := pipex
.DEFAULT_GOAL := all
CC:= cc 
AR := ar
RM := rm -rf

################################################################################
###############                  DIRECTORIES                      ##############
################################################################################

OBJ_DIR := _obj

INC_DIRS := inc
SRC_DIRS := src

# Tell the Makefile where headers and source files are
vpath %.h $(INC_DIRS)
vpath %.c $(SRC_DIRS)

################################################################################
###############                  SOURCE FILES                     ##############
################################################################################

MAIN_FILE := main.c

SRC_TEST_MAIN := main_tests.c

TEST_FILES := heredoc.c helper_functions_1.c helper_functions_2.c
TEST := $(addprefix , $(TEST_FILES))

#Combines all
MELTING_POT := $(TEST)

SRCS := $(MAIN_FILE) $(addprefix src/, $(MELTING_POT))

OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

################################################################################
########                   Git Modules                          ################
################################################################################

MODULES_DIR := modules

LIBFT_DIR := $(addprefix $(MODULES_DIR)/, my_libft)
LIBFT_OBJS := $(addprefix $(LIBFT_DIR)/, build)
LIBFT_A := $(addprefix $(LIBFT_DIR)/, libft.a)



################################################################################
########                         COMPILING                      ################
################################################################################

CFLAGS := -Wall -Wextra -g -MMD -MP -I$(INC_DIRS)
# CFLAGS :=	-Wall -Werror -Wextra -g -MMD -MP $(addprefix -I, $(INC_DIRS))
CFLAGS_SAN := $(CFLAGS)
#LDFLAGS := -lncurses -fsanitize=address
# LDFLAGS := -lncurses
#LDFLAGS_SAN := -lncurses -fsanitize=address
ARFLAGS := -rcs

# ANSI color codes
GREEN := \033[0;32m
MAGENTA := \033[0;35m
BOLD := \033[1m
NC := \033[0m # Reset

NAME_TEST=tests.out

all: $(NAME) $(LIBFT_A)

$(LIBFT_A):
	@echo "Compiling libft..."
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT_A)
	$(CC) $(LDFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)
	@echo "$(GREEN)$(BOLD)Successful Compilation$(NC)"

# Rule to compile .o files
$(OBJ_DIR)/%.o: %.c| $(OBJ_DIR)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Ensure the directories exist
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR) $(LIBFT_OBJS)

fclean: clean
	$(RM) $(NAME) $(NAME_TEST) $(LIBFT_A)
	@echo "$(MAGENTA)$(BOLD)Executable + Object Files cleaned$(NC)"

re: fclean all

bonus: all

san:
	make CFLAGS="$(CFLAGS_SAN)" LDFLAGS="$(LDFLAGS_SAN)"
	@echo "$(GREEN)$(BOLD)Successful Compilation with fsan$(NC)"

debug: clean
debug: CFLAGS += -DDEBUG
debug: $(NAME)

redebug: fclean debug

test:
	make $(NAME_TEST) MAIN_FILE="$(SRC_TEST_MAIN)" NAME=$(NAME_TEST)

retest: fclean test

-include $(OBJS:%.o=%.d)

.PHONY: all clean fclean re bonus san debug test
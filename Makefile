# ---------------------------------------------------------------------------- #
#                                  VARIABLES                                   #
# ---------------------------------------------------------------------------- #

NAME			:=	libftprintf.a

# --------------------------------- PATHNAMES -------------------------------- #

SRC_CONVERSIONS	:=	conversions/
SRC_DATA		:=	data/
SRC_PARSING		:=	parsing/
SRC_PRINTF		:=	printf/
SRC_UTILS		:=	utils/
SRC_VPRINTF		:=	vprintf/

# -------------------------------- CONVERSIONS ------------------------------- #

SRC				+=	$(SRC_CONVERSIONS)convert_field.c
SRC				+=	$(SRC_CONVERSIONS)convert_flags.c
SRC				+=	$(SRC_CONVERSIONS)convert_literals.c
SRC				+=	$(SRC_CONVERSIONS)convert_numerals.c

# ----------------------------------- DATA ----------------------------------- #

SRC				+=	$(SRC_DATA)clean_data.c
SRC				+=	$(SRC_DATA)init_data.c
SRC				+=	$(SRC_DATA)join_data.c

# ---------------------------------- PARSING --------------------------------- #

SRC				+=	$(SRC_PARSING)parse_flag.c
SRC				+=	$(SRC_PARSING)parse_format.c
SRC				+=	$(SRC_PARSING)parse_padding.c
SRC				+=	$(SRC_PARSING)parse_precision.c
SRC				+=	$(SRC_PARSING)process_format.c

# ---------------------------------- PRINTF ---------------------------------- #

SRC				+=	$(SRC_PRINTF)ft_dprintf.c
SRC				+=	$(SRC_PRINTF)ft_printf.c
SRC				+=	$(SRC_PRINTF)ft_snprintf.c
SRC				+=	$(SRC_PRINTF)ft_sprintf.c

# ----------------------------------- UTILS ---------------------------------- #

SRC				+=	$(SRC_UTILS)ft_free.c
SRC				+=	$(SRC_UTILS)ft_utoa_base.c
SRC				+=	$(SRC_UTILS)ft_memset.c
SRC				+=	$(SRC_UTILS)ft_strchr.c
SRC				+=	$(SRC_UTILS)ft_strcpy.c
SRC				+=	$(SRC_UTILS)ft_strdup.c
SRC				+=	$(SRC_UTILS)ft_strlen.c
SRC				+=	$(SRC_UTILS)ft_strncpy.c
SRC				+=	$(SRC_UTILS)ft_valloc.c

# ---------------------------------- VPRINTF --------------------------------- #

SRC				+=	$(SRC_VPRINTF)ft_vdprintf.c
SRC				+=	$(SRC_VPRINTF)ft_vsnprintf.c
SRC				+=	$(SRC_VPRINTF)ft_vsprintf.c

# --------------------------------- COMMANDS --------------------------------- #

CC				:=	cc
RM				:=	/bin/rm -rf
AR				:=	ar rc
MKDIR			:=	mkdir -p

# ----------------------------------- FLAGS ---------------------------------- #

CFLAGS			+=	-Wall
CFLAGS			+=	-Wextra
CFLAGS			+=	-Werror
CFLAGS			+=	-MMD
CFLAGS			+=	-MP

DEBUG_CFLAGS	+=	-g3

MAKE_NO_PRINT	:=	--no-print-directory
MAKE_FLAGS		+=	$(MAKE_NO_PRINT)
MAKE_FLAGS		+=	-C

# ----------------------------------- PATHS ---------------------------------- #

INCLUDES		:=	includes/

SRCS_DIR		:=	sources/
SRCS			:=	$(addprefix $(SRCS_DIR), $(SRC))

OBJS_DIR		:=	objects/
OBJS			:=	$(addprefix $(OBJS_DIR), $(SRC:.c=.o))

# ---------------------------------- STYLES ---------------------------------- #

RED				:=	"\033[0;31m\033[1m"
GREEN			:=	"\033[0;32m\033[1m"
BLUE			:=	"\033[0;34m\033[1m"
PURPLE			:=	"\033[0;35m\033[1m"
YELLOW			:=	"\033[1;33m\033[1m"
WHITE			:=	"\033[0;37m\033[1m"
NO_STYLE		:=	"\033[0m"

# ----------------------------------- ECHO ----------------------------------- #

ECHO			:=	echo

DELETION		:=	$(RED)Deletion$(NO_STYLE) of
CREATION		:=	$(GREEN)Creation$(NO_STYLE) of
TO_UPPER		:=	tr '[:lower:]' '[:upper:]'
TRUNC_A			:=	tr -d '.a'
PROJECT			:=	$(shell $(ECHO) $(NAME) | $(TRUNC_A) | $(TO_UPPER))
OBJ_FILES		:=	$(BLUE)object files$(NO_STYLE)
DEPS_FILES		:=	$(BLUE)dependencies files$(NO_STYLE)
AND				:=	and
COMPLETE		:=	complete
BONUS_FILES		:=	bonus object files
TO_UPPER		:=	tr '[:lower:]' '[:upper:]'
TRUNC_A			:=	tr -d '.a'
PROJECT			:=	$(shell $(ECHO) $(NAME) | $(TRUNC_A) | $(TO_UPPER))
PROJECT_NAME	:=	$(WHITE)$(PROJECT)$(NO_STYLE)
NAME_FILE		:=	$(BLUE)$(NAME)$(NO_STYLE)
NORM_MSG		:=	$(GREEN)Norminette on $(PROJECT_NAME)$(GREEN): OK!$(NO_STYLE)

COMP_OBJS		:=	$(ECHO) $(CREATION) $(PROJECT_NAME) $(OBJ_FILES) $(AND) $(DEPS_FILES) $(COMPLETE)
COMP_NAME		:=	$(ECHO) $(CREATION) $(PROJECT_NAME) $(NAME_FILE) $(COMPLETE)
OK_NORM			:=	$(ECHO) $(NORM_MSG)
COMP_CLEAN		:=	$(ECHO) $(DELETION) $(PROJECT_NAME) $(OBJ_FILES) $(AND) $(DEPS_FILES) $(COMPLETE)
COMP_FCLEAN		:=	$(ECHO) $(DELETION) $(PROJECT_NAME) $(NAME_FILE) $(COMPLETE)

define HELP_MSG
Usage: make [TARGET]
		all         - Create the archive file(s)
		clean       - Remove object file(s)
		fclean      - Remove object file(s) and archive file(s)
		re          - Recreate the archive file(s)
		bonus       - Build the bonus part of the program
		norm        - Run norminette checks
		debug       - Activate debug flags
		help        - Display this help message
endef
export HELP_MSG

HELP			:=	@$(ECHO) "$$HELP_MSG"

# -------------------------------- NORMINETTE -------------------------------- #

NORMINETTE		:=	norminette
NORMSH			:=	$(NORMINETTE) -R CheckForbiddenSourceHeader $(SRCS)
NORMD			:=	$(NORMINETTE) -R CheckDefine $(INCLUDES)

# ---------------------------------------------------------------------------- #
#                                    RULES                                     #
# ---------------------------------------------------------------------------- #

$(OBJS_DIR)%.o:		$(SRCS_DIR)%.c
					@$(MKDIR) $(dir $@)
					@$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

all:				$(NAME)

$(NAME):			$(OBJS)
					@$(COMP_OBJS)
					@$(AR) $(NAME) $(OBJS)
					@$(COMP_NAME)

clean:
					@$(RM) $(OBJS_DIR)
					@$(COMP_CLEAN)

fclean:				clean
					@$(RM) $(NAME)
					@$(COMP_FCLEAN)

re:					fclean all

bonus:				all

norm:
					@$(NORMSH)
					@$(NORMD)
					@$(OK_NORM)

debug:
					@$(MAKE) $(MAKE_NO_PRINT) CFLAGS+="$(DEBUG_CFLAGS)" re

help:
					$(HELP)

-include $(DEPS)

.PHONY:				all clean fclean re bonus norm

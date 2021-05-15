NAME		=	libasm.a
TEST_EXEC	=	test.out

# **************************************************************************** #
# *-------------------------PATHS AND DIRECTORIES----------------------------* #
# **************************************************************************** #

include	src.mk

SRC_C_PATH	=	src/c/
SRC_C		=	$(addprefix $(SRC_C_PATH), $(SRC_FILES_C))
OBJ_C		=	$(SRC_C:.c=.o)

SRC_S_PATH	=	src/asm/
SRC_S		=	$(addprefix $(SRC_S_PATH), $(SRC_FILES_S))
OBJ_S		=	$(SRC_S:.s=.o)

LIBS		=	asm
LIB_DIR		=	.
INC_DIR		=	include

# **************************************************************************** #
# *---------------------------COMPILERS AND FLAGS----------------------------* #
# **************************************************************************** #

CC			=	gcc
NASM		=	nasm
ASMFLAGS	=	-f elf64

CFLAGS		=	-Wall -Wextra -Werror
CPPFLAGS	=	$(foreach path, $(INC_DIR), -I $(path))
LDFLAGS		=	$(foreach path, $(LIB_DIR), -L $(path))
LIBFLAGS	=	$(foreach lib, $(LIBS), -l $(lib))
LIBC		=	ar -rcs
RM			=	rm -f

# **************************************************************************** #
# *-----------------------------------RULES----------------------------------* #
# **************************************************************************** #


$(NAME):	$(OBJ_S) 
		@$(LIBC) $(NAME) $(OBJ_S)
		@echo "$(basename $(NAME)) built successfully."

all:	$(NAME)

clean:
		@$(RM) $(OBJ_S) $(OBJ_C)
		@$(RM) $(TEST_EXEC)
		@echo "Object files for $(basename $(NAME)) removed."
		@$(RM) src/text/write.txt

fclean:	clean
		@$(RM) $(NAME)
		@echo "$(NAME) removed."

re:	fclean all

eval:	$(OBJ_C) $(NAME)
		@$(CC) -no-pie $(OBJ_C) $(LDFLAGS) $(LIBFLAGS) -o $(TEST_EXEC) 
		@echo "$(TEST_EXEC) built successfully."
		@./$(TEST_EXEC)

.c.o:
		@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $(<:.c=.o)
.s.o:
		@$(NASM) $(ASMFLAGS) $< -o $(<:.s=.o)

.PHONY: all clean fclean re eval less .c.o .s.o

NAME = calc

SRCS = src/mx_calculator.c \
            src/mx_atoi.c \
            src/mx_isdigit.c \
            src/mx_isspace.c \
            src/mx_printint.c \
            src/mx_printchar.c \
            src/mx_printstr.c \
            src/mx_strlen.c \
            src/mx_printerr.c \
            src/mx_add.c \
            src/mx_sub.c \
            src/mx_mul.c \
            src/mx_div.c \
            src/mx_mod.c \
            
OUT = mx_calculator.o \
            mx_atoi.o \
            mx_isspace.o \
            mx_isdigit.o \
            mx_printstr.o \
            mx_printchar.o \
            mx_printint.o \
            mx_strlen.o \
            mx_printerr.o \
            mx_add.o \
            mx_sub.o \
            mx_mul.o \
            mx_div.o \
            mx_mod.o \
            
INCLUDES = inc/

all: $(NAME)

$(NAME): $(SRCS)
	@clang -std=c11 -Wall -Wextra -Werror -Wpedantic -c $(SRCS) -I $(INCLUDES)	
	@clang -std=c11 -Wall -Wextra -Werror -Wpedantic -o calc $(OUT)
clean:
	@/bin/rm -f $(OUT)
fclean: clean
	@/bin/rm -f $(NAME)

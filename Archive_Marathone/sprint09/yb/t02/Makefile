NAME = minilibmx.a

SRCS = src/mx_atoi.c \
		src/mx_isdigit.c \
		src/mx_isspace.c \
		src/mx_printchar.c \
		src/mx_printint.c \
		src/mx_printstr.c \
		src/mx_strcmp.c \
		src/mx_strcpy.c \
		src/mx_strlen.c \

OUT = mx_atoi.o \
		mx_isdigit.o \
		mx_isspace.o \
		mx_printchar.o \
		mx_printint.o \
		mx_printstr.o \
		mx_strcmp.o \
		mx_strcpy.o \
		mx_strlen.o \

INCLUDES = inc/


all: $(NAME)

$(NAME): $(SRCS)
	@clang -std=c11 -Wall -Wextra -Werror -Wpedantic -c $(SRCS) -I $(INCLUDES)
	@ar rc $(NAME) $(OUT)
clean:
	@/bin/rm -f $(OUT)
fclean: clean
    
	@/bin/rm -f $(NAME)
re: fclean all


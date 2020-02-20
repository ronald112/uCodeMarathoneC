NAME = read_file

INC = inc/minilibmx.h

HEADBIN = minilibmx.h

SRCS = src/read_file.c \
			src/mx_atoi.c \
			src/mx_isdigit.c \
			src/mx_isalpha.c \
			src/mx_isspace.c \
			src/mx_toupper.c \
			src/mx_printint.c \
			src/mx_printchar.c \
			src/mx_strcmp.c \
			src/mx_printstr.c \
			src/mx_strlen.c \
			src/mx_strcpy.c \
			src/mx_printerr.c \

SRCSBIN = read_file.c \
			mx_atoi.c \
			mx_isdigit.c \
			mx_isalpha.c \
			mx_isspace.c \
			mx_toupper.c \
			mx_printint.c \
			mx_printchar.c \
			mx_strcmp.c \
			mx_printstr.c \
			mx_strlen.c \
			mx_strcpy.c \
			mx_printerr.c \

OBJBIN = read_file.o \
			mx_atoi.o \
			mx_isdigit.o \
			mx_isalpha.o \
			mx_isspace.o \
			mx_toupper.o \
			mx_printint.o \
			mx_printchar.o \
			mx_strcmp.o \
			mx_printstr.o \
			mx_strlen.o \
			mx_strcpy.o \
			mx_printerr.o \



CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install uninstall 
	
install:
	@cp $(SRCS) .
	@cp $(INC) .
	@clang $(CFLAGS) -o $(NAME) $(SRCSBIN)
	
uninstall: 
	@rm -rf $(SRCSBIN)
	@rm -rf $(OBJBIN)
	@rm -rf $(HEADBIN)
clean:
	@rm -rf $(NAME)	
	@rm -rf $(SRCSBIN)
	@rm -rf $(OBJBIN)
	@rm -rf $(HEADBIN)
reinstall: clean all


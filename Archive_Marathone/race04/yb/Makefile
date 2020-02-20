NAME = race04

INC = inc/header.h

HEADBIN = header.h

SRCS = src/main.c \
			src/mx_math.c \
			src/mx_atoi.c \
			src/mx_isdigit.c \
			src/mx_isspace.c \
			src/mx_printint.c \
			src/mx_printchar.c \
			src/mx_printstr.c \
			src/mx_strlen.c \
			src/mx_errcheck.c \
			src/mx_file_to_str.c \
			src/mx_oper.c \
			src/mx_param.c \
			src/mx_printerr.c \
			src/mx_printmass.c \
			src/mx_strnew.c \
			src/mx_valid_char.c \
			

SRCSBIN = main.c \
			mx_math.c \
			mx_atoi.c \
			mx_isdigit.c \
			mx_isspace.c \
			mx_printint.c \
			mx_printchar.c \
			mx_printstr.c \
			mx_strlen.c \
			mx_errcheck.c \
			mx_file_to_str.c \
			mx_oper.c \
			mx_param.c \
			mx_printerr.c \
			mx_printmass.c \
			mx_strnew.c \
			mx_valid_char.c \



CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install uninstall 
	
install:
	@cp $(SRCS) .
	@cp $(INC) .
	@clang $(CFLAGS) -o $(NAME) $(SRCSBIN)	

uninstall: 
	@rm -rf $(SRCSBIN)
	@rm -rf $(HEADBIN)

clean: uninstall
	@rm -rf $(NAME)	
	@rm -rf path.txt
	
reinstall:
	@cp $(SRCS) .
	@cp $(INC) .
	@clang $(CFLAGS) -o $(NAME) $(SRCSBIN)

	@rm -rf $(SRCSBIN)
	@rm -rf $(HEADBIN)


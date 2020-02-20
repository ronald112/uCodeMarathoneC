NAME = race05

INC = inc/header.h

HEADBIN = header.h

SRCS = src/main.c \
#		src/mx_printerr.c \

SRCSBIN = main.c \
#		mx_printerr.c \

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -lncurses



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
	
reinstall:
	@cp $(SRCS) .
	@cp $(INC) .
	@clang $(CFLAGS) -o $(NAME) $(SRCSBIN)

	@rm -rf $(SRCSBIN)
	@rm -rf $(HEADBIN)


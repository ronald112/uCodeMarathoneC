CC = gcc
NAME = pathfinder.c
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic
LFLAGS = -ILibmx/inc Libmx/libmx.a
DFLAGS = -g -fsanitize=address

all:
	@$(CC) $(CFLAGS) $(NAME) $(LFLAGS)

rls:
	@$(CC) $(CFLAGS) -Werror $(NAME) $(LFLAGS)

dbg:
	@$(CC) $(CFLAGS) $(DFLAGS) $(NAME) $(LFLAGS)

uninstall:
	@rm -f a.out
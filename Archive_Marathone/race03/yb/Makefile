NAME = race03

CC=g++

SRCS = src/mx_poker.c \
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
			src/mx_is_valid_card.c \
			src/mx_init_card.c \
			src/mx_sort_cards.c \
			src/mx_check_dup.c \
			src/mx_is_royal_flush.c \
			src/mx_is_straight_flush.c \
			src/mx_is_four.c \
			src/mx_is_full_house.c \
			src/mx_is_flush.c \
			src/mx_is_straight.c \
			src/mx_is_three.c \
			src/mx_is_two_pair.c \
			src/mx_is_two.c \
			src/mx_comb_finder.c \
			src/mx_rank_to_str.c \

INC = inc/minilibmx.h

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install clean
install:
	@cp $(SRCS) .
	@cp $(INC) .
	@clang $(CFLAGS) -o $(NAME) *.c
uninstall: clean
	@rm -rf $(NAME)
clean:
	@rm -rf *.h
	@rm -rf *.c
reinstall: uninstall clean all


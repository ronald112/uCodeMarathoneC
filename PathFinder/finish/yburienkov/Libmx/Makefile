NAME = libmx.a

CC = clang

INC = libmx.h

RAW = printchar print_unicode printstr print_strarr printint pow sqrt \
	nbr_to_hex hex_to_nbr itoa foreach binary_search bubble_sort quicksort \
	\
	strlen swap_char str_reverse strdel del_strarr get_char_index strdup \
	strndup strcpy strncpy strcmp strcat strstr get_substr_index count_substr \
	count_words strnew strtrim del_extra_spaces strsplit strjoin file_to_str \
	read_line replace_substr \
	\
	memset memcpy memccpy memcmp memchr memrchr memmem memmove realloc \
	\
	create_node push_front push_back pop_front pop_back list_size sort_list \
	\
	atoi printerr \
	isalpha isdigit isspace islower isupper \
	\
	tolower toupper pow_for_mx_hex_to_nbr \
	strlen_for_mx_str_reverse isspace_forsplit strtrim_forsplit del_extra_spaces_forsplit \
	\
	open read_mod read_mod_readline \
	\
	clear_list print_list swap_node 



SRC = $(addprefix mx_, $(addsuffix .c, $(RAW)))
OBJ = $(addprefix mx_, $(addsuffix .o, $(RAW)))

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install clean

install:
	@cp $(addprefix src/, $(SRC)) .
	@cp $(addprefix inc/, $(INC)) .
	@$(CC) $(CFLAGS) -c $(SRC)
	@ar rcs $(NAME) $(OBJ)
	@mkdir obj
	@mv $(OBJ) ./obj

uninstall: clean
	@rm -rf $(NAME)

clean:
	@rm -rf $(INC) $(SRC) ./obj

reinstall: uninstall install

NAME = pathfinder

CC = clang

INC = pathfinder.h

RAW = mx_wrong_line mx_create_graph mx_create_vars mx_check_valid_1Line \
	mx_check_isvalid_alpha mx_first_check mx_check_file_empty \
	mx_check_valid_frst_line mx_check_valid_file mx_strjoin_mod1 \
	mx_get_rslt_rdline mx_add_to_graph mx_add_to_isld mx_crt_isld_matrix \
	mx_free_vars_str mx_set_weight_arr mx_crt_isld_matrix_copy \
	mx_free_fn mx_get_min_distance mx_add_to_begin mx_get_nb_way \
	mx_add_to_str mx_print_dist mx_print_route mx_check_first_line \
	mx_find_route mx_get_all_path mx_free_djkstra mx_set_to_false_checker \
	mx_print_solution mx_set_start_vars mx_add_par_path mx_add_parent_and_weight \
	mx_dijkstra mx_addstr main

SRC = $(addsuffix .c, $(RAW))
OBJ = $(addsuffix .o, $(RAW))

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

LFLAGS = -ILibmx/inc

#@$(CC) $(CFLAGS) -c $(SRC) -I $(INC) -v

all: install clean

install:
	@make install -sC libmx
	@cp $(addprefix src/, $(SRC)) .
	@cp $(addprefix inc/, $(INC)) .
	@$(CC) $(CFLAGS) -c $(SRC) -I $(INC)
	@$(CC) $(CFLAGS) libmx/libmx.a $(OBJ) -o $(NAME)
	@mkdir -p obj
	@mv $(OBJ) ./obj

uninstall: clean
	@make uninstall -sC libmx
	@rm -rf $(NAME)

clean:
	@make clean -sC libmx
	@rm -rf $(INC) $(SRC) $(OBJ) ./obj

reinstall: uninstall install

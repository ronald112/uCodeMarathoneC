NAME = pathfinder

LIB_AR = ./Libmx/libmx.a

LIB = ./Libmx

CC = gcc

RAW = mx_wrong_line mx_create_graph mx_create_vars mx_check_valid_1Line \
	mx_check_isvalid_alpha mx_first_check mx_check_file_empty \
	mx_check_valid_frst_line mx_check_valid_file mx_strjoin_mod1 \
	mx_get_rslt_rdline mx_add_to_graph mx_add_to_isld mx_crt_isld_matrix \
	mx_free_vars_str mx_set_weight_arr mx_crt_isld_matrix_copy \
	mx_free_fn mx_get_min_distance mx_add_to_begin mx_get_nb_way \
	mx_add_to_str mx_print_dist mx_print_route mx_check_first_line \
	mx_find_route mx_print_all mx_free_djkstra mx_set_to_false_checker \
	mx_print_solution mx_set_start_vars mx_add_par_path mx_add_parent_and_weight\
	mx_dijkstra 

SRC_DIR = src/
OBJ_DIR = obj/

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(RAW)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(RAW)))

INC = inc/pathfinder.h

CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -Werror

all: uninstall install clean

install: 
	@cd $(LIB) && make install
	@mkdir $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(SRC) -c $(SRC) -I $(INC)
	@mv $(OBJ) $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(SRC) $(LIB_AR) -o $(NAME) -I $(INC)
	@make clean


uninstall: clean
	@rm -rf $(NAME)
	@cd $(LIB) && make uninstall

clean: 
	@rm -rf $(OBJ_DIR)
	@cd $(LIB) && make clean

reinstall: uninstall all
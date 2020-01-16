NAME = pathfinder
LIB = libmx.a
CC = clang

RAW = mx_wrong_line mx_create_graph mx_create_vars mx_check_valid_1Line \
	mx_check_isvalid_alpha mx_first_check mx_check_file_empty \
	mx_check_valid_frst_line mx_check_valid_file mx_strjoin_mod1 \
	mx_get_rslt_rdline mx_add_to_graph mx_add_to_isld mx_crt_isld_matrix \
	mx_free_vars_str mx_set_weight_arr mx_crt_isld_matrix_copy \
	mx_free_fn mx_get_min_distance mx_add_to_begin \
	mx_create_routes mx_lutil \
	mx_free_djkstra mx_sort_list_djkvar \
	mx_print_routes mx_set_start_vars mx_add_parent_and_weight \
	mx_dijkstra mx_addstr mx_main

SRC_DIR = ./src/
OBJ_DIR = ./obj/
LIB_DIR = ./libmx/

SRC = $(addprefix $(SRC_DIR), $(addprefix , $(addsuffix .c, $(RAW))))
OBJ = $(addprefix $(OBJ_DIR), $(addprefix , $(addsuffix .o, $(RAW))))
LIB_PATH = $(addprefix $(LIB_DIR), $(LIB))

WFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
LFLAGS = -Iinc -Ilibmx/inc
CFLAGS = -Ofast -march=native -pipe -fomit-frame-pointer
DFLAGS = -O0 -g -fsanitize=address

all: install clean

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIB):
	@make -sC $(LIB_DIR) -f Makefile install

# install
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(WFLAGS) $(LFLAGS) -o $@ -c $<

$(NAME): $(OBJ_DIR) $(OBJ)
	@$(CC) $(WFLAGS) $(LFLAGS) $(OBJ) -o $(NAME) $(LIB_PATH)

# optimize
# $(OBJ_DIR)%.o: $(SRC_DIR)%.c
# 	@$(CC) $(WFLAGS) $(LFLAGS) $(CFLAGS) -o $@ -c $<

# $(NAME): $(OBJ_DIR) $(OBJ)
# 	@$(CC) $(WFLAGS) $(LFLAGS) $(CFLAGS) $(OBJ) -o $(NAME) $(LIB_PATH)

# debug
# $(OBJ_DIR)%.o: $(SRC_DIR)%.c
# 	@$(CC) $(WFLAGS) $(LFLAGS) $(DFLAGS) -o $@ -c $<

# $(NAME): $(OBJ_DIR) $(OBJ)
# 	@$(CC) $(WFLAGS) $(LFLAGS) $(DFLAGS) $(OBJ) -o $(NAME) $(LIB_PATH)

install: $(LIB) $(NAME)

clean:
	@make -sC $(LIB_DIR) -f Makefile clean
	@rm -rf $(OBJ_DIR)

uninstall:
	@make -sC $(LIB_DIR) -f Makefile uninstall
	@rm -rf $(NAME)
	@rm -rf $(OBJ_DIR)

reinstall: uninstall install


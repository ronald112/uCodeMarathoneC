NAME = uls

INC = ./inc/uls.h \
		./libmx/inc/libmx.h \

INCL = ./libmx/inc/libmx.h \

HEADTMP = ./uls.h \
			./libmx.h \
			./libmx/libmx.h

FILES = mx_parse_flags default_fun testLS mx_set_flags_false \
		mx_create_list_of_catalog mx_init_info mx_print_lflag \
		mx_get_full_path mx_ifl_true mx_get_permissions \
		mx_chk_xatr mx_add_links mx_add_usr mx_add_filesize \
		mx_add_lastchange_time mx_add_hardlink mx_print_totalsize

SRC = $(addsuffix .c, $(FILES))

SRCS = $(addprefix src/, $(SRC))

OBJ = $(addsuffix .o, $(FILES))

OBJO = $(addprefix obj/, $(OBJ))

CFLGS = -std=c11 -Wall -Wpedantic -Wextra #-Werror# -g -fsanitize=address

all: install clean

install:
	@make -C libmx -f Makefile install
	@cp $(INC) $(SRCS) .
	@cp $(INCL) ./libmx/
	@clang $(CFLGS) -c  $(SRC) libmx/inc/libmx.h -Iinc
	@mkdir -p obj
	@mv $(OBJ) ./obj
	@clang $(CFLGS) $(OBJO) libmx/libmx.a -o $(NAME)

uninstall:
	@rm $(NAME)

clean:
	@make -C libmx -f Makefile uninstall
	@make -C libmx -f Makefile clean
	@rm -rf $(OBJO) $(SRC) $(HEADTMP)
	@rm -rf ./obj
	@rm -rf ./libmx/libmx.h.gch

reinstall: uninstall all

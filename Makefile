NAME = uls
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -Werror
INC = uls.h
SRC = open_dir.c\
	mx_sort.c\
	mx_biggest.c\
	mx_multicol.c\
	mx_parse.c
OBJ = open_dir.o\
	mx_sort.o\
	mx_biggest.o\
	mx_multicol.o\
	mx_parse.o
all: install clean
install:
	@make install -sC libmx
	@cp $(addprefix src/, $(SRC)) .
	@cp $(addprefix inc/, $(INC)) .
	@clang $(CFLAGS) -c $(SRC) -I $(INC)
	@clang $(CFLAGS) libmx/libmx.a $(OBJ) -o $(NAME)
	@mkdir -p obj
	@mv $(OBJ) ./obj
uninstall: clean
	@make uninstall -sC libmx
	@rm -rf $(NAME)
clean:
	@make clean -sC libmx
	@rm -rf $(INC) $(SRC) ./obj
reinstall: uninstall install
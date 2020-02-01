NAME = uls
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -Werror
INC = uls.h libmx.h
SRC = open_dir.c
OBJ = open_dir.o
all: install clean
install:
	@make reinstall -sC libmx
	@cp $(addprefix src/, $(SRC)) .
	@cp $(addprefix inc/, $(INC)) .
	@clang $(CFLAGS) -c $(SRC) -I $(INC)
	@clang $(CFLAGS) libmx/libmx.a $(OBJ) -o $(NAME)
	@mkdir -p obj
	@mv $(OBJ) ./obj
	@rm -rf libmx.a __.SYMDEF\ SORTED libmx.h.gch
uninstall: clean
	@make uninstall -sC libmx
	@rm -rf $(NAME)
clean:
	@make clean -sC libmx
	@rm -rf $(INC) $(SRC) ./obj
reinstall: uninstall install
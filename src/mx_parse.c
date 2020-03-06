#include "uls.h"

void mx_parse(int argc, char **argv) {
    char *str = mx_strnew(2);
    str = "1l";

    for (int i = 1; i < argc && argv[i][0] == '-'; i++) {
        if (argv[i][0] == '-' && argv[i][1] != '\0') {
            for (int j = 1; argv[i][j] != '\0'; j++) {
                if (mx_get_char_index(str, argv[i][j]) == -1) {
                        write(2, "uls: illegal option -- ", 23);
                        write(2, &argv[i][j], 1);
                        write(2, "\nusage: uls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n", 64);
                        exit(1);
                    }
            }
        }
    }
}

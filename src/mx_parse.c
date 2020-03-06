#include "uls.h"

static int len_record(int argc, char **argv) {
    int size = 0;

    for (int i = 1; i < argc && argv[i][0] == '-'; i++)
        if (argv[i][0] == '-' && argv[i][1] != '\0')
            for (int j = 1; argv[i][j] != '\0'; j++)
                if (argv[i][0] == '-' && argv[i][1] != '-')
                	size = size + mx_strlen(argv[i]) - 1;
    return size;
}

static char *record(int argc, char **argv) {
    char *str = NULL;
    int size = 0;
    int k = 0;

    size = len_record(argc, argv);
    str = mx_strnew(size);
    for (int i = 1; i < argc && argv[i][0] == '-'; i++)
        if (argv[i][0] == '-' && argv[i][1] != '\0')
            for (int j = 1; argv[i][j] != '\0'; j++)
                if (argv[i][0] == '-') {
                	if (mx_strcmp(argv[i], "--") == 0) 
                		return str;
                    else
                        str[k++] = argv[i][j];
                }
    return str;
} 

void mx_parse(int argc, char **argv) {
    char *str = mx_strnew(11);
    //char str[11];
    str = "1lmCSturafA";
    char *true_str = NULL;
    int h = 0;

    for (int i = 1; i < argc && argv[i][0] == '-'; i++) {
        if (argv[i][0] == '-' && argv[i][1] != '\0') {
            for (int j = 1; argv[i][j] != '\0'; j++) {
                if (mx_get_char_index(str, argv[i][j]) == -1) {
                	if (mx_strcmp(argv[i], "--") == 0) 
                		h = i;
                	else {
                        write(2, "uls: illegal option -- ", 23);
                        write(2, &argv[i][j], 1);
                        write(2, "\nusage: uls [-ACSaflmrtu1] [file ...]\n", 38);
                        exit(1);
                    }
                }
                else
                    true_str = record(argc, argv);    
            }
        }
    }
    mx_printstr(true_str);
    mx_printchar('\n');
}
